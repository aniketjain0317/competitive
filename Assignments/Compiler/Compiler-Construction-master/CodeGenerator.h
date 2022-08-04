#ifndef COMPILER_CODEGENERATOR_H
#define COMPILER_CODEGENERATOR_H

#include "icg.h"
//input iCode & output -> asm file

void generateAssemblyFile(iCode code, int maxVariableName, const char* filename);

#endif //COMPILER_CODEGENERATOR_H
