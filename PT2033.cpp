#include <Arduino.h>
#include <Wire.h>
#include "PT2033.h"

PT2033::PT2033(){
	Wire.begin();
}

void PT2033::setVolume(int vol){
  vol = 63 - vol;
  writeWire(vol);
}

void PT2033::setAttL(int att_l){
  att_l = 0b11000000 + att_l;
  writeWire(att_l);
}

void PT2033::setAttR(int att_r){
  att_r = 0b11100000 + att_r;
  writeWire(att_r);
}

void PT2033::setAttS(int att_s){
  att_s = 0b10000000 + att_s;
  writeWire(att_s);
}

void PT2033::setIn(int in, int loud, int loud_gain){
  switch (in){
    case 0:in = 0b00000000;break;
    case 1:in = 0b00000001;break;
    case 2:in = 0b00000010;break;
    case 3:in = 0b00000011;break;
  }
  switch (loud){
    case 1:loud = 0b00000000;break;
    case 0:loud = 0b00000100;break;
  }
  switch (loud_gain){
    case 0:loud_gain = 0b00000000;break;
    case 1:loud_gain = 0b00001000;break;
    case 2:loud_gain = 0b00010000;break;
    case 3:loud_gain = 0b00011000;break; 
  }
  int sw = 0b01000000 + in + loud + loud_gain;
  writeWire(sw);
}

void PT2033::setBass(int bass){
  switch (bass){
    case -7: bass = 0b01100000;break;
    case -6: bass = 0b01100001;break;
    case -5: bass = 0b01100010;break;
    case -4: bass = 0b01100011;break; 
    case -3: bass = 0b01100100;break;
    case -2: bass = 0b01100101;break;
    case -1: bass = 0b01100110;break;
    case 0:  bass = 0b01100111;break;
    case 1:  bass = 0b01101110;break;
    case 2:  bass = 0b01101101;break;
    case 3:  bass = 0b01101100;break;
    case 4:  bass = 0b01101011;break;
    case 5:  bass = 0b01101010;break;
    case 6:  bass = 0b01101001;break;
    case 7:  bass = 0b01101000;break;
  }
  writeWire(bass);
}

void PT2033::setTreble(int treb){
  switch (treb){
    case -7: treb = 0b01110000;break;
    case -6: treb = 0b01110001;break;
    case -5: treb = 0b01110010;break;
    case -4: treb = 0b01110011;break; 
    case -3: treb = 0b01110100;break;
    case -2: treb = 0b01110101;break;
    case -1: treb = 0b01110110;break;
    case 0:  treb = 0b01111111;break;
    case 1:  treb = 0b01111110;break;
    case 2:  treb = 0b01111101;break;
    case 3:  treb = 0b01111100;break;
    case 4:  treb = 0b01111011;break;
    case 5:  treb = 0b01111010;break;
    case 6:  treb = 0b01111001;break;
    case 7:  treb = 0b01111000;break;
  }
  writeWire(treb);
}

void PT2033::writeWire(char a){
  Wire.beginTransmission(PT2033_address);
  Wire.write (a);
  Wire.endTransmission();
}
