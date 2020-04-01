#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <string>

#include "Utils.hpp"
// Count one_fault;
// Count two_fault;

// #include "Node.hpp"
#include "Route.hpp"



using namespace std;

// string route_default(int cur_x, int cur_y, int dest_x, int dest_y);

void route(int cur_x, int cur_y, int dest_x, int dest_y, int faulty_x1, int faulty_y1, char faulty_dir1, int faulty_x2, int faulty_y2, char faulty_dir2, Count& num_fault) 
{
  // int cur_x = 2;
  // int cur_y = 0;
  // int dest_x = 1;
  // int dest_y = 2;
  // int faulty_x1 = 2;
  // int faulty_y1 = 0;
  // char faulty_dir1 = 3;
  // int faulty_x2 = 1;
  // int faulty_y2 = 0;
  // char faulty_dir2 = 3;
  
  int start_x = cur_x;
  int start_y = cur_y;
  stringstream filename;
  if (faulty_x2 == 9) {
  filename << "1s" << start_x << start_y << "_d" << dest_x << dest_y << "_f" << faulty_x1 << faulty_y1 << direction(faulty_dir1);
  }
  else {
  filename << "2s" << start_x << start_y << "_d" << dest_x << dest_y << "_f" << faulty_x1 << faulty_y1 << direction(faulty_dir1) << "_f" << faulty_x2 << faulty_y2 << direction(faulty_dir2);
  }

  // string compare = route_default(cur_x, cur_y, dest_x, dest_y);


  // if (compare == "FAIL") {
  //   ofstream bigfail("__FAILWithNoFaults.txt", ios::out | ios::app);
  //   bigfail << filename.str() << endl;
  // }
  // if (compare == "LIVELOCK") {
  //   ofstream biglive("__LIVELOCKWithNoFaults.txt", ios::out | ios::app);
  //   biglive << filename.str() << endl;
  // }
  
  stringstream ss;

  Node node[3][3]; //X then Y coordinate

  node[faulty_x1][faulty_y1].faulty(faulty_dir1);
  
  if (faulty_x2 != 9) {
    node[faulty_x2][faulty_y2].faulty(faulty_dir2);
  }

  // 02 12 22
  // 01 11 21
  // 00 10 20

  int t = 0;
  bool delivered = false;
  string traveling = "new";

  bool unroutable = false;
  bool livelock = false;

  while (!delivered) //routing with faulty link checks
  {
    node[cur_x][cur_y].has_flit(); //make sure all current nodes are counted

    // If the packet has reached its destination, deliver the packet.
    if (cur_x == dest_x && cur_y == dest_y) { //delivered
      delivered = true;
      ss << "DELIVERED!" << endl;
      break;
    }

    // else if the packet is one hop away and the corresponding link is available, send on that link
    else if (cur_x - dest_x == 1 && cur_y == dest_y && node[cur_x][cur_y].west_ok) { // 1 node west
        cur_x--;
        traveling = "west";
        ss << traveling << " to " << cur_x << cur_y << endl;
    }
    else if (cur_y - 1 == dest_y && cur_x == dest_x && node[cur_x][cur_y].south_ok) { // 1 node south
        cur_y--;
        traveling = "south";
        ss << traveling << " to " << cur_x << cur_y << endl;
    }
    else if (cur_x + 1 == dest_x && cur_y == dest_y && node[cur_x][cur_y].east_ok) { // 1 node east
        cur_x++;
        traveling = "east";
        ss << traveling << " to " << cur_x << cur_y << endl;
    }
    else if (cur_y + 1 == dest_y && cur_x == dest_x && node[cur_x][cur_y].north_ok) { // 1 node north
        cur_y++;
        traveling = "north";
        ss << traveling << " to " << cur_x << cur_y << endl;
    }

    // go west if:
    else if (cur_x != 0 && (traveling == "west" || traveling == "south" || traveling == "new") && node[cur_x][cur_y].west_ok && 
              (cur_x >= dest_x || (cur_y <= dest_y && !node[cur_x][cur_y].south_ok))) {
      cur_x--;
      traveling = "west";
      ss << traveling << " to " << cur_x << cur_y << endl;
    }

    // go south if:
    else if (cur_y != 0 && (traveling == "west" || traveling == "south" || traveling == "new") && node[cur_x][cur_y].south_ok && 
              (cur_y >= dest_y || (cur_x <= dest_x && !node[cur_x][cur_y].west_ok)) && 
              (dest_x != cur_x + 1 || dest_y != cur_y + 1)) {
      cur_y--;
      traveling = "south";
      ss << traveling << " to " << cur_x << cur_y << endl;
    }

    // go east if:
    else if (cur_x != 2 && (traveling != "west") && node[cur_x][cur_y].east_ok && (dest_x > cur_x + 1 || (dest_x > cur_x && dest_y == cur_y + 1))) {
      cur_x++;
      traveling = "east";
      ss << traveling << " to " << cur_x << cur_y << endl;
    }

    // go north if:
    else if (cur_y != 2 && (traveling != "south") && node[cur_x][cur_y].north_ok && dest_y > cur_y) {
      cur_y++;
      traveling = "north";
      ss << traveling << " to " << cur_x << cur_y << endl;
    }

    //ELSE go west if
    // else if (cur_x != 0 && cur_x >= dest_x && (traveling != "east" || (cur_y < dest_y && cur_x == dest_x)) && node[cur_x][cur_y].west_ok) { // JUST COLUMN
    else if (cur_x != 0 && cur_x >= dest_x && (traveling != "east" || (cur_y + 1 == dest_y && cur_x == dest_x)) && node[cur_x][cur_y].west_ok) { // ONE NODE ABOVE 
      cur_x--;
      traveling = "west";
      ss << traveling << " two " << cur_x << cur_y << endl;
    }

    //ELSE go south if
    else if (cur_y != 0 && cur_y >= dest_y && traveling != "north" && node[cur_x][cur_y].south_ok /**/ && (traveling != "east" || dest_x != 2 || dest_y != 2 /*|| node[cur_x][cur_y].east_ok*/ )) {
      cur_y--;
      traveling = "south";
      ss << traveling << " two " << cur_x << cur_y << endl;
    }

    //ELSE go east if
    else if (cur_x != 2 && cur_x <= dest_x && (traveling != "west" || cur_x == dest_x || (cur_x + 1 == dest_x && cur_y + 1 != dest_y)) 
            && node[cur_x][cur_y].east_ok) {
      cur_x++;
      traveling = "east";
      ss << traveling << " two " << cur_x << cur_y << endl;
    }

    //ELSE go north if
    else if (cur_y != 2 && cur_y <= dest_y && (traveling != "south" || cur_x <= dest_x) && node[cur_x][cur_y].north_ok) {
      cur_y++;
      traveling = "north";
      ss << traveling << " two " << cur_x << cur_y << endl;
    }

    // UNROUTABLE
    else {
      unroutable = true;
      num_fault.new_nodeliver();
      ofstream noroute("_cannotroute.txt", ios::out | ios::app);
      noroute << filename.str() << endl;
      ofstream noroutefile("cannotroutetrace/" + filename.str() + ".txt", ios::out | ios::app);
      noroutefile << "MODIFIED ROUTE: \n" << ss.str() << endl;
      noroutefile << "--- no routing decision available" << endl;
      // noroutefile << "ORIGINAL ROUTE: \n" << compare << "\n\nMODIFIED ROUTE: \n" << ss.str() << endl;
      break;
    }

    // LIVELOCK PROBABLE
    if (t >= 1000) {
      livelock = true;
      num_fault.new_livelock();
      ofstream livelock("_livelock.txt", ios::out | ios::app);
      livelock << filename.str() << endl;
      ofstream livefile("livelocktrace/" + filename.str() + ".txt", ios::out | ios::app);
      livefile << "MODIFIED ROUTE: \n" << ss.str() << endl;
      // livefile << "ORIGINAL ROUTE: \n" << compare << "\n\nMODIFIED ROUTE: \n" << ss.str() << endl;
      break;
    }
    else {
      t++;
    }

  }

  // if (ss.str() == compare) {
  //   if (faulty_x2 == 9) {
  //       one_fault.new_nochange();
  //     }
  //     else {
  //       two_fault.new_nochange();
  //     }
  //   ofstream nochange("_nochange.txt", ios::out | ios::app);
  //   nochange << filename.str() << endl;
  // }
  // else  
  if (delivered) {
    num_fault.new_delivered();
    ofstream deliv("_delivered.txt", ios::out | ios::app);
    deliv << filename.str() << endl;
    // ofstream delivered("deliveredtrace/" + filename.str() + ".txt", ios::out | ios::app);
    // delivered << "ORIGINAL ROUTE: \n" << compare << "\n\nMODIFIED ROUTE: \n" << ss.str() << endl;
  }

  // ofstream tested("_tested.txt", ios::out | ios::app);
  // tested << filename.str() << endl;

}


// string route_default(int cur_x, int cur_y, int dest_x, int dest_y) 
// {
//   //with no faults (for comparison):

//   stringstream ss;

//   Node node[3][3]; //X then Y coordinate

//   // 02 12 22
//   // 01 11 21
//   // 00 10 20

//   int t = 0;
//   bool delivered = false;
//   string traveling = "new";

//   while (!delivered) //routing with faulty link checks
//   {
//     node[cur_x][cur_y].has_flit(); //make sure all current nodes are counted

//     // If the packet has reached its destination, deliver the packet.
//     if (cur_x == dest_x && cur_y == dest_y) { //delivered
//       delivered = true;
//       ss << "DELIVERED!" << endl;
//       break;
//     }

//     // else if the packet is one hop away and the corresponding link is available, send on that link
//     else if (cur_x - dest_x == 1 && cur_y == dest_y && node[cur_x][cur_y].west_ok) { // 1 node west
//         cur_x--;
//         traveling = "west";
//         ss << traveling << " to " << cur_x << cur_y << endl;
//     }
//     else if (cur_y - 1 == dest_y && cur_x == dest_x && node[cur_x][cur_y].south_ok) { // 1 node south
//         cur_y--;
//         traveling = "south";
//         ss << traveling << " to " << cur_x << cur_y << endl;
//     }
//     else if (cur_x + 1 == dest_x && cur_y == dest_y && node[cur_x][cur_y].east_ok) { // 1 node east
//         cur_x++;
//         traveling = "east";
//         ss << traveling << " to " << cur_x << cur_y << endl;
//     }
//     else if (cur_y + 1 == dest_y && cur_x == dest_x && node[cur_x][cur_y].north_ok) { // 1 node north
//         cur_y++;
//         traveling = "north";
//         ss << traveling << " to " << cur_x << cur_y << endl;
//     }

//     // go west if:
//     else if (cur_x != 0 && (traveling == "west" || traveling == "south" || traveling == "new") && node[cur_x][cur_y].west_ok && 
//               (cur_x >= dest_x || (cur_y <= dest_y && !node[cur_x][cur_y].south_ok))) {
//       cur_x--;
//       traveling = "west";
//       ss << traveling << " to " << cur_x << cur_y << endl;
//     }

//     // go south if:
//     else if (cur_y != 0 && (traveling == "west" || traveling == "south" || traveling == "new") && node[cur_x][cur_y].south_ok && 
//               (cur_y >= dest_y || (cur_x <= dest_x && !node[cur_x][cur_y].west_ok))) {
//       cur_y--;
//       traveling = "south";
//       ss << traveling << " to " << cur_x << cur_y << endl;
//     }

//     // go east if:
//     else if (cur_x != 2 && (traveling != "west") && node[cur_x][cur_y].east_ok && (dest_x > cur_x + 1 || (dest_x > cur_x && dest_y == cur_y + 1))) {
//       cur_x++;
//       traveling = "east";
//       ss << traveling << " to " << cur_x << cur_y << endl;
//     }

//     // go north if:
//     else if (cur_y != 2 && (traveling != "south") && node[cur_x][cur_y].north_ok && dest_y > cur_y) {
//       cur_y++;
//       traveling = "north";
//       ss << traveling << " to " << cur_x << cur_y << endl;
//     }

//     //ELSE go west if
//     // else if (cur_x != 0 && cur_x >= dest_x && (traveling != "east" || (cur_y < dest_y && cur_x == dest_x)) && node[cur_x][cur_y].west_ok) { // JUST COLUMN
//     else if (cur_x != 0 && cur_x >= dest_x && (traveling != "east" || (cur_y + 1 == dest_y && cur_x == dest_x)) && node[cur_x][cur_y].west_ok) { // ONE NODE ABOVE 
//       cur_x--;
//       traveling = "west";
//       ss << traveling << " two " << cur_x << cur_y << endl;
//     }

//     //ELSE go south if
//     else if (cur_y != 0 && cur_y >= dest_y && traveling != "north" && node[cur_x][cur_y].south_ok) {
//       cur_y--;
//       traveling = "south";
//       ss << traveling << " two " << cur_x << cur_y << endl;
//     }

//     //ELSE go east if
//     else if (cur_x != 2 && cur_x <= dest_x && (traveling != "west" || cur_x == dest_x || (cur_x + 1 == dest_x && cur_y + 1 != dest_y)) 
//             && node[cur_x][cur_y].east_ok) {
//       cur_x++;
//       traveling = "east";
//       ss << traveling << " two " << cur_x << cur_y << endl;
//     }

//     //ELSE go north if
//     else if (cur_y != 2 && cur_y <= dest_y && (traveling != "south" || cur_x <= dest_x) && node[cur_x][cur_y].north_ok) {
//       cur_y++;
//       traveling = "north";
//       ss << traveling << " two " << cur_x << cur_y << endl;
//     }

//     // UNROUTABLE
//     else {
//       ss << "FAILURE TO DELIVER";
//       return "FAIL";
//       break;
//     }

//     if (t >= 1000) {
//       ss << "LIVELOCK LIKELY";
//       return "LIVELOCK";
//       break;
//     }
//     else {
//       t++;
//     }
//   }
  
//   return ss.str();
// }




