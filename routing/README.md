# Routing Algorithm Verification

Each folder in this directory corresponds to a version of the routing protocol that was progressively improved upon by the C++ model.

Detailed description and instructions for the IVy syntax and tool are available at <http://microsoft.github.io/ivy/>. We include specific instructions here to describe how to produce a trace identical to those listed here.

## Execution Instructions

1. With IVy installed, download one of the folders (named after the NoC dimmensions). In order to run correctly, the following file architecture should exist: 
```
NxN
 - cannotroutetrace/[empty]
 - deliveredtrace/[empty]
 - livelocktrace/[empty]
 - livelocks/
   - main.cpp
   - Utils.cpp
   - Utils.hpp
   - _1.txt
   - _2.txt
   - _3.txt
   - ivyfiles/
     - tests/[empty]
 - pattern_finder/
   - test/[empty]
   - a.out
 - Node.cpp
 - Node.hpp
 - Route.cpp
 - Route.hpp
 - Utils.cpp
 - Utils.hpp
 - main.cpp
 - makefile
 ```
2. To execute the C++ simulation, navigate to the `NxN` directory and use the `make` command.
3. To prove livelock scenarios, navigate to the `livelocks` directory and execute `a.out`. You may have to copy the `livelocks` directory into your `NxN` directory, depending on the version of the protocol you download. Then navigate to the `ivyfiles` directory and use the `make` command to use IVy to verify the livelock scenarios. The `tests` folder contains the traces from IVy to verify correctness (`OK` at the bottom of the trace indicates correctness).
4. To analyze the livelock scenarios, navigate to the `pattern_finder` directory or move it into the `NxN` directory. Execute `a.out` in that directory. It will prompt you for a path to the folder it will look in for the livelock trace. Once it has analyzed the traces, it will give detailed summaries of the livelock patterns in the `test` folder.
