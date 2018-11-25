#ifndef SAMS_META_ROOT_HPP
#define SAMS_META_ROOT_HPP 1

#include "MetaHeader.hpp"
#include "Power.hpp"

namespace Meta
{
  template<
    UInt_t Number, UInt_t RPow,
    UInt_t Guess = 4, UInt_t Iter = sizeof(UInt_t) * 6>
  struct Root
  {
    enum {
      value = Root<
        Number, RPow,
        ((Guess + Number / Power<Guess, RPow - 1>::value + 1) / 2),
        Iter - 1
      >::value
    };
  };


  template<UInt_t Number, UInt_t Guess, UInt_t Iter>
  struct Root<Number, 0, Guess, Iter> { enum { value = 0 }; };

  template<UInt_t Number, UInt_t RPow, UInt_t Guess>
  struct Root<Number, RPow, Guess, 0> { enum { value = Guess }; };
}

#endif
