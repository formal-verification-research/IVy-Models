# VERSION 3
This version started with the accurate livelock checker. 
Goal: write a script to automate livelock discovery

## 3.0
Equivalent to version 2.3 (livelock-free new protocol)

## 3.1
Equivalent to version 2.4 (livelock-ridden old protocol, used to automate the script).

# VERSION 2
This version started once version 1 was accurately able to detect livelocks.
Goal: get actual livelock detection and verification working

## 2.0
Finding a way to detect all livelocks using ~livelock | specific_pattern

## 2.1 
Adding up to 6 steps in cycle rather than just 4

## 2.2
It was reaching a weird state by going south 1 from G to H, then east to I, then north to I. Adding more details to getNextZone

## 2.3
Extending invariants to cover 6 steps (i.e. NESWNES vs NESWN), plus some repairs to the typos in the routing protocol.

LIVELOCK FREEDOM TESTED AND ACHIEVED!!!

## 2.4
Testing livelock verification on former protocol... it works!!

## 2.5
Testing the new protocol, but without the destNE specification. destNE NOT NECESSARY!!! Hooray! This version is the clean version, without extra comments hanging out


# VERSION 1
This version is a rough version that only validates that the routing protocol actually routes the flits.
Goal: Detect livelocks

## 1.1
First glimpse at successful livelock detection!

## 1.2
Livelock-free with very limited rules

## 1.3
Same great features as 1.2 plus better fault recall!
First glimpse at actually livelock free system!

## 1.4
Fault tolerance up to 3 faults? because why not

## 1.5
What. It's fault tolerant up to 4 faults. This is exciting!

## 1.6
Okay but 5 faults definitely crashes it. Whoops!

## 1.7
Further testing on old and new protocols


# VERSION 0
This version exists only to test the model checking capability in IVy. Nothing real gets tested here.
Goal: Get unbounded model checker working

## 0.1
This version shows the basic thing works

## 0.2
Working toward reachable states and testing the require keyword

## 0.3
Tested with and without the model checker active. IVy failed due to an unreachable state error, but the model checker passed because all reachable states satisfied the invariant.

## 0.4
Playing with the idea of a ~delivered invariant

## 0.5
Playing with bit vectors as a move counter (flag likely livelocks?). Works great in model checker, not so much in IVy.