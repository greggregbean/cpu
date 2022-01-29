#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <txlib.h>
#include <math.h>

FILE* LOGFILE = fopen("../logfile.txt", "w");

#include "../SCT.h"

int main ()
{
    cpu proc = {};

    int testCommandLine[LENOFCOMMANDLINE] = {};

    cpuConstructor(&proc);

    FILE* binarycode = fopen("../Run/binarycode.bin", "rb"); assert(binarycode);

    int lenOfCommandline = fread(proc.commandLine, sizeof (int), LENOFCOMMANDLINE, binarycode);

    fclose(binarycode);

    printf("LEN OF COMMAND LINE = %d. \n", lenOfCommandline);

    printf("COMMAND LINE: \n");

    for(int i = 0; i < lenOfCommandline; i++)
    {
        printf("[%02d]%03d ", i, proc.commandLine[i]);
    }

    printf("\n\n");

    cpufunc(&proc, lenOfCommandline);

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \nTHE PROGRAMM HAS BEEN COMPLETED. \n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n\n");

    cpuDistructor(&proc);
}
