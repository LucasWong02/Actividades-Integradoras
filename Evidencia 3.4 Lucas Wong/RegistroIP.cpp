#include "RegistroIP.h"

RegistroIP::RegistroIP(){
  FullText = "";
  ip = "";
  Suma=0;
}
//Objeto registro para separar datos especificos de los logs
RegistroIP::RegistroIP(std::string dat, std::string ad, long int suma) {
  FullText = dat;
  ip = ad;
  Suma=suma;
}
//Gets para la impresion de datos
std::string RegistroIP::getFullText(){
  return FullText;
}
std::string RegistroIP::getIp(){
  return ip;
}
long int RegistroIP::getSuma(){
  return Suma;
}