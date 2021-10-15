
#include "audioobject.hpp"

AudioObject::AudioObject(const SampleInfo &info, IAudioData *data)
    : m_audioPos(0), m_audioLength(data->getAudioLength()), m_sampleInfo(info),
      m_audioData(data) {}

bool AudioObject::generateSamples(float *stream, size_t streamLength) {
  m_audioPos = m_audioData->generateSamples(stream, streamLength, m_audioPos,
                                            m_sampleInfo);

  if (m_audioPos == (size_t)-1) {
    m_audioPos = 0;
    return false;
  }

  return true;
}

void AudioObject::setPos(double pos) {
  if (pos < 0.0) {
    pos = 0.0;
  } else if (pos > 1.0) {
    pos = 1.0;
  }

  m_audioPos = posToAbsolutePos(pos);
}

size_t AudioObject::posToAbsolutePos(const double pos) const {
  return (size_t)pos * this->m_audioLength;
}