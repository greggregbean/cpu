#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <txlib.h>

#include "translator.h"

int main ()
{
    FILE* textcode      = fopen("../Run/textcode.txt",       "r"); assert (textcode);
    FILE* numericalcode = fopen("../Run/numericalcode.txt",  "w"); assert (numericalcode);
    FILE* binarycode    = fopen("../Run/binarycode.bin",    "wb"); assert (binarycode);

    int commandLine [LENOFCOMMANDLINE] = {'\0'};
    int translatorIp = 0;

    int labelsSize = 0;
    label labelBuffer [LENOFLABELBUFFER] = {'\0'};

    printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n FIRST TRANSLATION\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n\n");

    translator(textcode, numericalcode, binarycode, labelBuffer, commandLine, &translatorIp, &labelsSize);

    fseek(textcode, 0, SEEK_SET);
    fseek(numericalcode, 0, SEEK_SET);
    translatorIp = 0;

    printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n SECOND TRANSLATION\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n\n");

    translator(textcode, numericalcode, binarycode, labelBuffer, commandLine, &translatorIp, &labelsSize);

    fwrite(commandLine, sizeof(int), translatorIp, binarycode);

    printf("Binary code is in binarycode.bin\n");

    fclose(textcode);
    fclose(numericalcode);
    fclose(binarycode);
}
