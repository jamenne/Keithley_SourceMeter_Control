/*

SourecMeter.h


Created by Janine Müller on 05.10.2016


*/

#ifndef ____SourceMeter__
#define ____SourceMeter__

#include <string>
#include <vector>

using namespace std;

class SourceMeter
{
public:
	SourceMeter();
	~SourceMeter();

	bool GetOutputStatus(int smuX);
	double GetActualVoltage(int smuX);
	double GetBiasVoltage(int smuX);
	int GetUD();

	void Initialize(int masterUD, int pad, double biasVoltageA, double biasVoltageB);
	void ResetDevice();
	void ResetChannel(int smuX);
	void SelectSourceFunction(int smuX, bool voltage= true);
	void SetOutputOnOff(int smuX, bool On = true);
	void SelectRange(int smuX, string range, bool voltage = true);
	void SetLimit(int smuX, string limit, bool voltage = true);

	double GetSourceVoltage(int smuX);
	void SetSourceVoltage(int smuX, string level);
	double GetSourceCurrent(int smuX);
	void SetSourceCurrent(int smuX, string level);

	vector<double> MeasureIV(int smuX);
	void WriteMeasurementToFile(vector<double> measurement);

private:
	bool _outputStatusA; 
	bool _outputStatusB;

	// verbosity
	bool _verbosity;

	// bias and actual source voltages for Output A
	double _biasVoltageA;
	double _actualVoltageA;

	// bias and actual source voltages for Output B
	double _biasVoltageB;
	double _actualVoltageB;

	// source current
	double _actualCurrentA;
	double _actualCurrentB;

	int _ud;

	char _readA[70];
	char _readB[70];


};


#endif /* defined(____SourceMeter__) */