/**
 * Simple conio for E:
 */

#include <atari.h>
#include <string.h>
#include "cio.h"

void print(const char* c)
{
  int l=strlen(c);

  OS.iocb[0].buffer=c;
  OS.iocb[0].buflen=l;
  OS.iocb[0].command=IOCB_PUTCHR;
  ciov();
}

void printc(char* c)
{
  OS.iocb[0].buffer=c;
  OS.iocb[0].buflen=1;
  OS.iocb[0].command=IOCB_PUTCHR;
  ciov();
}
