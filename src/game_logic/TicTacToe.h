#include "GameJudge.hpp"

namespace tic_tac_toe {
class TicTacToe {
	Board board;
	GameJudge judge;
	GameState state{GameState::IDLE};

	void updateState(std::size_t row, std::size_t column);
public:
	TicTacToe(std::size_t height, std::size_t width);
	void move(int row, int column);

	GameState getState() const;
	const Board& getBoard() const;
};
}
