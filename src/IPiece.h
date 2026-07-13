#ifndef IPiece_H
#define IPiece_H

#include <string>

class Board;

class IPiece {
public:
    virtual ~IPiece() = default;
    virtual bool valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const = 0;
    virtual std::string get_name() const = 0;
};

#endif // IPiece_H
