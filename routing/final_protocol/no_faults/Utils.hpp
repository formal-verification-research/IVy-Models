#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <string>

#include "Node.hpp"

using namespace std;

class Count {
  public:
    Count();
    void new_livelock();
    void new_delivered();
    // void new_nochange();
    void new_nodeliver();
    void print_report(int max_dim, int max_moves);

  private:
    int livelock = 0;
    int delivered = 0;
    // int nochange = 0;
    int nodeliver = 0;
    int total = 0;
};

char direction(const char c);
std::string longDirection(const char c);

#endif