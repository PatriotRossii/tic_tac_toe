#include "GameState.hpp"

namespace tic_tac_toe {
GameState fromThrift(::GameState::type gameState) {
	switch(gameState) {
	case ::GameState::type::XMove:
		return GameState::XMove;
	case ::GameState::type::OMove:
		return GameState::OMove;
	case ::GameState::type::XWin:
		return GameState::XWin;
	case ::GameState::type::OWin:
		return GameState::OWin;
	case ::GameState::type::Draw:
		return GameState::Draw;
	}
}
::GameState::type toThrift(GameState gameState) {
	switch(gameState) {
	case GameState::XMove:
		return ::GameState::type::XMove;
	case GameState::OMove:
		return ::GameState::type::OMove;
	case GameState::XWin:
		return ::GameState::type::XWin;
	case GameState::OWin:
		return ::GameState::type::OWin;
	case GameState::Draw:
		return ::GameState::type::Draw;
	}
}
}