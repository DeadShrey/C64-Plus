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
                break;
            case 'n':
                type = PieceType::Knight;
                break;
            case 'b':
                type = PieceType::Bishop;
                break;
            case 'r':
                type = PieceType::Rook;
                break;
            case 'q':
                type = PieceType::Queen;
                break;
            case 'k':
                type = PieceType::King;
                break;
            default:
                type = PieceType::None;
                break;
        }
    }

    char Piece::symbol() const {
        char sym;
        switch (type) {
            case PieceType::Pawn:
                sym = 'p';
                break;
            case PieceType::Knight:
                sym = 'n';
                break;
            case PieceType::Bishop:
                sym = 'b';
                break;
            case PieceType::Rook:
                sym = 'r';
                break;
            case PieceType::Queen:
                sym = 'q';
                break;
            case PieceType::King:
                sym = 'k';
                break;
            case PieceType::None:
                sym = '.';
                break;
            default:
                sym = '?';
                break;
        }

        return (color == PieceColor::White) ? std::toupper(sym) : sym;
    }
}
