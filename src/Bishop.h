#ifndef Bishop_H
#define Bishop_H

#include "IPiece.h"
#include "Board.h"

class Bishop : public IPiece {
public:
    Bishop() = default;
    bool valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const override;
    std::string get_name()const override { return "Bishop"; }
};

#endif // Bishop_H
