#include <stdio.h>
#include "key.h"

void SetCursorPos(int XPos, int YPos)
{
	printf("\033[%d;%dH", YPos+1, XPos+1);
}

void clearConsole(){
	printf("\033[2J\033[1;1H");
}

int main(void) {
	int i;
	for (i = 0; i < 4; i++) {
		SetCursorPos(7, 1 + i);
		printf("▣");
	}
	
	while (true) {
		if (getKey()) {
			clearConsole();
		}
	}
	return 0;
}

// Everything Works!!!