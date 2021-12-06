include "cellState.thrift"
include "cell.thrift"

service StorageService {
	void setBoardSize(1: i64 height, 2: i64 width),

	void setCell(1: i64 row, 2: i64 column, 3: cellState.CellState newState),
	cell.Cell getCell(1: i64 row, 2: i64 column),

	i64 getHeight(),
	i64 getWidth()
}