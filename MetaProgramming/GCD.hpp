#ifndef SAMS_META_GREATEST_COMMON_DENOMINATOR_HPP
#define SAMS_META_GREATEST_COMMON_DENOMINATOR_HPP 1

#include "MetaHeader.hpp"

namespace Meta
{
  template<UInt_t A, UInt_t B>
  struct GCD { enum{ value = GCD<B, A % B>::value }; };

  template<UInt_t A>
  struct GCD<A, 0> { enum{ value = A }; };
}

#endif
