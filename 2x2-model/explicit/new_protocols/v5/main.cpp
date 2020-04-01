#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

#include "Utils.hpp"

Count one_fault;
Count two_fault;

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
  int cur_x = 0;
  int cur_y = 0;
  int dest_x = 0;
  int dest_y = 0;
  int faulty_x1 = 0;
  int faulty_y1 = 0;
  char faulty_dir1 = 0;
  int faulty_x2 = 0;
  int faulty_y2 = 0;
  char faulty_dir2 = 1;

  

  for (cur_x = 0; cur_x < 3; cur_x++) {
    for (cur_y = 0; cur_y < 3; cur_y++) {
      for (dest_x = 0; dest_x < 3; dest_x++) {
        for (dest_y = 0; dest_y < 3; dest_y++) {
          cout << "Testing: " << cur_x << cur_y << " to " << dest_x << dest_y << endl;
          for (faulty_x1 = 0; faulty_x1 < 3; faulty_x1++) {
            for (faulty_y1 = 0; faulty_y1 < 3; faulty_y1++) {
              for (faulty_dir1 = 0; faulty_dir1 < 4; faulty_dir1++) {

                //ONE FAULT
                if ((cur_x != dest_x || cur_y != dest_y)) {
                  if ((faulty_y1 != 2 || faulty_dir1 != 0) && 
                      (faulty_x1 != 2 || faulty_dir1 != 1) &&
                      (faulty_y1 != 0 || faulty_dir1 != 2) &&
                      (faulty_x1 != 0 || faulty_dir1 != 3)) {

                      route(cur_x, cur_y, dest_x, dest_y, faulty_x1, faulty_y1, faulty_dir1, 9, 9, 'x', one_fault);
                      
                  }
                }

                //TWO FAULTS
                for (faulty_x2 = faulty_x1; faulty_x2 < 3; faulty_x2++) {
                  for (faulty_y2 = faulty_y1; faulty_y2 < 3; faulty_y2++) {
                    if ((faulty_x2 > faulty_x1 || faulty_y2 > faulty_y1)) {
                      faulty_dir2 = 0;
                    }
                    else {
                      faulty_dir2 = faulty_dir1;
                    }
                    for ( /*blank*/ ; faulty_dir2 < 4; faulty_dir2++) {
                      if ((cur_x != dest_x || cur_y != dest_y) && (faulty_x1 != faulty_x2 || faulty_y1 != faulty_y2 || faulty_dir1 != faulty_dir2)) {
                        if ((faulty_y1 != 2 || faulty_dir1 != 0) && 
                            (faulty_x1 != 2 || faulty_dir1 != 1) &&
                            (faulty_y1 != 0 || faulty_dir1 != 2) &&
                            (faulty_x1 != 0 || faulty_dir1 != 3) &&
                            (faulty_y2 != 2 || faulty_dir2 != 0) && 
                            (faulty_x2 != 2 || faulty_dir2 != 1) &&
                            (faulty_y2 != 0 || faulty_dir2 != 2) &&
                            (faulty_x2 != 0 || faulty_dir2 != 3)) {

                            route(cur_x, cur_y, dest_x, dest_y, faulty_x1, faulty_y1, faulty_dir1, faulty_x2, faulty_y2, faulty_dir2, two_fault);
                         
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
    }
  }

  cout << endl;

  one_fault.print_report(1);
  two_fault.print_report(2);



}



