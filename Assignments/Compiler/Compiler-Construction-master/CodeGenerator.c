//
// Created by Vaibhav Maheshwari on 2019-04-12.
//

#include "CodeGenerator.h"
#include <string.h>

/**
 * Translation of Intermediate Code to final Assembly Code
 *
 * global main
 *
 * ;Declare used libc functions
 * extern scanf
 * extern printf
 *
 * ;Fixed data section
 *
 * section .data
 * scanfFormatString : db "%d",0
 * printfFormatString : db "%d", 0xA, 0 ;prints a newline character too
 *
 * section .bss
 * divImm resd 1
 *
 * section .text
 * main:
 *
 *
 *                              Quadruple representation                      In Code
 *
 *                          op  |  arg1  |  arg2  |  result
 *                          --------------------------------
 *  1. t v                  T   |   t    |   v    |    -         Make entry in bss section with label v
 *
 *  2. v = v1 op a          op  |   v1   |   a    |    v         +                     -                     *                             /
 *                                                               add <reg>,<reg>       sub <reg>,<reg>       imul <reg32>,<reg32>          idiv <reg32>     Divides edx:eax contents with second operand
 *                                                               add <reg>,<con>       sub <reg>,<con>       imul <reg32>,<reg32>,<con>    idiv <mem>       and store the quotient in eax and remainder in edx
 *                                                               add <mem>,<reg>       sub <mem>,<reg>
 *
 *  3. v = a                =   |   a    |   -    |    v         mov v, a //a can be both register and immediate value
 *
 *  4. L                    L   |   -    |   -    |    L         L:
 *
 *  5. goto L               G   |   -    |   -    |    L         jmp L
 *
 *  6. if v relop a goto L  I   |   v    |   a    |    L         cmp <reg>,<reg>    used to set the flags
 *                                                               cmp <reg>,<con>
 *
 *                                                               == : je L (jump when equal)
 *                                                               != : jne L (jump when not equal)
 *                                                                > : jg L (jump when greater than)
 *                                                               >= : jge L (jump when greater than or equal to)
 *                                                                < : jl L (jump when less than)
 *                                                               <= : jle L (jump when less than or equal to)
 *
 *
 *  7. read v               R   |   v    |        |              push dword v ;argument to store into
 *                                                               push dword scanfFormatString ;format string
 *                                                               call scanf
 *                                                               add esp, 8 ; 2 * 4
 *
 *  8. write v              W   |   v    |        |              push dword [v]
 *                                                               push dword printfFormatString
 *                                                               call printf
 *                                                               add esp, 8 ; 2 * 4
 */

const char* fileHeader = "global main\n\n"
                         "extern scanf\n"
                         "extern printf\n\n"
                         "section .data\n"
                         "scanfFormatString : db \"%d\",0\n"
                         "printfFormatString : db \"%d\", 0xA, 0\n\n"
                         "section .bss\n"
                         "divImm resd 1\n";

const char* textSection = "\nsection .text\n"
                          "main:\n\n";

const char* fileFooter = "\nmov ebx, 0\n"
                         "mov eax, 1\n"
                         "int 80h";

void generateAssemblyFile(iCode code, int maxVariableName, const char* fileName) {
    FILE* outputFile = fopen(fileName, "w");

    //write the header
    fwrite(fileHeader, sizeof(char), strlen(fileHeader), outputFile);

    for (int i = 0; i <= maxVariableName; i++)
        fprintf(outputFile, "i%d resd 1\n", i);

    //write the text section
    fwrite(textSection, sizeof(char), strlen(textSection), outputFile);

    char* reg1 = "eax";
    char* reg2 = "ebx";

    const char* readCode =  "push dword i%d\n"
                            "push dword scanfFormatString\n"
                            "call scanf\n"
                            "add esp, 8\n";

    const char* writeCode = "push dword [i%d]\n"
                            "push dword printfFormatString\n"
                            "call printf\n"
                            "add esp, 8\n";

    while (code != NULL) {
        switch (code->operator) {
            case 'T': {
                //already handled above so no need to do anything here
                break;
            }
            case '+':
            case '-': {
                char* opcode = (code->operator == '+') ? "add" : "sub";
                if (code->arg2.type == VAR) {
                    // v = v1 op a; load v1, operate with a, store to v
                    fprintf(outputFile, "mov %s, dword [i%d]\n", reg1, code->arg1.value);
                    fprintf(outputFile, "%s %s, dword [i%d]\n", opcode, reg1, code->arg2.value);
                    fprintf(outputFile, "mov [i%d], %s\n", code->result.value, reg1);
                } else { //constant
                    fprintf(outputFile, "mov %s, dword [i%d]\n", reg1, code->arg1.value);
                    fprintf(outputFile, "%s %s, dword %d\n", opcode, reg1, code->arg2.value);
                    fprintf(outputFile, "mov [i%d], %s\n", code->result.value, reg1);
                }
                break;
            }
            case '*': {
                if (code->arg2.type == VAR) {
                    fprintf(outputFile, "mov %s, dword [i%d]\n", reg1, code->arg1.value);
                    fprintf(outputFile, "imul %s, dword [i%d]\n", reg1, code->arg2.value);
                    fprintf(outputFile, "mov [i%d], %s\n", code->result.value, reg1);
                } else { //constant
                    fprintf(outputFile, "imul %s, dword [i%d], %d\n", reg1, code->arg1.value, code->arg2.value);
                    fprintf(outputFile, "mov [i%d], %s\n", code->result.value, reg1);
                }
                break;
            }
            case '/': { //requires eax
                if (code->arg2.type == VAR) {
                    fprintf(outputFile, "mov edx, 0\n");
                    fprintf(outputFile, "mov eax, dword [i%d]\n", code->arg1.value);
                    fprintf(outputFile, "idiv dword [i%d]\n", code->arg2.value);
                    fprintf(outputFile, "mov [i%d], eax\n", code->result.value);
                } else {
                    fprintf(outputFile, "mov edx, 0\n");
                    fprintf(outputFile, "mov eax, dword [i%d]\n", code->arg1.value);
                    fprintf(outputFile, "mov %s, %d\n", reg2, code->arg2.value);
                    fprintf(outputFile, "idiv %s\n", reg2);
                    fprintf(outputFile, "mov [i%d], eax\n", code->result.value);
                }
                break;
            }
            case '=': {
                if (code->arg1.type == VAR) {
                    fprintf(outputFile, "mov %s, dword [i%d]\n", reg1, code->arg1.value);
                    fprintf(outputFile, "mov [i%d], %s\n", code->result.value, reg1);
                } else { //constant
                    fprintf(outputFile, "mov [i%d], dword %d\n", code->result.value, code->arg1.value);
                }
                break;
            }
            case 'L': {
                fprintf(outputFile, "L%d:\n", code->result.value);
                break;
            }
            case 'G': {
                fprintf(outputFile, "jmp L%d\n", code->result.value);
                break;
            }
            case 'I': {
                //cmp
                if (code->arg2.type == VAR) {
                    fprintf(outputFile, "mov %s, dword [i%d]\n", reg1, code->arg1.value);
                    fprintf(outputFile, "mov %s, dword [i%d]\n", reg2, code->arg2.value);
                    fprintf(outputFile, "cmp %s, %s\n", reg1, reg2);
                } else {
                    fprintf(outputFile, "mov %s, dword [i%d]\n", reg1, code->arg1.value);
                    fprintf(outputFile, "cmp %s, %d\n", reg1, code->arg2.value);
                }

                //jump
                switch (code->condOp) {
                    case TK_LT: fprintf(outputFile, "jl L%d\n", code->result.value); break;
                    case TK_LE: fprintf(outputFile, "jle L%d\n", code->result.value); break;
                    case TK_EQ: fprintf(outputFile, "je L%d\n", code->result.value); break;
                    case TK_NE: fprintf(outputFile, "jne L%d\n", code->result.value); break;
                    case TK_GT: fprintf(outputFile, "jg L%d\n", code->result.value); break;
                    case TK_GE: fprintf(outputFile, "jge L%d\n", code->result.value); break;
                }
                break;
            }
            case 'R': {
                fprintf(outputFile, readCode, code->arg1.value);
                break;
            }
            case 'W': {
                fprintf(outputFile, writeCode, code->arg1.value);
                break;
            }
        }
        code = code->next;
    }

    //write the footer
    fwrite(fileFooter, sizeof(char), strlen(fileFooter), outputFile);
    fclose(outputFile);
}
