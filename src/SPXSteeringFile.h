//************************************************************/
//
//	Steering File Header
//
//	Outlines the SPXSteeringFile class, which standardizes the
//	format and I/O of the Steering File Format (SFF), a file
//	format that allows for interfacing between Grids, Data,
//	and Cross Sections within Spectrum
//
//	@Author: 	Joe Gibson - CERN ATLAS
//	@Date:		19.09.2014
//
//************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "INIReader.h"

#include "SPXRatioStyle.h"
#include "SPXDisplayStyle.h"
#include "SPXOverlayStyle.h"
#include "SPXPDFBandType.h"
#include "SPXPDFErrorType.h"
#include "SPXPDFErrorSize.h"
#include "SPXFrameOptions.h"

#include "SPXPDFSteeringFile.h"
#include "SPXGridSteeringFile.h"

#include "SPXException.h"

#ifndef SPXSTEERINGFILE_H
#define SPXSTEERINGFILE_H

const int STYLE_EMPTY = -1;
const int COLOR_EMPTY = -1;

class SPXSteeringFile {

private:

	//INI Reader
	INIReader *reader;

	//Metadata
	std::string filename;
	unsigned int numberOfFrames;

	//[GEN]
	bool debug;
	std::string dataDirectory;
	std::string gridDirectory;
	
	//[GRAPH]
	bool plotBand;
	bool plotErrorTicks;
	bool plotMarker;
	bool plotStaggered;
	double xLegend;
	double yLegend;
	std::string ratioTitle;
	SPXRatioStyle ratioStyle;
	SPXOverlayStyle overlayStyle;
	SPXDisplayStyle displayStyle;
	double yOverlayMin;
	double yOverlayMax;
	double yRatioMin;
	double yRatioMax;
	
	//[PDF]
	//@TODO: At some point just get rid of <...>Filepaths and just use the .GetFilepath method
	//			of the SPXPDFSteeringFile class instead...
	std::vector<std::string> pdfSteeringFilepaths;
	std::vector<SPXPDFSteeringFile> pdfSteeringFiles;
	int pdfFillStyle;
	int pdfFillColor;
	int pdfMarkerStyle;
	SPXPDFBandType pdfBandType;
	SPXPDFErrorType pdfErrorType;
	SPXPDFErrorSize pdfErrorSize;
	
	//[FRAME_n]
	std::vector<SPXFrameOptions> frameOptions;
	
	void SetDefaults(void);
	unsigned int ParseNumberOfFrames(void);
	void ParseFrameOptions(unsigned int numFrames);
	
public:

	void Print(void);
	void PrintPDFSteeringFiles(void);
	void PrintDataSteeringFiles(void);
	void PrintGridSteeringFiles(void);
	
	void Parse(void);
	void ParsePDFSteeringFiles(void);
	void ParseDataSteeringFiles(void);
	void ParseGridSteeringFiles(void);
	
	explicit SPXSteeringFile(const std::string &filename) : debug(false){	
		//Set filename
		this->filename = filename;		
	}
	
	std::string GetFilename(void) const {
		return this->filename;
	}
	
	void SetDebug(bool b) {
		debug = b;
	}
	
	bool GetDebug(void) const {
		return this->debug;
	}
	
	std::string GetDataDirectory(void) const {
		return this->dataDirectory;
	}
	
	std::string GetGridDirectory(void) const {
		return this->gridDirectory;
	}
	
	bool GetPlotBand(void) const {
		return this->plotBand;
	}
	
	bool GetPlotErrorTicks(void) const {
		return this->plotErrorTicks;
	}
	
	bool GetPlotMarker(void) const {
		return this->plotMarker;
	}
	
	bool GetPlotStaggered(void) const {
		return this->plotStaggered;
	}
	
	double GetXLegend(void) const {
		return this->xLegend;
	}
	
	double GetYLegend(void) const {
		return this->yLegend;
	}
	
	std::string GetRatioTitle(void) const {
		return this->ratioTitle;
	}
	
	const SPXRatioStyle & GetRatioStyle(void) const {
		return this->ratioStyle;
	}
	
	const SPXOverlayStyle & GetOverlayStyle(void) const {
		return this->overlayStyle;
	}
	
	const SPXDisplayStyle & GetDisplayStyle(void) const {
		return this->displayStyle;
	}
	
	double GetYOverlayMin(void) const {
		return this->yOverlayMin;
	}
	
	double GetYOverlayMax(void) const {
		return this->yOverlayMax;
	}
	
	double GetYRatioMin(void) const {
		return this->yRatioMin;
	}
	
	double GetYRatioMax(void) const {
		return this->yRatioMax;
	}
	
	unsigned int GetNumberOfPDFSteeringFilepaths(void) const {
		return this->pdfSteeringFilepaths.size();
	}
	
	const std::vector<std::string> & GetPDFSteeringFilepaths(void) const {
		return this->pdfSteeringFilepaths;
	}
	
	const std::string & GetPDFSteeringFilepath(unsigned int index) const {
		if((index + 1) > pdfSteeringFilepaths.size()) {
			int top = pdfSteeringFilepaths.size() - 1;
			throw SPXOutOfRangeException(top, index, "SPXSteeringFile::GetPDFSteeringFilepath: Index out of range");
		}
		
		return pdfSteeringFilepaths.at(index);
	}
	
	unsigned int GetNumberOfPDFSteeringFiles(void) const {
		return this->pdfSteeringFiles.size();
	}
	
	const std::vector<SPXPDFSteeringFile> & GetPDFSteeringFiles(void) const {
		return this->pdfSteeringFiles;
	}
	
	const SPXPDFSteeringFile & GetPDFSteeringFile(unsigned int index) const {
		if((index + 1) > pdfSteeringFiles.size()) {
			int top = pdfSteeringFiles.size() - 1;
			throw SPXOutOfRangeException(top, index, "SPXSteeringFile::GetPDFSteeringFile: Index out of range");
		}
		
		return pdfSteeringFiles.at(index);
	}
	
	int GetPDFFillStyle(void) const {
		return this->pdfFillStyle;
	}
	
	int GetPDFFillColor(void) const {
		return this->pdfFillColor;
	}	
	
	int GetPDFMarkerStyle(void) const {
		return this->pdfMarkerStyle;
	}
	
	const SPXPDFBandType & GetPDFBandType(void) const {
		return this->pdfBandType;
	}
	
	const SPXPDFErrorType & GetPDFErrorType(void) const {
		return this->pdfErrorType;
	}
	
	const SPXPDFErrorSize & GetPDFErrorSize(void) const {
		return this->pdfErrorSize;
	}
	
	unsigned int GetNumberOfFrames(void) const {
		return this->frameOptions.size();
	}
	
	const std::vector<SPXFrameOptions> & GetFrameOptionsVector(void) const {
		return this->frameOptions;
	}
	
	const SPXFrameOptions & GetFrameOptions(unsigned int index) const {
		
		if((index + 1) > frameOptions.size()) {
			int top = frameOptions.size() - 1;
			throw SPXOutOfRangeException(top, index, "SPXSteeringFile::GetFrameOptions: Index out of range");
		}
		
		return frameOptions.at(index);
	}
	
	//@TODO: Implement: Allow 2D indexing of Data/Grid Steering files
	const SPXDataSteeringFile & GetDataSteeringFile(unsigned int frameOptionsIndex, unsigned int frameOptionsInstanceIndex) const {
		//Error check: check both indices against array sizes and issue SPXOutOfRangeExceptions if out of range before returning steering file
	}
	
	//@TODO Same for Grid...
};

#endif