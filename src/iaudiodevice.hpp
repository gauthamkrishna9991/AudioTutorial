
#if !defined(I_AUDIO_DEVICE_INC_HPP)
#define I_AUDIO_DEVICE_INC_HPP

#include "iaudiodata.hpp"
#include <string>

class IAudioDevice {
private:
  /* data */
public:
  virtual ~IAudioDevice(){};
  virtual IAudioData *createAudioFromFile(const std::string &filepath) = 0;
  virtual void releaseAudio(IAudioData *audioData) = 0;
};

#endif // I_AUDIO_DEVICE_INC_HPP
