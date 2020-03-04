#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

#include "Utils.hpp"

using namespace std;

void check_files();



int main() 
{
 
  check_files();

  return 0;
}


void check_files() 
{
  int cur_x;
  int cur_y;
  int dest_x;
  int dest_y;
  int faulty_x;
  int faulty_y;
  char faulty_dir;

  ofstream passout("_passed.txt", ios::out | ios::app);
  ofstream noroute("_cannotroute.txt", ios::out | ios::app);
  ofstream deliver("_delivered.txt", ios::out | ios::app);
  ofstream others("_others.txt", ios::out | ios::app);

  cout << "files opened. " << endl;

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

                    stringstream filename;
                    string line;
                    filename << "test_s" << cur_x << cur_y << "_d" << dest_x << dest_y << "_f" << faulty_x << faulty_y << direction(faulty_dir) << ".txt";
                    ifstream fin(filename.str(), ios::in);
                    

                    while(getline(fin, line))
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
                }
              }
            }
          }
        }
      }
    }
  }

  passout.close();
  noroute.close();
  deliver.close();
   others.close();

}
