#include "../headers/audio.h"


Audio::Audio() {
  printf("\n   \e[2;39;40m Audio Initialized...\e[0m\n");

  ALCdevice* openALDevice = alcOpenDevice(nullptr);
  if(!openALDevice) printf("\n\e[0;31;40m Wav -> ERROR opening openAL device ERROR\e[0m");

  loadWavFile("assets/audio/loop94.wav", wav);
};

Audio::~Audio() {
  /* Delete all audio buffers here */
};

void Audio::Update() {
  /* FixedUpdate loop also? Better cals running both */
};


void Audio::loadWavFile(const char* _path, Wav _wav) {
  /* Will use Third Party Lib until M.V.P then will refactor */
  char buffer[4];

  ifstream _file(_path);

  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> RIFF read ERROR \e[0m");
  if(strncmp(buffer, "RIFF", 4) != 0) printf("\n\e[0;31;40m Wav -> not valid .wav\n   HEADER DOESN'T BEGIN W/ RIFF \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> size of file read ERROR \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> WAVE read ERROR \e[0m");
  if(strncmp(buffer, "WAVE", 4) != 0) printf("\n\e[0;31;40m Wav -> not valid .wav\n   HEADER DOESN'T CONTAIN WAVE \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> fmt/0 read ERROR \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> fmt data chunk(16) read ERROR \e[0m");
  if(!_file.read(buffer, 2)) printf("\n\e[0;31;40m Wav -> PCM read ERROR \e[0m");
  if(!_file.read(buffer, 2)) printf("\n\e[0;31;40m Wav -> # of channels read ERROR \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> sample rate read ERROR \e[0m");

};