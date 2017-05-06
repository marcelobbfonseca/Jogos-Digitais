#ifndef ERROR_H
#define ERROR_H

#define CONVERSAO_GRAUS_RADIANOS 57.324840764

using namespace std;
void Warning(int line, string description, string file);
void ErrorExit(int line, string description, string file);
void debugInt(string description, int value, string file, int line );
void debugFloat(string description, float value, string file, int line );
void debugString(string description, string value, string file, int line );

#endif