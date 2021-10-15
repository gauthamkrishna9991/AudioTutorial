#include "sdlwavaudiodata.hpp"

SDLWAVAudioData::SDLWAVAudioData(const std::string &fileName) {

  // TODO: Handle streamFromFile
  SDL_AudioSpec wavSpec;
  Uint8 *wavStart;
  Uint32 wavLength;

  if (SDL_LoadWAV(fileName.c_str(), &wavSpec, &wavStart, &wavLength) == NULL) {
    // TODO: Proper Error Handling
    // std::cerr << "ERROR: " << FILE_PATH << " could not be loaded as audio
    // file"
    //           << std::endl;
    throw fileName;
  }

  this->m_pos = wavStart;
  this->m_start = wavStart;
  this->m_end = m_start + wavLength;
}

SDLWAVAudioData::~SDLWAVAudioData() { SDL_FreeWAV(m_start); }

size_t SDLWAVAudioData::generateSamples(float *stream, size_t streamLength,
                                        size_t pos, const SampleInfo &info) {

  float pitch = (float)info.pitch;
  m_pos = m_start + pos;

  if (m_pos >= m_end || m_pos < m_start) {
    return (size_t)-1;
  }

  auto len = (Uint32)streamLength;
  Uint32 lengthLeft = (Uint32)((this->m_end - this->m_pos) / pitch);
  len = (len > lengthLeft) ? lengthLeft : len;

  // TODO: MAKE THIS MORE GENERAL
  Sint16 *samples = (Sint16 *)this->m_pos;
  float sampleIndex = 0.0F;

  float factor = info.volume * 1.0F / (float)(INT16_MAX + 1.0F);
  for (Uint32 i = 0; i < len; i++) {
    
    stream[i] = (samples[(size_t)sampleIndex]) * factor;
    sampleIndex += pitch;
  }

  this->m_pos = (Uint8 *)(samples + (size_t)sampleIndex);

  return (size_t)(this->m_pos - this->m_start);
}

size_t SDLWAVAudioData::getAudioLength() {
  return (size_t)(this->m_end - this->m_start);
}