# Just a note
Do we really need the indicators of many vs one if we're livelock-free in a system that considers the option of a flit going an arbitrary number of times in one direction? See version 1.3 lines 359-772

# VERSION 1
This version is a rough version that only validates that the routing protocol actually routes the flits.

## 1.1
First glimpse at successful livelock detection!

## 1.2
Livelock-free with very limited rules

## 1.3
Same great features as 1.2 plus better fault recall!
First glimpse at actually livelock free system!

### 1.4
Fault tolerance up to 3 faults? because why not

### 1.5
What. It's fault tolerant up to 4 faults. This is exciting!

### 1.6
Okay but 5 faults definitely crashes it. Whoops!

# VERSION 0
This version exists only to test the model checking capability in IVy. Nothing real gets tested here.

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