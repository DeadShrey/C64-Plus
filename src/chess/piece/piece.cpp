#include "piece.hpp"

namespace chess {
    Piece::Piece() {
        type = PieceType::None;
        color = PieceColor::None;
    }

    Piece::Piece(const PieceType type, const PieceColor color) {
        this->type = type;
        this->color = color;
    }
}