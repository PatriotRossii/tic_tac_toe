#pragma once

#include "CellState.hpp"

namespace tic_tac_toe {
struct Cell {
	int row, column;
	CellState state;

	Cell& operator=(CellState newState);
	bool operator==(const Cell& other) const;
};
}