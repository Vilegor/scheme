#include <iostream>
#include <tchar.h>
#include "Element.h"
#include "Capacity.h"
#include "Inductance.h"
#include "Resistor.h"
#include "FileReader.h"
#include "Exceptions.h"
#include <typeinfo>
#include <vector>

using namespace std;

int _tmain(int _Argc, _TCHAR* argv[])
{
	try{
		FileReader freader(L"part1.TXT");
		freader.init();
		vector<voltage_t> test = *freader.getVoltage();
		vector<StartEnd> test2 = *freader.getUnn();
		vector<Student> stud;
		for(int i = 0; i < STUDENTS_COUNT; i++){
			stud.insert(stud.end(),Student(
				i,freader.getBranchDirections(),
				freader.getUnn(),freader.getResistance(),
				freader.getVoltage(),freader.getAmperage(),
				freader.getMEG()));
		}

		for(int i = 0; i < STUDENTS_COUNT; i++){
			stud[i].initGraph();
			//vector<resistance_t> test4 = stud[i].getResistance();
		}
		stud[2].checkGraph();
		stud[2].reportComposing();
		system("pause");
	}
	catch(Exception *e)
	{
		e->print();
		system("pause");
	}
}