
#ifndef __RESIGSTRO_H
#define __RESIGSTRO_H
#include <string>
#include <iostream>
#include "dateTime.h"
using namespace std;

//Declaracion de la clase
class Registro {
public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string ip, std::string falla, dateTime fechaHora);
    dateTime getFechaHora();
    std::string getMes();
    std::string getDia();
    std::string getHora();
    std::string getIp();
    std::string getFalla();
private:
    dateTime fechaHora;
    std::string mes;
    std::string dia;
    std::string hora;
    std::string ip;
    std::string falla;
};

#endif

