#pragma once

#include "../piece/piece.hpp"

namespace chess {
    struct Move {
        int from;
        int to;
        Piece capture;

        Move(int from, int to, Piece capture = Piece(PieceType::None, PieceColor::None));
    };
}