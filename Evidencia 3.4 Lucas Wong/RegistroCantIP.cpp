#include "RegistroCantIP.h"

RegistroCantIP::RegistroCantIP(){
  ip = "";
  cant=0;
}
//Objeto registro para separar datos especificos de los logs
RegistroCantIP::RegistroCantIP(std::string dat, int Cantidad, long int Sum) {
  ip = dat;
  cant=Cantidad;
  suma=Sum;
}
//Gets para la impresion de datos
std::string RegistroCantIP::getIp(){
  return ip;
}
int RegistroCantIP::getCant(){
  return cant;
}
long int RegistroCantIP::getSuma(){
  return suma;
}