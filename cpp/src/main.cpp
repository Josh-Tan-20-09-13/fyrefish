#include "board/Board.h"
#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
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
