//************************************************************/
//
//	Data Format Header
//
//	Outlines the SPXDataFormat class, which describes the 
//	formats available for experimental data. 
//	The options are:
//
//		spectrum_t1s 	(DF_SPECTRUM_T1S)
//		spectrum_t1a 	(DF_SPECTRUM_T1A)
//		spectrum_t2s 	(DF_SPECTRUM_T2S)
//		spectrum_t2a 	(DF_SPECTRUM_T2A)
//		herapdf			(DF_HERAPDF)
//
//	@Author: 	Joe Gibson - CERN ATLAS
//	@Date:		08.10.2014
//
//************************************************************/

#include <iostream>
#include <sstream>

#include "SPXDataFormat.h"
#include "SPXException.h"

//Class name for debug statements
const std::string cn = "SPXDataFormat::";

//Must define the static debug variable in the implementation
bool SPXDataFormat::debug;

//Constructs an SPXDataFormat object with a given string (effectively
//	calls the Parse() method on the input string)
SPXDataFormat::SPXDataFormat(std::string s) {
	this->Clear();
	this->Parse(s);
}

//Takes a string argument in the form:
//	
//	spectrum_t1s 	XOR
//	spectrum_t1a 	XOR
//	spectrum_t2s 	XOR
//	spectrum_t2a 	XOR
//	herapdf
//
// Sets the format based on the input string
void SPXDataFormat::Parse(std::string s) {
	std::string mn = "Parse: ";
	
	if(debug) std::cout << cn << mn << "Parsing configuration string: " << s << std::endl;
	
	//Clear the format each time it is parsed
	this->Clear();
	
	if(!s.compare("spectrum_t1s")) {
		if(debug) std::cout << cn << mn << "Successfully matched format string: \"spectrum_t1s\"" << std::endl;
		format = DF_SPECTRUM_T1S;
		if(debug) std::cout << cn << mn << "Data Format successfully set to \"spectrum_t1s\"" << std::endl;
	}
	else if(!s.compare("spectrum_t1a")) {
		if(debug) std::cout << cn << mn << "Successfully matched format string: \"spectrum_t1a\"" << std::endl;
		format = DF_SPECTRUM_T1A;
		if(debug) std::cout << cn << mn << "Data Format successfully set to \"spectrum_t1a\"" << std::endl;
	}
	else if(!s.compare("spectrum_t2s")) {
		if(debug) std::cout << cn << mn << "Successfully matched format string: \"spectrum_t2s\"" << std::endl;
		format = DF_SPECTRUM_T2S;
		if(debug) std::cout << cn << mn << "Data Format successfully set to \"spectrum_t2s\"" << std::endl;
	}
	else if(!s.compare("spectrum_t2a")) {
		if(debug) std::cout << cn << mn << "Successfully matched format string: \"spectrum_t2a\"" << std::endl;
		format = DF_SPECTRUM_T2A;
		if(debug) std::cout << cn << mn << "Data Format successfully set to \"spectrum_t2a\"" << std::endl;
	}
	else if(!s.compare("herapdf")) {
		if(debug) std::cout << cn << mn << "Successfully matched format string: \"herapdf\"" << std::endl;
		format = DF_HERAPDF;
		if(debug) std::cout << cn << mn << "Data Format successfully set to \"herapdf\"" << std::endl;
	}
	else {
		format = DF_INVALID;
		
		std::ostringstream oss;
		oss << "Incorrect Data Format: Unrecognized format option: \"" << s << "\" is invalid";
		throw SPXINIParseException("DATA", "data_format", oss.str());
	}
}

//Print displays the output of ToString to the console
void SPXDataFormat::Print(void) {
	std::string mn = "Print: ";
	std::cout << this->ToString() << std::endl;
}

//ToString does the opposite of Parse: it assembles a string based on
// the object's format data
std::string SPXDataFormat::ToString(void) {
	std::string mn = "ToString: ";
	
	//Empty style
	if(this->IsEmpty()) {
		return "";
	}
	
	//Check for validity
	if(!this->IsValid()) {
		return "INVALID_DATA_FORMAT";
	}
	
	if(format == DF_SPECTRUM_T1S) {
		return "Spectrum T1S";
	}
	if(format == DF_SPECTRUM_T1A) {
		return "Spectrum T1A";
	}
	if(format == DF_SPECTRUM_T2S) {
		return "Spectrum T2S";
	}
	if(format == DF_SPECTRUM_T2A) {
		return "Spectrum T2A";
	}
	if(format == DF_HERAPDF) {
		return "HERAPDF";
	}
	
	return "INVALID_DATA_FORMAT";
}

//Determines whether the band format is empty or not
bool SPXDataFormat::IsEmpty(void) {
	std::string mn = "IsEmpty: ";
	
	return !(bool)format;
}

//Determines the validity of the band format
bool SPXDataFormat::IsValid(void) {
	std::string mn = "IsValid: ";
	
	//Empty style: valid, but empty
	if(this->IsEmpty()){
		if(debug) std::cout << cn << mn << "Data Format is empty" << std::endl;
		return true;
	}
	
	if(format == DF_INVALID) {
		if(debug) std::cout << cn << mn << "Data Format is invalid: Set to DF_INVALID (-1)" << std::endl;
		return false;
	}
	
	if(format == DF_SPECTRUM_T1S) {
		return true;		
	} else if(format == DF_SPECTRUM_T1A) {
		return true;		
	} else if(format == DF_SPECTRUM_T2S) {
		return true;		
	} else if(format == DF_SPECTRUM_T2A) {
		return true;		
	} else if(format == DF_HERAPDF) {
		return true;	
	} else {
		if(debug) std::cout << cn << mn << "Data format is invalid: Set to unknown value: " << format << std::endl;
		return false;
	}
}

