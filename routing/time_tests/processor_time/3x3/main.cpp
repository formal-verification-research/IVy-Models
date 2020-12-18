#define MAX_X 2
#define MAX_Y 2

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <time.h>

#include "Utils.hpp"

Count one_fault;
Count two_fault;

#include "Route.hpp"

using namespace std;

void make_files();
// void make_makefile();

int main() 
{
  
  struct timespec begin, end; 
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);

  make_files();
  // make_makefile();
  cout << "TERMINATED." << endl;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
  long nanoseconds = end.tv_nsec - begin.tv_nsec;
  long seconds = end.tv_sec - begin.tv_sec;
  int minutes = seconds / 60;
  double elapsed = seconds + nanoseconds*1e-9;

  stringstream ss;

  ss << "_" << MAX_X + 1 << "x" << MAX_Y + 1 << "_time.txt";

  ofstream timer(ss.str(), ios::out | ios::app);
  timer << "Runtime: " << endl;
  timer << setprecision(10);
  timer << "Total Decimal time: " << elapsed << " seconds" << endl;
  timer << "Total Elapsed time: " << seconds << " seconds" << endl;
  timer << "Total Elapsed time: " << seconds / 60 << " minutes with " << seconds % 60 << " seconds" << endl;
  timer << "Total Elapsed time: " << seconds / (60*60) << " hours with " << seconds / 60 << " minutes with " << seconds % 60 << " seconds" << endl;
  timer << "\n----------------------\n\n";

  cout << "Runtime: " << endl;
  cout << "Total Decimal time: " << elapsed << " seconds" << endl;
  cout << "Total Elapsed time: " << seconds << " seconds" << endl;
  cout << "Total Elapsed time: " << seconds / 60 << " minutes with " << seconds % 60 << " seconds" << endl;
  cout << "Total Elapsed time: " << seconds / (60*60) << " hours with " << seconds / 60 << " minutes with " << seconds % 60 << " seconds" << endl;
  cout << "\n----------------------\n\n";

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

  int max_moves_1 = 0;
  int max_moves_2 = 0;
  long int t = 0;

  for (cur_x = 0; cur_x <= MAX_X; cur_x++) {
    for (cur_y = 0; cur_y <= MAX_Y; cur_y++) {
          cout << "Testing starting node: " << cur_x << cur_y << "  -  (1:" << max_moves_1 << " | 2:" << max_moves_2 << ")" << endl;
      for (dest_x = 0; dest_x <= MAX_X; dest_x++) {
        for (dest_y = 0; dest_y <= MAX_Y; dest_y++) {
          // cout << "Testing: " << cur_x << cur_y << " to " << dest_x << dest_y << "  -  (1:" << max_moves_1 << " | 2:" << max_moves_2 << ")" << endl;
          for (faulty_x1 = 0; faulty_x1 <= MAX_X; faulty_x1++) {
            for (faulty_y1 = 0; faulty_y1 <= MAX_Y; faulty_y1++) {
              for (faulty_dir1 = 0; faulty_dir1 < 4; faulty_dir1++) {

                //ONE FAULT
                if ((cur_x != dest_x || cur_y != dest_y)) {
                  if ((faulty_y1 != MAX_Y || faulty_dir1 != 0) && 
                      (faulty_x1 != MAX_X || faulty_dir1 != 1) &&
                      (faulty_y1 != 0 || faulty_dir1 != 2) &&
                      (faulty_x1 != 0 || faulty_dir1 != 3)) {
                        t = route(cur_x, cur_y, dest_x, dest_y, faulty_x1, faulty_y1, faulty_dir1, -9, -9, 'x', one_fault);
                        if (t > max_moves_1 && t != 1000) {
                          max_moves_1 = t;
                        }
                        
                        faulty_x2 = faulty_x1;
                        faulty_y2 = faulty_y1;
                        faulty_dir2 = faulty_dir1;


                        //TWO FAULTS
                        for ( /* blank */ ; faulty_x2 <= MAX_X; faulty_x2++, faulty_y2 = 0) {
                          for ( /* blank */ ; faulty_y2 <= MAX_Y; faulty_y2++, faulty_dir2 = 0) { //changed to 0
                            // if ((faulty_x2 > faulty_x1 || faulty_y2 > faulty_y1)) {
                            //   faulty_dir2 = 0;
                            // }
                            // else {
                            //   faulty_dir2 = faulty_dir1;
                            // }

                            for ( /* blank */ ; faulty_dir2 < 4; faulty_dir2++) {
                              if ((cur_x != dest_x || cur_y != dest_y) && 
                                    (faulty_x1 != faulty_x2 || faulty_y1 != faulty_y2 || faulty_dir1 != faulty_dir2) &&
                                    (faulty_y2 != MAX_Y || faulty_dir2 != 0) && 
                                    (faulty_x2 != MAX_X || faulty_dir2 != 1) &&
                                    (faulty_y2 != 0 || faulty_dir2 != 2) &&
                                    (faulty_x2 != 0 || faulty_dir2 != 3)) {
                                      t = route(cur_x, cur_y, dest_x, dest_y, faulty_x1, faulty_y1, faulty_dir1, faulty_x2, faulty_y2, faulty_dir2, two_fault);
                                      if (t > max_moves_2 && t != 1000) {
                                      max_moves_2 = t;
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
    }
  }

  cout << "GENERATING REPORT..." << endl;

  one_fault.print_report(1, max_moves_1);
  two_fault.print_report(2, max_moves_2);

}



