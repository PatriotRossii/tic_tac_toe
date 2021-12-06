#pragma once

#include <vector>

#include "../utility/IsSame.hpp"

namespace tic_tac_toe {
bool GameJudge::checkRow(std::size_t row) {
	IsSame<Board> isSame = IsSame<Board>{board};

	std::vector<std::pair<std::size_t, std::size_t>> indeces;
	for(std::size_t cRow = row, cColumn = 0; cColumn < board.getWidth(); ++cColumn) {
		indeces.emplace_back(cRow, cColumn);
	}

	return isSame(indeces);
}
bool GameJudge::checkColumn(std::size_t column) {
	IsSame<Board> isSame = IsSame<Board>{board};

	std::vector<std::pair<std::size_t, std::size_t>> indeces;
	for(std::size_t cColumn = column, cRow = 0; cRow < board.getHeight(); ++cRow) {
		indeces.emplace_back(cRow, cColumn);
	}

	return isSame(indeces);
}
bool GameJudge::checkDiagonals(std::size_t row, std::size_t column) {
	IsSame<Board> isSame = IsSame<Board>{board};
	bool flag = false;

	{
		std::vector<std::pair<std::size_t, std::size_t>> indeces;
		for(std::size_t cRow = row, cColumn = column; cRow >= 0 && cColumn < board.getWidth(); --cRow, ++cColumn) {
			indeces.emplace_back(cRow, cColumn);
		}
		for(std::size_t cRow = row + 1, cColumn = column - 1; cRow < board.getHeight() && cColumn >= 0; ++cRow, --cColumn) {
			indeces.emplace_back(cRow, cColumn);
		}
		if(indeces.size() != 1) {
			flag = flag || isSame(indeces);
		}
	}

	{
		std::vector<std::pair<std::size_t, std::size_t>> indeces;
		for(std::size_t cRow = row, cColumn = column; cRow >= 0 && cColumn >= 0; --cRow, --cColumn) {
			indeces.emplace_back(cRow, cColumn);
		}
		for(std::size_t cRow = row + 1, cColumn = column + 1; cRow < board.getHeight() && cColumn < board.getWidth() ; ++cRow, ++cColumn) {
			indeces.emplace_back(cRow, cColumn);
		}
		if(indeces.size() != 1) {
			flag = flag || isSame(indeces);
		}
	}

	return flag;
}

bool GameJudge::checkWin(std::size_t row, std::size_t column) {
	return checkRow(row) || checkColumn(column) || checkDiagonals(row, column);
}
}
