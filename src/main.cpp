#include <SDL2/SDL.h>
#include <iostream>

#include "audioobject.hpp"
#include "iaudiocontext.hpp"
#include "iaudiodevice.hpp"

#include "sdl/sdlaudiocontext.hpp"
#include "sdl/sdlaudiodevice.hpp"

#define FILE_PATH "./res/audio/testClip.wav"

int main() {
  if (SDL_Init(SDL_INIT_AUDIO) >= 0) {
    IAudioDevice *device = new SDLAudioDevice();
    IAudioContext *context = new SDLAudioContext();

    IAudioData *data = device->createAudioFromFile(FILE_PATH);

    SampleInfo info;
    info.volume = 1.0F;
    info.pitch = 1.0;

    AudioObject sound(info, data);

    char in = 0;
    while (in != 'q') {
      std::cin >> in;
      switch (in) {
      case 'a':
        context->PlayAudio(sound);
        break;
      case 'b':
        context->PauseAudio(sound);
        break;
      case 'd':
        context->StopAudio(sound);
        break;
      }
    }

    device->releaseAudio(data);
    delete context;
    delete device;
  } else {
    std::cout << "SDL2 Not Working Properly" << std::endl;
  }
  return (0);
}