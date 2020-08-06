#include <cstdio>

/* OpenAL */
#include <AL/al.h>
#include <AL/alc.h>

/* @TODO make all public names Uppercase and not CamelCase */
class Audio {
  private:
    void loadWavFile();

  public:
    Audio();
    virtual ~Audio();

    void Update();
};
