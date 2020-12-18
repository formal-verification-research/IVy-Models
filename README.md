# Scaling Up Network-on-Chip Verification
As presented by Landon Taylor and Zhen Zhang. 

See <https://formal-verification-research.github.io> for more information

---

This repository contains the files used as part of our research to formally verify a fault-tolerant livelock-free routing algorithm for a mesh network.

Within each folder, steps to recreate our results are enumerated. 

## Repository Contents:

| Directory         | Description       |
| ----------------- | ----------------- |
| arbitration       | Verifying correctness of the handshake arbitration protocol and the network architecture. See Sections 5 and 6 in our paper. | 
| routing           | Correct verification of the routing protocol using C++ simulation. | 
| zones             | Using scripts to formally verify the zone-based model |
| software          | Software used to generate verification results |
