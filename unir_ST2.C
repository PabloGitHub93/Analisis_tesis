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

	gStyle->SetLegendBorderSize(0);	
	
	TCanvas *c1 = new TCanvas("c1","",600,400);
	
	c1->SetBottomMargin(0.2);
	c1->SetLeftMargin(0.2);

	h3->SetTitle("ST se#tilde{n}al + background m_{S}=60 GeV");
	h3->SetMarkerColor(kGreen+2);
	h3->SetMarkerStyle(21);
	h3->SetLineColor(kGreen+2);
	h3->SetLineWidth(2);
	h3->SetTitleSize(0.055,"XY");
	h3->SetLabelSize(0.055,"XY");
	h3->GetYaxis()->SetTitle("Eventos");
	h3->Draw("same");
	
	h1->SetTitle("ST se#tilde{n}al + background m_{S}=60 GeV");
	h1->SetMarkerColor(kBlue+1);	
	h1->SetMarkerStyle(22);
	h1->SetLineColor(kBlue+1);
	h1->SetLineWidth(2);
	h1->SetTitleSize(0.055,"XY");
	h1->SetLabelSize(0.055,"XY");
	h1->GetYaxis()->SetTitle("Eventos");
	//norm=h1->GetMaximum();
	//h1->Scale(1.0/norm);
	//h1->SetStats();
	h1->Draw("same");

	h2->SetTitle("ST se#tilde{n}al + background");
	h2->SetMarkerColor(kRed+1);
	h2->SetMarkerStyle(23);
	h2->SetLineColor(kRed+1);
	h2->SetLineWidth(2);
	h2->Draw("same");

	leg1 = new TLegend(0.55,0.65,0.89,0.89);
 	leg1->AddEntry(h1,"#lambda_{hS}=0.001","l");
	leg1->AddEntry(h2,"#lambda_{hS}=0.006","l");
	leg1->AddEntry(h3,"#lambda_{hS}=0.016","l");
	leg1->Draw();

	f6->cd();
	c1->Write();


return;
}
