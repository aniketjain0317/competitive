all : symbol.o lexer.o parser.o ast.o typeChecker.o icg.o CodeGenerator.o driver.o 
	gcc -o compiler symbol.o lexer.o parser.o ast.o typeChecker.o icg.o CodeGenerator.o driver.o -lm
symbol.o : symbol.c symbol.h
	gcc -c symbol.c
lexer.o : lexer.c lexer.h lexerDef.h symbol.h
	gcc -c lexer.c
parser.o : parser.c parser.h parserDef.h symbol.h
	gcc -c parser.c
ast.o : ast.c ast.h
	gcc -c ast.c
typeChecker.o : typeChecker.c typeChecker.h
	gcc -c typeChecker.c
icg.o : icg.c icg.h 
	gcc -c icg.c
CodeGenerator.o : CodeGenerator.c CodeGenerator.h
	gcc -c CodeGenerator.c
driver.o : driver.c parser.h symbol.h
	gcc -c driver.c
clean :
	rm compiler symbol.o lexer.o parser.o ast.o typeChecker.o icg.o CodeGenerator.o driver.o
