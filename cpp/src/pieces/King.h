#ifndef King_H
#define King_H

#include "IPiece.h"
#include "board/Board.h"

class King : public IPiece {
public:
    King() = default;
    bool valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const override;
    std::string get_name() const override { return "King"; }
};

#endif // King_H
