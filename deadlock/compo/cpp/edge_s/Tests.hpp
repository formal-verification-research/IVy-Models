#ifndef TESTS_HPP
#define TESTS_HPP

// The following can be found in type_planning.xlsx
// This model represents: corner_nw
#define NUM_ZONES 13
#define NUM_OPTIONS 1782

//Comment out the invalid entry directions.
#define IN_CONDITIONS (inDir == 0 || inDir == 1 || inDir == 2)

#include <string>

void runSafeTests(std::string testID);
void runUnsafeTests(std::string testID);
int countPass(bool pass[NUM_OPTIONS]);
int countFail(bool pass[NUM_OPTIONS]);

#endif