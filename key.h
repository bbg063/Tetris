#ifndef KEY_H_
#define KEY_H_

enum KEY {
	KEY_UP = 65,
	KEY_DOWN = 66,
	KEY_RIGHT = 67,
	KEY_LEFT = 68,
	KEY_SPACE = 32,
	KEY_QUIT = 113,
	KEY_UNREGISTERED = -1
};

void SetCursorPos(int XPos, int YPos);
void clearConsole(void);
int getch(void);
int kbhit(void);
KEY getKey(void);

#endif // KEY_H_