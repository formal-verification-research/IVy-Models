#include "Utils.hpp"
#include <string>

char direction(const char c) 
{
  switch (c) {
    case 0: return 'n';
      break;
    case 1: return 'e';
      break;
    case 2: return 's';
      break;
    case 3: return 'w';
      break;
    default: return 'X';
  }
}

std::string longDirection(const char c) 
{
  switch (c) {
    case 0: return "north";
      break;
    case 1: return "east";
      break;
    case 2: return "south";
      break;
    case 3: return "west";
      break;
    default: return "SOMETHING_WENT_WRONG";
  }
}