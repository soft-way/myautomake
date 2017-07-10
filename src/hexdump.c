
#include "utils.h"
#include "stdio.h"
#include "stdlib.h"


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("\tUsage: %s <dump_filename>\n\n", argv[0]);
        exit(-1);
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Can not open file %s\n", argv[1]);
        exit(-2);
    }

    char buf[10240];
    size_t offset = 0;
    while (!feof(input))
    {
        size_t size = fread(buf, 1, sizeof(buf), input);
        hexdump(offset, buf, size);
        offset += sizeof(buf);
    }

    fclose(input);

    return 0;
}
