
#include "Utils.hpp"

#include <string>
#include <iomanip>

char direction(const char c) 
{
  switch (c) {
    case 0: return 'n';
      break;
    case 1: return 'e';
      break;
    case 2: return 's';
      break;
    case 3: return 'w';
      break;
    default: return 'X';
  }
}

std::string longDirection(const char c) 
{
  switch (c) {
    case 0: return "north";
      break;
    case 1: return "east";
      break;
    case 2: return "south";
      break;
    case 3: return "west";
      break;
    default: return "SOMETHING_WENT_WRONG";
  }
}

Count::Count() {
  livelock = 0;
  delivered = 0;
  // nochange = 0;
  nodeliver = 0;
  total = 0;
}

void Count::new_livelock() {
  livelock++;
  total++;
}
void Count::new_delivered() {
  delivered++;
  total++;
}
// void Count::new_nochange() {
//   nochange++;
//   total++;
// }
void Count::new_nodeliver() {
  nodeliver++;
  total++;
}

void Count::print_report(int faulty_count, int max_moves) {
  
  string tempstr = "_report.txt";

  if (faulty_count == 1) {
    tempstr = "_1_report.txt";
  }
  if (faulty_count == 2) {
    tempstr = "_2_report.txt";
  }

  ofstream counts(tempstr, ios::out | ios::app);

  counts << setprecision(10);
  double temp_per = 0.0f;

  temp_per = (double)total / (double)total;
  counts << "Total Scenarios: " << total << " (" << temp_per * 100.0f << "%)" << endl;

  temp_per = (double)delivered / (double)total;
  counts << "Delivered:       " << delivered << " (" << temp_per * 100.0f << "%)" << endl;

  temp_per = (double)nodeliver / (double)total;
  counts << "Undeliverable:   " << nodeliver << " (" << temp_per * 100.0f << "%)" << endl;

  temp_per = (double)livelock / (double)total;
  counts << "Livelocks Found: " << livelock << " (" << temp_per * 100.0f << "%)" << endl;

  counts << "Maximum Moves:   " << max_moves << endl;

  counts << "--- end of report ---\n" << endl;
}