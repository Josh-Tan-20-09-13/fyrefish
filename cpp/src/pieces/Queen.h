#ifndef Queen_H
#define Queen_H

#include "IPiece.h"
#include "board/Board.h"

class Queen : public IPiece {
public:
    Queen() = default;
    bool valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const override;
    std::string get_name() const override { return "Queen"; }
};

#endif // Queen_H
