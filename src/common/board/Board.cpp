#include "Board.hpp"

namespace tic_tac_toe {
Board::Board(std::size_t height_, std::size_t width_): height{height_}, width{width_} {
	board.reserve(height);
	for(std::size_t i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for(std::size_t j = 0; j < width; ++j) {
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

std::size_t Board::getHeight() const {
	return height;
}
std::size_t Board::getWidth() const {
	return width;
}
}