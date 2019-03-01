#include "key.h"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


void setCursorPos(int XPos, int YPos) {
	printf("\033[%d;%dH", YPos + 1, XPos + 1);
}

void clearConsole(void) {
	printf("\033[2J\033[1;1H");
}

int getch(void) {
	int ch;
	struct termios oldt;
	struct termios newt;
	tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
	newt = oldt; /* copy old settings to new settings */
	newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
	tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
	ch = getchar(); /* standard getchar call */
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
	return ch; /*return received char */
}
 
// 키보드 눌렸는지 여부 확인
int kbhit(void) {
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

KEY getKey() {
	int x = ' ';
	int y = ' ';
	int z = ' ';
	x = getch();
	if (x == 27) {
		y = getch();
		z = getch();
	}
	
	if (x == 27 && y == 91) { // arrow key case
		switch (z) {
			case KEY_UP:
				return KEY_UP;
				break;
			case KEY_DOWN:
				return KEY_DOWN;
				break;
			case KEY_RIGHT:
				return KEY_RIGHT;
				break;
			case KEY_LEFT:
				return KEY_LEFT;
				break;
		}
	}
	else { // another character case
		switch (x) {
			case KEY_QUIT:
				return KEY_QUIT;
				break;
			case KEY_SPACE:
				return KEY_SPACE;
				break;
		}
	}
	
	return KEY_UNREGISTERED; // 게임과 관계없는 키는 다 씹어서 리턴
}