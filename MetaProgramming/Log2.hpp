#ifndef SAMS_META_LOG_TWO_HPP
#define SAMS_META_LOG_TWO_HPP 1

#include "MetaHeader.hpp"

namespace Meta
{
  template<UInt_t Number, UInt_t Power = sizeof(UInt_t)*8 - 1>
  struct Log2
  {
  	enum {
  		value = (Number & (UInt_t(1) << Power))
  			? (Number & (UInt_t(1) << (Power - 1)))
        ? Power + 1 : Power
  			: Log2<Number, Power - 1>::value
  	};
  };

  template<UInt_t Number>
  struct Log2<Number, 0> { enum { value = 0 }; };
}

#endif
