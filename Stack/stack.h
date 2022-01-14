// --- STACK ---

#define STKCAPACITY 100
#define RESIZECOF 1.5
#define STCANARY 0xDEADDEAD
#define DATACANARY 0xFEED

typedef int datatype;

typedef struct
{
    long long int stcan1;
    datatype* data;
    size_t size;
    size_t capacity;
    void (*printElem) (datatype data);
    void (*printElemInLogfile) (datatype data);
    long long int stcan2;
} stack;

// VERIFICATION

enum typesOfErrors
{
    NULL_POINTER_OF_STACK = -1,
    NULL_POINTER_OF_DATA = -2,
    WRONG_C1 = 1,
    WRONG_C2 = 2,
    WRONG_DC1 = 3,
    WRONG_DC2 = 4,
    WRONG_HASH = 5,
    WRONG_SIZE = 6
};

// ALL FUNCTIONS

int verificator(stack* stk, FILE* logfile);
void stkconstructor(stack* stk, int capacity, void (*printFunc) (datatype data), void (*printFuncInLogfile) (datatype data));
void stkpush(stack* stk, datatype val);
void stkresize(stack* stk, double val);
void stkpop(stack* stk);
void stackdump(int statusOfVerification, stack* stk);
void printstk(stack* stk);
void PrintLongInt (long int val);
void PrintInt (int val);
void PrintDouble (double val);
void PrintChar (char val);

// INCLUDING FILES

#include "verification.cpp"
#include "stkconstructor.cpp"
#include "pushpop.cpp"

