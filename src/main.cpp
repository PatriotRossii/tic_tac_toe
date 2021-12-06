#include <iostream>
#include <vector>
#include <tuple>

#include "common/cell/CellState.hpp"
#include "common/cell/Cell.hpp"
#include "common/board/Board.hpp"

namespace tic_tac_toe {
enum class GameState {
	OMove,
	XMove,
	OWin,
	XWin,
	Draw
};

class TicTacToe {
public:
	static const int HEIGHT = 3;
	static const int WIDTH = 3;
private:
	Board board{HEIGHT, WIDTH};
	GameState state{GameState::IDLE};

	void updateState(int row, int column) {
		bool rowCheck = checkRow(row);
		bool columnCheck = checkColumn(column);
		bool diagonalsCheck = checkDiagonals(row, column);

		bool win = rowCheck || columnCheck || diagonalsCheck;
		if(win) {
			state = currentMove == CurrentMove::X ? GameState::XWin : GameState::OWin;
		} else {
			state = state == GameState::XMove ? GameState::OMove : GameState::XMove;
		}
	}
public:
	GameState getState() const {
		return state;
	}
	void move(int row, int column) {
		if(board[row][column].state != CellState::Empty || (state != GameState::XMove && state != GameState::OMove)) {
			return;
		}
		CellState newState = state == GameState::XMove ? CellState::X : CellState::O;
		board[row][column] = newState;
		updateState(row, column);
	}

	const Board& getBoard() const {
		return board;
	}
};
}

int main() {
	tic_tac_toe::TicTacToe game;
	while(game.getState() == tic_tac_toe::GameState::IDLE) {
		int row, column;

		std::cout << "Row: ";
		std::cin >> row;
		std::cout << "Column: ";
		std::cin >> column;

		std::cout << std::endl;

		game.move(row, column);

		const tic_tac_toe::Board& board = game.getBoard();
		for(int i = 0; i < tic_tac_toe::TicTacToe::HEIGHT; ++i) {
			for(int j = 0; j < tic_tac_toe::TicTacToe::WIDTH; ++j) {
				tic_tac_toe::CellState state = board[i][j].state;
				switch(state) {
				case tic_tac_toe::CellState::X:
					std::cout << 'X';
					break;
				case tic_tac_toe::CellState::O:
					std::cout << 'O';
					break;
				case tic_tac_toe::CellState::Empty:
					std::cout << 'E';
					break;
				}
			}
			std::cout << std::endl;
		}


		std::cout << std::endl;
	}
}