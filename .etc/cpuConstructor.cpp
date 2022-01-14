void cpuConstructor(cpu* proc)
{
    assert(proc != NULL);

    proc -> commandLine = (int*) calloc(LENOFCOMMANDLINE, sizeof(int));
    proc -> registers   = (int*) calloc(REGISTERSLEN,     sizeof(int));
    proc -> ip = 0;
}
