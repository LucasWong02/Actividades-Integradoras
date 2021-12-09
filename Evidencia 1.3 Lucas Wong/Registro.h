#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include "dateTime.h"

using namespace std;

class Registro {
  private:
    dateTime fechaHora;
    string mes;
    string dia;
    string hora;
    string ip;
    string falla;

  public:
    Registro(string mes, string dia, string hora, string ip, string falla, dateTime fechaHora);
    dateTime getFechaHora();
    string getMes();
    string getDia();
    string getHora();
    string getIp();
    string getFalla();
};

#endif //_REGISTRO_H_