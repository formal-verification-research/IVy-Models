#ifndef ROUTE_HPP
#define ROUTE_HPP

#include "Utils.hpp"

// Count one_fault;
// Count two_fault;

// std::string route_default(int cur_x, int cur_y, int dest_x, int dest_y);
int route(int cur_x, int cur_y, int dest_x, int dest_y, Count& num_fault, int max_dim);


#endif