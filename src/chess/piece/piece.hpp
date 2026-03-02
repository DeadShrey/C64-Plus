#pragma once

namespace chess {
    enum struct PieceType {None, Pawn, Knight, Bishop, Rook, Queen, King};
    enum struct PieceColor {None, White, Black};

    struct Piece {
        PieceType type;
        PieceColor color;

        Piece();
        Piece(PieceType type, PieceColor color);
        explicit Piece(char symbol);

        char symbol() const;
    };
}