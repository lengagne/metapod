// Copyright 2011, 2012,
//
// Maxime Reis
//
// JRL/LAAS, CNRS/AIST
//
// This file is part of metapod.
// metapod is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// metapod is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License
// along with metapod.  If not, see <http://www.gnu.org/licenses/>.

/*
 * This file contains common tools and includes shared by the test suite
 */

#ifndef METAPOD_TEST_COMMON_TOOLS
# define METAPOD_TEST_COMMON_TOOLS

// Common includes
# include <string>
# include <iostream>
# include <fstream>

// metapod includes
# include "metapod/models/simple-humanoid/robot.hh"
# include "metapod/algos/rnea.hh"
# include "metapod/tools/print.hh"
# include "metapod/tools/initconf.hh"

// Boost test suite includes
# define BOOST_TEST_MODULE METAPOD_RNEA
# include <boost/test/unit_test.hpp>

// Performance test : some tests also output an average execution time of the tested component if METAPOD_PERF_TEST is defined
//# define METAPOD_PERF_TEST 
# ifdef METAPOD_PERF_TEST
#  include <sys/time.h>
# endif

// Converts a string to a double if possible, returns 0 otherwise
double stringToDouble( const std::string& s )
 {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
 }

// Returns true if the normalized difference between two doubles is strictly inferior to the threshold parameter, false otherwise
bool compareDouble(double x, double y, double epsilon)
{
  double normalized_diff = fabs((x-y)/y);
  return normalized_diff<epsilon?1:0;
}

// Extracts the next double encountered in a stream file and returns it. Returns 0 if none is found.
double getNextDouble( std::ifstream & is )
{
  std::string s;
  while(!is.eof())
  {
    is >> s;
    if(stringToDouble(s))
      return stringToDouble(s);
  }
  return 0;
}

#endif