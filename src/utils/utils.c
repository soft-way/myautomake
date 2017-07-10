
#include "utils.h"

void hexdump(size_t offset, void *buf, size_t buflen)
{
    /*           1         2         3         4         5         6
                 0123456789012345678901234567890123456789012345678901234567890123456789
                 xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx    ................
    */

    int i, j;
    char line[68];
    for (i=0; i < buflen; i += 16) {
        for (j=0; j < 16; j++) {
            if (i+j < buflen) {
                unsigned char b = ((unsigned char*)buf)[i+j];
                sprintf(line + j*3, "%02hhx ", b);
                line[50+j] = (isalnum(b) ? b : '.');
            } else {
                sprintf(line + j*3, "   ");
                line[50+j] = ' ';
            }
        }
        line[47] = ' ';
        line[48] = ';';
        line[49] = ' ';
        line[66] = '\0';
        printf("%08xh: %s\n", offset, line);
        offset += 16;
    }
}
