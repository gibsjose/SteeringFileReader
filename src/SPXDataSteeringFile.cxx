//************************************************************/
//
//	Data Steering File Header
//
//	Outlines the SPXDataSteeringFile class, which standardizes the
//	format and I/O of the Data portion of the 
//	Steering File Format (SFF), a file format that allows for 
//	interfacing between Grids, Data, and Cross Sections with 
//	the MyAnalysis Program
//
//	@Author: 	Joe Gibson - CERN ATLAS
//	@Date:		06.10.2014
//
//************************************************************/


#include "SPXDataSteeringFile.h"
#include "SPXException.h"

//Class name for debug statements
const std::string cn = "SPXDataSteeringFile::";

void SPXDataSteeringFile::SetDefaults(void) {
	std::string mn = "SetDefaults: ";
	
	if(debug) std::cout << cn << mn << "Setting default Data Steering File data" << std::endl;
	
	/*
	name.clear();
	if(debug) std::cout << cn << mn << "name set to default: \" \"" << std::endl;
	
	xUnits.clear();
	if(debug) std::cout << cn << mn << "xUnits set to default: \" \"" << std::endl;
	
	yUnits.clear();
	if(debug) std::cout << cn << mn << "yUnits set to default: \" \"" << std::endl;
	
	dividedByBinWidth = false;
	if(debug) std::cout << cn << mn << "dividedByBinWidth set to default: \"false\"" << std::endl;
	
	gridPath.clear();
	if(debug) std::cout << cn << mn << "gridPath set to default: \" \"" << std::endl;
	
	generatorID.clear();
	if(debug) std::cout << cn << mn << "generatorID set to default: \" \"" << std::endl;
	
	nTupleID.clear();
	if(debug) std::cout << cn << mn << "nTupleID set to default: \" \"" << std::endl;
	
	lowestOrder.clear();
	if(debug) std::cout << cn << mn << "lowestOrder set to default: \" \"" << std::endl;
	*/
}

//Print the Data Steering File Data in a nice format
void SPXDataSteeringFile::Print(void) {
	/*
	std::cout << "Grid Steering File: " << filename << std::endl;
	std::cout << "\t General Options [GEN]" << std::endl;
	std::cout << "\t\t Debug is " << (debug ? "ON" : "OFF") << std::endl << std::endl;
	std::cout << "\t Description [DESC]" << std::endl;
	std::cout << "\t\t Name: " << name << std::endl << std::endl;
	std::cout << "\t Graphing Options [GRAPH]" << std::endl;
	std::cout << "\t\t X Units: " << xUnits << std::endl;
	std::cout << "\t\t Y Units: " << yUnits << std::endl;
	std::cout << "\t\t Reference Histogram Divided by Bin Width? " << (dividedByBinWidth ? "YES" : "NO") << std::endl;
	std::cout << "\t Grid Options [GRID]" << std::endl;
	std::cout << "\t\t Grid Path: " << gridPath << std::endl;
	std::cout << "\t\t Generator ID: " << generatorID << std::endl;
	std::cout << "\t\t NTuple ID: " << nTupleID << std::endl;
	std::cout << "\t\t Lowest Order: " << lowestOrder << std::endl << std::endl;
	*/
	
	std::cout << "Data Steering File: " << filename << std::endl;
	std::cout << "\t General Options [GEN]" << std::endl;
	std::cout << "\t\t Debug is " << (debug ? "ON" : "OFF") << std::endl << std::endl;
	std::cout << "\t Description [DESC]" << std::endl;
	std::cout << "\t\t Name: " << name << std::endl;
	std::cout << "\t\t Year: " << year << std::endl;
	std::cout << "\t\t Reaction: " << reaction << std::endl << std::endl;
	std::cout << "\t Graphing Options [GRAPH]" << std::endl;
	std::cout << "\t\t Plot Sqrts? " << (plotSqrts ? "YES" : "NO") << std::endl;
	std::cout << "\t\t Sqrts: " << sqrts << std::endl;
	std::cout << "\t\t X Label: " << xLabel << std::endl;
	std::cout << "\t\t Y Label: " << yLabel << std::endl;
	std::cout << "\t\t X Units: " << xUnits << std::endl;
	std::cout << "\t\t Y Units: " << yUnits << std::endl;
	std::cout << "\t\t X Scale: " << xScale << std::endl;
	std::cout << "\t\t Y Scale: " << yScale << std::endl;
}

void SPXDataSteeringFile::Parse(void) {
	std::string mn = "Parse: ";
	
	if(filename.empty()) {
		throw SPXFileIOException(filename, "Empty file string \"\" was given");
	}
	
	//Initialize reader
	reader = new INIReader(filename);
	
	if(reader->ParseError() < 0) {
		delete reader;
		
    	throw SPXFileIOException(filename, "INIReader::INIReader(): ParseError generated when parsing file");
	}
	
	//General Options [GEN]
	debug = reader->GetBoolean("GEN", "debug", debug);
	if(debug) std::cout << cn << mn << "Debug is ON" << std::endl;
	
	//Set Defaults
	this->SetDefaults();
	
	/*
	//Description [DESC]
	name = reader->Get("DESC", "name", "EMPTY");
	if(!name.compare("EMPTY")) {
		if(debug) std::cout << cn << mn << "Grid name was not specified" << std::endl;
		name.clear();
	} else {
		if(debug) std::cout << cn << mn << "Successfully read Grid Name: " << name << std::endl;
	}
	
	//Graping Options [GRAPH]
	xUnits = reader->Get("GRAPH", "x_units", "EMPTY");
	if(!xUnits.compare("EMPTY")) {
		throw SPXINIParseException("GRAPH", "x_units", "You MUST specify the x_units");
	} else {
		if(debug) std::cout << cn << mn << "Successfully read X Units: " << xUnits << std::endl;
	}
	
	yUnits = reader->Get("GRAPH", "y_units", "EMPTY");
	if(!yUnits.compare("EMPTY")) {
		throw SPXINIParseException("GRAPH", "y_units", "You MUST specify the y_units");
	} else {
		if(debug) std::cout << cn << mn << "Successfully read Y Units: " << yUnits << std::endl;
	}
	
	dividedByBinWidth = reader->GetBoolean("GRAPH", "divided_by_bin_width", false);
	if(debug) std::cout << cn << mn << "Divided By Bin Width set to: " << (dividedByBinWidth ? "ON" : "OFF") << std::endl;
	
	//Grid Options [GRID]
	gridPath = reader->Get("GRID", "grid_path", "EMPTY");
	if(!gridPath.compare("EMPTY")) {
		throw SPXINIParseException("GRAPH", "grid_path", "You MUST specify the grid_path");
	} else {
		if(debug) std::cout << cn << mn << "Successfully read Grid Path: " << gridPath << std::endl;
	}
	
	generatorID = reader->Get("GRID", "generator_id", "EMPTY");
	if(!generatorID.compare("EMPTY")) {
		if(debug) std::cout << cn << mn << "Generator ID was not specified" << std::endl;
		name.clear();
	} else {
		if(debug) std::cout << cn << mn << "Successfully read Generator ID: " << generatorID << std::endl;
	}
	
	generatorID = reader->Get("GRID", "generator_id", "EMPTY");
	if(!generatorID.compare("EMPTY")) {
		if(debug) std::cout << cn << mn << "Generator ID was not specified" << std::endl;
		generatorID.clear();
	} else {
		if(debug) std::cout << cn << mn << "Successfully read Generator ID: " << generatorID << std::endl;
	}
	
	nTupleID = reader->Get("GRID", "ntuple_id", "EMPTY");
	if(!nTupleID.compare("EMPTY")) {
		if(debug) std::cout << cn << mn << "NTuple ID was not specified" << std::endl;
		nTupleID.clear();
	} else {
		if(debug) std::cout << cn << mn << "Successfully read NTuple ID: " << nTupleID << std::endl;
	}
	
	lowestOrder = reader->Get("GRID", "lowest_order", "EMPTY");
	if(!lowestOrder.compare("EMPTY")) {
		if(debug) std::cout << cn << mn << "Lowest Order was not specified" << std::endl;
		lowestOrder.clear();
	} else {
		if(debug) std::cout << cn << mn << "Successfully read Lowest Order: " << lowestOrder << std::endl;
	}
	*/
}