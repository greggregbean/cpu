#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <txlib.h>

#include "translator.h"

int main ()
{
    FILE* textcode      = fopen("../Run/textcode.txt",      "r"); assert (textcode);
    FILE* numericalcode = fopen("../Run/numericalcode.txt", "w"); assert (numericalcode);
    FILE* binarycode    = fopen("../Run/binarycode.bin",    "w"); assert (binarycode);

    label labelBuffer [LENOFLABELBUFFER] = {'\0'};

    translator(textcode, numericalcode, binarycode, labelBuffer);

    fclose(textcode);
    fclose(numericalcode);
    fclose(binarycode);
}
