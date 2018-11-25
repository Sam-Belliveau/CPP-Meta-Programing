#ifndef SAMS_META_FACTORIAL_HPP
#define SAMS_META_FACTORIAL_HPP 1

#include "MetaHeader.hpp"

namespace Meta
{
  template<UInt_t Number>
  struct Factorial
  {
    enum {
      value = Number * Factorial<Number - 1>::value
    };
  };

  template<>
  struct Factorial<0> { enum { value = 1 }; };
}

#endif
