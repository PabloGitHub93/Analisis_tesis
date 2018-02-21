#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TSystem.h"
   
void unir_histos()
{

float norm;

   // gSystem->Load("libDelphes");
  //Leo el histograma
  TFile* f1 = new TFile("histogramasM60L0001.root","Read");
  TFile* f2 = new TFile("unidosM60L0001.root","Recreate");

  gStyle->SetLegendBorderSize(0);	
  
  TH1F* h1 = (TH1F*) f1->Get("jet_pt_0");
  h1->SetName("h1");

  TH1F* h2 = (TH1F*) f1->Get("jet_pt_1");
  h2->SetName("h2");
  TH1F* h3 = (TH1F*) f1->Get("jet_pt_2");
  h3->SetName("h3");
  TH1F* h4 = (TH1F*) f1->Get("jet_pt_3");
  h4->SetName("h4");

  TCanvas *c1 = new TCanvas("c1","",600,400);

  c1->SetBottomMargin(0.2);
  c1->SetLeftMargin(0.2);
  
  norm=h1->GetMaximum();
  h1->SetMarkerColor(kBlack);
  h1->SetMarkerStyle(21);
  h1->SetLineColor(kBlack);
  h1->SetLineWidth(2);
  h1->SetTitleSize(0.055,"XY");
  h1->SetLabelSize(0.055,"XY");
  h1->SetTitle("Primer y segundo jet p_{T}");
  h1->Scale(1.0/norm);
  h1->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h1->GetXaxis()->SetTitle("jet p_{T}, GeV/c");
  h1->SetAxisRange(0,350,"X");
  //h1->SetStats();
  h1->Draw();
 
  h2->SetMarkerColor(kRed+1);
  h2->SetMarkerStyle(21);
  h2->SetLineColor(kRed+1);
  norm=h2->GetMaximum();
  h2->Scale(1.0/norm);
//h2->SetStats();
  h2->Draw("same");
 
  norm=h3->GetMaximum();
  h3->SetLineColor(kBlue+1);
  h3->SetMarkerColor(kBlue+1);
  h3->SetMarkerStyle(21);
  h3->Scale(1.0/norm);
//h3->SetStats();
  h3->Draw("same");
 
  h4->SetLineColor(kGreen+2);
  h4->SetMarkerColor(kGreen+2);
  h4->SetMarkerStyle(21);
  norm=h4->GetMaximum();
  h4->Scale(1.0/norm);
//h4->SetStats();
  h4->Draw("same");
  c1->Update();
   leg1 = new TLegend(0.55,0.6,0.89,0.89);
   //leg->SetHeader("","C"); // option "C" allows to center the header
   leg1->AddEntry(h1,"Primer jet Se#tilde{n}al","l");
   leg1->AddEntry(h2,"Segundo jet Se#tilde{n}al","l");
   leg1->AddEntry(h3,"Primer jet background","l");
   leg1->AddEntry(h4,"Segundo jet background","l");
   leg1->Draw();


  c1->SetName("c1");
  f2->cd();
  c1->Write();             //1 y 2 jet de la signal y el background

//---------------------------------------------------------
  TH1F* h5 = (TH1F*) f1->Get("MissingET_signal");
  h5->SetName("h5");

  TH1F* h6 = (TH1F*) f1->Get("MissingET_background");
  h6->SetName("h6");

  TCanvas *c2 = new TCanvas("c2","",600,400);

  c2->SetBottomMargin(0.2);
  c2->SetLeftMargin(0.2);

  h5->SetTitle("Energ#acute{i}a Perdida");
  h5->SetMarkerColor(kBlue+1);
  h5->SetMarkerStyle(21);
  norm=h5->GetMaximum();
  h5->Scale(1.0/norm);
//h5->SetStats();
  h5->SetLineColor(kBlue+1);  
  h5->SetLineWidth(2);
  h5->SetTitleSize(0.055,"XY");
  h5->SetLabelSize(0.055,"XY");
  h5->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h5->SetAxisRange(0,350,"X");  
  h5->Draw();

  h6->SetMarkerColor(kRed+1);
  h6->SetMarkerStyle(21);
  h6->SetLineColor(kRed+1);
  norm=h6->GetMaximum();
  h6->Scale(1.0/norm);
//h6->SetStats();
  h6->SetLineWidth(2);
  h6->Draw("same");

   leg2 = new TLegend(0.55,0.80,0.9,0.9);
   leg2->AddEntry(h5,"Se#tilde{n}al","l");
   leg2->AddEntry(h6,"Background","l");
   leg2->Draw();

  f2->cd();
  c2->Write();            //Energía perdida 
//----------------------------------------------------------

  TH1F* h7 = (TH1F*) f1->Get("JetPT_signal");
  h7->SetName("h7");

  TH1F* h8 = (TH1F*) f1->Get("JetPT_background");
  h8->SetName("h8");

  TCanvas *c3 = new TCanvas("c3","",600,400);

  c3->SetBottomMargin(0.2);
  c3->SetLeftMargin(0.2);
  
  h7->SetTitle("Transverse momentum");
  h7->SetMarkerColor(kBlue+1);
  h7->SetMarkerStyle(21);
  norm=h7->GetMaximum();
  h7->Scale(1.0/norm);
  h7->SetLineColor(kBlue+1);  
  h7->SetLineWidth(2);
  h7->SetTitleSize(0.055,"XY");
  h7->SetLabelSize(0.055,"XY");
  h7->GetYaxis()->SetTitle("#Eventos / Max. #eventos");  
//h7->SetStats();
  h7->Draw();
 
  h8->SetMarkerColor(kRed+1);
  h8->SetMarkerStyle(21);
  h8->SetLineColor(kRed+1);
  h8->SetLineWidth(2);  
  norm=h8->GetMaximum();
  h8->Scale(1.0/norm);
//h8->SetStats();
  h8->Draw("same");
 
   leg3 = new TLegend(0.55,0.80,0.9,0.9);
   leg3->AddEntry(h7,"Signal","l");
   leg3->AddEntry(h8,"Background","l");
   leg3->Draw();
  f2->cd();
  c3->Write();      //PT de los todos los jets
//-----------------------------------------------------------------------

  TH1F* h9 = (TH1F*) f1->Get("METPhi_signal");
  h9->SetName("h9");

  TH1F* h10 = (TH1F*) f1->Get("METPhi_background");
  h10->SetName("h10");

  TCanvas *c4 = new TCanvas("c4","",600,400);

  c4->SetBottomMargin(0.2);
  c4->SetLeftMargin(0.2);
  
  h9->SetTitle("MET #phi");
  h9->SetMarkerColor(kBlue+1);
  h9->SetMarkerStyle(21);
  norm=h9->GetMaximum();
  h9->Scale(1.0/norm);
//h9->SetStats();
  h9->SetLineColor(kBlue+1);  
  h9->SetLineWidth(2);
  h9->SetTitleSize(0.055,"XY");
  h9->SetLabelSize(0.055,"XY");
  h9->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h9->GetXaxis()->SetTitle("#phi, rad");
  h9->SetAxisRange(0.3,1.5,"Y");
  h9->Draw();

  h10->SetMarkerColor(kRed+1);
  h10->SetMarkerStyle(21);
  h10->SetLineColor(kRed+1);
  norm=h10->GetMaximum();
  h10->Scale(1.0/norm);
//h10->SetStats();
  h10->Draw("same");

   leg4 = new TLegend(0.55,0.65,0.89,0.89);
   leg4->AddEntry(h9,"Se#tilde{n}al","l");
   leg4->AddEntry(h10,"Background","l");
   leg4->Draw();

  f2->cd();
  c4->Write();          //Phi de la energía perdida
//--------------------------------------------------------

  TH1F* h11 = (TH1F*) f1->Get("METEta_signal");
  h11->SetName("h11");

  TH1F* h12 = (TH1F*) f1->Get("METEta_background");
  h12->SetName("h12");

  TCanvas *c5 = new TCanvas("c5","",600,400);

  c5->SetBottomMargin(0.2);
  c5->SetLeftMargin(0.2);
  
  h11->SetTitle("MET #eta");
  h11->SetMarkerColor(kBlue+1);
  h11->SetMarkerStyle(21);
  norm=h11->GetMaximum();
  h11->Scale(1.0/norm);
//h11->SetStats();
  h11->SetLineColor(kBlue+1);  
  h11->SetLineWidth(2);
  h11->SetTitleSize(0.055,"XY");
  h11->SetLabelSize(0.055,"XY");
  h11->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h11->GetXaxis()->SetTitle("#eta");    
  h11->Draw();

  h12->SetMarkerColor(kRed+1);
  h12->SetMarkerStyle(21);
  h12->SetLineColor(kRed+1);
  norm=h12->GetMaximum();
  h12->Scale(1.0/norm);
//h12->SetStats();
  h12->Draw("same");

   leg5 = new TLegend(0.55,0.65,0.89,0.89);
   leg5->AddEntry(h11,"Se#tilde{n}al","l");
   leg5->AddEntry(h12,"Background","l");
   leg5->Draw();
  f2->cd();
  c5->Write();       //Eta de la energía perdida
//--------------------------------------------------------

  TH1F* h13 = (TH1F*) f1->Get("S_PT");
  h13->SetName("h13");

  TH1F* h14 = (TH1F*) f1->Get("tT_PT");
  h14->SetName("h14");

  TCanvas *c6 = new TCanvas("c6","",600,400);
  c6->SetBottomMargin(0.2);
  c6->SetLeftMargin(0.2);


  h13->SetTitle("Momento transversal de las Part#acute{i}culas S y top-antitop");
  h13->SetMarkerColor(kBlue+1);
  h13->SetMarkerStyle(21);
  norm=h13->GetMaximum();
  h13->Scale(1.0/norm);
//h13->SetStats();
  h13->SetLineColor(kBlue+1);  
  h13->SetLineWidth(2);
  h13->SetTitleSize(0.055,"XY");
  h13->SetLabelSize(0.055,"XY");
  h13->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h13->GetXaxis()->SetTitle("p_{T}, GeV/c");
  h13->SetAxisRange(0,500,"X");
  h13->Draw();

  h14->SetMarkerColor(kRed+1);
  h14->SetMarkerStyle(21);
  h14->SetLineColor(kRed+1);
  norm=h14->GetMaximum();
  h14->Scale(1.0/norm);
//h14->SetStats();
  h14->Draw("same");

   leg6 = new TLegend(0.55,0.65,0.89,0.89);
   leg6->AddEntry(h13,"Part#acute{i}culas S","l");
   leg6->AddEntry(h14,"top-antitop","l");
   leg6->Draw();
  f2->cd();
  c6->Write();      //PT de las S y t
//---------------------------------------------------

  TH1F* h15 = (TH1F*) f1->Get("S_Phi");
  h15->SetName("h15");

  TH1F* h16 = (TH1F*) f1->Get("tT_Phi");
  h16->SetName("h16");

  TCanvas *c7 = new TCanvas("c7","",600,400);

  c7->SetBottomMargin(0.2);
  c7->SetLeftMargin(0.2);
  
  h15->SetTitle("#phi de las Part#acute{i}culas S y top-antitop");
  h15->SetMarkerColor(kBlue+1);
  h15->SetMarkerStyle(21);
  norm=h15->GetMaximum();
  h15->Scale(1.0/norm);
//h15->SetStats();
  h15->SetLineColor(kBlue+1);  
  h15->SetLineWidth(2);
  h15->SetTitleSize(0.055,"XY");
  h15->SetLabelSize(0.055,"XY");
  h15->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h15->GetXaxis()->SetTitle("#phi, rad");
  h15->SetAxisRange(0.3,1.5,"Y");
  h15->Draw();

  h16->SetMarkerColor(kRed+1);
  h16->SetMarkerStyle(21);
  h16->SetLineColor(kRed+1);
  norm=h16->GetMaximum();
  h16->Scale(1.0/norm);
//h16->SetStats();
  h16->Draw("same");

  leg7 = new TLegend(0.55,0.65,0.89,0.89);
  leg7->AddEntry(h15,"Part#acute{i}culas S","l");
  leg7->AddEntry(h16,"top-antitop","l");
  leg7->Draw();
  f2->cd();
  c7->Write();      // Phi de las S y t
//-------------------------------------------

  TH1F* h17 = (TH1F*) f1->Get("S_Eta");
  h17->SetName("h17");

  TH1F* h18 = (TH1F*) f1->Get("tT_Eta");
  h18->SetName("h18");

  TCanvas *c8 = new TCanvas("c8","",600,400);

  c8->SetBottomMargin(0.2);
  c8->SetLeftMargin(0.2);

  h17->SetTitle("#eta de las Part#acute{i}culas S y top-antitop");
  h17->SetMarkerColor(kBlue+1);
  h17->SetMarkerStyle(21);
  norm=h17->GetMaximum();
  h17->Scale(1.0/norm);
//h17->SetStats();
  h17->SetLineColor(kBlue+1);  
  h17->SetLineWidth(2);
  h17->SetTitleSize(0.055,"XY");
  h17->SetLabelSize(0.055,"XY");
  h17->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h17->GetXaxis()->SetTitle("#eta");    
  h17->Draw();

  h18->SetMarkerColor(kRed+1);
  h18->SetMarkerStyle(21);
  h18->SetLineColor(kRed+1);
  norm=h18->GetMaximum();
  h18->Scale(1.0/norm);
//h18->SetStats();
  h18->Draw("same");

  leg8 = new TLegend(0.55,0.65,0.89,0.89);
  leg8->AddEntry(h17,"Part#acute{i}culas S","l");
  leg8->AddEntry(h18,"top-antitop","l");
  leg8->Draw();
  f2->cd();
  c8->Write();        // Eta de las S y t
//---------------------------------------------

  TH1F* h19 = (TH1F*) f1->Get("S_Delta Eta");
  h19->SetName("h19");

  TH1F* h20 = (TH1F*) f1->Get("tT_Delta Eta");
  h20->SetName("h20");

  TCanvas *c9 = new TCanvas("c9","",600,400);

  c9->SetBottomMargin(0.2);
  c9->SetLeftMargin(0.2);

  h19->SetTitle("#Delta #eta");
  h19->SetMarkerColor(kBlue+1);
  h19->SetMarkerStyle(21);
  norm=h19->GetMaximum();
  h19->Scale(1.0/norm);
//h19->SetStats();
  h19->SetLineColor(kBlue+1);  
  h19->SetLineWidth(2);
  h19->SetTitleSize(0.055,"XY");
  h19->SetLabelSize(0.055,"XY");
  h19->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h19->GetXaxis()->SetTitle("#Delta #eta");
  h19->SetAxisRange(0.3,1.5,"Y");
  h19->Draw();

  h20->SetMarkerColor(kRed+1);
  h20->SetMarkerStyle(21);
  h20->SetLineColor(kRed+1);
  norm=h20->GetMaximum();
  h20->Scale(1.0/norm);
//h20->SetStats();
  h20->Draw("same");

  leg9 = new TLegend(0.55,0.65,0.89,0.89);
  leg9->AddEntry(h19,"Part#acute{i}culas S","l");
  leg9->AddEntry(h20,"top-antitop","l");
  leg9->Draw();
  f2->cd();
  c9->Write();         // Delta Eta
//--------------------------------------------------------

  TH1F* h21 = (TH1F*) f1->Get("S_Delta Phi");
  h21->SetName("h21");

  TH1F* h22 = (TH1F*) f1->Get("tT_Delta Phi");
  h22->SetName("h22");

  TCanvas *c10 = new TCanvas("c10","",600,400);
  c10->cd();
h21->SetTitle("Delta Phi");
  h21->SetMarkerColor(1);
  h21->SetMarkerStyle(2);
  norm=h21->GetMaximum();
  h21->Scale(1.0/norm);
//h21->SetStats();
  h21->Draw();
  c10->Update();
  h22->SetMarkerColor(2);
  h22->SetMarkerStyle(2);
  h22->SetLineColor(kRed);
  norm=h22->GetMaximum();
  h22->Scale(1.0/norm);
//h22->SetStats();
  h22->Draw("same");
  c10->Update();
   leg10 = new TLegend(0.55,0.80,0.9,0.9);
   leg10->AddEntry(h21,"S particle","f");
   leg10->AddEntry(h22,"t particle","f");
   leg10->Draw();
  f2->cd();
  c10->Write();          //Delta Phi
//---------------------------------------------------

  TH1F* h23 = (TH1F*) f1->Get("part_PT_signal");
  h23->SetName("h23");

  TH1F* h24 = (TH1F*) f1->Get("part_PT_background");
  h24->SetName("h24");

  TCanvas *c11 = new TCanvas("c11","",600,400);
  c11->cd();
h23->SetTitle("All particles PT");
  h23->SetMarkerColor(1);
  h23->SetMarkerStyle(2);
  norm=h23->GetMaximum();
  h23->Scale(1.0/norm);
//h23->SetStats();
  h23->Draw();
  c11->Update();
  h24->SetMarkerColor(2);
  h24->SetMarkerStyle(2);
  h24->SetLineColor(kRed);
  norm=h24->GetMaximum();
  h24->Scale(1.0/norm);
//h24->SetStats();
  h24->Draw("same");
  c11->Update();
   leg11 = new TLegend(0.55,0.80,0.9,0.9);
   leg11->AddEntry(h23,"Se#tilde{n}al","f");
   leg11->AddEntry(h24,"Background","f");
   leg11->Draw();
  f2->cd();
  c11->Write();            // PT todas las partículas
//-----------------------------------

  TH1F* h25 = (TH1F*) f1->Get("part_Eta_signal");
  h25->SetName("h25");

  TH1F* h26 = (TH1F*) f1->Get("part_Eta_background");
  h26->SetName("h26");

  TCanvas *c12 = new TCanvas("c12","",600,400);
  c12->cd();
h25->SetTitle("All particles Eta");
  h25->SetMarkerColor(1);
  h25->SetMarkerStyle(2);
  norm=h25->GetMaximum();
  h25->Scale(1.0/norm);
//h25->SetStats();
  h25->Draw();
  c12->Update();
  h26->SetMarkerColor(2);
  h26->SetMarkerStyle(2);
  h26->SetLineColor(kRed);
  norm=h26->GetMaximum();
  h26->Scale(1.0/norm);
//h26->SetStats();
  h26->Draw("same");
  c12->Update();
   leg12 = new TLegend(0.55,0.80,0.9,0.9);
   leg12->AddEntry(h25,"Se#tilde{n}al","f");
   leg12->AddEntry(h26,"Background","f");
   leg12->Draw();
  f2->cd();
  c12->Write();           // Eta todas las partículas
//-------------------------------------------------------

  TH1F* h27 = (TH1F*) f1->Get("part_Phi_signal");
  h27->SetName("h27");

  TH1F* h28 = (TH1F*) f1->Get("part_Phi_background");
  h28->SetName("h28");

  TCanvas *c13 = new TCanvas("c13","",600,400);
  c13->cd();
h27->SetTitle("All particles phi");
  h27->SetMarkerColor(1);
  h27->SetMarkerStyle(2);
  norm=h27->GetMaximum();
  h27->Scale(1.0/norm);
//h27->SetStats();
  h27->Draw();
  c13->Update();
  h28->SetMarkerColor(2);
  h28->SetMarkerStyle(2);
  h28->SetLineColor(kRed);
  norm=h28->GetMaximum();
  h28->Scale(1.0/norm);
//h28->SetStats();
  h28->Draw("same");
  c13->Update();
   leg13 = new TLegend(0.55,0.80,0.9,0.9);
   leg13->AddEntry(h27,"Se#tilde{n}al","f");
   leg13->AddEntry(h28,"Background","f");
   leg13->Draw();
  f2->cd();
  c13->Write();           //   Phi todas las partículas
//-------------------------------------------------------

  TH1F* h29 = (TH1F*) f1->Get("part_PID_signal");
  h29->SetName("h29");

  TH1F* h30 = (TH1F*) f1->Get("part_PID_background");
  h30->SetName("h30");

  TCanvas *c14 = new TCanvas("c14","",600,400);
  c14->cd();
h29->SetTitle("All particles ID");
  h29->SetMarkerColor(1);
  h29->SetMarkerStyle(2);
  norm=h29->GetMaximum();
  h29->Scale(1.0/norm);
//h29->SetStats();
  h29->Draw();
  c14->Update();
  h30->SetMarkerColor(2);
  h30->SetMarkerStyle(2);
  h30->SetLineColor(kRed);
  norm=h30->GetMaximum();
  h30->Scale(1.0/norm);
//h30->SetStats();
  h30->Draw("same");
  c14->Update();
   leg14 = new TLegend(0.55,0.80,0.9,0.9);
   leg14->AddEntry(h29,"Se#tilde{n}al","f");
   leg14->AddEntry(h30,"Background","f");
   leg14->Draw();
  f2->cd();
  c14->Write();    //PID todas las partículas

//------------------------------------------------
TH1F* h31 = (TH1F*) f1->Get("DeltaRSS");
  h31->SetName("h31");

  TH1F* h32 = (TH1F*) f1->Get("DeltaRSJet");
  h32->SetName("h32");

TCanvas *c15 = new TCanvas("c15","",600,400);
  c15->cd();
h31->SetTitle("Delta R");
  h31->SetMarkerColor(1);
  h31->SetMarkerStyle(2);
  norm=h31->GetMaximum();
  h31->Scale(1.0/norm);
//h29->SetStats();
  h31->Draw();
  c15->Update();
  h32->SetMarkerColor(2);
  h32->SetMarkerStyle(2);
  h32->SetLineColor(kRed);
  norm=h32->GetMaximum();
  h32->Scale(1.0/norm);
//h30->SetStats();
  h32->Draw("same");
  c15->Update();
   leg15 = new TLegend(0.55,0.80,0.9,0.9);
   leg15->AddEntry(h31,"Delta R between S particles","f");
   leg15->AddEntry(h30,"Delta R between S direction and leading jet","f");
   leg15->Draw();
  f2->cd();
  c15->Write();    //Delta R




//----------------------------------------------------          

TH1F* h33 = (TH1F*) f1->Get("DeltaRMETJet_S");
  h33->SetName("h33");

  TH1F* h34 = (TH1F*) f1->Get("DeltaRMETJet_t");
  h34->SetName("h34");
  
TCanvas *c16 = new TCanvas("c16","",600,400);
  c16->cd();

  c16->SetBottomMargin(0.2);
  c16->SetLeftMargin(0.2);
  
  h33->SetTitle("#Delta R entre la direcci#acute{o}n de la MET y el jet m#acute{a}s energ#acute{e}tico");
  h33->SetMarkerColor(kBlue+1);
  h33->SetMarkerStyle(21);
  h33->SetLineColor(kBlue+1);
  h33->SetLineWidth(2);
  h33->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h33->GetXaxis()->SetTitle("#Delta R");
  h33->SetTitleSize(0.055,"XY");
  h33->SetLabelSize(0.055,"XY");
  h33->SetAxisRange(0,7,"X");
  norm=h33->GetMaximum();
  h33->Scale(1.0/norm);
 // h33->SetStats();
  h33->Draw();
  c16->Update();
  h34->SetMarkerColor(kRed+1);
  h34->SetMarkerStyle(21);
  h34->SetLineColor(kRed+1);
  norm=h34->GetMaximum();
  h34->Scale(1.0/norm);
//  h34->SetStats();
  h34->Draw("same");
  c16->Update();
   leg16 = new TLegend(0.55,0.80,0.9,0.9);
   leg16->AddEntry(h33,"Delta R. Se#tilde{n}al","l");
   leg16->AddEntry(h34,"Delta R. Background","l");
   leg16->Draw();
  f2->cd();
  c16->Write();    //Delta R entre MET y jet

//-------------------------------------------------------------------------------------------------

  TH1F* h35 = (TH1F*) f1->Get("DPhiMETJet_S");
  h35->SetName("h35");

  TH1F* h36 = (TH1F*) f1->Get("DPhiMETJet_t");
  h36->SetName("h36");

TCanvas *c17 = new TCanvas("c17","",600,400);
  c17->cd();


  c17->SetBottomMargin(0.2);
  c17->SetLeftMargin(0.2);
  
  h35->SetTitle("#Delta #phi entre la direcci#acute{o}n de la MET y el jet m#acute{a}s energ#acute{e}tico");
  h35->SetMarkerColor(kBlue+1);
  h35->SetMarkerStyle(21);
  h35->SetLineColor(kBlue+1);
  h35->SetLineWidth(2);
  h35->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h35->GetXaxis()->SetTitle("#Delta #phi");
  h35->SetTitleSize(0.055,"XY");
  h35->SetLabelSize(0.055,"XY");  
  norm=h35->GetMaximum();
  h35->Scale(1.0/norm);
//  h35->SetStats();
  h35->Draw();
  c17->Update();
  h36->SetMarkerColor(kRed+1);
  h36->SetMarkerStyle(21);
  h36->SetLineColor(kRed+1);
  norm=h36->GetMaximum();
  h36->Scale(1.0/norm);
//  h36->SetStats();
  h36->Draw("same");
  c17->Update();
   leg17 = new TLegend(0.55,0.80,0.9,0.9);
   leg17->AddEntry(h35,"Se#tilde{n}al","l");
   leg17->AddEntry(h36,"Background","l");
   leg17->Draw();
  f2->cd();
  c17->Write();    //Delta Phi entre MET y jet

//--------------------------------------------------------------------------------------------

TH1F* h37 = (TH1F*) f1->Get("ST_S");
  h37->SetName("h37");

  TH1F* h38 = (TH1F*) f1->Get("ST_t");
  h38->SetName("h38");

TCanvas *c18 = new TCanvas("c18","",600,400);
  c18->cd();

  c18->SetBottomMargin(0.2);
  c18->SetLeftMargin(0.2);
  
  h37->SetTitle("ST");
  h37->SetMarkerColor(kBlue+1);
  h37->SetMarkerStyle(21);
  h37->SetLineColor(kBlue+1);
  h37->SetLineWidth(2);
  h37->GetYaxis()->SetTitle("#Eventos / Max. #eventos");
  h37->GetXaxis()->SetTitle("ST");
  h37->SetAxisRange(0,1150,"X");
  norm=h37->GetMaximum();
  h37->Scale(1.0/norm);
//  h37->SetStats();
  h37->Draw();
  c18->Update();
  h38->SetMarkerColor(kRed+1);
  h38->SetMarkerStyle(21);
  h38->SetLineColor(kRed+1);
  norm=h38->GetMaximum();
  h38->Scale(1.0/norm);
//  h38->SetStats();
  h38->Draw("same");
  c18->Update();
   leg18 = new TLegend(0.55,0.80,0.9,0.9);
   leg18->AddEntry(h37,"ST Se#tilde{n}al","l");
   leg18->AddEntry(h38,"ST Background","l");
   leg18->Draw();
  f2->cd();
  c18->Write();    //Delta R entre MET y jet


return;
}
