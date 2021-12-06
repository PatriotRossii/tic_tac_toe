#include "CellState.thrift"

struct Cell {
	1: i64 row,
	2: i64 column,
	3: CellState state,
}