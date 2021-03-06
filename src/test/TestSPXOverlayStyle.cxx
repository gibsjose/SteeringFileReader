//Test Overlay Style Class
#include <iostream>

#include "SPXOverlayStyle.h"

void PrintTest(SPXOverlayStyle &os);

int main(int argc, char *argv[]) {
    std::cout << "Testing Overlay Style Class" << std::endl;
  	
  	if((argc - 1) < 1) {
  		std::cout << "Defaulting to debug mode ON" << std::endl << std::endl;
  		SPXOverlayStyle::SetDebug(true);
  	} else {	
	  	//Get debug mode from argument
	  	std::string arg(argv[1]);
  
	  	if(!arg.compare("true")) {	
	  		std::cout << "Debug mode ON" << std::endl << std::endl;
	  		SPXOverlayStyle::SetDebug(true);
	  	} else if(!arg.compare("false")) {
	  		std::cout << "Debug mode OFF" << std::endl << std::endl;
	  		SPXOverlayStyle::SetDebug(false);
	  	} else {
	  		std::cout << "@usage: <TestName> <debug flag> ( =true OR =false)" << std::endl;
	  		return -1;
	  	}
  	}
    
    std::cout << "OS0" << std::endl;
    SPXOverlayStyle os0;
    PrintTest(os0);
	
	std::cout << "OS1" << std::endl;
    SPXOverlayStyle os1("data");
    PrintTest(os1);
    
    std::cout << "OS2" << std::endl;
    SPXOverlayStyle os2("convolute");
    PrintTest(os2);
    
    std::cout << "OS3" << std::endl;
    SPXOverlayStyle os3("data, reference");
    PrintTest(os3);
    
    std::cout << "OS4" << std::endl;
    SPXOverlayStyle os4("data, convolute");
    PrintTest(os4);
    
    std::cout << "OS5" << std::endl;
    SPXOverlayStyle os5("reference, data");
    PrintTest(os5);
    
    std::cout << "OS6" << std::endl;
    SPXOverlayStyle os6("reference, convolute");
    PrintTest(os6);
    
    std::cout << "OS7" << std::endl;
    SPXOverlayStyle os7("convolute, data");
    PrintTest(os7);
    
    std::cout << "OS8" << std::endl;
    SPXOverlayStyle os8("convolute, reference");
    PrintTest(os8);
    
    std::cout << "OS9" << std::endl;
    SPXOverlayStyle os9("data, reference, convolute");
    PrintTest(os9);
    
    std::cout << "OS10" << std::endl;
    SPXOverlayStyle os10("convolute, reference, data");
    PrintTest(os10);
    
    std::cout << "OS11" << std::endl;
    SPXOverlayStyle os11(1);
    PrintTest(os11);
    
    std::cout << "OS12" << std::endl;
    SPXOverlayStyle os12(5);
    PrintTest(os12);
    
    std::cout << "OS13" << std::endl;
    SPXOverlayStyle os13(7);
    PrintTest(os13);
    
    //=========================================================================================
    
    std::cout << "BOS0" << std::endl;
    SPXOverlayStyle bos0("date");
    PrintTest(bos0);
    
    std::cout << "BOS1" << std::endl;
    SPXOverlayStyle bos1("date, refrence, convolute");
    PrintTest(bos1);
    
    std::cout << "BOS2" << std::endl;
    SPXOverlayStyle bos2("data, convolute, junk");
    PrintTest(bos2);
    
    std::cout << "BOS3" << std::endl;
    SPXOverlayStyle bos3("convoluted");
    PrintTest(bos3);
    
    std::cout << "BOS4" << std::endl;
    SPXOverlayStyle bos4("junk, more junk, 11231dad3da");
    PrintTest(bos4);
    
    std::cout << "BOS5" << std::endl;
    SPXOverlayStyle bos5("   , date, , ,, convolute, , reference      ,  ");
    PrintTest(bos5);
    
    std::cout << "BOS6" << std::endl;
    SPXOverlayStyle bos6("date reference convolute");
    PrintTest(bos6);
    
    std::cout << "BOS7" << std::endl;
    SPXOverlayStyle bos7("convolute date");
    PrintTest(bos7);
    
    std::cout << "BOS8" << std::endl;
    SPXOverlayStyle bos8(8);
    PrintTest(bos8);
    
    std::cout << "BOS9" << std::endl;
    SPXOverlayStyle bos9(-1);
    PrintTest(bos9);
    
    std::cout << "BOS10" << std::endl;
    SPXOverlayStyle bos10(342);
    PrintTest(bos10);
}

void PrintTest(SPXOverlayStyle &os) {
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    
    if(os.IsEmpty()) {
    	std::cout << "EMPTY" << std::endl;
    }
    
    if(!os.IsValid()) {
    	std::cout << "INVALID" << std::endl;
    } else {
    	std::cout << "VALID" << std::endl;
    
		os.Print();
		
		std::cout << "Style = " << os.GetStyle() << std::endl;
		if(os.ContainsData()) { std::cout << "[x] DATA" << std::endl; }
		else { std::cout << "[ ] DATA" << std::endl; }
		
		if(os.ContainsReference()) { std::cout << "[x] REFERENCE" << std::endl; }
		else { std::cout << "[ ] REFERENCE" << std::endl; }
		
		if(os.ContainsConvolute()) { std::cout << "[x] CONVOLUTE" << std::endl; }
		else { std::cout << "[ ] CONVOLUTE" << std::endl; }
    }
    
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
}
