#include "board.hpp"

#include <locale>
#include <vector>
#include <string>
#include <string_view>

#include "../piece/piece.hpp"

namespace chess {
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
}