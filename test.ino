#include <Wire.h>
#include <PT2033.h>
  PT2033 pt;
  
void setup(){ 
  Serial.begin(9600);Wire.begin();
  audio();
}

void loop(){}

void audio(){
  pt.setVolume(55);  // громкость 0...63       
  pt.setAttL(0);     // аттенюатор L 0...31     
  pt.setAttR(0);     // аттенюатор R 0...31
  pt.setAttS(0);    // аттенюатор S 0...31

  pt.setIn(0,0,0); // вход 0...3, тонкомпенсация 1 вкл 0 выкл, усиление 0...3
  pt.setBass(0);       // тембр НЧ -7...+7
  pt.setTreble(0);     // тембр ВЧ -7...+7
}
