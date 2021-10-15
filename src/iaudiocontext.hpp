
#if !defined(I_AUDIO_CONTEXT_INC_HPP)
#define I_AUDIO_CONTEXT_INC_HPP

#include "audioobject.hpp"

struct IAudioContext {
  virtual ~IAudioContext(){};
  virtual void PlayAudio(AudioObject &ao) = 0;
  virtual void PauseAudio(AudioObject &ao) = 0;
  virtual void StopAudio(AudioObject &ao) = 0;
};

#endif // I_AUDIO_CONTEXT_INC_HPP
