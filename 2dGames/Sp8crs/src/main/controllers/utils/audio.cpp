#include "../../headers/utils/audio.h"

void Audio::init() {

}

void Audio::playerMoving() {
  /* MOVING SOUND */
}

void Audio::playerShooting() {
  /* SHOOTING SOUND */
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