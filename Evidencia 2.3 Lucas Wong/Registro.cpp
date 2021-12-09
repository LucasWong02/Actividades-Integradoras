#include "Registro.h"
Registro::Registro() {
    mes = "";
    dia = "";
}
//Objeto registro para separar datos especificos de los logs
Registro::Registro(std::string m, std::string d, std::string h, std::string ad, std::string f, dateTime dat) {
  fechaHora = dat;
  mes = m;
  dia = d;
  hora = h;
  ip = ad;
  falla = f;
}
//Gets para la impresion de datos
dateTime Registro::getFechaHora() {
  return fechaHora;
}
std::string Registro::getMes(){
  return mes;
}
std::string Registro::getDia(){
  return dia;
}
std::string Registro::getHora(){
  return hora;
}
std::string Registro::getIp(){
  return ip;
}
std::string Registro::getFalla(){
  return falla;
}