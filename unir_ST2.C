#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TSystem.h"


void unir_ST2()

{

	float norm;

	TFile* f1 = new TFile("resultados_M60_L00010.root","Read");
	TFile* f2 = new TFile("resultados_M60_L00060.root","Read");
	TFile* f3 = new TFile("resultados_M60_L00160.root","Read");


	TFile* f6 = new TFile("ST_unidosM60.root","Recreate");

	TH1F* h1 = (TH1F*) f1->Get("ST_t_S");
	h1->SetName("M60L00010");

	TH1F* h2 = (TH1F*) f2->Get("ST_t_S");
	h2->SetName("M60L00060");

	TH1F* h3 = (TH1F*) f3->Get("ST_t_S");
	h3->SetName("M60L00160");	


	TCanvas *c1 = new TCanvas("c1","",600,400);
	c1->cd();

	h1->SetTitle("ST signal plus background M=60 GeV");
	h1->SetMarkerColor(1);
	h1->SetMarkerStyle(2);
	//norm=h1->GetMaximum();
	//h1->Scale(1.0/norm);
	//h1->SetStats();
	h1->Draw();
	c1->Update();


	h2->SetTitle("ST signal plus background");
	h2->SetMarkerColor(2);
	h2->SetMarkerStyle(2);
	h2->SetLineColor(2);
	h2->Draw("same");
	c1->Update();

	h3->SetTitle("ST signal plus background");
	h3->SetMarkerColor(3);
	h3->SetMarkerStyle(2);
	h3->SetLineColor(3);
	h3->Draw("same");
	c1->Update();

 

	leg1 = new TLegend(0.55,0.80,0.9,0.9);
 	leg1->AddEntry(h1,"L=0.001","f");
	leg1->AddEntry(h2,"L=0.006","f");
	leg1->AddEntry(h3,"L=0.016","f");
	leg1->Draw();

	f6->cd();
	c1->Write();


return;
}
