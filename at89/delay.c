
#include "hw.h"

// For now, this is close enough for me...
void delay(int delay)
{
 int i, j;
 for (j=0; j<delay; j++)
   for (i=0; i<(OSCILLATOR/10000)/12; i++)
     ;
}

