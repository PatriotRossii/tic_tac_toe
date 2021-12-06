#pragma once

#include <vector>

#include "../cell/Cell.hpp"
#include "../cell/CellState.hpp"

namespace tic_tac_toe {
class Board {
	std::vector<std::vector<Cell>> board;
	std::size_t height, width;
	void initialize(std::size_t height, std::size_t width);
public:
	Board(std::size_t height, std::size_t width);
	void setBoardSize(std::size_t height, std::size_t width);

	const std::vector<Cell>& operator[](std::size_t row) const;
	std::vector<Cell>& operator[](std::size_t row);

	std::size_t getHeight() const;
	std::size_t getWidth() const;
};
}