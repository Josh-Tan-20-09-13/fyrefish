#ifndef Pawn_H
#define Pawn_H

#include "IPiece.h"
#include "board/Board.h"

class Pawn : public IPiece {
public:
    Pawn() = default;
    bool valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const override;
    std::string get_name() const override { return "Pawn"; }
};

#endif // Pawn_H
