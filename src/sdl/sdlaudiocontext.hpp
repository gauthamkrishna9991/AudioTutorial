
#if !defined(SDL_AUDIO_CONTEXT_INC_HPP)
#define SDL_AUDIO_CONTEXT_INC_HPP

#include "../iaudiocontext.hpp"

#include <SDL2/SDL.h>
#include <vector>

class SDLAudioContext : public IAudioContext {
private:
  SDL_AudioDeviceID m_device;
  std::vector<float> m_stream;
  std::vector<AudioObject *> m_playingAudio;

  bool removeAudio(AudioObject &ao);

  SDLAudioContext(SDLAudioContext &other) { (void)other; }
  void operator=(const SDLAudioContext &other) { (void)other; }

public:
  SDLAudioContext(/* args */);
  virtual ~SDLAudioContext();
  virtual void PlayAudio(AudioObject &ao);
  virtual void PauseAudio(AudioObject &ao);
  virtual void StopAudio(AudioObject &ao);

  void generateSamples(Uint8 *stream, int streamLen);
};

#endif // SDL_AUDIO_CONTEXT_INC_HPP
