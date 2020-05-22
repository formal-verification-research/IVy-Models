# **2x2 Routing Protocol Model**
Readme updated 7 NOV 2019

# Description of Each Object and Its Current Actions

### Variables
`type int` is used to create an integer variable. `interpret int -> int` tells IVy it really is an integer.  
`type arbiter` is a list of the arbiters that any given router can choose from (further specified in each router). This is used mainly by the `assigned` variables (later discussed.)  
`type router` is a list of the routers. It is currently unused.  
`type coord` is a set of numbers that make up the coordinates of the node (0 or 1).  
`relation sending` is set to true then to false by the `intf.send` action. This may be more useful in the future.  
`var flit_to_watch` is the ID of the flit that the program decides to observe. See `spec.after init` for more details.  

### intf
This object holds actions that are called throughout the program.  
`action change_watch` is used to change which flit the system will watch. It's called when the flit is found to be in livelock.  
`action check` is called by the arbiter objects and "checks" the routers to see if they have packets. Perhaps it will be eliminated eventually, depending on the invariants we add to the `spec` to run before this action.  
`action choose` is called by the arbiter. When simultaneous requests occur, the arbiter chooses one to serve arbitrarily. Perhaps it will be eliminated eventually, depending on the invariants we add to the `spec` to run before this action.  
`action send` is called by the arbiter. When a flit is ready to be sent, it quickly causes `sending(s,r,a)` to be true then false.  

### spec
This object holds conditions on which the actions from `intf` are required to run.  
`after init` sets the faulty status of the arbiters to false (see `individual faulty` in each arbiter object).  
`before intf.change_watch` is currently empty. It will eventually contain specifications.  
`before intf.check` holds a requirement that prevents deadlock. It's checked by the first `invariant` (see below).  
`before intf.choose` is currently empty. It will eventually contain specifications.  
`before intf.send` is currently empty. It will eventually contain specifications.  


## Generating Routers
These routers generate flits and send them into the system.  

### r_PE_10
This is currently the only generating router in the system.  
`individual has_flit` shows whether or not there is currently a flit in this router.  
`individual ready` shows whether or not it is ready to send the flit it has into the system.  
`individual x_dest` is the x-coordinate of the destination of the flit.  
`individual y_dest` is the y-coordinate of the destination of the flit.  
`individual assigned` is the arbiter that gets assigned to send the packet on.  
`individual id` is the ID of the flit that is currently in the router.  
`individual last_generated` is the last ID the router generated (to make a sequential list).  

`after init` does the following:  
- arbitrarily decides if r_PE_10 has a flit or not  
- sets `ready` to false  
- resets `last_generated`.  

`action generate` includes the following logic:  
- if `has_flit` is true  
  - arbitrarily chooses `x_dest` and `y_dest`  
  - sets `id` to one more than `last_generated`  
  - ensures `id` is greater than `last_generated`  
  - updates `last_generated` to the current `id`  
  - if the destination is (1,1), assign to the north arbiter if it's available; if not, assign to the west arbiter if it's available; if not, drop the packet.  
  - if the destination isn't (1,1), assign to the west arbiter if it's available; if not, assign to the north arbiter if it's available; if not, drop the packet.  

`action send_flit` calls `intf.check` or tells the arbiters to check for flits once it's ready to send the flit.  


## Arbiters
All the arbiters follow a similar pattern, so for simplicity's sake, only `arb_N_10` is defined here.  

### arb_N_10
Similar elements are found in objects `arb_W_10`, `arb_E_00`, and `arb_S_11`  
`individual faulty` shows if the link *leaving* the arbiter is faulty.  
`individual busy` shows if the link *leaving* the arbiter is busy (if the downstream router already has a flit).  
`type can_get_from` is a list of all the routers that can possibly send a flit to the current arbiter.  
`individual get_from` is the router that the arbiter has decided to get a flit from.  
`individual rand` is used to create a random boolean value if it needs to choose between exactly 2 routers to serve.  
`after init` does the following:  
- requires `busy` to be false and that at least one router from the `can_get_from` list has a flit that's `assigned` to this arbiter.  
- sets `rand` nondeterministically.  
`before move_flit` does the following:  
- if all 3 have flits, choose one nondeterministically from `can_get_from` (store chosen router in `get_from`).  
- if only 2 have flits, choose one nondeterministically using `rand` (store chosen router in `get_from`).  
- if only 1 has a flit, choose it and store in `get_from`.  
`action move_flit` does the following:  
- calls `intf.send` to modify the `sending` relation.  
- if `get_from` is any upstream router  
  - remove the flit from the upstream router (set `has_flit` to `false`)  
  - copy the information (`x_dest`, `y_dest`, and `id`) to the downstream router  
  - set `has_flit` to `true` in the downstream router.  


## Routers
All the routers (except the generating routers) follow a similar pattern, so for simplicity's sake, only `r_W_10` is defined here.  

### arb_N_10
Similar elements are found in objects `r_N_10`, `r_E_00`, and `r_S_11`.  
`individual has_flit` shows whether there is currently a flit in the router  
`individual x_dest` is the x-coordinate of the eventual destination of the flit.  
`individual y_dest` is the y-coordinate of the eventual destination of the flit.  
`individual assigned` is the downstream arbiter that is assigned to handle the flit.  
`individual ready` shows if the arbiter has been assigned and the flit is ready to send.  
`individual id` is the ID of the flit that's currently in the router.  
`individual tally` is the count of how many times the `flit_to_watch` ID has been in this router.  

`after init` does the following:  
- nondeterministically decides if there is already a flit here (`has_flit = *;`)  
- reset the counter (`tally`).  
- if `has_flit` is true  
  - set `busy` to `true`  
  - set `id` to `0` (we don't need to track the flits that aren't generated by `r_PE_10`).  

`action assigned` does the following, only if `has_flit = true`:  
- if the destination is this node, assign it to arb_PE_10 (this node's processing element arbiter)  
- if the destination is (1,1), assign to the north arbiter if it's available; if not, assign to the west arbiter if it's available; if not, drop the packet.  
- if the destination isn't (1,1), assign to the west arbiter if it's available; if not, assign to the north arbiter if it's available; if not, drop the packet.  

`action counter` does the following if the flit it has is `flit_to_watch`:  
- if `tally < 5` (if the packet hasn't been here 5 times already)  
  - increment the `tally`  
- else  
  - drop the flit (`has_flit := false`)  
  - call `intf.change_watch` to start observing a different flit  
  - reset `tally`  

`execute` makes sure to count the visits before sending the flit somewhere.  

## Invariants
The invariants are currently as follows:  
- Each critical router in one direction cannot be busy (to prevent deadlock)  
- No `tally` variable should ever be greater than 5.  
