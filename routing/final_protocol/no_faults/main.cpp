#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

#include "Utils.hpp"
#include "Route.hpp"


void make_files();
Count no_fault;

using namespace std;

int main() 
{
  make_files();
  // make_makefile();
  cout << "TERMINATED." << endl;
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

  int max_moves = 0;
  int t = 0;

  int max_dim = 20;

  for (max_dim = 20; max_dim < 100; max_dim++) {
    cout << "Testing: " << max_dim << endl;
    for (cur_x = 0; cur_x <= max_dim; cur_x++) {
      for (cur_y = 0; cur_y <= max_dim; cur_y++) {
        for (dest_x = 0; dest_x <= max_dim; dest_x++) {
          for (dest_y = 0; dest_y <= max_dim; dest_y++) {
            if ((cur_x != dest_x || cur_y != dest_y)) {
              t = route(cur_x, cur_y, dest_x, dest_y, no_fault, max_dim);
              if (t > max_moves) max_moves = t;
            }
          }
        }
      }
    }
    no_fault.print_report(max_dim + 1, max_moves);
  }

}



