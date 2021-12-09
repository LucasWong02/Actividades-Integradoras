#ifndef __REGISTROIP_H
#define __REGISTROIP_H
#include <string>
#include <iostream>
using namespace std;


//Declaracion de la clase
class RegistroIP {
  public:
      RegistroIP();
      RegistroIP(std::string fechaHora, std::string ip, long int Suma);
      std::string getFullText();
      std::string getIp();
      std::string getFalla();
      long int getSuma();
  private:
      std::string FullText;
      std::string ip;
      long int Suma;
};

#endif