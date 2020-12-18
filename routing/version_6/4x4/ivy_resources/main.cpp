#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <string>
#include "Utils.hpp"

#define MAX_DIM 4

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

  ifstream livelist("../_livelock.txt", ios::in);
  
  
  int i = 0;

  while(getline(livelist, line)) {
    i++;
    
    ifstream ifile("../livelocktrace/" + line + ".txt", ios::in);
    stringstream ss;

    ss << line;
    // cout << ss.str() << endl;
    ss >> temp >> temp >> start_x >> start_y >> temp;
    ss >> temp >> dest_x >> dest_y >> temp;
    ss >> temp >> faulty_x_1 >> faulty_y_1 >> faulty_dir_1 >> temp;
    ss >> temp >> faulty_x_2 >> faulty_y_2 >> faulty_dir_2;
    // cout << i << ". " << start_x << start_y << endl;

    // cout << temp << " ";
    // cout << start_x << " ";
    // cout << start_y << " ";
    // cout << dest_x << " ";
    // cout << dest_y << " ";
    // cout << faulty_x_1 << " ";
    // cout << faulty_y_1 << " ";
    // cout << faulty_dir_1 << " ";
    // cout << faulty_x_2 << " ";
    // cout << faulty_y_2 << " ";
    // cout << faulty_dir_2 << endl;
    
    string tempstr;
    if (!ifile.is_open()) {
      cout << "COULD NOT OPEN " << line + ".txt" << endl;
    }

    while(getline(ifile, tempstr)) {
      if (tempstr == "MODIFIED ROUTE: ") {
        cout << line << ".txt" << endl;
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
            // cout << "found twice loopsize" << endl;
            // cout << "loopSize == " << loopSize << endl;
            // cout << "starting at " << ai[0] << endl;

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

    ifstream in1("_1.txt", ios::in);
    ifstream in2("_2.txt", ios::in);
    ifstream in3("_3.txt", ios::in);

    string to;
    string dir[18] = {""};
    char to_x[18] = {0};
    char to_y[18] = {0};

    for (int c = 0; c < 17; c++) {
      stringstream rt;
      rt << pattern[c + ai[0]]; //buffer of 1, to rule out extraneous incoming directions
      rt >> dir[c] >> to >> to_x[c] >> to_y[c];
    }

    ofstream ofile("ivyfiles/" + line + ".ivy", ios::out | ios::app);

    ofile << in1.rdbuf();
    ofile << "    node(" << faulty_x_1 << "," << faulty_y_1 << ")." << longDirection(faulty_dir_1) << "_faulty := true;" << endl;
    ofile << "    node(" << faulty_x_2 << "," << faulty_y_2 << ")." << longDirection(faulty_dir_2) << "_faulty := true;" << endl;

    ofile << in2.rdbuf();
    if (ai[0] == 1) {
      ofile << "    current_x := " << start_x << ";" << endl;
      ofile << "    current_y := " << start_y << ";" << endl;
      ofile << "    traveling := new;" << endl;
      // cout << "start livelock at " << start_x << start_y << endl;
    }
    else {
      ofile << "    current_x := " << to_x[ai[0] - 1] << ";" << endl;
      ofile << "    current_y := " << to_y[ai[0] - 1] << ";" << endl;
      ofile << "    traveling := " << dir[ai[0] - 1] << ";" << endl;
      // cout << "start livelock at " << to_x[ai[0] - 1] << to_y[ai[0] - 1] << endl;
    }

    ofile << "    dest_x := " << dest_x << ";" << endl;
    ofile << "    dest_y := " << dest_y << ";" << endl;
    
    ofile << in3.rdbuf();
    ofile << "invariant flit.dest_x = " << dest_x << endl;
    ofile << "invariant flit.dest_y = " << dest_y << endl;

    bool had_flit[MAX_DIM][MAX_DIM] = {false};

    for (int d = 0; d < loopSize; d++) {
      int calc = ai[0] + d - 1;
      had_flit[to_x[calc]-48][to_y[calc]-48] = true;
      // cout << "had_flit[" << to_x[calc]-48 << "][" << to_y[calc]-48 << "= true" << endl;

    }

    for (int a = 0; a < MAX_DIM; a++) {
      for (int b = 0; b < MAX_DIM; b++) {
        if (!had_flit[a][b]) {
          ofile << "invariant ~node(" << a << "," << b << ").has_flit" << endl;
        }
      }
    }


    for (int d = 0; d < loopSize; d++) {
      int calc = ai[0] + d - 1;
      ofile << "invariant node(" << to_x[calc] << "," << to_y[calc] << ").has_flit -> (flit.traveling = " << dir[calc];
      if (ai[0] == 1 && to_x[calc] == start_x && to_y[calc] == start_y) {
        ofile << " | flit.traveling = new)" << endl;
      }
      else {
        ofile << ")" << endl;
      }
      
      // cout << "start livelock at " << start_x << start_y << endl;
    }

    for (int d = 0; d < loopSize; d++) {
      int curr = ai[0] + d - 1;
      int next = ai[0] + d;
      ofile << "invariant node(" << to_x[curr] << "," << to_y[curr] << ").sent -> (flit.traveling = " << dir[next] << " & node(" << to_x[next] << "," << to_y[next] << ").has_flit)" << endl;
    }

  }

  return 0;

}

// Will start the ivy simulation where the livelock starts
// (C++ proves that the start of livelock is reachable)