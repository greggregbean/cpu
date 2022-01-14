#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <txlib.h>

#include "doc.h"

int main ()
{
    FILE* textcode      = fopen("textcode.txt",      "r"); assert (textcode);
    FILE* numericalcode = fopen("numericalcode.txt", "w"); assert (numericalcode);
    FILE* binarycode    = fopen("binarycode.bin",    "w"); assert (binarycode);

    label labelBuffer [LENOFLABELBUFFER] = {'\0'};

    translator(textcode, numericalcode, binarycode, labelBuffer);

    fclose(textcode);

    cpu proc = {'\0'};

    cpuConstructor(&proc);

    fread(proc.commandLine, sizeof (int), LENOFCOMMANDLINE, binarycode);

    int i = 0;

    while(proc.commandLine[i] != '\0')
    {
        printf("%03d ", proc.commandLine[i++]);
    }
}
