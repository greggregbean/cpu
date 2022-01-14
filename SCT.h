// --- STACK ---
#include "Stack/stack.h"

// --- TRANSLATOR --
#include "Translator/translator.h"

// --- CPU ---
#define REGISTERSLEN 5

typedef struct
{
    int* commandLine;
    int ip;
    int* registers;
    stack stk;
    int* ram;
} cpu;

void cpuConstructor(cpu* proc);
void cpufunc(cpu* proc);

#include "Cpu/cpuConstructor.cpp"
#include "Cpu/cpufunc.cpp"




