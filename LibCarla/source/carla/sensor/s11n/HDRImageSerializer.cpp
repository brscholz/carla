//
// Created by flo on 09.11.20.
//

#include "HDRImageSerializer.h"
#include "carla/sensor/s11n/HDRImageSerializer.h"

#include "carla/sensor/data/Image.h"

namespace carla {
  namespace sensor {
    namespace s11n {

      SharedPtr<SensorData> HDRImageSerializer::Deserialize(RawData &&data) {
        auto image = SharedPtr<data::HDRImage>(new data::HDRImage{std::move(data)});
        for (auto &pixel : *image) {
          pixel.a = 65535u;
        }        
        return image;
      }

    } // namespace s11n
  } // namespace sensor
} // namespace carla
