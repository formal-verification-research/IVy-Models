#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

#include "Utils.hpp"

using namespace std;

void make_files();
void make_makefile();

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
  int faulty_x2;
  int faulty_y2;
  char faulty_dir2;

  ofstream passout("_passed.txt", ios::out | ios::app);
  ofstream noroute("_cannotroute.txt", ios::out | ios::app);
  ofstream deliver("_delivered.txt", ios::out | ios::app);
  ofstream others("_others.txt", ios::out | ios::app);

  for (cur_x = 0; cur_x < 3; cur_x++) {
    for (cur_y = 0; cur_y < 3; cur_y++) {
      for (dest_x = 0; dest_x < 3; dest_x++) {
        for (dest_y = 0; dest_y < 3; dest_y++) {
          for (faulty_x1 = 0; faulty_x1 < 3; faulty_x1++) {
            for (faulty_y1 = 0; faulty_y1 < 3; faulty_y1++) {
              for (faulty_dir1 = 0; faulty_dir1 < 4; faulty_dir1++) {
                for (faulty_x2 = 0; faulty_x2 < 3; faulty_x2++) {
                  for (faulty_y2 = 0; faulty_y2 < 3; faulty_y2++) {
                    for (faulty_dir2 = 0; faulty_dir2 < 4; faulty_dir2++) {
                      if ((cur_x != dest_x | cur_y != dest_y) &&
                          (faulty_x1 != faulty_x2 | faulty_y1 != faulty_y2)) {
                        if ((faulty_y1 != 2 | faulty_dir1 != 0) && 
                            (faulty_x1 != 2 | faulty_dir1 != 1) &&
                            (faulty_y1 != 0 | faulty_dir1 != 2) &&
                            (faulty_x1 != 0 | faulty_dir1 != 3) &&
                            (faulty_y2 != 2 | faulty_dir2 != 0) && 
                            (faulty_x2 != 2 | faulty_dir2 != 1) &&
                            (faulty_y2 != 0 | faulty_dir2 != 2) &&
                            (faulty_x2 != 0 | faulty_dir2 != 3)) {

                          // START COPY

                          stringstream filename;
                          string line;
                          filename << "test_s" << cur_x << cur_y << "_d" << dest_x << dest_y << "_f" << faulty_x1 << faulty_y1 << direction(faulty_dir1) << "_f" << faulty_x2 << faulty_y2 << direction(faulty_dir2) << ".txt";
                          ifstream ifile(filename.str(), ios::out | ios::app);

                          if (!ifile.is_open()) {
                            others << filename.str() << endl;
                            break;
                          }
                          else {
                            while(getline(ifile, line))
                            {
                              if (line == "    spec.can_route = false") {
                                noroute << filename.str() << endl;
                                break;
                              }
                              if (line == "    flit.delivered = true") {
                                deliver << filename.str() << endl;
                                break;
                              }
                              if (line == "OK") {
                                passout << filename.str() << endl;
                                break;
                              }
                              
                            }
                          }

                          //END COPY
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



void make_makefile() 
{
  int cur_x;
  int cur_y;
  int dest_x;
  int dest_y;
  int faulty_x1;
  int faulty_y1;
  char faulty_dir1;
  int faulty_x2;
  int faulty_y2;
  char faulty_dir2;
  
  ofstream ofile("makefile", ios::out | ios::app);
  // ofile << "ivychecks: " << endl;

  for (cur_x = 0; cur_x < 3; cur_x++) {
    for (cur_y = 0; cur_y < 3; cur_y++) {
      for (dest_x = 0; dest_x < 3; dest_x++) {
        for (dest_y = 0; dest_y < 3; dest_y++) {
          for (faulty_x1 = 0; faulty_x1 < 3; faulty_x1++) {
            for (faulty_y1 = 0; faulty_y1 < 3; faulty_y1++) {
              for (faulty_dir1 = 0; faulty_dir1 < 4; faulty_dir1++) {
                for (faulty_x2 = 0; faulty_x2 < 3; faulty_x2++) {
                  for (faulty_y2 = 0; faulty_y2 < 3; faulty_y2++) {
                    for (faulty_dir2 = 0; faulty_dir2 < 4; faulty_dir2++) {
                      if ((cur_x != dest_x | cur_y != dest_y) &&
                          (faulty_x1 != faulty_x2 | faulty_y1 != faulty_y2)) {
                        if ((faulty_y1 != 2 | faulty_dir1 != 0) && 
                            (faulty_x1 != 2 | faulty_dir1 != 1) &&
                            (faulty_y1 != 0 | faulty_dir1 != 2) &&
                            (faulty_x1 != 0 | faulty_dir1 != 3) &&
                            (faulty_y2 != 2 | faulty_dir2 != 0) && 
                            (faulty_x2 != 2 | faulty_dir2 != 1) &&
                            (faulty_y2 != 0 | faulty_dir2 != 2) &&
                            (faulty_x2 != 0 | faulty_dir2 != 3)) {

                          // START WRITING
                          stringstream filename;
                          filename << "s" << cur_x << cur_y << "_d" << dest_x << dest_y << "_f" << faulty_x1 << faulty_y1 << direction(faulty_dir1) << "_f" << faulty_x2 << faulty_y2 << direction(faulty_dir2);

                          ofile << "\tivy_check trace=true " << filename.str() << ".ivy > tests/test_" << filename.str() << ".txt" << endl;

                          //END WRITING
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
  ofile.close();
}

