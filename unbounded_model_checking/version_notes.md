# VERSION 1
This version is a rough version that only validates that the routing protocol actually routes the flits.

## 1.1



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