#pragma once

#include "gen-cpp/cellState_types.h"

namespace tic_tac_toe {
enum class CellState {
	Empty,
	O,
	X
};
CellState fromThrift(::CellState::type cellState);
::CellState::type toThrift(CellState state);
}
