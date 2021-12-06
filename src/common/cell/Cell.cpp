#include "Cell.hpp"

namespace tic_tac_toe {
bool Cell::operator==(const Cell& other) const {
	return this->state == other.state;
}
Cell& Cell::operator=(CellState newState) {
	state = newState;
	return *this;
}
Cell fromThrift(::Cell cell) {
	return Cell{cell.row, cell.column, fromThrift(cell.state)};
}
::Cell toThrift(Cell cell) {
	::Cell convertedCell;

	convertedCell.row = cell.row;
	convertedCell.column = cell.column;
	convertedCell.state = toThrift(cell.state);

	return convertedCell;
}
}
