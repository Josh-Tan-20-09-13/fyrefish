#include "Board.h"
#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include <string>
#include <iostream>
#include <iomanip>

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

    // Initial pieces setup
    // Rank 0
    set_piece(0, 0, std::make_shared<Rook>());
    set_piece(0, 1, std::make_shared<Knight>());
    set_piece(0, 2, std::make_shared<Bishop>());
    set_piece(0, 3, std::make_shared<Queen>());
    set_piece(0, 4, std::make_shared<King>());
    set_piece(0, 5, std::make_shared<Bishop>());
    set_piece(0, 6, std::make_shared<Knight>());
    set_piece(0, 7, std::make_shared<Rook>());

    // Rank 1
    for (int f = 0; f < 8; ++f) {
        set_piece(1, f, std::make_shared<Pawn>());
    }

    // Rank 6
    for (int f = 0; f < 8; ++f) {
        set_piece(6, f, std::make_shared<Pawn>());
    }

    // Rank 7
    set_piece(7, 0, std::make_shared<Rook>());
    set_piece(7, 1, std::make_shared<Knight>());
    set_piece(7, 2, std::make_shared<Bishop>());
    set_piece(7, 3, std::make_shared<Queen>());
    set_piece(7, 4, std::make_shared<King>());
    set_piece(7, 5, std::make_shared<Bishop>());
    set_piece(7, 6, std::make_shared<Knight>());
    set_piece(7, 7, std::make_shared<Rook>());
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

std::string Board::to_notation(int rank, int file) const {
    if (!is_valid_position(rank, file)) {
        return "";
    }
    char file_char = 'A' + file;
    char rank_char = '1' + rank;
    return std::string(1, file_char) + rank_char;
}

std::string Board::to_notation(int index) const {
    int rank = index / 8;
    int file = index % 8;
    return to_notation(rank, file);
}

void Board::draw() const {
    std::cout << "  +--------------------------+" << std::endl;
    for (int r = 7; r >= 0; --r) {
        std::cout << (r + 1) << " |  ";
        for (int f = 0; f < 8; ++f) {
            auto piece = grid[r][f];
            if (piece) {
                std::string name = piece->get_name();
                if (name == "Pawn")        std::cout << "P  ";
                else if (name == "Knight") std::cout << "K  ";
                else if (name == "Bishop") std::cout << "B  ";
                else if (name == "Rook")   std::cout << "R  ";
                else if (name == "Queen")  std::cout << "Q  ";
                else if (name == "King")   std::cout << "X  ";
                else std::cout << "? ";
            } else {
                std::cout << ".  ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "  +--------------------------+" << std::endl;
    std::cout << "    A  B  C  D  E  F  G  H" << std::endl;
}
