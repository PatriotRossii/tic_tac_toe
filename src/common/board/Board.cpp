#include "Board.hpp"

namespace tic_tac_toe {
Board::Board(int height, int width) {
	board.reserve(height);
	for(int i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for(int j = 0; j < width; ++j) {
			row.push_back(Cell{i, j, CellState::Empty});
		}
		board.push_back(std::move(row));
	}
}

const std::vector<Cell>& Board::operator[](std::size_t row) const {
	return board[row];
}
std::vector<Cell>& Board::operator[](std::size_t row) {
	return board[row];
}
}