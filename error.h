#ifndef ERROR_H
#define ERROR_H

using namespace std;


void printError(int line, string description, string file){
	cout << "\nLine:"<< line << " " << description << " File:" << file << endl;
	exit(1);
}

#endif