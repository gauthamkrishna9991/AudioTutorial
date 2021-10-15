
#if !defined(AUDIO_OBJECT_INC_HPP)
#define AUDIO_OBJECT_INC_HPP

#include "iaudiodata.hpp"
#include "sampleinfo.hpp"

class AudioObject {
private:
  size_t m_audioPos;
  size_t m_audioLength;
  SampleInfo m_sampleInfo;
  IAudioData *m_audioData;

  size_t posToAbsolutePos(double pos) const;

public:
  AudioObject(const SampleInfo &info, IAudioData *data);

  bool generateSamples(float *stream, size_t streamLength);

  void setPos(double pos); // B/W 0 and 1
};

#endif // AUDIO_OBJECT_INC_HPP
