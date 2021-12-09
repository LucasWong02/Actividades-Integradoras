#ifndef __REGISTROCANTIP_H
#define __REGISTROCANTIP_H
#include <string>
#include <iostream>
using namespace std;


//Declaracion de la clase
class RegistroCantIP {
  public:
      RegistroCantIP();
      RegistroCantIP(std::string ip, int cant, long int suma);
      std::string getIp();
      int getCant();
      long int getSuma();
  private:
      std::string ip;
      int cant;
      long int suma;
};
#endif