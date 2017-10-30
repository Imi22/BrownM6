#include "BM1DProcess.hh"

BM1DProcess::BM1DProcess(Int_t nP) : 
  nSteps (nP), p0(0.5), p1(0.3), _mu(1), _sigma(0.2),lim(100),lim2(180),_mu2(1.0),_sigma2(2.0)
{
  randomGenerator = new TRandom();
}

BM1DProcess::~BM1DProcess()
{
  ;
}

void BM1DProcess::Init(){
  t.push_back(0.0);  //let's start at t=0, x=0, you can change it if you vant, please use Set methods
  x.push_back(0.0);
}

void BM1DProcess::Run(){
  for (Int_t i = 1;i < nSteps;i++)
    {
      rand1 = randomGenerator->Uniform();
      rand2 = randomGenerator->Gaus(_mu,_sigma);
      rand3 = randomGenerator->Gaus(_mu2,_sigma2);
	if(rand1 < p0) {  //step in time, but no step in x
	  t.push_back(t[i-1] + 1);
	  x.push_back(x[i-1]);
	}
	else if(x[i-2]>=lim2 || lim>=x[i-2])
	{
	//step left or right
		t.push_back(t[i-1] + 1);
	  	x.push_back(x[i-1] + rand2); 
        }
	else
	{
		t.push_back(t[i-1] + 1);
		x.push_back(x[i-1] + rand3);
        }
std::cout<<" "<<i<<" "<<t[i]<<" "<<x[i]<<" "<<rand1<<" "<<rand2<<" "<<rand3<<std::endl;
    }
}

void BM1DProcess::Run(Int_t nofRuns){
for (Int_t j=0; j<nofRuns;j++){
  t.push_back(0.0);  
  x.push_back(0.0);
  std::cout<<j<<" 0 "<<t[j*nSteps]<<" "<<x[j*nSteps]<<std::endl;
  for (Int_t i = 1;i < nSteps;i++)
    {
      rand1 = randomGenerator->Uniform();
      rand2 = randomGenerator->Gaus(_mu,_sigma);
      rand3 = randomGenerator->Gaus(_mu2,_sigma2);
	if(rand1 < p0) {  //step in time, but no step in x
	  t.push_back(t[j*nSteps + i-1] + 1);
	  x.push_back(x[j*nSteps + i-1]);
	}
	else if(x[i-2]>=lim2 || lim>=x[i-2])
	{
		t.push_back(t[j*nSteps + i-1] + 1);
	  	x.push_back(x[j*nSteps + i-1] + rand2);}
	else
	{
		t.push_back(t[j*nSteps + i-1] + 1);
		x.push_back(x[j*nSteps + i-1] + rand3);
        }
std::cout<<nSteps<<" j:"<<j<<" i:"<<i<<" i+j*nSteps:"<<i+j*nSteps<<" t:"<<t[i+j*nSteps]<<" x:"<<x[i+j*nSteps]<<" "<<rand1<<" "<<rand2<<" "<<rand3<<" "<<std::endl;
    }
 }
}


