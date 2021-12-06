include "gameState.thrift"
include "cellState.thrift"

service GameLogicService {
	void move(1: i64 row, 2: i64 column),
	gameState.GameState getState(),
	bool isGameEnd()
}