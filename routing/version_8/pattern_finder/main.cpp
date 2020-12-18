#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <string>
#include "Utils.hpp"

using namespace std;

int main() 
{
  char temp;
  char start_x;
  char start_y;
  char dest_x;
  char dest_y;
  char faulty_x_1;
  char faulty_y_1;
  char faulty_dir_1;
  char faulty_x_2;
  char faulty_y_2;
  char faulty_dir_2;

  std::string line;
  std::string folder;
  std::string eat_strings;

  cout << "Folder to crawl? ";

  while (1) {

    cin >> folder;
    if (folder == "quit") break;

    ifstream livelist("../" + folder + "/_livelock.txt", ios::in);
    

    while(getline(livelist, line)) {
      
      stringstream ss;

      ss << line;
      ss >> line >> eat_strings;
      ss >> temp >> temp >> start_x >> start_y >> temp;
      ss >> temp >> dest_x >> dest_y >> temp;
      ss >> temp >> faulty_x_1 >> faulty_y_1 >> faulty_dir_1 >> temp;
      // ss >> temp >> faulty_x_2 >> faulty_y_2 >> faulty_dir_2 >> eat_strings;
      
      ifstream ifile("../" + folder + "/livelocktrace/" + line + ".txt", ios::in);
      
      string tempstr;
      if (!ifile.is_open()) {
        cout << "COULD NOT OPEN " << line + ".txt" << endl;
      }

      while(getline(ifile, tempstr)) {
        if (tempstr == "MODIFIED ROUTE: ") {
          cout << "Analyzing " << line << ".txt" << endl;
          break;
        }
      }

      string pattern[18]; 
      int i = 0;

      int ai[18] = {0};
      // int iEqual[9] = {0};
      int eqIndex = 0;
      int loopSize = 0;

      while(getline(ifile, tempstr) && i < 18) {
        
        pattern[i] = tempstr;

        for (int a = i - 1; a > 0; a--) {
          if (pattern[a] == pattern[i]) {
          
            ai[eqIndex] = a;
            // ai[eqIndex][1] = i;

            if (loopSize == 0 || i - a == loopSize) {
              loopSize = i - a;
            }
            else if (i - a == 2 * loopSize) {
              break;
            }
            else {
              cout << "ERROR PROCESSING " << line << ".txt" << endl;
            }
            // cout << "a " << a << " == i " << i << endl;
            eqIndex++;
          }
        }

        i++;
        
      }

      string to[18];
      string dir[18] = {""};
      char to_x[18] = {0};
      char to_y[18] = {0};

      for (int c = 0; c < 17; c++) {
        stringstream rt;
        rt << pattern[c + ai[0]];
        rt >> dir[c] >> to[c] >> to_x[c] >> to_y[c];
      }

      ofstream report("test/" + folder + "_report.txt", ios::out | ios::app);
      ofstream compare("test/" + folder + "_compare.txt", ios::out | ios::app);

      report << "--- PATTERN FROM: " << line << " -------------" << endl;
      
      if (ai[0] == 1) {
        report << "Livelock Starts: " << start_x << start_y << " (original start)" << endl;
      }
      else {
        report << "Livelock Starts: " << to_x[0] << to_y[0] << " (traveling " << dir[0] << ")" << endl;
      }

      report << "Loop includes " << loopSize << " nodes." << endl;
      report << "Loop is as follows: " << endl;
      compare << "p_";

      for (int d = 0; d < loopSize; d++) {
        report << dir[d] << " " << to[d] << " " << to_x[d] << to_y[d] << endl;
        
        if (to[d] == "to") {
          compare << dir[d] << to_x[d] << to_y[d] << "_";
        }
        else if (to[d] == "two") {
          compare << dir[d] << "*" << to_x[d] << to_y[d] << "_";
        }
      }
      compare << " " << line << endl;

      report << "--- End of report ------\n\n" << endl;
    
    } //end while loop




    ifstream crosscheck("test/" + folder + "_compare.txt", ios::in);
    // ifstream comparison("test/" + folder + "_report.txt", ios::in);

    struct listy {
      string name;
      string path;
      int group;
    };
    
    listy livelock[500];
    string unique_path[500];
    int qty_paths = 0;

    int index = 0;
    string tempstr;

    cout << "Identifying patterns..." << endl;

    while(getline(crosscheck, tempstr)) {
      
      // ifstream ifile("../" + folder + "/livelocktrace/" + line + ".txt", ios::in);
      stringstream ss;

      ss << tempstr;
      ss >> livelock[index].path >> livelock[index].name;
      
      // cout << "livelock[" << index << "].path == " << livelock[index].path << " | ";
      // cout << "livelock[" << index << "].name == " << livelock[index].name << endl;

      bool new_pattern = false;

      for (int a = 0; a <= qty_paths; a++) {
        if (a == qty_paths) {
          new_pattern = true;
          // cout << "NEW PATTERN" << endl;
          // break;
        }
        else if (unique_path[a] == livelock[index].path) {
          livelock[index].group = a;
          // cout << "SAME PATTERN" << endl;
          break;
        }
      }

      if (new_pattern) {
        unique_path[qty_paths] = livelock[index].path;
        livelock[index].group = qty_paths;            
        qty_paths++;
      }

      index++;

    } //end while loop
    
    ofstream patterns("test/" + folder + "_patterns.txt", ios::out | ios::app);
  
    for (int q = 0; q < qty_paths; q++) {
      patterns << "PATTERN #" << q + 1 << " -- (path " << unique_path[q] << ")" << endl;
      for (int g = 0; g < index; g++) {
        if (livelock[g].group == q) {
          patterns << livelock[g].name << " (" << livelock[g].path << ") " << endl;
        }
      }
      patterns << "---" << endl;

    }


    cout << "Next folder to check? 'quit' exits the program. ";

  }  


  return 0;

}

// Will start the ivy simulation where the livelock starts
// (C++ proves that the start of livelock is reachable)