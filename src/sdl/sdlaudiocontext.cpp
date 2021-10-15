
#include "sdlaudiocontext.hpp"

static void SDLAudioContext_AudioCallback(void *userdata, Uint8 *streamIn,
                                          int len) {
  SDLAudioContext *context = (SDLAudioContext *)userdata;
  context->generateSamples(streamIn, len);
}

SDLAudioContext::SDLAudioContext() {
  SDL_AudioSpec spec;

  // TODO: DO NOT HARD-CODE THESE VALUES!
  SDL_zero(spec);
  spec.freq = 44100;
  spec.format = AUDIO_S16SYS;
  spec.channels = 2;
  spec.samples = 2048;
  spec.callback = SDLAudioContext_AudioCallback;
  spec.userdata = this;

  // TODO: Handle differing specs.
  this->m_device = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, 0);
  if (this->m_device == 0) {
    // TODO: Proper Error Handling
    throw SDL_GetError();
    // return (1);
  }

  SDL_PauseAudioDevice(m_device, 0);
}

SDLAudioContext::~SDLAudioContext() { SDL_CloseAudioDevice(m_device); }

void SDLAudioContext::PlayAudio(AudioObject &ao) {
  SDL_LockAudioDevice(this->m_device);

  // this prevent duplicates
  this->removeAudio(ao);
  this->m_playingAudio.push_back(&ao);

  SDL_UnlockAudioDevice(this->m_device);
}

void SDLAudioContext::PauseAudio(AudioObject &ao) {
  SDL_LockAudioDevice(this->m_device);

  this->removeAudio(ao);

  SDL_UnlockAudioDevice(this->m_device);
}

void SDLAudioContext::StopAudio(AudioObject &ao) {
  SDL_LockAudioDevice(this->m_device);

  if (this->removeAudio(ao)) {
    ao.setPos(0.0);
  }

  SDL_UnlockAudioDevice(this->m_device);
}

void SDLAudioContext::generateSamples(Uint8 *streamIn, int streamInLen) {
  size_t streamLen = (size_t)(streamInLen / 2);

  this->m_stream.reserve(streamLen);
  float *floatStream = *(float **)(&this->m_stream);

  for (size_t i = 0; i < streamLen; i++) {
    floatStream[i] = 0.0F;
  } 

  std::vector<AudioObject *>::iterator it = m_playingAudio.begin();
  std::vector<AudioObject *>::iterator end = m_playingAudio.end();

  for (; it != end; ++it) {
    if (!(*it)->generateSamples(floatStream, streamLen)) {
      this->removeAudio(*(*it));
    }
  }

  Sint16 *stream = (Sint16 *)streamIn;
  for (size_t i = 0; i < streamLen; i++) {
    float val = floatStream[i];

    if (val > 1.0F) {
      val = 1.0F;
    } else if (val < -1.0F) {
      val = -1.0F;
    }

    stream[i] = (Sint16)(val * 32767);
  }
}

bool SDLAudioContext::removeAudio(AudioObject &ao) {
  std::vector<AudioObject *>::iterator it = m_playingAudio.begin();
  std::vector<AudioObject *>::iterator end = m_playingAudio.end();

  for (; it != end; ++it) {
    if (*it == &ao) {
      this->m_playingAudio.erase(it);
      return true;
    }
  }
  return false;
}