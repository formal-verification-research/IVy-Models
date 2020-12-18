# NoC Architecture Verification

The model names in this directory correspond to the description of each type from `type-notes.pdf`.

Detailed description and instructions for the IVy syntax and tool are available at <http://microsoft.github.io/ivy/>. We include specific instructions here to describe how to produce a trace identical to those listed here.

## Execution Instructions

1. With IVy installed, download the IVy file and navigate to its directory from the command line.
2. Create a trace file with the following command: `ivy_check trace=true file.ivy > file.txt` replacing file with the IVy model name.

The trace should indicate a pass with `OK` in older versions of IVy or `PASS` in newer versions. Should an invariant fail, the counterexample will be printed as a single-state transition from a valid state to an invalid state.
