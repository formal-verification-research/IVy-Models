#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

#include "Utils.hpp"
#include "Route.hpp"

using namespace std;

void make_files();
// void make_makefile();

int main() 
{
  make_files();
  // make_makefile();
  return 0;
}

void make_files() 
{
  int cur_x;
  int cur_y;
  int dest_x;
  int dest_y;
  int faulty_x1;
  int faulty_y1;
  char faulty_dir1;


  for (cur_x = 0; cur_x < 3; cur_x++) {
    for (cur_y = 0; cur_y < 3; cur_y++) {
      for (dest_x = 0; dest_x < 3; dest_x++) {
        cout << "." << endl;
        for (dest_y = 0; dest_y < 3; dest_y++) {
          cout << "|";
          for (faulty_x1 = 0; faulty_x1 < 3; faulty_x1++) {
            for (faulty_y1 = 0; faulty_y1 < 3; faulty_y1++) {
              for (faulty_dir1 = 0; faulty_dir1 < 4; faulty_dir1++) {

                if ((cur_x != dest_x | cur_y != dest_y)) {
                  if ((faulty_y1 != 2 | faulty_dir1 != 0) && 
                      (faulty_x1 != 2 | faulty_dir1 != 1) &&
                      (faulty_y1 != 0 | faulty_dir1 != 2) &&
                      (faulty_x1 != 0 | faulty_dir1 != 3)) {

                      route(cur_x, cur_y, dest_x, dest_y, faulty_x1, faulty_y1, faulty_dir1);
                    
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}


