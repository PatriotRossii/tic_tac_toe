#pragma once

#include "../common/board/Board.hpp"

namespace tic_tac_toe {
class GameJudge {
	const Board& board;
private:
	bool checkRow(std::size_t row);
	bool checkColumn(std::size_t column);
	bool checkDiagonals(std::size_t row, std::size_t column);
public:
	GameJudge(const Board& board);
	bool checkWin(std::size_t row, std::size_t column);
};
}
