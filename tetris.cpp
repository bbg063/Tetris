#include "tetris.h"
#include "key.h"
#include <string>
#include <iostream>

#define STRING_ACTIVE "▣"
#define STRING_INACTIVE "□"
#define STRING_BLANK "　"

#define CELL_ACTIVE 2
#define CELL_INACTIVE 1
#define CELL_BLANK 0

#define MAP_WIDTH 11
#define MAP_HEIGHT 16

class TetroType {
public:
	TetroType(int shapes[4][16]) {
		int i, j;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 16; j++) {
				shapes_[i][j] = shapes[i][j];
			}
		}
	}
	int* getShape(int idx) { // idx : 0 ~ 3
		return shapes_[idx];
	}
private:
	int shapes_[4][16];
};

class Tetromino {
public:
	Tetromino(TetroType* type) {
		tetroType_ = type;
		shapeIdx_ = 0;
	}

	void setType(TetroType* type) {
		tetroType_ = type;
		shapeIdx_ = 0;
	}

	void rotate(void) {
		shapeIdx_ = (++shapeIdx_) % 4;
	}
	
	int* getCurrentShape(void) {
		return tetroType_->getShape(shapeIdx_);
	}
	
	int getX() {
		return posX_;
	}
	
	int getY() {
		return posY_;
	}
	
	void setCoord(int x, int y) {
		posX_ = x;
		posY_ = y;
	}
private:
	int posX_, posY_;
	int shapeIdx_; // Value: 0 ~ 3
	TetroType* tetroType_;
};

class Map {
public:
	void print(std::string str, int pos_X, int pos_Y);
	void moveTetromino(Tetromino* t, KEY dir) {
		int dx = 0, dy = 0;
		switch (dir) {
			case KEY_LEFT:
				dx = -1;
				dy = 0;
				break;
			case KEY_RIGHT:
				dx = 1;
				dy = 0;
				break;
			case KEY_DOWN:
				dx = 0;
				dy = 1;
				break;
			default:
				return;
		}
		
		int tx = t->getX();
		int ty = t->getY();
		
		int* shape = t->getCurrentShape();
		int i;
		int x, y, coord;
		for (i = 0; i < 16; i++) {
			x = tx + i % 4;
			y = ty + i / 4;
			if (CELL_ACTIVE == shape[i]) {
				setCoord(x, y, CELL_BLANK);
			}
		}
		for (i = 0; i < 16; i++) {
			x = tx + i % 4;
			y = ty + i / 4;
			if (CELL_ACTIVE == shape[i]) {
				setCoord(x + dx, y + dy, CELL_ACTIVE);
			}
		}
		
		t->setCoord(tx + dx, ty + dy);
	}
	
	bool isColliding(Tetromino* t, KEY dir) {
		int dx = 0, dy = 0;
		switch (dir) {
			case KEY_LEFT:
				dx = -1;
				dy = 0;
				break;
			case KEY_RIGHT:
				dx = 1;
				dy = 0;
				break;
			case KEY_DOWN:
				dx = 0;
				dy = 1;
				break;
			default:
				return false;
		}
		
		int* shape = t->getCurrentShape();
		int i;
		int x, y, coord;
		for (i = 0; i < 16; i++) {
			if (shape[i] != CELL_ACTIVE) {
				continue;
			}
			
			x = t->getX() + i % 4;
			y = t->getY() + i / 4;
			if (isOccupied(x + dx, y + dy)) {
				return true;
			}
		}
		
		return false;
	}
	
	void rotateTetromino(Tetromino* t) {
		
	}
	
	void settleTetromino(Tetromino* t) {
		
	}
	
private:
	
	void setCoord(int x, int y, int cellState) {
		arr[y][x] = cellState;
	}
	
	bool isOccupied(int x, int y) {
		if (x >= MAP_WIDTH || x < 0 || y >= MAP_HEIGHT || y < 0) {
			return true;
		}
		if (CELL_INACTIVE == arr[y][x]) {
			return true;
		}
		return false;
	}
		
	int arr[MAP_HEIGHT][MAP_WIDTH];
};



class Game {
public:
	void handleInput(KEY input);
	
	void rotateTetromino(Map* map, Tetromino* t) {
		if (false == map->isColliding(t, KEY_UP)) {
			map->rotateTetromino(t);
		}
	}
	
	void moveTetromino(Map* map, Tetromino* t, KEY dir) {
		if (false == map->isColliding(t, dir)) {
			map->moveTetromino(t, dir);
		}
		else if (dir == KEY_DOWN) {
			map->settleTetromino(t);
		}
	}
	
	void dropTetromino(Map* map, Tetromino* t) {
		while (false == map->isColliding(t, KEY_DOWN)) {
			moveTetromino(map, t, KEY_DOWN);
		}
		moveTetromino(map, t, KEY_DOWN);
	}
	
private:
	bool isPlaying_;
	Map* map_;
	Tetromino* activeBlock_;
};

void Game::handleInput(KEY input) {
	switch (input) {
		case KEY_UP:
			
			break;
		case KEY_DOWN:
			break;
		case KEY_LEFT:
			break;
		case KEY_RIGHT:
			break;
		case KEY_SPACE:
			break;
		case KEY_QUIT:
			break;
	}
}

void loop(void) {
	bool playing = false;
	while (playing) {
		
	}
}

int main(void) {
		
	return 0;
}