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
		return pos_X;
	}
	
	int getY() {
		return pos_Y;
	}
	
	void setCoord(int x, int y) {
		pos_X = x;
		pos_Y = y;
	}
private:
	int pos_X, pos_Y;
	int shapeIdx_; // Value: 0 ~ 3
	TetroType* tetroType_;
};

class Map {
public:
	void print(std::string str, int pos_X, int pos_Y);
	void moveTetromino(Tetromino* t, KEY dir) {
		if (true == isColliding(t, dir)) {
			return;
		}
		
		
	}
	
private:
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
			coord = shape[i];
			x = t->getX() + coord % 4;
			y = t->getY() + coord / 4;
			if (isOccupied(x + dx, y + dy)) {
				return true;
			}
		}
		
		return false;
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
	
	void setCoord(int x, int y, int cellState) {
		arr[y][x] = cellState;
	}
	
	int arr[MAP_HEIGHT][MAP_WIDTH];
};



class Game {
public:
	void handleInput(KEY input);
	void moveTetromino(Map* map, Tetromino* t, KEY dir) {
		map->moveTetromino(t, dir);
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