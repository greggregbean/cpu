void cpufunc(cpu* proc, int lenOfCommandline)
{
    while (proc -> commandLine[proc -> ip] != CMD_HLT)
    {
        switch (proc -> commandLine[proc -> ip])
        {
            case CMD_PUSH:
                (proc -> ip)++;
                stkpush(&(proc -> stk), proc -> commandLine [proc -> ip]);
                (proc -> ip)++;

                break;

            case CMD_POP:
                stkpop(&(proc -> stk));
                (proc -> ip)++;

                break;

            case CMD_PUSHR:
                (proc -> ip)++;
                stkpush(&(proc -> stk), proc -> registers[proc -> commandLine [proc -> ip]]);
                (proc -> ip)++;

                break;
        }
    }
}
