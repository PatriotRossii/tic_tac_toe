#include <iostream>
#include <vector>
#include <tuple>

namespace tic_tac_toe {
enum class CurrentMove {
	X,
	O
};
enum class GameState {
	IDLE,
	OWin,
	XWin,
	Draw
};
enum class CellState {
	Empty,
	O,
	X
};
struct Cell {
	int row, column;
	CellState state;

	bool operator==(const Cell& other) const {
		return this->state == other.state;
	}
	Cell& operator=(CellState newState) {
		state = newState;
		return *this;
	}
};
class Board {
	std::vector<std::vector<Cell>> board;
public:
	Board(int height, int width) {
		board.reserve(height);
		for(int i = 0; i < height; ++i) {
			std::vector<Cell> row;
			for(int j = 0; j < width; ++j) {
				row.push_back(Cell{i, j, CellState::Empty});
			}
			board.push_back(std::move(row));
		}
	}
	void setCell(int row, int column, CellState state) {
		board[row][column] = state;
	}
	Cell getCell(int row, int column) const {
		return board[row][column];
	}

	const std::vector<Cell>& operator[](std::size_t row) const {
		return board[row];
	}
	std::vector<Cell>& operator[](std::size_t row) {
		return board[row];
	}
};

template<typename Container>
struct IsSame {
	const Container& container;
public:
	IsSame(const Container& container): container{container} { }
	bool operator()(std::vector<std::pair<std::size_t, std::size_t>> indeces) const {
		bool flag = true;

		const auto& first = container[indeces[0].first][indeces[0].second];
		for(std::size_t i = 1, size = indeces.size(); i < size; ++i) {
			flag = flag && container[indeces[i].first][indeces[i].second] == first;
		}

		return flag;
	}
};

class TicTacToe {
public:
	static const int HEIGHT = 3;
	static const int WIDTH = 3;
private:
	Board board{HEIGHT, WIDTH};
	GameState state{GameState::IDLE};
	CurrentMove currentMove{CurrentMove::X};

	bool checkRow(int row) {
		IsSame<Board> isSame = IsSame<Board>{board};

		std::vector<std::pair<std::size_t, std::size_t>> indeces;
		for(int cRow = row, cColumn = 0; cColumn < WIDTH; ++cColumn) {
			indeces.emplace_back(cRow, cColumn);
		}

		return isSame(indeces);
	}

	bool checkColumn(int column) {
		IsSame<Board> isSame = IsSame<Board>{board};

		std::vector<std::pair<std::size_t, std::size_t>> indeces;
		for(int cColumn = column, cRow = 0; cRow < HEIGHT; ++cRow) {
			indeces.emplace_back(cRow, cColumn);
		}

		return isSame(indeces);
	}

	bool checkDiagonals(int row, int column) {
		IsSame<Board> isSame = IsSame<Board>{board};
		bool flag = false;

		{
			std::vector<std::pair<std::size_t, std::size_t>> indeces;
			for(int cRow = row, cColumn = column; cRow >= 0 && cColumn < WIDTH; --cRow, ++cColumn) {
				indeces.emplace_back(cRow, cColumn);
			}
			for(int cRow = row + 1, cColumn = column - 1; cRow < HEIGHT && cColumn >= 0; ++cRow, --cColumn) {
				indeces.emplace_back(cRow, cColumn);
			}
			if(indeces.size() != 1) {
				flag = flag || isSame(indeces);
			}
		}

		{
			std::vector<std::pair<std::size_t, std::size_t>> indeces;
			for(int cRow = row, cColumn = column; cRow >= 0 && cColumn >= 0; --cRow, --cColumn) {
				indeces.emplace_back(cRow, cColumn);
			}
			for(int cRow = row + 1, cColumn = column + 1; cRow < HEIGHT && cColumn < WIDTH ; ++cRow, ++cColumn) {
				indeces.emplace_back(cRow, cColumn);
			}
			if(indeces.size() != 1) {
				flag = flag || isSame(indeces);
			}
		}

		return flag;
	}

	void updateState(int row, int column) {
		bool rowCheck = checkRow(row);
		bool columnCheck = checkColumn(column);
		bool diagonalsCheck = checkDiagonals(row, column);

		bool win = rowCheck || columnCheck || diagonalsCheck;
		if(win) {
			state = currentMove == CurrentMove::X ? GameState::XWin : GameState::OWin;
		}
		currentMove = currentMove == CurrentMove::X ? CurrentMove::O : CurrentMove::X;
	}
public:
	GameState getState() const {
		return state;
	}
	void move(int row, int column) {
		CellState newState = currentMove == CurrentMove::X ? CellState::X : CellState::O;
		if(board.getCell(row, column).state != CellState::Empty) {
			return;
		}
		board.setCell(row, column, newState);
		updateState(row, column);
	}

	const Board& getBoard() const {
		return board;
	}
};
}

int main() {
	tic_tac_toe::TicTacToe game;
	while(game.getState() == tic_tac_toe::GameState::IDLE) {
		int row, column;

		std::cout << "Row: ";
		std::cin >> row;
		std::cout << "Column: ";
		std::cin >> column;

		std::cout << std::endl;

		game.move(row, column);

		const tic_tac_toe::Board& board = game.getBoard();
		for(int i = 0; i < tic_tac_toe::TicTacToe::HEIGHT; ++i) {
			for(int j = 0; j < tic_tac_toe::TicTacToe::WIDTH; ++j) {
				tic_tac_toe::CellState state = board.getCell(i, j).state;
				switch(state) {
				case tic_tac_toe::CellState::X:
					std::cout << 'X';
					break;
				case tic_tac_toe::CellState::O:
					std::cout << 'O';
					break;
				case tic_tac_toe::CellState::Empty:
					std::cout << 'E';
					break;
				}
			}
			std::cout << std::endl;
		}


		std::cout << std::endl;
	}
}