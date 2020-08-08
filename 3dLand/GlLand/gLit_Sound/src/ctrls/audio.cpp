#include "../headers/audio.h"

Audio::Audio() {
  printf("\n   \e[2;39;40m Audio Initialized...\e[0m\n");

  this->openALDevice = alcOpenDevice(nullptr);
  if(!this->openALDevice) printf("\n\e[0;31;40m openAL -> ERROR opening openAL device ERROR\e[0m");

  enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
  if(!enumeration) printf("\n\e[0;31;40m openAL -> ERROR enumeration ERROR\e[0m");

  listAudioDevices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));

  wavData = loadWavFile("assets/audio/loop94.wav", wav);

  alGetError();
  openALContext = alcCreateContext(this->openALDevice, NULL);
  alcMakeContextCurrent(openALContext);
  if (!alcMakeContextCurrent(openALContext)) printf("\n\e[0;31;40m OpenAL -> makeContextCurr ERROR \e[0m");


  if(wav.Channels == 1 && wav.BitsPerSample == 8)       format = AL_FORMAT_MONO8;
  else if(wav.Channels == 1 && wav.BitsPerSample == 16) format = AL_FORMAT_MONO16;
  else if(wav.Channels == 2 && wav.BitsPerSample == 8)  format = AL_FORMAT_STEREO8;
  else if(wav.Channels == 2 && wav.BitsPerSample == 16) format = AL_FORMAT_STEREO16;

  ALfloat camListenerOri[] = { 0.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f };
  alListener3f(AL_POSITION, 0, 0, 0.0f);
  alListener3f(AL_VELOCITY, 0, 0, 0);
  alListenerfv(AL_ORIENTATION, camListenerOri);

  /* Source is called via> ID */
  alGenSources((ALuint)1, &source);
  alSourcef(source, AL_PITCH, 1);
  alSourcef(source, AL_GAIN, 1);
  alSource3f(source, AL_POSITION, 0, 0, 0);
  alSource3f(source, AL_VELOCITY, 0, 0, 0);
  alSourcei(source, AL_LOOPING, AL_FALSE);

  alGenBuffers((ALuint)1, &bufferID);
  alBufferData(bufferID, format, wavData, wav.Size, wav.SampleRate);

  alSourcei(source, AL_BUFFER, bufferID);

  state = AL_PLAYING;



};

Audio::~Audio() {
  alDeleteSources(1, &source);
  alDeleteBuffers(1, &bufferID);
  alcDestroyContext(this->openALContext);
  alcCloseDevice(this->openALDevice);
};

void Audio::Update() {
  /* FixedUpdate loop also? Better cals running both */
  alSourcePlay(source);

  alGetSourcei(source, AL_SOURCE_STATE, &state);
  while (state == AL_PLAYING) alGetSourcei(source, AL_SOURCE_STATE, &state);
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