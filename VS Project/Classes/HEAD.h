#pragma once
#include <vector>
#include <iostream>
#include <tchar.h>
#include <fstream>
#include <complex>

using namespace std;

#ifndef UNICODE

#define UNICODE

#endif

#ifndef _UNICODE

#define _UNICODE

#endif

#define BRANCH_COUNT 8
#define NODE_COUNT 6
#define STUDENTS_COUNT 30
#define MAX_MESSAGE_LENGTH 255
#define MAX_FILENAME_LENGTH 255
#define MAX_BUF_LENGTH 255
#define MAX_BRANCHES_COUNT 8
#define MIN_SQUARE_MATRIX_SIZE 2
#define MIN_MATRIX_SIZE 1
#define FIRST_STRING_INDEX 0
#define NUMS "1234567890"

#define RESISTANCE 1
#define CAPACITY 2
#define INDUCTANCE 3
#define SOURCE_DC 4
#define SOURCE_CURRENT 5

#define _testing

typedef unsigned int voltage_t;
typedef unsigned int amperage_t;
typedef unsigned int resistance_t;
typedef unsigned int capacity_t;
typedef unsigned int inductance_t;

#undef Matrix
#undef Exception
#undef value
typedef unsigned int _index;
typedef float _degree;

struct StartEnd{
	_index start;
	_index end;
};