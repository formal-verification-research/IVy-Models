#include <iostream>

#include "Utils.hpp"
#include "Route.hpp"
// #include "Conditions.hpp"

using namespace std;

bool routeSafe(char z, char trav, char northLink, char eastLink, char southLink, char westLink, bool destNE, ofstream& trace)  {

  char dirRouted = 9;

  // Since the program shows only 1 step of the algorithm, no while loop is used.

  // if delivered
  if (ZR) {
    return true; // If it reached its destination, there is no routing decision, and thus no deadlock
  }

  // if one hop away and link is free
  else if (ZN && westLink == 0) {
    dirRouted = 3;
  }
  else if (ZO && southLink == 0) {
    dirRouted = 2;
  }
  else if (ZP && eastLink == 0) {
    dirRouted = 1;
  }
  else if (ZQ && northLink == 0) {
    dirRouted = 0;
  }

  // first set of options
  
  // Go west if... 
  else if ( 
    westLink != 1 && westLink != '-' && ( trav == 'w' || trav == 's' ) &&
    ((ZA || ZB || ZC || ZJ || ZK || ZL || ZN || ZO || ZQ) || ((ZA || ZF || ZG || ZH || ZI || ZJ || ZK || ZL || ZM || ZN || ZP || ZQ) && southLink == 1)) &&
    (trav != 's' || !(ZG || ZM || ZQ || ZL) ) && !(trav == 'n' && westLink == 2)
  ) { dirRouted = 3; }

  // Go south if...
  else if ( 
    southLink != 1 && southLink != '-' && ( trav == 'w' || trav == 's' ) &&
    ((ZA || ZB || ZC || ZD || ZE || ZF || ZN || ZO || ZP) || ((ZC || ZD || ZE || ZF || ZG || ZH || ZI || ZJ || ZM || ZO || ZP || ZQ) && westLink == 1)) &&
    (!(ZD || ZP || ZM || ZI) || (ZA || ZB || ZC || ZD || ZE || ZF || ZN || ZO || ZP)) && !(trav == 'e' && southLink == 2)
  ) { dirRouted = 2; }

  // Go east if...
  else if ( 
    eastLink != 1 && eastLink != '-' && ( trav != 'w' ) && ((ZE || ZF || ZG || ZH) || (ZM)) 
  ) { dirRouted = 1; }

  // Go north if...
  else if ( 
    northLink != 1 && northLink != '-' && ( trav != 's' ) &&
    (ZB || ZC || ZD || ZE || ZO) 
  ) { dirRouted = 0; }

  // ELSE

  // Go west if...
  else if ( 
    westLink != 1 && westLink != '-' && 
    (ZA || ZB || ZC || ZJ || ZK || ZL || ZO || ZN || ZQ) && (ZQ || trav != 'e') && !(trav == 'n' && westLink == 2)
  ) { dirRouted = 3; }

  // Go south if...
  else if ( 
    southLink != 1 && southLink != '-' && trav != 'n' && 
    (ZA || ZB || ZC || ZD || ZE || ZF || ZN || ZO || ZP) && 
    (trav != 'e' || !destNE) && !(trav == 'e' && southLink == 2)
  ) { dirRouted = 2; }

  // Go east if...
  else if ( 
    eastLink != 1 && eastLink != '-' && 
    (ZC || ZD || ZE || ZF || ZG || ZH || ZI || ZJ || ZM || ZO || ZP || ZQ) && 
    (trav != 'w' || (ZA || ZF || ZN || ZP) || (ZD || ZP || ZI) ) 
  ) { dirRouted = 1; }

  // Go north if...
  else if ( 
    northLink != 1 && northLink != '-' && 
    (ZA || ZF || ZG || ZH || ZI || ZJ || ZK || ZL || ZM || ZN || ZP || ZQ) && 
    (trav != 's' || (ZC || ZD || ZE || ZF || ZG || ZH || ZI || ZJ || ZM || ZO || ZP || ZQ) ) 
  ) { dirRouted = 0; }

  else {
    dirRouted = 9;
  }

	trace << "Routed " << longDirection(dirRouted) << ": Zone " << (char)(z - 32) << ", trav " << (char)(trav - 32) << ", Links " << linkStatus(northLink) << linkStatus(eastLink) << linkStatus(southLink) << linkStatus(westLink) << " NE: " << destNE;									

  if (dirRouted == 3 && trav == 'n' && westLink == 2) { // Illegal N-W turn with busy neighbor
    trace << " ILLEGAL: WEST BUSY AND NOT DROPPED" << endl;
    return false;
  }

  else if (dirRouted == 2 && trav == 'e' && southLink == 2) { // Illegal S-W turn with busy neighbor
    trace << " ILLEGAL: SOUTH BUSY AND NOT DROPPED" << endl;
    return false;
  }

  else {
    trace << " Legal." << endl;
    return true;
  }

}



bool routeUnsafe(char z, char trav, char northLink, char eastLink, char southLink, char westLink, bool destNE, ofstream& trace)  {

  char dirRouted = 9;

  // Since the program shows only 1 step of the algorithm, no while loop is used.

  // if delivered
  if (ZR) {
    return true; // If it reached its destination, there is no routing decision, and thus no deadlock
  }

  // if one hop away and link is free
  else if (ZN && westLink != 1 && westLink != '-') {
    dirRouted = 3;
  }
  else if (ZO && southLink != 1 && southLink != '-') {
    dirRouted = 2;
  }
  else if (ZP && eastLink != 1 && eastLink != '-') {
    dirRouted = 1;
  }
  else if (ZQ == 'n' && northLink != 1 && northLink != '-') {
    dirRouted = 0;
  }

  // first set of options
  
  // Go west if... 
  else if ( 
    westLink != 1 && westLink != '-' && ( trav == 'w' || trav == 's' ) &&
    ((ZA || ZB || ZC || ZJ || ZK || ZL || ZN || ZO || ZQ) || ((ZA || ZF || ZG || ZH || ZI || ZJ || ZK || ZL || ZM || ZN || ZP || ZQ) && southLink == 1)) &&
    (trav != 's' || !(ZG || ZM || ZQ || ZL) )
  ) { dirRouted = 3; }

  // Go south if...
  else if ( 
    southLink != 1 && southLink != '-' && ( trav == 'w' || trav == 's' ) &&
    ((ZA || ZB || ZC || ZD || ZE || ZF || ZN || ZO || ZP) || ((ZC || ZD || ZE || ZF || ZG || ZH || ZI || ZJ || ZM || ZO || ZP || ZQ) && westLink == 1)) &&
    (!(ZD || ZP || ZM || ZI) || (ZA || ZB || ZC || ZD || ZE || ZF || ZN || ZO || ZP))
  ) { dirRouted = 2; }

  // Go east if...
  else if ( 
    eastLink != 1 && eastLink != '-' && ( trav != 'w' ) && ((ZE || ZF || ZG || ZH) || (ZM)) 
  ) { dirRouted = 1; }

  // Go north if...
  else if ( 
    northLink != 1 && northLink != '-' && ( trav != 's' ) &&
    (ZB || ZC || ZD || ZE || ZO) 
  ) { dirRouted = 0; }

  // ELSE

  // Go west if...
  else if ( 
    westLink != 1 && westLink != '-' && 
    (ZA || ZB || ZC || ZJ || ZK || ZL || ZO || ZN || ZQ) && (ZQ || trav != 'e') 
  ) { dirRouted = 3; }

  // Go south if...
  else if ( 
    southLink != 1 && southLink != '-' && trav != 'n' && 
    (ZA || ZB || ZC || ZD || ZE || ZF || ZN || ZO || ZP) && 
    (trav != 'e' || !destNE) 
  ) { dirRouted = 2; }

  // Go east if...
  else if ( 
    eastLink != 1 && eastLink != '-' && 
    (ZC || ZD || ZE || ZF || ZG || ZH || ZI || ZJ || ZM || ZO || ZP || ZQ) && 
    (trav != 'w' || (ZA || ZF || ZN || ZP) || (ZD || ZP || ZI) ) 
  ) { dirRouted = 1; }

  // Go north if...
  else if ( 
    northLink != 1 && northLink != '-' && 
    (ZA || ZF || ZG || ZH || ZI || ZJ || ZK || ZL || ZM || ZN || ZP || ZQ) && 
    (trav != 's' || (ZC || ZD || ZE || ZF || ZG || ZH || ZI || ZJ || ZM || ZO || ZP || ZQ) ) 
  ) { dirRouted = 0; }

  else {
    dirRouted = 9;
  }

	trace << "Routed " << longDirection(dirRouted) << ": Zone " << (char)(z - 32) << ", trav " << (char)(trav - 32) << ", Links " << linkStatus(northLink) << linkStatus(eastLink) << linkStatus(southLink) << linkStatus(westLink) << " NE: " << destNE;									

  if (dirRouted == 3 && trav == 'n' && westLink == 2) { // Illegal N-W turn with busy neighbor
    trace << " ILLEGAL: WEST BUSY AND NOT DROPPED" << endl;
    return false;
  }

  else if (dirRouted == 2 && trav == 'e' && southLink == 2) { // Illegal S-W turn with busy neighbor
    trace << " ILLEGAL: SOUTH BUSY AND NOT DROPPED" << endl;
    return false;
  }

  else {
    trace << " Legal." << endl;
    return true;
  }

}

