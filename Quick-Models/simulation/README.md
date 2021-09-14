# Routing Algorithm Verification

This directory includes a model of the routing algorithm after some modifications. It is *not* livelock-free for the purpose of illustrating the livelock proof.

Estimated required time: 30-60 minutes

## Execution Instructions

1. To execute the C++ simulation, navigate to the `NxN` directory and use the `make` command.
3. To prove livelock scenarios, navigate to the `livelocks` directory and execute `make`.
3. Then navigate to the `livelocks/ivyfiles` directory and use the `make` command to use IVy to verify the livelock scenarios. The `livelocks/ivyfiles/tests` folder contains the traces from IVy to verify correctness (`OK` at the bottom of the trace indicates correctness).
4. To analyze the livelock scenarios, navigate to the `../pattern_finder` directory. Execute `a.out` in that directory. It will prompt you for a path to the folder it will look in for the livelock trace. Once it has analyzed the traces, it will give detailed summaries of the livelock patterns in the `pattern_finder/test` folder.
