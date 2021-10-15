#if !defined(SDL_WAV_AUDIO_DATA_INC_HPP)
#define SDL_WAV_AUDIO_DATA_INC_HPP

#include "../iaudiodata.hpp"
#include <SDL2/SDL.h>
#include <string>

class SDLWAVAudioData : public IAudioData {
private:
  Uint8 *m_pos;
  Uint8 *m_start;
  Uint8 *m_end;

  SDLWAVAudioData(SDLWAVAudioData &other) { (void)other; }
  void operator=(SDLWAVAudioData &other) { (void)other; }

public:
  SDLWAVAudioData(const std::string &filename);
  virtual ~SDLWAVAudioData();
  virtual size_t generateSamples(float *stream, size_t streamLength, size_t pos,
                                 const SampleInfo &info);
  virtual size_t getAudioLength();
};

#endif // SDL_WAV_AUDIO_DATA_INC_HPP
