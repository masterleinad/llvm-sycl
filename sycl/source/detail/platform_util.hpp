//===--------- platform_util.hpp - platform utilities ----------*- C++ -*--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#pragma once

#include <cstdint>

#include <stddef.h> // for ::size_t

#include <sycl/detail/defines.hpp>

#ifdef _MSC_VER
// This feature is not supported in MSVC.
#define __builtin_expect(a, b) (a)
#endif

namespace sycl {
__SYCL_INLINE_VER_NAMESPACE(_V1) {
namespace detail {

struct PlatformUtil {
  enum class TypeIndex : unsigned int {
    Char = 0,
    Short = 1,
    Int = 2,
    Long = 3,
    Float = 4,
    Double = 5,
    Half = 6
  };

  /// Returns the maximum vector width counted in elements of the given type.
  static uint32_t getNativeVectorWidth(TypeIndex Index);

  static uint32_t getMaxClockFrequency();

  static uint32_t getMemCacheLineSize();

  static uint64_t getMemCacheSize();

  static void prefetch(const char *Ptr, size_t NumBytes);
};

} // namespace detail
} // __SYCL_INLINE_VER_NAMESPACE(_V1)
} // namespace sycl
