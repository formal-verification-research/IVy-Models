# Properties of livelock worth checking:

## Never terminates:
- Might require providing a specific cycle?
  - UNLESS: unbounded model checker works (only reachable states???)

## Within a zone
- Rule that says it leaves the zone
- Have a routing decision that says "send south until obstacle reached or left zone"

## In general
- No N E S W N, etc
- Proves livelock freedom plus some

## Things that can lead to livelock (things to watch for):
- Illegal turn (all livelock MUST include an illegal turn)
- 

## Things to consider:
- Bounded model may have something useful when considering max no of moves???
- Definitely a project for Deeplearning if depth > 10
- Can livelock be modelled in larger clusters of zones instead of the whole network? i.e. a flit will never leave a certain chunk?
- We need to assume faults are permanent

