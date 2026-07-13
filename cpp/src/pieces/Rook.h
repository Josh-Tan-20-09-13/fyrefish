#ifndef Rook_H
#define Rook_H

#include "IPiece.h"
#include "board/Board.h"

class Rook : public IPiece {
public:
    Rook() = default;
    bool valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const override;
    std::string get_name() const override { return "Rook"; }
};

#endif // Rook_H
