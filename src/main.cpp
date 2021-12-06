#include <iostream>

#include "common/cell/CellState.hpp"
#include "common/game/GameState.hpp"

#include "game_logic/TicTacToe.hpp"

int main() {
	tic_tac_toe::TicTacToe game{3, 3};
	while(!game.isGameEnd()) {
		int row, column;

		std::cout << "Row: ";
		std::cin >> row;
		std::cout << "Column: ";
		std::cin >> column;
		std::cout << std::endl;

		game.move(row, column);

		const tic_tac_toe::Board& board = game.getBoard();
		for(std::size_t i = 0; i < board.getHeight(); ++i) {
			for(std::size_t j = 0; j < board.getWidth(); ++j) {
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