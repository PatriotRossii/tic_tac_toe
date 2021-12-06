#include "Board.hpp"

namespace tic_tac_toe {
void Board::initialize(std::size_t height, std::size_t width) {
	this->height = height;
	this->width = width;
	board.clear();

	board.reserve(height);
	for(std::size_t i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for(std::size_t j = 0; j < width; ++j) {
			row.push_back(Cell{i, j, CellState::Empty});
		}
		board.push_back(std::move(row));
	}
}

Board::Board(std::size_t height, std::size_t width) {
	this->initialize(height, width);
}
void Board::setBoardSize(std::size_t height, std::size_t width) {
	this->initialize(height, width);
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