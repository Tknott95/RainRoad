#include<cstdio>
#include<cstdint>
#include<vector>
#include<fstream>

/* OpenAL */
#include <AL/al.h>
#include <AL/alc.h>

using namespace std;

struct Wav {
  uint8_t Channels;
  int32_t SampleRate;
  uint8_t BitsPerSample;
  vector<char> SoundData;
};

/* @TODO make all public names Uppercase and not CamelCase */
class Audio {
  private:
    Wav wav;
    void loadWavFile(ifstream& _file, Wav _wav, ALsizei& _size);

  public:
    Audio();
    virtual ~Audio();

    void Update();
};
