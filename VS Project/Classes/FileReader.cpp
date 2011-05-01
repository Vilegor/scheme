#include "FileReader.h"
#include "OpenFileException.h"

char* toChar(string str){
	char *_buf = new char[str.size() + 1];
	int _sz = str.size(), i = 0;
	for(i = 0; i < _sz; i++){
		_buf[i] = str[i];
	}
	_buf[i] = '\0';
	return _buf;
}

int findMEGNum(char* str){
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		char buf[2];
		buf[0] = str[i];
		buf[1] = '\0';
		if(strpbrk(buf,NUMS)){
			char c = str[i];
			return atoi(&c);
		}
	}
	return -1;
}

char* findUNum(char* str){
	char *nn = new char[3];
	int len = strlen(str);
	int j = 0;
	for(int i = 0; i < len; i++){
		char buf[2];
		buf[0] = str[i];
		buf[1] = '\0';
		if(strpbrk(buf,NUMS)){
			nn[j++] = str[i];
			if(j == 2){
				nn[2] = '\0';
				return nn;
			}
		}
	}
	return NULL;
}

FileReader::FileReader(void){
}

FileReader::FileReader( _TCHAR *filename ){
	_source.open(filename);
	
	if(!_source.is_open()){
		OpenFileException *e = new OpenFileException(filename);
		throw e;
	}
}


FileReader::~FileReader(void){
}

void FileReader::init(){
	char _buf[MAX_BUF_LENGTH];
	while(_source.getline(_buf,MAX_BUF_LENGTH)){
		//Gets 3 information lines
		_source.getline(_buf,MAX_BUF_LENGTH);
		_source.getline(_buf,MAX_BUF_LENGTH);
		Tokenizer *token = new Tokenizer;

		//Gets the information
		for(int i = 0; i < MAX_BRANCHES_COUNT; i++){
			_source.getline(_buf,MAX_BUF_LENGTH);
			token->setString(_buf);
			int N = atoi(toChar(token->next()));
			_branchNum.insert(_branchNum.end(),N);
			char *se = toChar(token->next());
			char s,e;
			s = se[0];
			e = se[1];
			StartEnd toAdd;
			toAdd.start = atoi(&s);
			toAdd.end = atoi(&e);
			_se.insert(_se.end(),toAdd);
			int R = atoi(toChar(token->next()));
			_r.insert(_r.end(),R);
			int E = atoi(toChar(token->next()));
			_e.insert(_e.end(),E);
			int I = atoi(toChar(token->next()));
			_i.insert(_i.end(),I);
		}
		//Skip 1 line
		_source.getline(_buf,MAX_BUF_LENGTH);

		_source.getline(_buf,MAX_BUF_LENGTH);
		_meg.insert(_meg.end(),findMEGNum(_buf));
		_source.getline(_buf,MAX_BUF_LENGTH);
		char *nn = findUNum(_buf);
		char s = nn[0], e = nn[1];
		StartEnd uSE;
		uSE.start = atoi(&s);
		uSE.end = atoi(&e);
		_uNN.insert(_uNN.end(),uSE);
		_source.getline(_buf,MAX_BUF_LENGTH);
		_source.getline(_buf,MAX_BUF_LENGTH);
		delete token;
	}
}

vector<size_t>* FileReader::getBranchNums(){
	return &_branchNum;
}

vector<StartEnd>* FileReader::getBranchDirections(){
	return &_se;
}

vector<resistance_t>* FileReader::getResistance(){
	return &_r;
}

vector<voltage_t>* FileReader::getVoltage(){
	return &_e;
}

vector<amperage_t>* FileReader::getAmperage(){
	return &_i;
}

vector<size_t>* FileReader::getMEG(){
	return &_meg;
}

vector<StartEnd>* FileReader::getUnn(){
	return &_uNN;
}
