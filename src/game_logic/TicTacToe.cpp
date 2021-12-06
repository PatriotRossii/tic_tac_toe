#include "TicTacToe.hpp"

namespace tic_tac_toe {
void TicTacToe::updateState(std::size_t row, std::size_t column) {
	bool win = judge.checkWin(row, column);
	if(win) {
		state = state == GameState::XMove ? GameState::XWin : GameState::OWin;
	} else {
		state = state == GameState::XMove ? GameState::OMove : GameState::XMove;
	}
}


TicTacToe::TicTacToe(std::size_t height, std::size_t width):
	board{height, width}, judge{board} { }
void TicTacToe::move(std::size_t row, std::size_t column) {
	if(board[row][column].state != CellState::Empty || isGameEnd()) {
		return;
	}
	CellState newState = state == GameState::XMove ? CellState::X : CellState::O;
	board[row][column] = newState;
	updateState(row, column);
}
GameState TicTacToe::getState() const {
	return state;
}
const Board& TicTacToe::getBoard() const {
	return board;
}

bool TicTacToe::isGameEnd() const {
	return (state == GameState::XWin || state == GameState::OWin || state == GameState::Draw);
}
}
