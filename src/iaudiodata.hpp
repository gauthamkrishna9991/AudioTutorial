
#ifndef I_AUDIO_DATA_INC_HPP
#define I_AUDIO_DATA_INC_HPP

#include "sampleinfo.hpp"
#include <cstddef>

class IAudioData {
private:
  /* nothing here */
public:
  virtual ~IAudioData(){};
  virtual size_t generateSamples(float *stream, size_t streamLength, size_t pos,
                                 const SampleInfo &info) = 0;
  virtual size_t getAudioLength() = 0;
};

#endif