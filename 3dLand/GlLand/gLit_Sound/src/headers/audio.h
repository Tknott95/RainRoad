#include<cstdio>
// #include<cstdint>
#include<cstring> /* for strncmp */

//#include<vector>
#include<fstream>

/* OpenAL */
#include <AL/al.h>
#include <AL/alc.h>

using namespace std;

struct Wav {
  uint8_t Channels;
  int32_t SampleRate;
  uint8_t BitsPerSample;
};
    // Wav wav;
    // void loadWavFile(const char* _path, Wav _wav);
// class Audio {
//   private:
//     // Wav wav;
//     // void loadWavFile(const char* _path, Wav _wav);

//   public:
//     Audio();
//     virtual ~Audio();

//     void Update();
// };

class Audio {
  private:
    

  public:
    Audio();
};