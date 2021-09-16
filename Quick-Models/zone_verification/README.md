## Zone Verification

Every reference to a directory will be from the perspective of the `Quick-Models/zone_verification` subfolder (i.e. directory `a` refers to the directory `~/Desktop/Quick-Models/zone_verification/a`).

This folder contains the model used to produce abstract zones with the help of IVy. The work from this subfolder is described in Sections 9-10 of the paper.

*This process will generally take under 30 minutes but may take more depending on available CPU*

###  To Reproduce Simulation Results

1. Execute `make`. When prompted for  the name of a file, enter `minimal_copy`, then enter `n` when asked if you’d like dropped flit testing. This `minimal_copy` model is a variation of Algorithm 1 and produces several livelock scenarios. As IVy detects livelock scenarios, they will appear on the terminal. IVy will provide a list of variables at the time livelock was detected. What follows the words `found livelock:` is the addition to the invariant used to detect additional livelock scenarios. It is, in effect, a livelock trace. That is, what follows `found livelock:` is $\sigma_1$ as explained in Section 10 of the paper (on page 17). 
2. Allow the terminal to run for several executions, then close it to kill the process (otherwise it will discover livelock scenarios for several hours). Examine the file at `minimal_copy_n_tests_<timestamp>/0.ivy`. This is the model that IVy first verified after executing the script. Now examine the file at `minimal_copy_n_tests_<timestamp>/1.ivy`. The livelock trace discovered in Step 1 is appended to the invariant at the end of `1.ivy` just as $\sigma _1$ is appended to $\sigma _0$ in Section 10 of the paper (on page 17). 

----

