void cpuConstructor(cpu* proc)
{
    assert(proc != NULL);

    proc -> commandLine = (int*) calloc(LENOFCOMMANDLINE, sizeof(int));

    stkconstructor(&(proc -> stk), STKCAPACITY, PrintInt);

    proc -> registers   = (int*) calloc(REGISTERSLEN,     sizeof(int));

    proc -> ip = 0;

    printf("CPU HAS BEEN CREATED. \n");
}

void cpuDistructor(cpu* proc)
{
    assert(proc != NULL);

    stackdistructor(&(proc -> stk));

    free(proc -> registers);

    *proc = {'\0'};

    printf("CPU HAS BEEN DISTROYERED. \n");

}
