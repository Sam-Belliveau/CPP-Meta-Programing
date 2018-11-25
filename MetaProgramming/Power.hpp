#ifndef SAMS_META_POWER_HPP
#define SAMS_META_POWER_HPP

#include "MetaHeader.hpp"

namespace Meta{

template<Int_t Base, UInt_t Power>
struct MetaPower
{
  enum {
    value = Base * MetaPower<Base, Power-1>::value
  };
};

template<Int_t Base>
struct MetaPower<Base, 1>
{
  enum {
    value = Base
  };
};

template<Int_t Base>
struct MetaPower<Base, 0>
{
  enum {
    value = 1
  };
};

}

#endif
