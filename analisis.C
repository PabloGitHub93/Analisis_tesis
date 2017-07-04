#include "TSystem.h"

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "external/ExRootAnalysis/ExRootResult.h"
#include <cmath> 
#endif
//---------------------------------------------------------------------

struct MyPlots
{

  TH1 *fDPhiMETJet[3];
};

//////////////////////////////////////////////////////

class ExRootResult;
class ExRootTreeReader;

//------------------------------------------------------------------------------


void GenerarHistogramas(ExRootResult *result, MyPlots *plots)
{
  plots->fDPhiMETJet[0] = result->AddHist1D(
    "DPhiMETJet_Signal", "Delta Phi between MET direction and leading jet",
    "Delta Phi", "frequency",
    100, 0.0, 2*3.1416);

  plots->fDPhiMETJet[1] = result->AddHist1D(
    "DPhiMETJet_background", "Delta Phi between MET direction and leading jet",
    "Delta Phi", "frequency",
    100, 0.0, 2*3.1416);

  plots->fDPhiMETJet[2] = result->AddHist1D(
    "DPhiMETJet_signal_plus_back", "Delta Phi between MET direction and leading jet",
    "Delta Phi", "frequency",
    100, 0.0, 2*3.1416);
}

void Analisis_simu(ExRootTreeReader *treeReader1, ExRootTreeReader *treeReader2, MyPlots *plots)    //Análisis de los eventos -------------------------------
{

TFile* f1 = new TFile("salida.root","Recreate");

f1->cd();
 TTree *signalTree     = new TTree("Signal", "SignalTree");
   TTree *background     = new TTree("BackgroundT", "BackgroundTree");

//TH1F *var1 = new TH1F("var1","var1",100,0.0,500.0);

float var1, var2, var3, var4;        //var1=MET, var2=DeltaPhi(MET,1Jet), var3=DeltaR(MET,1Jet), var4=ST; 
float var12, var22, var32, var42;

signalTree->Branch("var1",&var1,"var1/F");
signalTree->Branch("var2",&var2,"var2/F");
signalTree->Branch("var3",&var3,"var3/F");
signalTree->Branch("var4",&var4,"var4/F");

background->Branch("var1",&var12,"var1/F");
background->Branch("var2",&var22,"var2/F");
background->Branch("var3",&var32,"var3/F");
background->Branch("var4",&var42,"var4/F");

  // Get pointers to branches used in this analysis. Señal
  TClonesArray *branchJetS = treeReader1->UseBranch("Jet");
  TClonesArray *branchMETS = treeReader1->UseBranch("MissingET");
  TClonesArray *branchPartS = treeReader1->UseBranch("Particle");

  // Get pointers to branches used in this analysis. Background
  TClonesArray *branchJetT = treeReader2->UseBranch("Jet");
  TClonesArray *branchMETT = treeReader2->UseBranch("MissingET");
  TClonesArray *branchPartT = treeReader2->UseBranch("Particle");

  Long64_t numberOfEntries1 = treeReader1->GetEntries();
  Long64_t numberOfEntries2 = treeReader2->GetEntries();

  //Declaro los jets
  Jet *jetS;
  Jet *jetT;

//Declaro la MET
  MissingET *metS;
  MissingET *metT;


//Algunas variables
float PhiJet1, PhiMET, DeltaPhi;


//  -----------------------------------------------------------------------------------------------------------
  for(Int_t entry = 0; entry < numberOfEntries1; ++entry)             //Blucle sobre los eventos de la señal
  {
    // Load selected branches with data from specified event
    treeReader1->ReadEntry(entry);
    
    // If event contains at least 1 jet
    if(branchJetS->GetEntries() > 0)
    {
      // Take first jet
      jetS = (Jet*) branchJetS->At(0);
      PhiJet1 = jetS->Phi;
    }

	metS = (MissingET*) branchMETS->At(0);
	var1=metS->MET;
        var2=metS->Phi;
        var3=metS->Eta;
        PhiMET=metS->Phi;

  DeltaPhi = PhiMET-PhiJet1;
  plots->fDPhiMETJet[0]->Fill(DeltaPhi); //usar st en lugar de delta phi
  plots->fDPhiMETJet[2]->Fill(DeltaPhi); 
  var4 = DeltaPhi;

  signalTree->Fill();

  var12 = var1;
  var22 = var2;
  var32 = var3;
  var42 = var4;

  background->Fill();

  }   //Fin blucle sobre los eventos de la señal

  plots->fDPhiMETJet[0]->Sumw2();

  signalTree->Print();
  background->Print();



//  -----------------------------------------------------------------------------------------------------------
  for(Int_t entry = 0; entry < numberOfEntries2; ++entry)             //Blucle sobre los eventos del background
  {
    // Load selected branches with data from specified event
    treeReader2->ReadEntry(entry);
    
    // If event contains at least 1 jet
    if(branchJetT->GetEntries() > 0)
    {
      // Take first jet
      jetT = (Jet*) branchJetT->At(0);
      PhiJet1 = jetT->Phi;
    }

	metT = (MissingET*) branchMETT->At(0);
        PhiMET=metT->Phi;

  DeltaPhi = PhiMET-PhiJet1;
  plots->fDPhiMETJet[1]->Fill(DeltaPhi); 
  plots->fDPhiMETJet[2]->Fill(DeltaPhi); 



  }   //Fin blucle sobre los eventos del background

  plots->fDPhiMETJet[1]->Sumw2();

f1->Write();

} //Fin Analisis_simu

//------------------------------------------------------------------------------

void PrintHistograms(ExRootResult *result, MyPlots *plots)
{
  result->Print("png");
}

//------------------------------------------------------------------------------




void analisis(const char *señal, const char *background)
{

gSystem->Load("libDelphes");

  // Creo 2 cadenas para los archivos root tipo árbol
  TChain chain1("Delphes");
  TChain chain2("Delphes");
  chain1.Add(señal);
  chain2.Add(background);

// Creo 2 objetos de la clase ExRootTreeReader
  ExRootTreeReader *treeReader1 = new ExRootTreeReader(&chain1);     
  ExRootTreeReader *treeReader2 = new ExRootTreeReader(&chain2);

ExRootResult *result = new ExRootResult();

MyPlots *plots = new MyPlots;

 GenerarHistogramas(result, plots);


Analisis_simu(treeReader1, treeReader2, plots);

  PrintHistograms(result, plots);

  result->Write("resultados.root");

 cout << "** Exiting..." << endl;

  delete plots;
  delete result;
  delete treeReader1;
  delete treeReader2;

}
