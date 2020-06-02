#ifndef ROUTE_HPP
#define ROUTE_HPP

#define ZA z == 'a'
#define ZB z == 'b'
#define ZC z == 'c'
#define ZD z == 'd'
#define ZE z == 'e'
#define ZF z == 'f'
#define ZG z == 'g'
#define ZH z == 'h'
#define ZI z == 'i'
#define ZJ z == 'j'
#define ZK z == 'k'
#define ZL z == 'l'
#define ZM z == 'm'
#define ZN z == 'n'
#define ZO z == 'o'
#define ZP z == 'p'
#define ZQ z == 'q'
#define ZR z == 'r'

bool routeSafe(char z, char trav, char northLink, char eastLink, char southLink, char westLink, bool destNE, ofstream& trace);
bool routeUnsafe(char z, char trav, char northLink, char eastLink, char southLink, char westLink, bool destNE, ofstream& trace);

#endif