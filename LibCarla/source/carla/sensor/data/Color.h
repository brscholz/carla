// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "carla/rpc/Color.h"
#include "carla/rpc/FloatColor.h"

#include <cstdint>

namespace carla {
namespace sensor {
namespace data {

#pragma pack(push, 1)
  /// A 32-bit BGRA color.
  struct Color {
    Color() = default;
    Color(const Color &) = default;

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255u)
      : b(b), g(g), r(r), a(a) {}

    Color &operator=(const Color &) = default;

    bool operator==(const Color &rhs) const  {
      return (r == rhs.r) && (g == rhs.g) && (b == rhs.b);
    }

    bool operator!=(const Color &rhs) const  {
      return !(*this == rhs);
    }

    operator rpc::Color() const {
      return {r, g, b};
    }
    operator rpc::FloatColor() const {
      return {r/255.f, g/255.f, b/255.f, a/255.f};
    }

    uint8_t b = 0u;
    uint8_t g = 0u;
    uint8_t r = 0u;
    uint8_t a = 0u;
    MSGPACK_DEFINE_ARRAY(r, g, b, a);
  };
#pragma pack(pop)

  static_assert(sizeof(Color) == sizeof(uint32_t), "Invalid color size!");

#pragma pack(push, 1)
  /// A 64-bit BGRA color.
  struct HDRColor {
    HDRColor() = default;
    HDRColor(const HDRColor &) = default;

    HDRColor(uint16_t r, uint16_t g, uint16_t b, uint16_t a = 65535u)
      : r(r), g(g), b(b), a(a) {}

    HDRColor &operator=(const HDRColor &) = default;

    bool operator==(const HDRColor &rhs) const  {
      return (r == rhs.r) && (g == rhs.g) && (b == rhs.b);
    }

    bool operator!=(const HDRColor &rhs) const  {
      return !(*this == rhs);
    }

    operator rpc::Color() const {
      return {static_cast<uint8_t>(r/65535u*255u), static_cast<uint8_t>(g/65535u*255u), static_cast<uint8_t>(b/65535u*255u)};
    }
    operator rpc::FloatColor() const {
      return {r/65535.f, g/65535.f, b/65535.f, a/65535.f};
    }

    uint16_t r = 0u;
    uint16_t g = 0u;
    uint16_t b = 0u;
    uint16_t a = 65535u;    
    MSGPACK_DEFINE_ARRAY(r, g, b, a);
  };
#pragma pack(pop)

  static_assert(sizeof(HDRColor) == sizeof(uint64_t), "Invalid color size!");


#pragma pack(push, 1)
  /// Optical flow pixel format. 2 channel float data.
  struct OpticalFlowPixel {
    OpticalFlowPixel() = default;
    OpticalFlowPixel(const OpticalFlowPixel &) = default;

    OpticalFlowPixel(float x, float y)
      : x(x), y(y) {}

    OpticalFlowPixel &operator=(const OpticalFlowPixel &) = default;

    bool operator==(const OpticalFlowPixel &rhs) const  {
      return (x == rhs.x) && (y == rhs.y);
    }

    bool operator!=(const OpticalFlowPixel &rhs) const  {
      return !(*this == rhs);
    }

    float x = 0;
    float y = 0;
  };
#pragma pack(pop)

} // namespace data
} // namespace sensor
} // namespace carla
