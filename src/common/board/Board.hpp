#pragma once

#include <vector>

#include "../cell/Cell.hpp"
#include "../cell/CellState.hpp"

namespace tic_tac_toe {
class Board {
	std::vector<std::vector<Cell>> board;
public:
	Board(int height, int width);

	const std::vector<Cell>& operator[](std::size_t row) const;
	std::vector<Cell>& operator[](std::size_t row);
};
}