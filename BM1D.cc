#include <iostream>
#include "BM1DProcess.hh"
#include "Plotter.hh"
#include "TApplication.h"

using namespace std;

int main(int argc, char* argv[])
{
  TApplication App("tapp", &argc, argv);
  Int_t n = 1000;
  BM1DProcess *myBM1DProcess = new BM1DProcess(n);
//  myBM1DProcess->Init();
  myBM1DProcess->SetP1(0.2);
  myBM1DProcess->Run(10);
  Plotter* myPlotter = new Plotter();
  myPlotter->Plot(n, 10, myBM1DProcess->GetT(), myBM1DProcess->GetX());

  App.Run();
  return 0;
}
