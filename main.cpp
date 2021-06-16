//
//  comp.cpp
//  CF.custom_compare
//
//  Created by Alan Sampson on 5/15/21.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "container.hpp"

using namespace std::literals::string_literals;

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "CF.custom_compare\n"s;
  std::cout << "C++ Version: " << __cplusplus << std::endl;

  auto y1 = container("C1"s, "2021-01-31");
  auto y2 = container("C2"s, "1999-12-31");
  auto y3 = container("C3"s, "2021-01-31");
  auto y4 = container("C4"s, "2020-06-14");
  auto y5 = container("C5"s, "2000-01-01");

  std::cout << y1 << std::endl;
  std::cout << y2 << std::endl;

  auto rr = false;
  std::cout << std::boolalpha;
  rr = y1 < y2;
  std::cout << "y1 <  y2: "s << rr << std::endl;
  rr = y1 <= y2;
  std::cout << "y1 <= y2: "s << rr << std::endl;
  rr = y1 > y2;
  std::cout << "y1 >  y2: "s << rr << std::endl;
  rr = y1 >= y2;
  std::cout << "y1 >= y2: "s << rr << std::endl;
  rr = y1 == y2;
  std::cout << "y1 == y2: "s << rr << std::endl;
  rr = y1 != y2;
  std::cout << "y1 != y2: "s << rr << std::endl;
  std::cout << std::noboolalpha;
  std::cout << std::endl;

  auto ctnrs = std::vector { y1, y2, y3, y4, y5, };
  std::for_each(ctnrs.cbegin(), ctnrs.cend(), [](auto const & ctr) {
    std::cout << ctr << '\n';
  });
  std::cout << std::endl;

  std::cout << "Sorting: std::less<>()\n"s;
  std::sort(ctnrs.begin(), ctnrs.end(), std::less<>());
  std::for_each(ctnrs.cbegin(), ctnrs.cend(), [](auto const & ctr) {
    std::cout << ctr << '\n';
  });
  std::cout << std::endl;

  std::cout << "Sorting: std::greater<>()\n"s;
  std::sort(ctnrs.begin(), ctnrs.end(), std::greater<>());
  std::for_each(ctnrs.cbegin(), ctnrs.cend(), [](auto const & ctr) {
    std::cout << ctr << '\n';
  });
  std::cout << std::endl;

  std::cout << "Sorting: default\n"s;
  std::sort(ctnrs.begin(), ctnrs.end());
  std::for_each(ctnrs.cbegin(), ctnrs.cend(), [](auto const & ctr) {
    std::cout << ctr << '\n';
  });
  std::cout << std::endl;

  return 0;
}
