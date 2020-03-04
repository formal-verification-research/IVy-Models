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
  make_makefile();
  return 0;
}

void make_files() 
{
  // int cur_x;
  // int cur_y;
  // int dest_x;
  // int dest_y;
  int faulty_x1;
  int faulty_y1;
  char faulty_dir1;
  int faulty_x2;
  int faulty_y2;
  char faulty_dir2;

  // for (cur_x = 0; cur_x < 3; cur_x++) {
  //   for (cur_y = 0; cur_y < 3; cur_y++) {
  //     for (dest_x = 0; dest_x < 3; dest_x++) {
  //       for (dest_y = 0; dest_y < 3; dest_y++) {
          for (faulty_x1 = 0; faulty_x1 < 3; faulty_x1++) {
            for (faulty_y1 = 0; faulty_y1 < 3; faulty_y1++) {
              for (faulty_dir1 = 0; faulty_dir1 < 4; faulty_dir1++) {
                for (faulty_x2 = 0; faulty_x2 < 3; faulty_x2++) {
                  for (faulty_y2 = 0; faulty_y2 < 3; faulty_y2++) {
                    for (faulty_dir2 = 0; faulty_dir2 < 4; faulty_dir2++) {
                      // if (cur_x != dest_x | cur_y != dest_y) {
                        if ((faulty_y1 != 2 | faulty_dir1 != 0) && 
                            (faulty_x1 != 2 | faulty_dir1 != 1) &&
                            (faulty_y1 != 0 | faulty_dir1 != 2) &&
                            (faulty_x1 != 0 | faulty_dir1 != 3) &&
                            (faulty_y2 != 2 | faulty_dir2 != 0) && 
                            (faulty_x2 != 2 | faulty_dir2 != 1) &&
                            (faulty_y2 != 0 | faulty_dir2 != 2) &&
                            (faulty_x2 != 0 | faulty_dir2 != 3)) {

                          // START COPY
                          ifstream in1("in1.txt", ios::in);
                          ifstream in2("in2.txt", ios::in);
                          ifstream in3("in3.txt", ios::in);

                          stringstream filename;
                          filename << "f" << faulty_x1 << faulty_y1 << direction(faulty_dir1) << "_f" << faulty_x2 << faulty_y2 << direction(faulty_dir2) << ".ivy";
                          ofstream ofile(filename.str(), ios::out | ios::app);

                          if (!in1.is_open()) {
                            cout << "ERROR: in1.txt NOT OPEN! --------------------------------\n---------------------------------------------------------" << endl;
                            return;
                          }
                          else {
                            ofile << in1.rdbuf();
                          }

                          ofile << "    node(" << faulty_x1 << "," << faulty_y1 << ")." << longDirection(faulty_dir1) << "_free := false;" << endl;
                          ofile << "    node(" << faulty_x2 << "," << faulty_y2 << ")." << longDirection(faulty_dir2) << "_free := false;" << endl;

                          if (!in2.is_open()) {
                            cout << "ERROR: in2.txt NOT OPEN! --------------------------------\n---------------------------------------------------------" << endl;
                            return;
                          }
                          else {
                            ofile << in2.rdbuf();
                          }

                          // ofile << "    current_x := " << cur_x << ";" << endl;
                          // ofile << "    current_y := " << cur_y << ";" << endl;
                          // ofile << "    dest_x := " << dest_x << ";" << endl;
                          // ofile << "    dest_y := " << dest_y << ";" << endl;

                          if (!in3.is_open()) {
                            cout << "ERROR: in3.txt NOT OPEN! --------------------------------\n---------------------------------------------------------" << endl;
                            return;
                          }
                          else {
                            ofile << in3.rdbuf();
                          }

                          ofile.close();
                          //END COPY
                        }
                      // }
                    }
                  }
                }
              }
            }
          }
  //       }
  //     }
  //   }
  // }

}



void make_makefile() 
{
  // int cur_x;
  // int cur_y;
  // int dest_x;
  // int dest_y;
  int faulty_x1;
  int faulty_y1;
  char faulty_dir1;
  int faulty_x2;
  int faulty_y2;
  char faulty_dir2;
  
  ofstream ofile("makefile", ios::out | ios::app);
  ofile << "ivychecks: " << endl;

  // for (cur_x = 0; cur_x < 3; cur_x++) {
  //   for (cur_y = 0; cur_y < 3; cur_y++) {
  //     for (dest_x = 0; dest_x < 3; dest_x++) {
  //       for (dest_y = 0; dest_y < 3; dest_y++) {
          for (faulty_x1 = 0; faulty_x1 < 3; faulty_x1++) {
            for (faulty_y1 = 0; faulty_y1 < 3; faulty_y1++) {
              for (faulty_dir1 = 0; faulty_dir1 < 4; faulty_dir1++) {
                for (faulty_x2 = 0; faulty_x2 < 3; faulty_x2++) {
                  for (faulty_y2 = 0; faulty_y2 < 3; faulty_y2++) {
                    for (faulty_dir2 = 0; faulty_dir2 < 4; faulty_dir2++) {
                      // if (cur_x != dest_x | cur_y != dest_y) {
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
                          filename << "f" << faulty_x1 << faulty_y1 << direction(faulty_dir1) << "_f" << faulty_x2 << faulty_y2 << direction(faulty_dir2);

                          ofile << "\tivy_check trace=true " << filename.str() << ".ivy > tests/test_" << filename.str() << ".txt" << endl;

                          //END WRITING
                        }
                      // }
                    }
                  }
                }
              }
            }
          }
  //       }
  //     }
  //   }
  // }
  ofile.close();
}

