#pragma once
#include "HEAD.h"
#include "Tokenizer.h"
#include "Student.h"

class FileReader{

public:

	FileReader(void);
	FileReader(_TCHAR *filename);
	~FileReader(void);
	void init();

	vector<size_t>* getBranchNums();
	vector<StartEnd>* getBranchDirections();
	vector<resistance_t>* getResistance();
	vector<voltage_t>* getVoltage();
	vector<amperage_t>* getAmperage();
	vector<size_t>* getMEG();
	vector<StartEnd>* getUnn();

	friend class Student;

private:

	fstream _source;
	vector<size_t> _branchNum;
	vector<StartEnd> _uNN;
	vector<StartEnd> _se;
	vector<resistance_t> _r;
	vector<voltage_t> _e;
	vector<amperage_t> _i;
	vector<size_t> _meg;
};