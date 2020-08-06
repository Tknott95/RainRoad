#include "../headers/audio.h"

void Audio::loadWavFile(ifstream& _file, 
                    uint8_t& _channels,
                    int32_t& _sampleRate,
                    uint8_t& _bitsPerSample,
                    ALsizei& _size) {

};

Audio::Audio() {
  printf(" Audio Initialized...");
};

Audio::~Audio() {
  /* Delete all audio buffers here */
};

void Audio::Update() {
  /* FixedUpdate loop also? Better cals running both */
};