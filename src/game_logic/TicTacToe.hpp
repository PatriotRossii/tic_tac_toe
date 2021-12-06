#include "common/game/GameState.hpp"
#include "common/board/Board.hpp"
#include "GameJudge.hpp"

namespace tic_tac_toe {
class TicTacToe {
	Board board;
	GameJudge judge{[&board](std::size_t row, std::size_t column) -> Cell {
		return board[row][column];
	}};
	GameState state{GameState::XMove};

	void updateState(std::size_t row, std::size_t column);
public:
	TicTacToe(std::size_t height, std::size_t width);
	void move(std::size_t row, std::size_t column);

	GameState getState() const;
	const Board& getBoard() const;

	bool isGameEnd() const;
};
}
