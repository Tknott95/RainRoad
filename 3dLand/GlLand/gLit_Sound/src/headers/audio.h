#include<cstdio>
#include<cstring> /* for strncmp */
#include<fstream>
#include <bit>
/* OpenAL */
#include <AL/al.h>
#include <AL/alc.h>

enum class endian
{
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
};

class Audio {
  private:
    Wav wav;
    void loadWavFile(const char* _path, Wav _wav);
  public:
    Audio();
    virtual ~Audio();

    void Update();
};