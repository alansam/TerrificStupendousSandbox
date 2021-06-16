//
//  container.cpp
//  CF.custom_compare
//
//  Created by Alan Sampson on 5/15/21.
//

#include "container.hpp"

//  MARK: Static instance_count
uint64_t container::instance_count { 0ull };

/*
 *  MARK: Friend operator <<
 */
auto operator<<(std::ostream & ooo, container const & me)
  -> std::ostream & {
  ooo << me.to_string();
  return ooo;
}

/*
 *  MARK: to_string()
 */
auto container::to_string(void) const -> std::string {
  std::ostringstream oss;
  oss << "ID: "s<< std::setw(4) << id_ << ' '
      << "Name: "s << std::setw(8) << name_ << ' '
      << "Date: "s << std::setw(10) << ymd_;

  return oss.str();
}
