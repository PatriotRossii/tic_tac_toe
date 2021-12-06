#include <iostream>

#include "common/cell/CellState.hpp"
#include "common/game/GameState.hpp"

#include "game_logic/TicTacToe.hpp"

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