cmake_minimum_required(VERSION 3.13)
project(TicTacToe)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++2a -Wall")

set(SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/common/board/Board.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/common/cell/Cell.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/game_logic/GameJudge.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/game_logic/TicTacToe.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

include_directories(src/)
add_executable(TicTacToe ${SOURCE_FILES})
