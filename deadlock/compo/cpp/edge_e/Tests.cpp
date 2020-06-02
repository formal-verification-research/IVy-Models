#include "Tests.hpp"
#include "Utils.hpp"
#include "Route.hpp"

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
// #include <cstdlib>

/*
CODES USED IN VARIABLES (EASIER FOR LOOPS): 


Dir: North  0
     East   1
     South  2
     West   3
		 Error  9  //Means it's waiting on a busy link on an illegal turn

		// Zones: a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  (all possible zones)
		// Codes: 0  1  2  -  -  -  -  -  -  3  4  5  -  6  7  -  8  9  (depend on node type)

Link: Ready  0
      Faulty 1
      Busy   2
			Fake   -

*/

void runSafeTests(std::string testID) 
{
	char zone = 0; 
	char inDir = 0;
	char northLink = '-';
	char eastLink = '-';
	char southLink = '-';
	char westLink = '-';
	bool pass[NUM_OPTIONS + 1] = {};
	int i = 0;
	stringstream trace;

	ofstream exactTrace("_" + testID + "_SafeTrace.txt", ios::out | ios::app);
	
	for (zone = 0; zone < NUM_ZONES; zone++) {
		for (inDir = 0; inDir < 4; inDir++) { 
			if (IN_CONDITIONS) {
				for (northLink = 0; northLink < 3; northLink++) {
					// for (eastLink = 0; eastLink < 3; eastLink++) {
						for (southLink = 0; southLink < 3; southLink++) {
							for (westLink = 0; westLink < 3; westLink++) {
									
									if(getZone(zone) == 'f' || getZone(zone) == 'g' || getZone(zone) == 'h' || getZone(zone) == 'i' || getZone(zone) == 'j' || getZone(zone) == 'm' || getZone(zone) == 'p' || getZone(zone) == 'q' || getZone(zone) == 'r') { // the zones where it's possible they're the NE corner
										pass[i] = routeSafe(getZone(zone), direction(inDir), northLink, eastLink, southLink, westLink, true, exactTrace);
										if (pass[i]) trace << "PASS: ";
										else trace << "FAIL: ";
										trace << "Zone " << (char)(getZone(zone) - 32) << ", inDir " << longDirection(inDir) << ", Links " << linkStatus(northLink) << linkStatus(eastLink) << linkStatus(southLink) << linkStatus(westLink) << " NE \n";									
										i++;
									}

									pass[i] = routeSafe(getZone(zone), direction(inDir), northLink, eastLink, southLink, westLink, false, exactTrace);
									if (pass[i]) trace << "PASS: ";
									else trace << "FAIL: ";
									trace << "Zone " << (char)(getZone(zone) - 32) << ", inDir " << longDirection(inDir) << ", Links " << linkStatus(northLink) << linkStatus(eastLink) << linkStatus(southLink) << linkStatus(westLink) << " -- \n";
									
									i++;
								

							} //westLink
						} //southLink
					// } //eastLink
				} //northLink
			}
		} //inDir
	} //zone


	ofstream results("_" + testID + "_SafeResults.txt", ios::out);
	// ofstream results("_results.txt", ios::out | ios::app);
	
	results << i << " Total Scenarios Tested." << endl;
	results << countPass(pass) << " Passed Scenarios (" << 100 * ((float)countPass(pass) / (float)NUM_OPTIONS) << "%)" << endl;
	results << countFail(pass) << " Failed Scenarios (" << 100 * ((float)countFail(pass) / (float)NUM_OPTIONS) << "%)" << endl;
	results << "---------" << endl;
	results << trace.str() << "\n\n\n." << endl;

	return;	
}

void runUnsafeTests(std::string testID) 
{
	char zone = 0; 
	char inDir = 0;
	char northLink = '-';
	char eastLink = '-';
	char southLink = '-';
	char westLink = '-';
	bool pass[NUM_OPTIONS + 1] = {};
	int i = 0;
	stringstream trace;

	ofstream exactTrace("_" + testID + "_UnsafeTrace.txt", ios::out | ios::app);
	
	for (zone = 0; zone < NUM_ZONES; zone++) {
		for (inDir = 0; inDir < 4; inDir++) { 
			if (IN_CONDITIONS) {
				for (northLink = 0; northLink < 3; northLink++) {
					// for (eastLink = 0; eastLink < 3; eastLink++) {
						for (southLink = 0; southLink < 3; southLink++) {
							for (westLink = 0; westLink < 3; westLink++) {
									
									if(getZone(zone) == 'f' || getZone(zone) == 'g' || getZone(zone) == 'h' || getZone(zone) == 'i' || getZone(zone) == 'j' || getZone(zone) == 'm' || getZone(zone) == 'p' || getZone(zone) == 'q' || getZone(zone) == 'r') { // the zones where it's possible they're the NE corner
										pass[i] = routeUnsafe(getZone(zone), direction(inDir), northLink, eastLink, southLink, westLink, true, exactTrace);
										if (pass[i]) trace << "PASS: ";
										else trace << "FAIL: ";
										trace << "Zone " << (char)(getZone(zone) - 32) << ", inDir " << longDirection(inDir) << ", Links " << linkStatus(northLink) << linkStatus(eastLink) << linkStatus(southLink) << linkStatus(westLink) << " NE \n";									
										i++;
									}

									pass[i] = routeUnsafe(getZone(zone), direction(inDir), northLink, eastLink, southLink, westLink, false, exactTrace);
									if (pass[i]) trace << "PASS: ";
									else trace << "FAIL: ";
									trace << "Zone " << (char)(getZone(zone) - 32) << ", inDir " << longDirection(inDir) << ", Links " << linkStatus(northLink) << linkStatus(eastLink) << linkStatus(southLink) << linkStatus(westLink) << " -- \n";
									
									i++;
								

							} //westLink
						} //southLink
					} //eastLink
				// } //northLink
			}
		} //inDir
	} //zone


	ofstream results("_" + testID + "_UnsafeResults.txt", ios::out);
	// ofstream results("_results.txt", ios::out | ios::app);
	
	results << i << " Total Scenarios Tested." << endl;
	results << countPass(pass) << " Passed Scenarios (" << 100 * ((float)countPass(pass) / (float)NUM_OPTIONS) << "%)" << endl;
	results << countFail(pass) << " Failed Scenarios (" << 100 * ((float)countFail(pass) / (float)NUM_OPTIONS) << "%)" << endl;
	results << "---------" << endl;
	results << trace.str() << "\n\n\n." << endl;

	return;	
}

int countPass(bool pass[NUM_OPTIONS]) {
	int c = 0, i;
	for (i = 0; i < NUM_OPTIONS; i++) {
		if (pass[i]) c++;
	}
	return c;
}

int countFail(bool pass[NUM_OPTIONS]) {
	int c = 0, i;
	for (i = 0; i < NUM_OPTIONS; i++) {
		if (!pass[i]) c++;
	}
	return c;
}