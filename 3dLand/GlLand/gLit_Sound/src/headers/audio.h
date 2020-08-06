#include <cstdio>
#include <vector>

/* OpenAL */
#include <AL/al.h>
#include <AL/alc.h>

using namespace std;

/* @TODO make all public names Uppercase and not CamelCase */
class Audio {
  private:
    uint8_t channels;
    int32_t sampleRate;
    uint8_t bitsPerSample;
    vector<char> soundData;

    void loadWavFile(ifstream&, uint8_t& ,int32_t& , uint8_t&, ALsizei&); /* file, channels, sampleRate, bitsperSample, size */

  public:
    Audio();
    virtual ~Audio();

    void Update();
};
