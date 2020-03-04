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
  int cur_x;
  int cur_y;
  int dest_x;
  int dest_y;
  int faulty_x;
  int faulty_y;
  char faulty_dir;

  for (cur_x = 0; cur_x < 3; cur_x++) {
    for (cur_y = 0; cur_y < 3; cur_y++) {
      for (dest_x = 0; dest_x < 3; dest_x++) {
        for (dest_y = 0; dest_y < 3; dest_y++) {
          for (faulty_x = 0; faulty_x < 3; faulty_x++) {
            for (faulty_y = 0; faulty_y < 3; faulty_y++) {
              for (faulty_dir = 0; faulty_dir < 4; faulty_dir++) {
                
                if (cur_x != dest_x | cur_y != dest_y) {

                  if ((faulty_y != 2 | faulty_dir != 0) && 
                      (faulty_x != 2 | faulty_dir != 1) &&
                      (faulty_y != 0 | faulty_dir != 2) &&
                      (faulty_x != 0 | faulty_dir != 3)) {

                    // START COPY
                    ifstream in1("in1.txt", ios::in);
                    ifstream in2("in2.txt", ios::in);
                    ifstream in3("in3.txt", ios::in);

                    stringstream filename;
                    filename << "s" << cur_x << cur_y << "_d" << dest_x << dest_y << "_f" << faulty_x << faulty_y << direction(faulty_dir) << ".ivy";
                    ofstream ofile(filename.str(), ios::out | ios::app);

                    if (!in1.is_open()) {
                      cout << "ERROR: in1.txt NOT OPEN! --------------------------------\n---------------------------------------------------------" << endl;
                      return;
                    }
                    else {
                      ofile << in1.rdbuf();
                    }

                    ofile << "    node(" << faulty_x << "," << faulty_y << ")." << longDirection(faulty_dir) << "_free := false;" << endl;

                    if (!in2.is_open()) {
                      cout << "ERROR: in2.txt NOT OPEN! --------------------------------\n---------------------------------------------------------" << endl;
                      return;
                    }
                    else {
                      ofile << in2.rdbuf();
                    }

                    ofile << "    current_x := " << cur_x << ";" << endl;
                    ofile << "    current_y := " << cur_y << ";" << endl;
                    ofile << "    dest_x := " << dest_x << ";" << endl;
                    ofile << "    dest_y := " << dest_y << ";" << endl;

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
  int faulty_x;
  int faulty_y;
  char faulty_dir;
  
  ofstream ofile("makefile", ios::out | ios::app);
  ofile << "ivychecks: " << endl;

  for (cur_x = 0; cur_x < 3; cur_x++) {
    for (cur_y = 0; cur_y < 3; cur_y++) {
      for (dest_x = 0; dest_x < 3; dest_x++) {
        for (dest_y = 0; dest_y < 3; dest_y++) {
          for (faulty_x = 0; faulty_x < 3; faulty_x++) {
            for (faulty_y = 0; faulty_y < 3; faulty_y++) {
              for (faulty_dir = 0; faulty_dir < 4; faulty_dir++) {
                
                if (cur_x != dest_x | cur_y != dest_y) {

                  if ((faulty_y != 2 | faulty_dir != 0) && 
                      (faulty_x != 2 | faulty_dir != 1) &&
                      (faulty_y != 0 | faulty_dir != 2) &&
                      (faulty_x != 0 | faulty_dir != 3)) {

                    // START WRITING
                    stringstream filename;
                    filename << "s" << cur_x << cur_y << "_d" << dest_x << dest_y << "_f" << faulty_x << faulty_y << direction(faulty_dir);

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
  ofile.close();
}

