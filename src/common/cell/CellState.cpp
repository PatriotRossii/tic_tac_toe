#include "CellState.hpp"

namespace tic_tac_toe {
CellState fromThrift(::CellState::type cellState) {
	switch(cellState) {
	case ::CellState::type::Empty:
		return CellState::Empty;
	case ::CellState::type::X:
		return CellState::X;
	case ::CellState::type::O:
		return CellState::O;
	}
}
::CellState::type toThrift(CellState state) {
	switch(cellState) {
	case CellState::Empty:
		return ::CellState::type::Empty;
	case CellState::X:
		return ::CellState::type::X;
	case CellState::O:
		return ::CellState::type::O;
	}
}
}
