#ifndef ROUTE_HPP
#define ROUTE_HPP

#include "Utils.hpp"

// Count one_fault;
// Count two_fault;

// std::string route_default(int cur_x, int cur_y, int dest_x, int dest_y);
int route(int cur_x, int cur_y, int dest_x, int dest_y, int faulty_x1, int faulty_y1, char faulty_dir1, int faulty_x2, int faulty_y2, char faulty_dir2, Count& num_fault);


#endif