#pragma once

#include <array>
#include <string>
#include <string_view>

#include "../piece/piece.hpp"

namespace chess {
    struct Board {
        static constexpr std::string_view STARTING_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        std::array<Piece, 64> board = {};
        bool turn;
        bool wKCastle;
        bool wQCastle;
        bool bKCastle;
        bool bQCastle;
        std::string enPassantSq;
        int halfMoves;
        int fullMoves;

        explicit Board(std::string_view fen);
    };
}