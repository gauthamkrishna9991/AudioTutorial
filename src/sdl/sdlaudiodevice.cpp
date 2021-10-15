#include "sdlaudiodevice.hpp"
#include "sdlwavaudiodata.hpp"

IAudioData *SDLAudioDevice::createAudioFromFile(const std::string &filePath) {
  return new SDLWAVAudioData(filePath);
}

void SDLAudioDevice::releaseAudio(IAudioData *audioData) { delete audioData; }