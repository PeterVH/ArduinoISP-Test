#include "hw.h"
#include "delay.h"


void main(void){
	while (1) {
		delay(200);
		P1_0 = !P1_0;
	}
}
