// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "carla/MsgPack.h"

#include <cstdint>

#ifdef LIBCARLA_INCLUDED_FROM_UE4
#  include "Math/Color.h"
#endif // LIBCARLA_INCLUDED_FROM_UE4

namespace carla {
namespace rpc {

  class Color {
  public:

    uint8_t r = 0u;
    uint8_t g = 0u;
    uint8_t b = 0u;

    Color() = default;
    Color(const Color &) = default;

    Color(uint8_t r, uint8_t g, uint8_t b)
      : r(r), g(g), b(b) {}

    Color &operator=(const Color &) = default;

#ifdef LIBCARLA_INCLUDED_FROM_UE4

    Color(const FColor &color)
      : Color(color.R, color.G, color.B) {}

    Color(const FLinearColor &color)
      : Color(color.R * 255.0f, color.G  * 255.0f, color.B  * 255.0f) {}

    operator FColor() const {
      return FColor{r, g, b};
    }

    operator FLinearColor() const {
      return FLinearColor{
        static_cast<float>(r)/255.0f,
        static_cast<float>(g)/255.0f,
        static_cast<float>(b)/255.0f,
        1.0f
      };
    }

#endif // LIBCARLA_INCLUDED_FROM_UE4

    MSGPACK_DEFINE_ARRAY(r, g, b);
  };
  
  class HDRColor {
  public:

    float r = 0.f;
    float g = 0.f;
    float b = 0.f;

    HDRColor() = default;
    HDRColor(const HDRColor &) = default;

    HDRColor(float r, float g, float b)
      : r(r), g(g), b(b) {}

    HDRColor &operator=(const HDRColor &) = default;

#ifdef LIBCARLA_INCLUDED_FROM_UE4

    HDRColor(const FFloat16Color &color)
      : HDRColor(color.R.GetFloat(), color.G.GetFloat(), color.B.GetFloat()) {}

	// FLinearColor should be a value between 0 and 1... (see above Color(FLinearColor)-function)
	// Linear Color is NOT sRBG, it is as said linear...
    HDRColor(const FLinearColor &color)
      : HDRColor(color.R, color.G, color.B) {}

    operator FFloat16Color() const {
      return FLinearColor{
        r,
        g,
        b,
        1.0f
      };
    }

    operator FLinearColor() const {
      return FLinearColor{
        r,
        g,
        b,
        1.0f
      };
    }

#endif // LIBCARLA_INCLUDED_FROM_UE4

    MSGPACK_DEFINE_ARRAY(r, g, b);
  };

} // namespace rpc
} // namespace carla
