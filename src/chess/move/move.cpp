#include "move.hpp"

namespace chess {
    Move::Move(const int from, const int to, const Piece capture) {
        this->from = from;
        this->to = to;
        this->capture = capture;
    }
}