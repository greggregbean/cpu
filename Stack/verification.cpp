void printstk(stack* stk)
{
    assert(stk != NULL);

    printf("DATA: ");

    for (size_t num = 1; num < stk -> size; num++)
    {
        stk -> printElem (stk -> data[num]);
    }

}

void PrintInt (int val)
{
    printf ("%d ", val);
}

void PrintLongInt (long int val)
{
    printf ("%ld ", val);
}

void PrintDouble (double val)
{
    printf ("%lg", val);
}

void PrintChar (char val)
{
    printf ("%c", val);
}

void stackdump(int statusOfVerification, stack* stk)
{
    switch (statusOfVerification)
    {
        case NULL_POINTER_OF_STACK:
            fprintf(LOGFILE, "Error: WRONG POINTER OF STACK \n\n");
            break;
        case WRONG_C1:
            fprintf(LOGFILE, "Error: WRONG STACK CANARY 1 \n\n");
            break;
        case WRONG_C2:
            fprintf(LOGFILE, "Error: WRONG STACK CANARY 2 \n\n");
            break;
        case WRONG_DC1:
            fprintf(LOGFILE, "Error: WRONG DATA CANARY 1 \n\n");
            break;
        case WRONG_DC2:
            fprintf(LOGFILE, "Error: WRONG DATA CANARY 2 \n\n");
            break;
        case WRONG_HASH:
            fprintf(LOGFILE, "Error: WRONG HASH \n\LOGFILEn");
            break;
        case WRONG_SIZE:
            fprintf(LOGFILE, "Error: WRONG SIZE \n\n");
            break;
        default:
            fprintf(LOGFILE, "NO ERRORS \n\n");
    }

    fprintf(LOGFILE, "THE POINTER OF STACK: %p \n", stk);

    fprintf(LOGFILE, "CAPACITY: %d \n", stk -> capacity);

    fprintf(LOGFILE, "SIZE: %d \n", stk -> size);

    fprintf(LOGFILE, "Stack canaries: \n");
    fprintf(LOGFILE, "First - %X", stk -> stcan1);
    fprintf(LOGFILE, "(%p); should be: DEADDEAD \n", &(stk -> stcan1));
    fprintf(LOGFILE, "Second - %X", stk -> stcan2);
    fprintf(LOGFILE, "(%p);  should be: DEADDEAD \n \n", &(stk -> stcan2));

    fprintf(LOGFILE, "Data canaries: \n");
    fprintf(LOGFILE, "1st data canary - %X (%p); Should be: FEED\n", stk -> data[0], &(stk -> data[0]));
    fprintf(LOGFILE, "2nd data canary - %X (%p); Should be: FEED\n \n", stk -> data[stk -> capacity + 1], &(stk -> data[stk -> capacity+1]));

    fprintf(LOGFILE, "DATA: ");

    for (size_t num = 1; num < stk -> size; num++)
    {
        stk -> printElem (stk -> data[num]);
    }
}

int verificator(stack* stk, FILE* LOGFILE)
{
     int statusOfVerification = 0;

     if (stk == NULL)
     {
        statusOfVerification = NULL_POINTER_OF_STACK;
        printf ("There is a mistake on this stage. (Check LOGFILE)\n");
        stackdump(statusOfVerification, stk);
        exit(0);
     }

     else if (stk -> data == NULL)
     {
        statusOfVerification = NULL_POINTER_OF_DATA;
        printf ("There is a mistake on this stage. (Check LOGFILE)\n");
        stackdump(statusOfVerification, stk);
        exit(0);
     }

     else if (stk -> stcan1 != STCANARY)
     {
        statusOfVerification = WRONG_C1;
        printf ("There is a mistake on this stage. (Check logfile)\n");
        stackdump(statusOfVerification, stk);
        exit(0);
     }

     else if (stk -> stcan2 != STCANARY)
     {
        statusOfVerification = WRONG_C2;
        printf ("There is a mistake on this stage. (Check LOGFILE)\n");
        stackdump(statusOfVerification, stk);
        exit(0);
     }

     else if (stk -> data[0] != (datatype) DATACANARY)
     {
        statusOfVerification = WRONG_DC1;
        printf ("There is a mistake on this stage. (Check LOGFILE)\n");
        stackdump(statusOfVerification, stk);
        exit(0);
     }

     else if (stk -> data[stk -> capacity + 1] != (datatype) DATACANARY)
     {
        statusOfVerification = WRONG_DC2;
        printf ("There is a mistake on this stage. (Check LOGFILE)\n");
        stackdump(statusOfVerification, stk);
        exit(0);
     }

     else if ((stk -> size > stk -> capacity + 1) || (stk -> size < 0))
     {
        statusOfVerification = WRONG_SIZE;
        printf ("There is a mistake on this stage. (Check LOGFILE)\n");
        stackdump(statusOfVerification, stk);
        exit(0);
     }
}
