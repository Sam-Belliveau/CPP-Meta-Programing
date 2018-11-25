#ifndef SAMS_META_PRIME_HPP
#define SAMS_META_PRIME_HPP 1

#include "MetaHeader.hpp"
#include "SquareRoot.hpp"

namespace Meta{

template<UInt_t Number, UInt_t Check = SquareRoot<Number>::value | 1>
struct IsPrime
{
  enum
  {
    value =
      (Number % Check == 0)
        ? false
        : IsPrime<Number, (Check - 2) | 1>::value
  };
};

template<UInt_t Number>
struct IsPrime<Number, 1>
{ enum { value = Number != 2 && (Number & 1) }; };

}

#endif
