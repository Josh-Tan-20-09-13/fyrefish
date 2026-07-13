#ifndef Knight_H
#define Knight_H

#include "IPiece.h"
#include "Board.h"

class Knight : public IPiece {
public:
    Knight() = default;
    bool valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const override;
    std::string get_name() const override { return "Knight"; }
};

#endif // Knight_H
