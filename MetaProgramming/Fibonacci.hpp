#ifndef SAMS_META_FIBONACCI_HPP
#define SAMS_META_FIBONACCI_HPP 1

#include "MetaHeader.hpp"

namespace Meta
{
  template<UInt_t N>
  struct Fibonacci
  {
    enum {
      value = Fibonacci<N-1>::value + Fibonacci<N-2>::value
    };
  };

  template<>
  struct Fibonacci<1> { enum { value = 1 }; };

  template<>
  struct Fibonacci<0> { enum { value = 0 }; };
}

#endif
