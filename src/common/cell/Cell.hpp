#pragma once

#include <cstddef>

#include "gen-cpp/cell_types.h"
#include "CellState.hpp"

namespace tic_tac_toe {
struct Cell {
	std::size_t row, column;
	CellState state;

	Cell& operator=(CellState newState);
	bool operator==(const Cell& other) const;
};
Cell fromThrift(::Cell cell);
::Cell toThrift(Cell);
}