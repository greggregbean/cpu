void regprint(cpu* proc)
{
    printf("REGISTERS: ");

    for(int i = 1; i <= 4; i++)
    {
        printf("%03d ",proc -> registers[i]);
    }

    printf("\n\n");
}

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
                regprint(proc);

                break;

            case CMD_POPR:
                (proc -> ip)++;
                proc -> registers[proc -> commandLine [proc -> ip]] = stkpop(&(proc -> stk));
                (proc -> ip)++;
                regprint(proc);

                break;

        }
    }
}
