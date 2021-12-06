#pragma once

#include "../common/board/Board.hpp"


namespace tic_tac_toe {
class GameJudge {
	std::function<Cell(std::size_t, std::size_t)> accessFn;
private:
	bool checkRow(std::size_t row);
	bool checkColumn(std::size_t column);
	bool checkDiagonals(std::size_t row, std::size_t column);
public:
	GameJudge(std::function<Cell(std::size_t, std::size_t)> fn);
	bool checkWin(std::size_t row, std::size_t column);
};
}
