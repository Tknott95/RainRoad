#include "../headers/audio.h"


Audio::Audio() {
  printf("\n   \e[2;39;40m Audio Initialized...\e[0m\n");

  this->openALDevice = alcOpenDevice(nullptr);
  if(!this->openALDevice) printf("\n\e[0;31;40m Wav -> ERROR opening openAL device ERROR\e[0m");

  char* wavData = loadWavFile("assets/audio/loop94.wav", wav);

  openALContext = alcCreateContext(this->openALDevice, NULL);
  if (!alcMakeContextCurrent(openALContext)) printf("\n\e[0;31;40m OpenAL -> makeContextCurr ERROR \e[0m");

  alGenBuffers(1, &bufferID);

  // if(wav.Channels == 1 && wav.BitsPerSample == 8)       format = AL_FORMAT_MONO8;
  // else if(wav.Channels == 1 && wav.BitsPerSample == 16) format = AL_FORMAT_MONO16;
  // else if(wav.Channels == 2 && wav.BitsPerSample == 8)  format = AL_FORMAT_STEREO8;
  // else if(wav.Channels == 2 && wav.BitsPerSample == 16) format = AL_FORMAT_STEREO16;

  // ALsizei size, freq;
  // ALenum format;
  // ALvoid *data;
  // ALboolean loop = AL_FALSE;
  // loadWAVFile("assets/audio/loop94.wav", &format, &data, &size, &freq, &loop);

  alBufferData(bufferID, format, wavData, wav.Size, wav.BitsPerSample);

  /* Source is called via> ID */
  alGenSources(1, &source);
  alSourcef(source, AL_PITCH, 1);
  alSourcef(source, AL_GAIN, 1);
  alSource3f(source, AL_POSITION, 0, 0, 0);
  alSource3f(source, AL_VELOCITY, 0, 0, 0);
  alSourcei(source, AL_LOOPING, AL_FALSE);

  // alSourcePlay(source);
  // alGetSourcei(source, AL_SOURCE_STATE, &source);
  // while (source == AL_PLAYING) alGetSourcei(source, AL_SOURCE_STATE, &source);

  ALfloat camListenerOri[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
  alListener3f(AL_POSITION, 0, 0, 1.0f);
  alListener3f(AL_VELOCITY, 0, 0, 0);
  alListenerfv(AL_ORIENTATION, camListenerOri);

};

Audio::~Audio() {
  alDeleteSources(1, &source);
  alDeleteBuffers(1, &bufferID);
  alcDestroyContext(this->openALContext);
  alcCloseDevice(this->openALDevice);
};

void Audio::Update() {
  /* FixedUpdate loop also? Better cals running both */
};

int32_t Audio::convToInt(char* buffer, size_t len) {
  int32_t a = 0;
  if(endian::native == endian::little)
    memcpy(&a, buffer, len);
  else
    for(size_t i = 0; i < len; ++i) reinterpret_cast<char*>(&a)[3 - i] = buffer[i];
  return a;
};

char* Audio::loadWavFile(const char* _path, Wav _wav) {
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
  wav.Channels = convToInt(buffer, 2);
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> sample rate read ERROR \e[0m");
  wav.SampleRate = convToInt(buffer, 4);
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> (sampleRate * bitsPerSample * channels) / 8  read ERROR \e[0m");
  if(!_file.read(buffer, 2)) printf("\n\e[0;31;40m Wav -> dafuq ERROR \e[0m");
  if(!_file.read(buffer, 2)) printf("\n\e[0;31;40m Wav -> bits per sample read ERROR \e[0m");
  wav.BitsPerSample = convToInt(buffer, 2);
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> chunk header read ERROR \e[0m");
  if(strncmp(buffer, "data", 4) != 0) printf("\n\e[0;31;40m Wav -> NOT VALID WAVE no 'data' tag ERROR \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> data size read ERROR \e[0m");
  wav.Size = convToInt(buffer, 4);
  if(_file.eof()) printf("\n\e[0;31;40m Wav -> EOF on wav file ERROR \e[0m");
  if(_file.fail()) printf("\n\e[0;31;40m Wav -> state set on file ERROR \e[0m");

  ifstream wavFile02(_path, std::ios::binary);
  char* data = new char[wav.Size];

  wavFile02.read(data, wav.Size);
  return data;
};