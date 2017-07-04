#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TSystem.h"


void histos_ST2()

{

	//float norm;

	TFile* f1 = new TFile("resultados_M60_L00160.root","Read");
	TFile* f2 = new TFile("ST_histos.root","Recreate");

	TH1F* h1 = (TH1F*) f1->Get("ST_t_S");
	h1->SetName("SplusB");

	TH1F* h2 = (TH1F*) f1->Get("ST_S");
	h1->SetName("Signal");

	TH1F* h3 = (TH1F*) f1->Get("ST_t");
	h1->SetName("Background");

	TCanvas *c1 = new TCanvas("c1","",600,400);
	c1->cd();
	h1->SetTitle("ST variable for M=60GeV, L=0.016");
	h1->SetMarkerColor(1);
	h1->SetMarkerStyle(2);
	//norm=h1->GetMaximum();
	//h1->Scale(1.0/norm);
	//h1->SetStats();
	h1->Draw();
	c1->Update();

	// h2->SetTitle("ST signal");
	h2->SetMarkerColor(2);
	h2->SetMarkerStyle(2);
	h2->SetLineColor(2);
	//norm=h2->GetMaximum();
	//h2->Scale(1.0/norm);
	//h2->SetStats();
	h2->Draw("same");
	c1->Update();

	//h3->SetTitle("ST background");
	h3->SetMarkerColor(3);
	h3->SetMarkerStyle(2);
	h3->SetLineColor(3);
	//norm=h3->GetMaximum();
	//h3->Scale(1.0/norm);
	//h3->SetStats();
	h3->Draw("same");
	c1->Update();


	leg1 = new TLegend(0.55,0.80,0.9,0.9);
 	leg1->AddEntry(h1,"Signal plus Background","f");
	leg1->AddEntry(h2,"Signal","f");
	leg1->AddEntry(h3,"Background","f");
	leg1->Draw();

	f2->cd();
	c1->Write();

}

