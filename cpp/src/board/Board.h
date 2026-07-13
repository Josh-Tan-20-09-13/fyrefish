#ifndef Board_H
#define Board_H

#include "pieces/IPiece.h"
#include <vector>
#include <memory>
#include <array>
#include <string>

class Board {
public:
    Board();
    ~Board();

    void reset();
    bool is_valid_position(int rank, int file) const;
    void set_piece(int rank, int file, std::shared_ptr<IPiece> piece);
    std::shared_ptr<IPiece> get_piece(int rank, int file) const;
    std::string to_notation(int rank, int file) const;
    std::string to_notation(int index) const;
    void draw() const;

private:
    std::array<std::array<std::shared_ptr<IPiece>, 8>, 8> grid;
};

#endif // Board_H
