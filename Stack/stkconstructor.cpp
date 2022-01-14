void stkconstructor(stack* stk, int capacity, void (*printFunc) (datatype data))
{
    assert (stk != NULL);

    printf("STACK CONSTRUCTOR: \n");

    stk -> stcan1 = STCANARY;

    assert((stk -> capacity = capacity) >= 0);
    printf("Capacity: %d\n", stk -> capacity);
    stk -> size = 1;

    ((stk -> data = (datatype*) calloc(capacity + 2, sizeof(datatype)))) != NULL;
    assert (stk -> data);

    stk -> data[0] = (datatype) DATACANARY;
    stk -> data[stk -> capacity + 1] = (datatype) DATACANARY;

    stk -> printElem = printFunc;

    stk -> stcan2 = STCANARY;

    printf("Stack canaries: \n");
    printf("First - %X", stk -> stcan1);
    printf("(%p) \n", &(stk -> stcan1));
    printf("Second - %X", stk -> stcan2);
    printf("(%p) \n", &(stk -> stcan2));

    printf("Data canaries: \n");
    printf("1st data canary - %X (%p) \n", stk -> data[0], &(stk -> data[0]));
    printf("2nd data canary - %X (%p) \n \n", stk -> data[stk -> capacity + 1], &(stk -> data[stk -> capacity+1]));

    verificator(stk, LOGFILE);
}

void stackdistructor(stack* stk)
{
    assert(stk != NULL);
    assert(stk -> data != NULL);

    free(stk -> data);
    *stk = {'\0'};

    printf("STACK CLEARED \n\n");
}


