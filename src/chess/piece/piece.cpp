#include "piece.hpp"

#include <locale>

namespace chess {
    Piece::Piece() {
        type = PieceType::None;
        color = PieceColor::None;
    }

    Piece::Piece(const PieceType type, const PieceColor color) {
        this->type = type;
        this->color = color;
    }

    Piece::Piece(const char symbol) {
        color = std::isupper(symbol) ? PieceColor::White : PieceColor::Black;

        switch (std::tolower(symbol)) {
            case 'p':
                type = PieceType::Pawn;
            case 'n':
                type = PieceType::Knight;
            case 'b':
                type = PieceType::Bishop;
            case 'r':
                type = PieceType::Rook;
            case 'q':
                type = PieceType::Queen;
            case 'k':
                type = PieceType::King;
            default:
                type = PieceType::None;
        }
    }
}
