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

#ifndef SPXDATASTEERINGFILE_H
#define SPXDATASTEERINGFILE_H

#include <iostream>

#include "INIReader.h"

typedef enum SPXDataFormat {
	Spectrum = 0,
	HERAPDF = 1
} SPXDataFormat;

class SPXDataSteeringFile {

private:

	//INI Reader
	INIReader *reader;
	
	//Metadata
	std::string filename;
	
	//[GEN]
	bool debug;
	
	//[DESC]
	std::string name;				//Name of Steering Data
	unsigned long year;				//Year
	std::string reaction;			//Reaction name

	//[GRAPH]
	bool plotSqrts;					//@TODO RENAME 'plotSqrts' --> ???
	double sqrts;					//@TODO RENAME 'sqrts' --> ???
	std::string title;				//Data graph title
	std::string xLabel;				//X-Axis label
	std::string yLabel;				//Y-Axis label
	std::string xUnits;				//X-Axis units
	std::string yUnits;				//Y-Axis units
	double xScale;					//X-Axis scale
	double yScale;					//Y-Axis scale
	bool frameXLog;					//Plot the X-axis as logarithmic
	bool frameYLog;					//Plot the Y-Axis as logarithmic
	double frameXMin;				//X-Axis minimum frame
	double frameYMin;				//Y-Axis minimum frame
	bool dividedByBinWidth;			//Whether data has been divided by the bin width
	std::string legendLabel 		//Legend label describing the data set
	std::string jetAlgorithmLabel;	//Jet algorithm label
	int jetAlgorithmNumber;			//Jet algorithm number

	//[DATA]
	SPXDataFormat dataFormat;		//The format of the data: Current supported formats are: Spectrum, HERAPDF
	std::string dataFilename;		//The data filename
	bool errorInPercent;			//Whether the errors in the data file are given in percents
	bool tablePlusMinus;			//@TODO RENAME 'tablePlusMinus' --> ???
	//bool systStstTot				//@TODO RENAME 'systStstTot' --> ??????????????????????
	
	void SetDefaults(void);

public:

	void Print(void);
	void Parse(void);

	SPXDataSteeringFile(void) : filename(""), debug(false) {}
	
	explicit SPXDataSteeringFile(std::string filename) : debug(false) {
		this->filename = filename;
	}
	
	const std::string & GetFilename(void) const {
		return filename;
	}
	
	const std::string & GetName(void) const {
		return name;
	}
	
	unsigned long GetYear(void) const {
		return year;
	}
	
	const std::string & GetReaction(void) const {
		return reaction;
	}
	
	bool ShouldPlotSqrts(void) const {
		return plotSqrts;
	}
	
	double GetSqrts(void) const {
		return sqrts;
	}
	
	const std::string & GetTitle(void) const {
		return title;
	}
	
	const std::string & GetXLabel(void) const {
		return xLabel;
	}
	
	const std::string & GetYLabel(void) const {
		return yLabel;
	}
	
	const std::string & GetXUnits(void) const {
		return xUnits;
	}
	
	const std::string & GetYUnits(void) const {
		return yUnits;
	}
	
	double GetXScale(void) const {
		return xScale;
	}
	
	double GetYScale(void) const {
		return yScale;
	}
	
	double GetFrameXMin(void) const {
		return frameXMin;
	}
	
	double GetFrameYMin(void) const {
		return frameYMin;
	}
	
	bool IsDividedByBinWidth(void) const {
		return dividedByBinWidth;
	}
	
	SPXDataType GetDataType(void) const {
		return dataType;
	}
	
	const std::string GetDataFilename(void) const {
		return dataFilename;
	}
	
	bool IsErrorInPercent(void) const {
		return errorInPercent;
	}
};

#endif
