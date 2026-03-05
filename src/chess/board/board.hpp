#pragma once

#include <array>
#include <string>
#include <string_view>
#include <vector>

#include "../piece/piece.hpp"
#include "../move/move.hpp"

namespace chess {
    struct BoardHistory {
        int halfMoves;

        explicit BoardHistory(int halfMoves);
    };

    struct Board {
        static constexpr std::string_view STARTING_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        static constexpr bool WHITE = true;
        static constexpr bool BLACK = false;

        std::array<Piece, 64> board = {};
        bool turn;
        bool wKCastle;
        bool wQCastle;
        bool bKCastle;
        bool bQCastle;
        std::string enPassantSq;
        int halfMoves;
        int fullMoves;
        std::vector<Move> moveStack;
        std::vector<BoardHistory> historyStack;

        explicit Board(std::string_view fen);

        static int getSq(std::string_view sq);

        void makeMove(Move move);
        Move unmakeMove();
    };
}