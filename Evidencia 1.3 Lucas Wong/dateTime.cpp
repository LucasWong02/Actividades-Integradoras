#include "dateTime.h"

dateTime::dateTime(std::string mes, int dia, int horas, int minutos, int segundos) {
  dateStruct.tm_sec = segundos;
  dateStruct.tm_min = minutos;
  dateStruct.tm_hour = horas;
  dateStruct.tm_mday = dia;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i]==mes)
      dateStruct.tm_mon = i;
  }
  min=minutos;
  seg=segundos;
  dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct);
}

dateTime::dateTime(){
  dateStruct.tm_sec = 0;
  dateStruct.tm_min = 0;
  dateStruct.tm_hour = 0;
  dateStruct.tm_mday = 0;
  dateStruct.tm_mon = 1;

  dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct);
}

time_t dateTime::getDate() {
  return date;
}

bool dateTime::operator==(const dateTime &other) {
  return this->date == other.date;
}

bool dateTime::operator!=(const dateTime &other) {
  return this->date != other.date;
}

bool dateTime::operator>(const dateTime &other) {
  return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other) {
  return this->date < other.date;
}
//Se añade esta sobrecarga de operador para el ordenamiento
bool dateTime::operator<=(const dateTime &other) {
  return this->date <= other.date;
}
int dateTime::getMin(){
  return min;
}
int dateTime::getSeg(){
  return seg;
}