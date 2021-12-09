#include "Registro.h"

//Objeto registro para separar datos especificos de los logs
Registro::Registro(string m, string d, string h, string ad, string f, dateTime dat) {
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
string Registro::getMes(){
  return mes;
}
string Registro::getDia(){
  return dia;
}
string Registro::getHora(){
  return hora;
}
string Registro::getIp(){
  return ip;
}
string Registro::getFalla(){
  return falla;
}