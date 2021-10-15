

#if !defined(SDL_AUDIO_DEVICE_INC_HPP)
#define SDL_AUDIO_DEVICE_INC_HPP

#include "../iaudiodevice.hpp"

class SDLAudioDevice : public IAudioDevice {
private:
  /* data */
public:
  virtual ~SDLAudioDevice(){};
  virtual IAudioData *createAudioFromFile(const std::string &filePath);
  void releaseAudio(IAudioData *audioData);
};

#endif // SDL_AUDIO_DEVICE_INC_HPP
