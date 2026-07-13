#include "Board.h"

Board::Board() {
    reset();
}

Board::~Board() = default;

void Board::reset() {
    for (int r = 0; r < 8; ++r) {
        for (int f = 0; f < 8; ++f) {
            grid[r][f] = nullptr;
        }
    }
}

bool Board::is_valid_position(int rank, int file) const {
    return rank >= 0 && rank < 8 && file >= 0 && file < 8;
}

void Board::set_piece(int rank, int file, std::shared_ptr<IPiece> piece) {
    if (is_valid_position(rank, file)) {
        grid[rank][file] = piece;
    }
}

std::shared_ptr<IPiece> Board::get_piece(int rank, int file) const {
    if (is_valid_position(rank, file)) {
        return grid[rank][file];
    }
    return nullptr;
}
