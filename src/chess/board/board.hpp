#pragma once

#include <array>
#include <string_view>

#include "../piece/piece.hpp"

namespace chess {
    struct Board {
        static constexpr std::string_view STARTING_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        std::array<Piece, 64> board = {};

        explicit Board(std::string_view fen);
    };
}