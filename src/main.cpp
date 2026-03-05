#include <iostream>
#include <string>

#include "chess/board/board.hpp"

int main() {
    auto board = chess::Board(chess::Board::STARTING_FEN);

    while (true) {
        // Printing the board
        std::cout << '\n';
        int enter = 1;
        for (chess::Piece piece : board.board) {
            std::cout << piece.symbol() << ' ';
            if (enter == 8) {
                std::cout << '\n';
                enter = 1;
            }
            else {
                enter++;
            }
        }

        std::cout << '\n' << "Enter move (UCI): ";
        std::string move;
        std::cin >> move;

        if (move == "quit") {
            break;
        }

        if (move == "undo") {
            board.unmakeMove();
            continue;
        }

        const int from = chess::Board::getSq(move.substr(0, 2));
        const int to = chess::Board::getSq(move.substr(2, 2));
        board.makeMove(chess::Move(from, to, board.board[to]));
    }
}