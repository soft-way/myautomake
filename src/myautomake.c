#include "utils.h"

int main(int argc, char *argv[])
{
    char buf[16] = "Hello World!";
    printf("%s\n", buf);

    hexdump(0, buf, sizeof(buf));

    return 0;
}
