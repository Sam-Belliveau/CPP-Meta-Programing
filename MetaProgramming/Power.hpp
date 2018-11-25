#ifndef SAMS_META_POWER_HPP
#define SAMS_META_POWER_HPP

#include "MetaHeader.hpp"

namespace Meta
{
  template<Int_t Base, UInt_t Exp>
  struct Power
  {
    enum {
      value = Base * Power<Base, Exp - 1>::value
    };
  };

  template<Int_t Base>
  struct Power<Base, 1> { enum { value = Base }; };

  template<Int_t Base>
  struct Power<Base, 0> { enum { value = 1 }; };
}

#endif
