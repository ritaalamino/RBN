// Copyright 2019 COPT

#ifndef UTIL_LOGICMAP_H
#define UTIL_LOGICMAP_H

#include <bits/stdc++.h>

#include <map>

namespace rbn {
namespace network {
namespace util {
  std::map<int, std::function<int(int, int)> >logic_map{
  /*AND*/ {0, [](int a, int b) { return a & b; }},
  /*OR*/  {1, [](int a, int b) { return a | b; }},
  /*XOR*/ {2, [](int a, int b) { return a ^ b;}},
  /*NOT*/ {3, [](int a, int b) { return !a;}},
  //  /*NOT*/ {2, [](int a, int b) { return !b}},
  /*XNOR*/{4, [](int a, int b) { return !(a ^ b);}},
  /*NAND*/{5, [](int a, int b) { return !(a & b);}},
  /*NOR*/ {6, [](int a, int b) { return !(a | b);}}
  };
}  // namespace util
}  // namespace network
}  // namespace rbn

    /**
      * The logic map functions for the connections
      */

#endif
