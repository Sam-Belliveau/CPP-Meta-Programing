#ifndef SAMS_META_SQUARE_ROOT_HPP
#define SAMS_META_SQUARE_ROOT_HPP 1

#include "MetaHeader.hpp"

namespace Meta
{
  template<UInt_t Number, UInt_t Guess = 4, UInt_t Iter = sizeof(UInt_t) * 5>
  struct SquareRoot
  {
    enum {
      value = SquareRoot<
        Number,
        ((Guess + Number / Guess + 1) / 2),
        Iter - 1
      >::value
    };
  };

  template<UInt_t Number, UInt_t Guess>
  struct SquareRoot<Number, Guess, 0> { enum { value = Guess }; };
}

#endif
