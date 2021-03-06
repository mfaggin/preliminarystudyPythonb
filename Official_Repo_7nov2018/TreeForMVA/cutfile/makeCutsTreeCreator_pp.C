#include <Riostream.h>
#include <TFile.h>
#include <AliRDHFCutsD0toKpi.h>
#include <AliRDHFCutsDstoKKpi.h>
#include <AliRDHFCutsDplustoKpipi.h>
#include <TClonesArray.h>
#include <TParameter.h>

#include "makeInputCutsD0toKpi_pp.C"
#include "makeInputCutsDstoKKpi_pp.C"
#include "makeInputCutsDplustoKpipi_pp.C"

Float_t minCent=0.;
Float_t maxCent=100.;


void makeCutsTreeCreator_pp()
{
    Printf("D0 filtering cuts");
    AliRDHFCutsD0toKpi  *looseCutsD0toKpi    = makeInputCutsD0toKpi_pp(0,"D0toKpiFilteringCuts",minCent,maxCent);
    Printf("\n\n");
    Printf("D0 analysis cuts");
    AliRDHFCutsD0toKpi  *analysisCutsD0toKpi = makeInputCutsD0toKpi_pp(1,"D0toKpiAnalysisCuts",minCent,maxCent);
    Printf("\n\n");
    Printf("*************************************************************");
    Printf("Ds filtering cuts");
    AliRDHFCutsDstoKKpi  *looseCutsDstoKKpi    = makeInputCutsDstoKKpi_pp(0,"DstoKKpiFilteringCuts",minCent,maxCent);
    Printf("\n\n");
    Printf("Ds analysis cuts");
    AliRDHFCutsDstoKKpi  *analysisCutsDstoKKpi = makeInputCutsDstoKKpi_pp(1,"DstoKKpiAnalysisCuts",minCent,maxCent);
    Printf("\n\n");
    Printf("*************************************************************");
    Printf("Dplus filtering cuts");
    AliRDHFCutsDplustoKpipi  *looseCutsDplustoKpipi    = makeInputCutsDplustoKpipi_pp(0,"DplustoKpipiFilteringCuts",minCent,maxCent);
    Printf("\n\n");
    Printf("Dplus analysis cuts");
    AliRDHFCutsDplustoKpipi  *analysisCutsDplustoKpipi = makeInputCutsDplustoKpipi_pp(1,"DplustoKpipiAnalysisCuts",minCent,maxCent);
  
    TFile* fout=new TFile("D0DsDplusCuts_pp.root","recreate");
    fout->cd();
    looseCutsD0toKpi->Write();
    analysisCutsD0toKpi->Write();
    looseCutsDstoKKpi->Write();
    analysisCutsDstoKKpi->Write();
    looseCutsDplustoKpipi->Write();
    analysisCutsDplustoKpipi->Write();
    fout->Close();
    
}


