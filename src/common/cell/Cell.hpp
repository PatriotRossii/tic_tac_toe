#pragma once

#include <cstddef>

#include "CellState.hpp"

namespace tic_tac_toe {
struct Cell {
	std::size_t row, column;
	CellState state;

	Cell& operator=(CellState newState);
	bool operator==(const Cell& other) const;
};
}