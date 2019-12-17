// liman324@yandex.ru rcl-radio.ru


#ifndef PT2033_H
#define PT2033_H

#define PT2033_address 0b1000100


#include <Arduino.h>
class PT2033
{
  public:
    PT2033();
        void setVolume(int vol); //  int 0...63     
	void setAttL(int att_l); //  int 0...31       
	void setAttR(int att_r); //  int 0...31     
        void setAttS(int att_s); //  int 0...31
        void setIn(int in, int loud, int loud_gain);   
         // int 0...3, int 0...1, int 0...3
        void setBass(int bass); // -7...+7
        void setTreble(int treb); //  -7...+7
	
  private:
	void writeWire(char a);
};
	
#endif //PT2033_H
