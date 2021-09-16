## Zone Abstraction

Every reference to a directory will be from the perspective of the `Quick-Models/zone_abstraction` subfolder (i.e. directory `a` refers to the directory `~/Desktop/Quick-Models/zone_abstraction/a`).

This folder contains the model used to produce abstract zones with the help of IVy. The work from this subfolder is described in Section 8 of the paper.

*This process will generally take under 30 minutes but may take more depending on available CPU*

###  To Reproduce Results

1. Navigate to the `5x5` directory and run the command `ivy_check 5x5.ivy > test.txt`. This model is an implementation of Figure 4(c) and its description in Section 8 of the paper.
2. After waiting for a moment, a lengthy trace will appear in the file `5x5/test.txt` ending with the keyword `FAIL`. In the case of this model, that indicates that two zones satisfy identical conditions. To discover which zones are identical, look for lines which read `zone.ok(j) = true` and `zone.ok(k) = true`. This indicates that zones B and L in Figure 4(c) can be combined into a single zone. This allows us to modify the model and continue to verify until the zones are all unique. The files `5x5/5x5_1.ivy` through `5x5/5x5_7.ivy` demonstrate our process of combining zones. These files show the intermediate steps between Figure 4(c) and Figure 4(d) in the paper.
3. When all the zones are unique and the conditions from Section 8 of the paper are all satisfied, IVy will verify it. In the `5x5` directory, execute the command `ivy_check 5x5_7.ivy > final.txt`. The trace in `final.txt` indicates a `PASS` at the end of the file. This means that all zones are unique. This is a verification of the zone model implemented in Figure 4(d) of the paper.