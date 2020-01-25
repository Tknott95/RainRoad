#include "../../headers/utils/audio.h"

void Audio::init() {
  if (!this->_bgMusic.openFromFile("utils/audio/bg/DOS-88-Automatav2.ogg"))  cout << "ERROR: Could not load game - utils/audio/bg/DOS-88-Automatav2.ogg file." << "\n" << endl;
  if (!this->_audio00.openFromFile("utils/audio/laser03.ogg"))  cout << "ERROR: Could not load game - utils/audio/laser03.ogg audio file." << "\n" << endl;
  if(!this->_audio01.openFromFile("utils/audio/doomed_music.wav"))  cout << "ERROR: Could not load game - utils/audio/doomed_music.wav file." << "\n" << endl;

  this->_bgMusic.setPosition(0, 1, 8);
  this->_bgMusic.setVolume(22);
  this->_bgMusic.setLoop(true);
  /* @TODO move bullet sound into bullet class */
  this->_audio00.setPosition(0, 1, 4);
  this->_audio00.setVolume(25);
  this->_audio01.setPosition(0, 1, 4);
  this->_audio01.setVolume(15);
  this->_bgMusic.play();
}

void Audio::playerMoving() {
  /* MOVING SOUND */
}

void Audio::playerShooting() {
  /* SHOOTING SOUND */
  this->_audio00.play();
}

void Audio::shipDestroyed() {

}

void Audio::enemyShooting() {
  /* possibly make this and the player shooting class one class with a type param? */
}

/*
* 1) bgMusic
* 2) player shot sound
* 3) enemy shot sound
* 4) ship del sound
* 5) wanting movement sound (vrrhrhrhhrrghrrrh) -______-
*/

/* @TODO make destruction sound onDel() - move to AudioClass <- from bullet.cpp */
/* @TODO make explosion anim onDel() - move to AudioClass  <- from bullet.cpp */