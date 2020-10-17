#include "../headers/audio.h"

Audio::Audio() {
  printf("\n   \e[2;39;40m Audio Initialized...\e[0m\n");

  wavData = loadWavFile("assets/audio/loop94.wav");

  this->openALDevice = alcOpenDevice(NULL); /* or NULL? read this can cause issues, forget which was which */
  if(!this->openALDevice) printf("\n\e[0;31;40m openAL -> ERROR opening openAL device ERROR\e[0m");

  this->openALContext = alcCreateContext(this->openALDevice, NULL);
  if(!this->openALContext) printf("\n\e[0;31;40m openAL -> ERROR opening openAL context ERROR\e[0m");


  // enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
  // if(!enumeration) printf("\n\e[0;31;40m openAL -> ERROR enumeration ERROR\e[0m");

  listAudioDevices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));

  alcMakeContextCurrent(this->openALContext);
  if(!alcMakeContextCurrent(this->openALContext)) printf("\n\e[0;31;40m OpenAL -> makeContextCurr ERROR \e[0m");
  alGenBuffers(1, &bufferID);

  if(wav.Channels == 1 && wav.BitsPerSample == 8)       format = AL_FORMAT_MONO8;
  else if(wav.Channels == 1 && wav.BitsPerSample == 16) format = AL_FORMAT_MONO16;
  else if(wav.Channels == 2 && wav.BitsPerSample == 8)  format = AL_FORMAT_STEREO8;
  else if(wav.Channels == 2 && wav.BitsPerSample == 16) format = AL_FORMAT_STEREO16;

<<<<<<< HEAD
  ALfloat camListenerOri[] = { 0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 0.0f };
  alListener3f(AL_POSITION, 0, 0, 0.0f);
  alListener3f(AL_VELOCITY, 0, 0, 0);
  alListenerfv(AL_ORIENTATION, camListenerOri);
=======
  // alBufferData(bufferID, format, wavData, wav.Size, wav.SampleRate);
>>>>>>> e779689e8391fe58e07c32b15b0307253643e441

  // alGenSources(1, &sourceID);
  // alSourcef(sourceID, AL_PITCH, 1);
  // alSourcef(sourceID, AL_GAIN, 1);
  // alSource3f(sourceID, AL_POSITION, 0, 0, 0);
  // alSource3f(sourceID, AL_VELOCITY, 0, 0, 0);
  // alSourcei(sourceID, AL_LOOPING, AL_TRUE);
  // alSourcei(sourceID, AL_BUFFER, bufferID);
  // alSourcePlay(sourceID);

  // ALfloat camListenerOri[] = { 0.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f };
  // alListener3f(AL_POSITION, 0, 0, 0.0f);
  // alListener3f(AL_VELOCITY, 0, 0, 0);
  // alListenerfv(AL_ORIENTATION, camListenerOri);

  // // /* Source is called via> ID */
  // // alGenSources(1, &sourceID);


  // state = AL_PLAYING;
  // alGetSourcei(sourceID, AL_SOURCE_STATE, &state);

};

Audio::~Audio() {
  alDeleteSources(1, &sourceID);
  alDeleteBuffers(1, &bufferID);
  alcDestroyContext(this->openALContext);
  alcCloseDevice(this->openALDevice);
  delete[] wavData;
};

void Audio::Update() {
  /* FixedUpdate loop also? Better cals running both */
  
   while (state == AL_PLAYING) alGetSourcei(sourceID, AL_SOURCE_STATE, &state);
};

bool isBigEndian() {
  int a = 1;
  return !((char*)&a)[0];
};

int Audio::convToInt(char* buffer, int len) {
  int a = 0;
  if (!isBigEndian()) {
    for (int i = 0; i<len; i++) ((char*)&a)[i] = buffer[i];
  } else {
    for (int i = 0; i<len; i++) ((char*)&a)[3 - i] = buffer[i];
  };
  return a;
};

char* Audio::loadWavFile(const char* _path) {
  char buffer[4];

  ifstream _file(_path, std::ios::binary);

  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> RIFF read ERROR \e[0m");
  if(strncmp(buffer, "RIFF", 4) != 0) printf("\n\e[0;31;40m Wav -> not valid .wav\n   HEADER DOESN'T BEGIN W/ RIFF \e[0m");

  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> size of file read ERROR \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> WAVE read ERROR \e[0m");
  // if(strncmp(buffer, "WAVE", 4) != 0) printf("\n\e[0;31;40m Wav -> not valid .wav\n   HEADER DOESN'T CONTAIN WAVE \e[0m");
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
  // if(strncmp(buffer, "data", 4) != 0) printf("\n\e[0;31;40m Wav -> NOT VALID WAVE no 'data' tag ERROR \e[0m");
  if(!_file.read(buffer, 4)) printf("\n\e[0;31;40m Wav -> data size read ERROR \e[0m");

  wav.Size = convToInt(buffer, 4);
  // if(_file.eof()) printf("\n\e[0;31;40m Wav -> EOF on wav file ERROR \e[0m");
  // if(_file.fail()) printf("\n\e[0;31;40m Wav -> state set on file ERROR \e[0m");

  // ifstream wavFile02(_path, std::ios::binary);
  char* data = new char[wav.Size];

  _file.read(data, wav.Size);
  return data;
};

void Audio::listAudioDevices(const ALCchar *devices) {
  const ALCchar *device = devices, *next = devices + 1;
  size_t len = 0;

  fprintf(stdout, "Devices list:\n");
  fprintf(stdout, "----------\n");
  while (device && *device != '\0' && next && *next != '\0') {
    fprintf(stdout, "%s\n", device);
    len = strlen(device);
    device += (len + 1);
     next += (len + 2);
  };
  fprintf(stdout, "----------\n");
};