#include <iostream>

#include "chess/board/board.hpp"

int main() {
    const auto board = chess::Board(chess::Board::STARTING_FEN);

    // Printing the board
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
}