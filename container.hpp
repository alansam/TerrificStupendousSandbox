//
//  container.hpp
//  CF.custom_compare
//
//  Created by Alan Sampson on 5/15/21.
//

#pragma once
#ifndef container_hpp
#define container_hpp

// #define AS_DEBUG
#ifdef AS_DEBUG
# define AS_DEBUG_TRACE
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std::literals::string_literals;

/*
 *  MARK: Class container
 */
class container {
public:
  container(std::string name = ""s, std::string ymd = "0000-01-01"s);
  container(container const & that);
  container(container && that);

  virtual
  ~container();

  container & operator=(container const &) = default;
  container & operator=(container &&) = default;

  auto to_string(void) const -> std::string;

  //  TODO: implement <=> for C++20
//  auto operator<=>(container const & that) const -> bool;
  auto operator<(container const & that) const -> bool;
  auto operator>(container const & that) const -> bool;
  auto operator<=(container const & that) const -> bool;
  auto operator>=(container const & that) const -> bool;
  auto operator==(container const & that) const -> bool;
  auto operator!=(container const & that) const -> bool;

  friend
  auto operator<<(std::ostream &, container const &) -> std::ostream &;

private:
  uint64_t id_;
  std::string name_;
  std::string ymd_;

  static
  uint64_t instance_count;
};

//  MARK: - Inline Implementations.
/*
 *  MARK: Default Constructor.
 */
inline
container::container(std::string name, std::string ymd)
 :  name_ {name}, ymd_ { ymd } {
  id_ = ++instance_count;
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << " dflt ctor ID: "s << id_
            << std::endl;
#endif
}

/*
 *  MARK: Copy Constructor.
 */
inline
container::container(container const & that) {
  id_ = that.id_;
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << " copy ctor ID: "s << id_
            << std::endl;
#endif
  name_ = that.name_;
  ymd_ = that.ymd_;
}

/*
 *  MARK: Move Constructor.
 */
inline
container::container(container && that) {
  id_ = std::move(that.id_);
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << " move ctor ID: "s << id_
            << std::endl;
#endif
  name_ = std::move(that.name_);
  ymd_ = std::move(that.ymd_);
}

/*
 *  MARK: Destructor
 */
inline
container::~container() {
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << " dtor ID: "s << id_
            << std::endl;
#endif
}

//  TODO: implement <=> for C++20
//inline
//auto container::operator<=>(container const & that) const -> bool {
//
//}

inline
auto container::operator<(container const & that) const -> bool {
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << std::endl;
#endif
  return ymd_ == that.ymd_
              ? name_ < that.name_
              : ymd_ < that.ymd_;
}

inline
auto container::operator>(container const & that) const -> bool {
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << std::endl;
#endif
  return ymd_ == that.ymd_
              ? name_ > that.name_
              : ymd_ > that.ymd_;
}

inline
auto container::operator<=(container const & that) const -> bool {
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << std::endl;
#endif
  return !(*this > that);
}

inline
auto container::operator>=(container const & that) const -> bool {
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << std::endl;
#endif
  return !(*this < that);
}

inline
auto container::operator==(container const & that) const -> bool {
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << std::endl;
#endif
  return ymd_ == that.ymd_
              ? name_ == that.name_
              : false;
}

inline
auto container::operator!=(container const & that) const -> bool {
#ifdef AS_DEBUG_TRACE
  std::cout << "In "s << __func__ << std::endl;
#endif
  return !(*this == that);
}

#endif /* container_hpp */
