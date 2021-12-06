#include "Cell.hpp"

namespace tic_tac_toe {
bool Cell::operator==(const Cell& other) const {
	return this->state == other.state;
}
Cell& Cell::operator=(CellState newState) {
	state = newState;
	return *this;
}
}
