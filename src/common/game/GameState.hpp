#pragma once

namespace tic_tac_toe {
enum class GameState {
	OMove,
	XMove,
	OWin,
	XWin,
	Draw
};
GameState fromThrift(::GameState::type);
::GameState::type toThrift(GameState);
}