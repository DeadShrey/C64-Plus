#include "board.hpp"

#include <locale>
#include <vector>
#include <string>
#include <string_view>

#include "../piece/piece.hpp"

namespace chess {
    BoardHistory::BoardHistory(const int halfMoves) {
        this->halfMoves = halfMoves;
    }

    Board::Board(const std::string_view fen) {
        // Splitting the fen string from spaces
        std::vector<std::string_view> parts;
        size_t start = 0;
        size_t end = fen.find(' ');

        while (end != std::string_view::npos) {
            parts.push_back(fen.substr(start, end - start));
            start = end + 1;
            end = fen.find(' ', start);
        }

        parts.push_back(fen.substr(start));

        // Setting up the board from fen string
        int sq = 0;

        for (const char symbol : parts[0]) {
            if (symbol == '/') {
                continue;
            }

            if (std::isdigit(symbol)) {
                sq += symbol - '0';
                continue;
            }

            board[sq] = Piece(symbol);
            sq++;
        }

        turn = parts[1] == "w";
        wKCastle = parts[2].contains('K');
        wQCastle = parts[2].contains('Q');
        bKCastle = parts[2].contains('k');
        bQCastle = parts[2].contains('q');
        enPassantSq = parts[3];
        halfMoves = std::stoi(std::string(parts[4]));
        fullMoves = std::stoi(std::string(parts[5]));
    }

    int Board::getSq(const std::string_view sq) {
        const int file = sq[0] - 'a';
        const int rank = 8 - (sq[1] - '0');
        return (rank * 8) + file;
    }

    void Board::makeMove(const Move move) {
        halfMoves = board[move.to].type != PieceType::None || board[move.from].type == PieceType::Pawn ? halfMoves + 1 : 0;
        fullMoves += turn == BLACK ? 1 : 0;
        board[move.to] = board[move.from];
        board[move.from] = Piece();
        moveStack.push_back(move);
        historyStack.emplace_back(halfMoves);
        turn = !turn;
    }

    Move Board::unmakeMove() {
        const Move move = moveStack.back();
        const BoardHistory history = historyStack.back();
        moveStack.pop_back();
        historyStack.pop_back();

        halfMoves = history.halfMoves;
        fullMoves -= turn == WHITE ? 1 : 0;
        board[move.from] = board[move.to];
        board[move.to] = move.capture;
        turn = !turn;

        return move;
    }
}
