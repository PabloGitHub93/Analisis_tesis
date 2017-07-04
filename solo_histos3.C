#include "TSystem.h"

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "external/ExRootAnalysis/ExRootResult.h"
#include <cmath> 
#endif

//------------------------------------------------------------------------------

struct MyPlots
{
  TH1 *fJetPT[4];
  TH1 *fMissingET[2];
  TH1 *fJetPT_todos[2];
  TH1 *fMETPhi[2];
  TH1 *fMETEta[2];
  TH1 *fsttPT[2];
  TH1 *fsttPhi[2];
  TH1 *fsttEta[2];
  TH1 *fsttDeltaEta[2];
  TH1 *fsttDeltaPhi[2];
  TH1 *fpartPT[2];
  TH1 *fpartEta[2];
  TH1 *fpartPhi[2];
  TH1 *fpartPID[2];
//Ahora los histogramas 2d ¡Revisar!
  TH2 *fEtaPT[2];
  TH2 *fPhiPT[2];
  TH1 *fDeltaRSS;
  TH1 *fDeltaRSJet;
  TH1 *fDeltaRMETJet[2];
  TH1 *fST[2];
  TH1 *fDPhiMETJet[2];
};

//----------------------------------------------------------------------------

class ExRootResult;
class ExRootTreeReader;

//------------------------------------------------------------------------------
void GenerarHistogramas(ExRootResult *result, MyPlots *plots)
{

	// Genero 4 histogramas para los jets 1 y 2 de la señal y el background

  plots->fJetPT[0] = result->AddHist1D(
    "jet_pt_0", "leading jet P_{T} señal",
    "jet P_{T}, GeV/c", "number of jets",
    100, 0.0, 500.0);

  plots->fJetPT[1] = result->AddHist1D(
    "jet_pt_1", "2nd leading jet P_{T} señal",
    "jet P_{T}, GeV/c", "number of jets",
    50, 0.0, 500.0);

  plots->fJetPT[2] = result->AddHist1D(
    "jet_pt_2", "leading jet P_{T} background",
    "jet P_{T}, GeV/c", "number of jets",
    100, 0.0, 500.0);

  plots->fJetPT[3] = result->AddHist1D(
    "jet_pt_3", "2nd leading jet P_{T} background",
    "jet P_{T}, GeV/c", "number of jets",
    50, 0.0, 500.0);

 plots->fMissingET[0] = result->AddHist1D(
    "MissingET_signal", "Energía perdida señal",
    "MET, GeV", "number of events",
    100, 0.0, 500.0);

  plots->fMissingET[1] = result->AddHist1D(
    "MissingET_background", "Energía perdida background",
    "MET, GeV", "number of events",
    100, 0.0, 500.0);

  plots->fJetPT_todos[0] = result->AddHist1D(
    "JetPT_signal", "PT de todos los jets señal",
    "JPT, GeV/c", "number of events",
    100, 0.0, 500.0);
  
  plots->fJetPT_todos[1] = result->AddHist1D(
    "JetPT_background", "PT de todos los jets background",
    "JPT, GeV/c", "number of events",
    100, 0.0, 500.0);

  plots->fMETPhi[0] = result->AddHist1D(
    "METPhi_signal ", "Phi de la energía perdida señal",
    "MPhi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fMETPhi[1] = result->AddHist1D(
    "METPhi_background", "Phi de la energía perdida background",
    "MPhi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fMETEta[0] = result->AddHist1D(
    "METEta_signal", "Eta de la energía perdida señal",
    "MEta", "number of events",
    100, 0.0, 10.0);

  plots->fMETEta[1] = result->AddHist1D(
    "METEta_background", "Eta de la energía perdida background",
    "MEta", "number of events",
    100, 0.0, 10.0);

  plots->fsttPT[0] = result->AddHist1D(
    "S_PT", "PT de las partículas S",
    "PT, GeV/c", "number of events",
    100, 0.0, 600.0);
 
   plots->fsttPT[1] = result->AddHist1D(
    "tT_PT", "PT de las partículas t",
    "PT, GeV/c", "number of events",
    100, 0.0, 600.0);

   plots->fsttPhi[0] = result->AddHist1D(
    "S_Phi", "Phi de las partículas S",
    "Phi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fsttPhi[1] = result->AddHist1D(
    "tT_Phi", "Phi de las partículas t",
    "Phi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fsttEta[0] = result->AddHist1D(
    "S_Eta", "Eta de las partículas S",
    "Eta", "number of events",
    100, 0.0, 10.0);

  plots->fsttEta[1] = result->AddHist1D(
    "tT_Eta", "Eta de las partículas t",
    "Eta", "number of events",
    100, 0.0, 10.0);

  plots->fsttDeltaEta[0] = result->AddHist1D(
    "S_Delta Eta", "Delta Eta de las partículas S",
    "Delta Eta", "number of events",
    100, -3.0, 3.0);

  plots->fsttDeltaEta[1] = result->AddHist1D(
    "tT_Delta Eta", "Delta Eta de las partículas t",
    "Delta Eta", "number of events",
    100, -3.0, 3.0);

  plots->fsttDeltaPhi[0] = result->AddHist1D(
    "S_Delta Phi", "Delta Phi de las partículas S",
    "Delta Phi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fsttDeltaPhi[1] = result->AddHist1D(
    "tT_Delta Phi", "Delta Phi de las partículas t",
    "Delta Phi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fpartPT[0] = result->AddHist1D(
    "part_PT_signal", "PT de todas las partículas señal",
    "PT, Gev/c", "number of events",
    100, 0.0, 150.0);

  plots->fpartPT[1] = result->AddHist1D(
    "part_PT_background", "PT de todas las partículas background",
    "PT, Gev/c", "number of events",
    100, 0.0, 150.0);

  plots->fpartEta[0] = result->AddHist1D(
    "part_Eta_signal", "Eta de todas las partículas señal",
    "Eta", "number of events",
    100, 0.0, 15.0);

  plots->fpartEta[1] = result->AddHist1D(
    "part_Eta_background", "Eta de todas las partículas background",
    "Eta", "number of events",
    100, 0.0, 15.0);

  plots->fpartPhi[0] = result->AddHist1D(
    "part_Phi_signal", "Phi de todas las partículas señal",
    "Phi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fpartPhi[1] = result->AddHist1D(
    "part_Phi_background", "Phi de todas las partículas background",
    "Phi, rad", "number of events",
    100, -3.1416, 3.1416);

  plots->fpartPID[0] = result->AddHist1D(
    "part_PID_signal", "PID de todas las partículas señal",
    "PID", "number of events",
    100, 0.0, 450.0);

 plots->fpartPID[1] = result->AddHist1D(
    "part_PID_background", "PID de todas las partículas background",
    "PID", "number of events",
    100, 0.0, 450.0);

 plots->fEtaPT[0] = result->AddHist2D(
    "part_PT_ETA_s", "PT vs ETA de las partículas S",
    "Eta","PT", 100, 0.0, 10.0, 100, 0.0, 1000.0);           

 plots->fEtaPT[1] = result->AddHist2D(
    "part_PT_ETA_t", "PT vs ETA de las partículas t",
    "Eta", "PT", 100, 0.0, 10.0, 100, 0.0, 1000.0);   

 plots->fPhiPT[0] = result->AddHist2D(
    "part_PT_Phi_s", "PT vs Phi de las partículas S",
    "Phi", "PT", 100, -2*3.1416, 2*3.1416, 100, 0.0, 1000.0);

 plots->fPhiPT[1] = result->AddHist2D(
    "part_PT_Phi_t", "PT vs Phi de las partículas t",
    "Phi", "PT", 100, -2*3.1416, 2*3.1416, 100, 0.0, 1000.0);

  plots->fDeltaRSS = result->AddHist1D(
    "DeltaRSS", "Delta R between S particles",
    "Delta R", "frequency",
    100, 0.0, 50.0);

  plots->fDeltaRSJet = result->AddHist1D(
    "DeltaRSJet", "Delta R between S direction and leading jet",
    "Delta R", "frequency",
    100, 0.0, 10.0);

  plots->fDeltaRMETJet[0] = result->AddHist1D(
    "DeltaRMETJet_S", "Delta R between MET direction and leading jet signal",
    "Delta R", "frequency",
    100, 0.0, 10.0);

  plots->fDeltaRMETJet[1] = result->AddHist1D(
    "DeltaRMETJet_t", "Delta R between MET direction and leading jet background",
    "Delta R", "frequency",
    100, 0.0, 10.0);

  plots->fST[0] = result->AddHist1D(
    "ST_S", "ST signal",
    "ST", "frequency",
    100, 0.0, 1500.0);

  plots->fST[1] = result->AddHist1D(
    "ST_t", "ST background",
    "ST", "frequency",
    100, 0.0, 1500.0);

  plots->fDPhiMETJet[0] = result->AddHist1D(
    "DPhiMETJet_S", "Delta Phi between MET direction and leading jet",
    "Delta Phi", "frequency",
    100, 0.0, 2*3.1416);

  plots->fDPhiMETJet[1] = result->AddHist1D(
    "DPhiMETJet_t", "Delta Phi between MET direction and leading jet",
    "Delta Phi", "frequency",
    100, 0.0, 2*3.1416);
}


void Analisis(ExRootTreeReader *treeReader1, ExRootTreeReader *treeReader2, MyPlots *plots)    //Análisis de los eventos -------------------------------
{

//_______________________________________________________________________________________________________________________________________
TFile* f1 = new TFile("salida.root","Recreate");         //Archivo para almacenar las hojas  MVA
f1->cd();
 TTree *signalTree     = new TTree("Signal", "SignalTree");
   TTree *background     = new TTree("BackgroundT", "BackgroundTree");

//TH1F *var1 = new TH1F("var1","var1",100,0.0,500.0);

float var1, var2, var3, var4;        //var1=MET, var2=DeltaPhi(MET,1Jet), var3=DeltaR(MET,1Jet), var4=ST; 
float var12, var22, var32, var42;
float PhiMET, PhiJet1, EtaMET, EtaJet1, DPhi, DEta;

var4=0;
var42=0;

signalTree->Branch("var1",&var1,"var1/F");
signalTree->Branch("var2",&var2,"var2/F");
signalTree->Branch("var3",&var3,"var3/F");
signalTree->Branch("var4",&var4,"var4/F");

background->Branch("var1",&var12,"var1/F");
background->Branch("var2",&var22,"var2/F");
background->Branch("var3",&var32,"var3/F");
background->Branch("var4",&var42,"var4/F");

//_______________________________________________________________________________________________________________________________________
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

  //Variables
  float ptS1=0;
  float ptS2, ptS; 
  float EtaS1,EtaS2,DeltaEta,EtaS;
  float PhiS1,PhiS2,DeltaPhi,PhiS;
  int i;
  float Etat, EtaT, Phit, PhiT, etaSS, phiSS, etaJet, phiJet;
  float wss=2439000.0/10000.0;
  float wtt=3295500.0/100000.0;
  float DeltaR1, DeltaR2;
  float px, px1, px2, py, py1, py2, pz, pz1, pz2, p;

  //Declaro los jets
  Jet *jetS[3];
  Jet *jetT[3];

//Declaro la MET
  MissingET *metS;
  MissingET *metT;

//Las partículas
  GenParticle *partS[2];
  GenParticle *partT[2];

//Aquí comienza el análisis. Loop sobre los eventos

// Loop over all events. Señal -----------------------------------------------------------------------------------------------------------
  for(Int_t entry = 0; entry < numberOfEntries1; ++entry)
  {
    // Load selected branches with data from specified event
    treeReader1->ReadEntry(entry);

    // If event contains at least 1 jet
    if(branchJetS->GetEntries() > 0)
    {
	if(branchJetS->GetEntries()>=2) //Aquí tomo los dos jets más energéticos
	{
      
      // Take first jet
      jetS[0] = (Jet*) branchJetS->At(0);
      PhiJet1 = jetS[0]->Phi;                     //Para el MVA
      EtaJet1 = jetS[0]->Eta;
      etaJet = jetS[0]->Eta;
      phiJet = jetS[0]->Phi;
      // Plot jet transverse momentum
      plots->fJetPT[0]->Fill(jetS[0]->PT,wss);


	//Tomamos el segundo jet
	jetS[1] = (Jet*) branchJetS->At(1);
	//Lleno el histograma 
	plots->fJetPT[1]->Fill(jetS[1]->PT,wss);
	

	}

	for(Int_t n_jets = 0; n_jets < branchJetS->GetEntries(); ++n_jets) //Aquí tomo el PT de todos los jets
	{
	//Tomamos los jets
	jetS[2] = (Jet*) branchJetS->At(n_jets);
	//Lleno el histograma
	plots->fJetPT_todos[0]->Fill(jetS[2]->PT,wss);
	var4=var4+jetS[2]->PT;
	}

    }  // Aquí termina el condicional sobre si hay jets pero continúa el bucle sobre los eventos
   

    // Veo si el evento contiene energía perdida y grafico

    if(branchMETS->GetEntries() > 0)
    {
      // Hago un bucle sobre las entradas de MET
      for(Int_t n_met = 0; n_met < branchMETS->GetEntries(); ++n_met) 
	{
	//Tomo los eventos
	metS = (MissingET*) branchMETS->At(n_met);
	//Lleno los histogramas
//	var1->Fill(metS->MET);   
	var1=metS->MET;
        PhiMET=metS->Phi;                                    //¡¡¡¡¡¡¡¡¡¡¡¡VARIABLE PARA EL MVA!!!!!!!!!!!!!!!!!!!
	EtaMET=metS->Eta;
	var4=var4+metS->MET;
	plots->fMissingET[0]->Fill(metS->MET,wss);
	plots->fMETPhi[0]->Fill(metS->Phi,wss);  
	plots->fMETEta[0]->Fill(metS->Eta,wss);
	}
    } //Aquí termina el bucle sobre la MET     
EtaS1 =0;
EtaS2=0;
PhiS1=0;
PhiS2=0;  
i=0;                
    if(branchPartS->GetEntries() > 0)
    {
	//Bucle sobre las partículas del evento
	for(Int_t n_part = 0; n_part < branchPartS->GetEntries(); ++n_part)
	{
	partS[0] = (GenParticle*) branchPartS->At(n_part);
	Int_t id = partS[0]->PID;
	plots->fpartPT[0]->Fill(partS[0]->PT,wss); //Lleno el histograma con el PT de todas las partículas
	plots->fpartPhi[0]->Fill(partS[0]->Phi,wss); //Lleno con Phi de todas la partículas 
	plots->fpartEta[0]->Fill(partS[0]->Eta,wss); //Lleno con Eta de todas las partículas
	plots->fpartPID[0]->Fill(partS[0]->PID,wss); //Lleno con el PID de todas las partículas
	
	if(id==26){
	  partS[1] = (GenParticle*) branchPartS->At(n_part);
	  ptS=partS[1]->PT;
	  PhiS=partS[1]->Phi;
	  EtaS=partS[1]->Eta;
	  plots->fsttPT[0]->Fill(ptS,wss);
	  plots->fsttPhi[0]->Fill(PhiS,wss);
	  plots->fsttEta[0]->Fill(EtaS,wss);
	  plots->fEtaPT[0]->Fill(EtaS,ptS1,wss);
	  plots->fPhiPT[0]->Fill(PhiS,ptS1,wss);
	  if(ptS==0){
	  cout<<"Aquí PT vale cero"<<endl;	  
	  }
	  if(i==0){   //Aquí tomo la primera partícula S que aparezca en el evento
	  ptS1=partS[1]->PT;
	  PhiS1=partS[1]->Phi;
	  EtaS1=partS[1]->Eta;
	  px1=partS[1]->Px;
	  py1=partS[1]->Py;
	  pz1=partS[1]->Pz;
	  i++;
	  break;
	} 

	  if(i==1){   //Aquí tomo la segunda partícula S que aparezca en el evento
	  partS[1] = (GenParticle*) branchPartS->At(n_part);
	  ptS2=partS[1]->PT;
	  PhiS2=partS[1]->Phi;
	  EtaS2=partS[1]->Eta;
	  px2=partS[1]->Px;
	  py2=partS[1]->Py;
	  pz2=partS[1]->Pz;
	  i--;
	  break;
	} 
	
	} //Cierro el condicional sobre la part S
	
	
	} //Cierro el for sobre las partículas
	DeltaEta=EtaS1-EtaS2;
	DeltaPhi=PhiS1-PhiS2;
	DeltaR1=sqrt(DeltaPhi*DeltaPhi+DeltaEta*DeltaEta);
	px=px1+px2;
	py=py1+py2;
	pz=pz1+pz2;
	p=sqrt(px*px+py*py+pz*pz);   
	etaSS=-1*log(acos(pz/p)/2);  
	phiSS=atan(py/px);
	// cout<< px <<" "<< py << " " << pz << " " << p << " " << etaSS << phiSS << etaJet << phiJet<<endl;  
	DeltaR2=sqrt((phiSS-phiJet)*(phiSS-phiJet)+(etaSS-etaJet)*(etaSS-etaJet));        
	plots->fsttDeltaEta[0]->Fill(DeltaEta,wss);
	plots->fsttDeltaPhi[0]->Fill(DeltaPhi,wss);
	plots->fDeltaRSS->Fill(DeltaR1);
	plots->fDeltaRSJet->Fill(DeltaR2);
	
    } //Cierro el condicional sobre las partículas
//__________________________________________________________________________________________________________________________________
//Aquí calculo las variables para el archivo para el MVA	
	DPhi=PhiMET-PhiJet1;
	DEta=EtaMET-EtaJet1;
	var3=sqrt(DPhi*DPhi-DEta*DEta);
	var2=PhiMET-PhiJet1;
	signalTree->Fill();
	plots->fDeltaRMETJet[0]->Fill(var3);
	plots->fDPhiMETJet[0]->Fill(var2);
	plots->fST[0]->Fill(var4);
	var4=0;
//___________________________________________________________________________________________________________________________________
  }  //Aquí termina el bucle sobre los eventos de la señal 
   plots->fsttPT[0]->Sumw2();
   plots->fJetPT[0]->Sumw2();
   plots->fJetPT[1]->Sumw2();
   plots->fMissingET[0]->Sumw2();
   plots->fJetPT_todos[0]->Sumw2();
   plots->fMETPhi[0]->Sumw2();
   plots->fMETEta[0]->Sumw2();
   plots->fsttPhi[0]->Sumw2();
   plots->fsttEta[0]->Sumw2();
   plots->fsttDeltaEta[0]->Sumw2();
   plots->fsttDeltaPhi[0]->Sumw2();
   plots->fpartPT[0]->Sumw2();
   plots->fpartEta[0]->Sumw2();
   plots->fpartPhi[0]->Sumw2();
   plots->fpartPID[0]->Sumw2();
   plots->fEtaPT[0]->Sumw2();
   plots->fPhiPT[0]->Sumw2();
   plots->fDeltaRSS->Sumw2();
   plots->fDeltaRSJet->Sumw2();
   plots->fDeltaRMETJet[0]->Sumw2();
   plots->fST[0]->Sumw2();
  plots->fDPhiMETJet[0]->Sumw2();

//_____________________________________________________________________________________________________________________________________________


signalTree->Print();


//_____________________________________________________________________________________________________________________________________________


//Ahora los eventos del background--------------------------------------------------------------------------------------


for(Int_t entry = 0; entry < numberOfEntries2; ++entry)
  {
    // Load selected branches with data from specified event
    treeReader2->ReadEntry(entry);

    // If event contains at least 1 jet
    if(branchJetT->GetEntries() > 0)
    {
	if(branchJetT->GetEntries()>=2) //Aquí tomo los dos jets más energéticos
	{
      
      // Take first jet
      jetT[0] = (Jet*) branchJetT->At(0);

      PhiJet1 = jetT[0]->Phi;                      // Para el MVA
      EtaJet1 = jetT[0]->Eta;
      // Plot jet transverse momentum
      plots->fJetPT[2]->Fill(jetT[0]->PT,wtt);

	//Tomamos el segundo jet
	jetT[1] = (Jet*) branchJetT->At(1);
	//Lleno el histograma 
	plots->fJetPT[3]->Fill(jetT[1]->PT,wtt);
	}

	for(Int_t n_jets = 0; n_jets < branchJetT->GetEntries(); ++n_jets) //Aquí tomo el PT de todos los jets
	{
	//Tomamos los jets
	jetT[2] = (Jet*) branchJetT->At(n_jets);
	//Lleno el histograma
	plots->fJetPT_todos[1]->Fill(jetT[2]->PT,wtt);
	var42=var42+jetT[2]->PT;
	}

    }  // Aquí termina el condicional sobre si hay jets pero continúa el bucle sobre los eventos
   

    // Veo si el evento contiene energía perdida y grafico

    if(branchMETT->GetEntries() > 0)
    {
      // Hago un bucle sobre las entradas de MET
      for(Int_t n_met = 0; n_met < branchMETT->GetEntries(); ++n_met) 
	{
	//Tomo los eventos
	metT = (MissingET*) branchMETT->At(n_met);
	//Lleno los histogramas
	var12 = metT->MET;
        PhiMET=metT->Phi;
	var42=var42+metS->MET;
	plots->fMissingET[1]->Fill(metT->MET,wtt);
	plots->fMETPhi[1]->Fill(metT->Phi,wtt);
	plots->fMETEta[1]->Fill(metT->Eta,wtt);
	}
    } //Aquí termina el bucle sobre la MET

Etat =0;         //declarar arriba
EtaT=0;
Phit=0;
PhiT=0;
    if(branchPartT->GetEntries() > 0)
    {
	//Bucle sobre las partículas del evento
	for(Int_t n_part = 0; n_part < branchPartT->GetEntries(); ++n_part)
	{
	partT[0] = (GenParticle*) branchPartT->At(n_part);
	Int_t id = partT[0]->PID;
	plots->fpartPT[1]->Fill(partT[0]->PT,wtt); //Lleno el histograma con el PT de todas las partículas
	plots->fpartPhi[1]->Fill(partT[0]->Phi,wtt); //Lleno con Phi de todas la partículas 
	plots->fpartEta[1]->Fill(partT[0]->Eta,wtt); //Lleno con Eta de todas las partículas
        plots->fpartPID[1]->Fill(partT[0]->PID,wtt); //Lleno con el PID de todas las partículas
	
	if(id==6 || id==-6){
	partT[1] = (GenParticle*) branchPartT->At(n_part);
	plots->fsttPT[1]->Fill(partT[1]->PT,wtt);
	plots->fsttPhi[1]->Fill(partT[1]->Phi,wtt);
	plots->fsttEta[1]->Fill(partT[1]->Eta,wtt);     //Poner los histogramas 2D

        if(id==6){
	  Etat=partT[1]->Eta;
	  Phit=partT[1]->Phi;
	  plots->fEtaPT[1]->Fill(Etat,partT[1]->PT,wtt);
	  plots->fPhiPT[1]->Fill(Phit,partT[1]->PT,wtt);
	  i++;
	  }
	  if(id==-6){
	  EtaT=partT[1]->Eta;
	  PhiT=partT[1]->Phi;
	  plots->fEtaPT[1]->Fill(EtaT,partT[1]->PT,wtt);
	  plots->fPhiPT[1]->Fill(PhiT,partT[1]->PT,wtt);
	  i=0;
	}
	}	
	} //Cierro el for sobre las partículas

	DeltaEta=Etat-EtaT;       
	plots->fsttDeltaEta[1]->Fill(DeltaEta,wtt);
	DeltaPhi=Phit-PhiT;
	plots->fsttDeltaPhi[1]->Fill(DeltaPhi,wtt);
    } //Cierro el condicional sobre las partículas
//_______________________________________________________________________________________________________________________________________
	var22 = PhiMET-PhiJet1;
	DPhi=PhiMET-PhiJet1;
	DEta=EtaMET-EtaJet1;
	var32=sqrt(DPhi*DPhi-DEta*DEta);
	background->Fill();

	plots->fDeltaRMETJet[1]->Fill(var32);
	plots->fDPhiMETJet[1]->Fill(var22);
	plots->fST[1]->Fill(var42);
	var42=0;
//________________________________________________________________________________________________________________________________________
  }  //Aquí termina el bucle sobre los eventos del background 
   plots->fsttPT[1]->Sumw2();
   plots->fJetPT[2]->Sumw2();
   plots->fJetPT[3]->Sumw2();
   plots->fMissingET[1]->Sumw2();
   plots->fJetPT_todos[1]->Sumw2();
   plots->fMETPhi[1]->Sumw2();
   plots->fMETEta[1]->Sumw2();
   plots->fsttPhi[1]->Sumw2();
   plots->fsttEta[1]->Sumw2();
   plots->fsttDeltaEta[1]->Sumw2();
   plots->fsttDeltaPhi[1]->Sumw2();
   plots->fpartPT[1]->Sumw2();
   plots->fpartEta[1]->Sumw2();
   plots->fpartPhi[1]->Sumw2();
   plots->fpartPID[1]->Sumw2();
   plots->fEtaPT[1]->Sumw2();
   plots->fPhiPT[1]->Sumw2();
   plots->fDeltaRMETJet[1]->Sumw2();
   plots->fST[1]->Sumw2();
  plots->fDPhiMETJet[1]->Sumw2();

background->Print();
f1->Write();

}//-----------___________-----------_______________------------_____________________--------------_______________-----------__________

//------------------------------------------------------------------------------

void PrintHistograms(ExRootResult *result, MyPlots *plots)
{
  result->Print("png");
}

//------------------------------------------------------------------------------

void solo_histos3(const char *señal, const char *background)
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

  Analisis(treeReader1, treeReader2, plots);

  PrintHistograms(result, plots);

  result->Write("histogramas.root");

 cout << "** Exiting..." << endl;

  delete plots;
  delete result;
  delete treeReader1;
  delete treeReader2;
  //delete chain1;
  //delete chain2;
}





  
