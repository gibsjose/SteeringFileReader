//Test Ratio Style Class
#include <iostream>

#include "SPXRatioStyle.h"

void PrintTest(SPXRatioStyle &rs);

int main(int argc, char *argv[]) {
    std::cout << "Testing Ratio Style Class" << std::endl;
  	
  	if((argc - 1) < 1) {
  		std::cout << "Defaulting to debug mode ON" << std::endl << std::endl;
  		SPXRatioStyle::SetDebug(true);
  	} else {	
	  	//Get debug mode from argument
	  	std::string arg(argv[1]);
  
	  	if(!arg.compare("true")) {	
	  		std::cout << "Debug mode ON" << std::endl << std::endl;
	  		SPXRatioStyle::SetDebug(true);
	  	} else if(!arg.compare("false")) {
	  		std::cout << "Debug mode OFF" << std::endl << std::endl;
	  		SPXRatioStyle::SetDebug(false);
	  	} else {
	  		std::cout << "@usage: <TestName> <debug flag> ( =true OR =false)" << std::endl;
	  		return -1;
	  	}
  	}
    
    std::cout << "RS0" << std::endl;
    SPXRatioStyle rs0;
    PrintTest(rs0);
    
    std::cout << "RS1" << std::endl;
    SPXRatioStyle rs1("data, reference, convolute / data");
    PrintTest(rs1);
    
   	std::cout << "RS2" << std::endl;
   	SPXRatioStyle rs2("data, reference, convolute/data");
    PrintTest(rs2);
    
    std::cout << "RS3" << std::endl;
    SPXRatioStyle rs3("data,reference,convolute/data");
    PrintTest(rs3);
    
    std::cout << "RS4" << std::endl;
    SPXRatioStyle rs4("convolute,data/reference");
    PrintTest(rs4);
    
    std::cout << "RS5" << std::endl;
    SPXRatioStyle rs5(1, 1);
    PrintTest(rs5);
    
    std::cout << "RS6" << std::endl;
    SPXRatioStyle rs6(7, 1);
    PrintTest(rs6);
    
    std::cout << "RS7" << std::endl;
    SPXRatioStyle rs7(5, 4);
    PrintTest(rs7);
    
    //=========================================================================================
    
    std::cout << "BRS0" << std::endl;
    SPXRatioStyle brs0("data, fererence, convolute / data");
    PrintTest(brs0);
    
    std::cout << "BRS1" << std::endl;
    SPXRatioStyle brs1("data reference, convolute / data");
    PrintTest(brs1);
    
    std::cout << "BRS2" << std::endl;
    SPXRatioStyle brs2("data reference convolute / data");
    PrintTest(brs2);
    
    std::cout << "BRS3" << std::endl;
    SPXRatioStyle brs3("convolute, data/data, reference");
    PrintTest(brs3);
    
    std::cout << "BRS4" << std::endl;
    SPXRatioStyle brs4("data, data, reference / data");
    PrintTest(brs4);
    
    std::cout << "BRS5" << std::endl;
    SPXRatioStyle brs5("data, reference, / data");
    PrintTest(brs5);
    
    std::cout << "BRS6" << std::endl;
    SPXRatioStyle brs6(" / data");
    PrintTest(brs6);
    
    std::cout << "BRS7" << std::endl;
    SPXRatioStyle brs7("data/       ");
    PrintTest(brs7);
    
    std::cout << "BRS8" << std::endl;
    SPXRatioStyle brs8("data/ ");
    PrintTest(brs8);
    
    std::cout << "BRS9" << std::endl;
    SPXRatioStyle brs9("junk/more junk");
    PrintTest(brs9);
    
    std::cout << "BRS10" << std::endl;
    SPXRatioStyle brs10(0, 1);
    PrintTest(brs10);
    
    std::cout << "BRS11" << std::endl;
    SPXRatioStyle brs11(8, 1);
    PrintTest(brs11);
    
    std::cout << "BRS12" << std::endl;
    SPXRatioStyle brs12(7, 3);
    PrintTest(brs12);
    
    std::cout << "BRS13" << std::endl;
    SPXRatioStyle brs13(4, 8);
    PrintTest(brs13);
}

void PrintTest(SPXRatioStyle &rs) {
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    
    if(rs.IsEmpty()) {
    	std::cout << "EMPTY" << std::endl;
    }
    
    if(!rs.IsValid()) {
    	std::cout << "INVALID" << std::endl;
    } else {
    	std::cout << "VALID" << std::endl;
    
		rs.Print();
		
		std::cout << "Numerator = " << rs.GetNumerator() << std::endl;
		if(rs.NumeratorContains(RS_DATA)) { std::cout << "[x] DATA" << std::endl; }
		else { std::cout << "[ ] DATA" << std::endl; }
		
		if(rs.NumeratorContains(RS_REFERENCE)) { std::cout << "[x] REFERENCE" << std::endl; }
		else { std::cout << "[ ] REFERENCE" << std::endl; }
		
		if(rs.NumeratorContains(RS_CONVOLUTE)) { std::cout << "[x] CONVOLUTE" << std::endl; }
		else { std::cout << "[ ] CONVOLUTE" << std::endl; }
		
		std::cout << "Denominator = " << rs.GetDenominator() << std::endl;
		if(rs.DenominatorContains(RS_DATA)) { std::cout << "[x] DATA" << std::endl; }
		else { std::cout << "[ ] DATA" << std::endl; }
		
		if(rs.DenominatorContains(RS_REFERENCE)) { std::cout << "[x] REFERENCE" << std::endl; }
		else { std::cout << "[ ] REFERENCE" << std::endl; }
		
		if(rs.DenominatorContains(RS_CONVOLUTE)) { std::cout << "[x] CONVOLUTE" << std::endl; }
		else { std::cout << "[ ] CONVOLUTE" << std::endl; }
    
    }
    
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
}
