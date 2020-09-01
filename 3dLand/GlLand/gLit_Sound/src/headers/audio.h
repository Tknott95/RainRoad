#include<cstdio>
#include<cstring> /* for strncmp */
#include<fstream>
#include<vector>
#include <bit>
/* OpenAL */
#include <AL/al.h>
#include <AL/alc.h>
enum class endian {
  #ifdef _WIN32
    little = 0,
    big    = 1,
    native = little
  #else
    little = __ORDER_LITTLE_ENDIAN__,
    big    = __ORDER_BIG_ENDIAN__,
    native = __BYTE_ORDER__
  #endif
};


using namespace std;

struct Wav {
  uint8_t Channels;
  int32_t SampleRate;
  uint8_t BitsPerSample;
  ALsizei Size;
};

class Audio {
  private:
    char* wavData;
    ALCdevice* openALDevice;
    ALCcontext* openALContext;
    ALboolean enumeration;
    ALuint bufferID;
    ALenum format;
    ALuint source;
    ALint state;

    Wav wav;
    // vector<char> soundData;
    int convToInt(char*, int);
    char* loadWavFile(const char* _path);
    void listAudioDevices(const ALCchar *devices);

  public:
    Audio();
    virtual ~Audio();

    void Update();
};