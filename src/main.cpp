#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include <iostream>
#include <memory>

int main() {
    Board board;
    std::cout << "FyreFish Board initialized." << std::endl;
    
    auto pawn = std::make_shared<Pawn>();
    board.set_piece(1, 0, pawn);
    
    auto piece = board.get_piece(1, 0);
    if (piece) {
        std::cout << "Piece at (1,0) is: " << piece->get_name() << std::endl;
    }
    
    return 0;
}
