#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TSystem.h"


void histos_ST2()

{

	//float norm;

	TFile* f1 = new TFile("resultados_M60_L00010.root","Read");
	TFile* f2 = new TFile("ST_histos.root","Recreate");

	TH1F* h1 = (TH1F*) f1->Get("ST_t_S");
	h1->SetName("SplusB");

	TH1F* h2 = (TH1F*) f1->Get("ST_S");
	h1->SetName("Se#tilde{n}al");

	TH1F* h3 = (TH1F*) f1->Get("ST_t");
	h1->SetName("Background");

	gStyle->SetLegendBorderSize(0);	

	TCanvas *c1 = new TCanvas("c1","",600,400);

	c1->SetBottomMargin(0.2);
	c1->SetLeftMargin(0.2);
	
	h1->SetTitle("ST para m_{S}=60GeV, #lambda_{hS}=0.001");
	h1->SetMarkerColor(kBlue+1);
	h1->SetMarkerStyle(21);
	h1->SetLineColor(kBlue+1);
	h1->SetLineWidth(2);
	h1->SetTitleSize(0.055,"XY");
	h1->SetLabelSize(0.055,"XY");
	h1->GetYaxis()->SetTitle("Eventos");
	//norm=h1->GetMaximum();
	//h1->Scale(1.0/norm);
	//h1->SetStats();
	h1->Draw();

	// h2->SetTitle("ST signal");
	h2->SetMarkerColor(kRed+1);
	h2->SetMarkerStyle(22);
	h2->SetLineColor(kRed+1);
	h2->SetLineWidth(2);
	//norm=h2->GetMaximum();
	//h2->Scale(1.0/norm);
	//h2->SetStats();
	h2->Draw("same");

	//h3->SetTitle("ST background");
	h3->SetMarkerColor(kGreen+2);
	h3->SetMarkerStyle(23);
	h3->SetLineColor(kGreen+2);
	h3->SetLineWidth(2);
	//norm=h3->GetMaximum();
	//h3->Scale(1.0/norm);
	//h3->SetStats();
	h3->Draw("same");


	leg1 = new TLegend(0.55,0.65,0.89,0.89);
 	leg1->AddEntry(h1,"Se#tilde{n}al + Background","l");
	leg1->AddEntry(h2,"Se#tilde{n}al","l");
	leg1->AddEntry(h3,"Background","l");
	leg1->Draw();

	f2->cd();
	c1->Write();

}

