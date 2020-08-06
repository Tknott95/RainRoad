#include <AL/al.h>
#include <AL/alc.h>

/* @TODO make all public names Uppercase and not CamelCase */
class Audio {
  private:
    Audio();
    virtual ~Audio();

  public:
    void Update();
};
