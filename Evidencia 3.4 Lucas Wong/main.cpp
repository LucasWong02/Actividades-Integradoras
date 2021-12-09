#include <iostream>
#include <fstream>
#include "MaxHeap.h"
#include "RegistroIP.h"
#include "RegistroCantIP.h"
#include "ReportesIP.h"

int main(){
  ReportesIP<RegistroIP> myHeap;
  myHeap.loadData();
  myHeap.heapSort();
  myHeap.writeData();
  //myHeap.printReportesIP();

  MaxHeap<RegistroCantIP> equal(myHeap.getSize());
  equal.loadData();
  //equal.printMaxHeap();
  equal.get5Up();
}