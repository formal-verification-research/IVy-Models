# Zone Verification

*Note: To execute these files, you must have IVy, AIGER, and the ABC Model Checker installed. All are freely available online.*

These are the final results we present in our paper. To recreate these results, simply run `python3 main.py` from the root directory and select your version when prompted.

This model is designed to do most of the work behind-the-scenes

The tests that run appear in a labeled, timestamped folder. 

## Versions Present

| Version         | Notes |
| :---            | :---  |
| v0              | Original routing protocol |
| v1              | Protocol from C++ verification | 
| v2              | Final protocol |
| minimal_copy    | Only records moves as one general movement |
| minimal_copy_ll | Original livelock-laden protocol (to verify that it still finds livelock) |
