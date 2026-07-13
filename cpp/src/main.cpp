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
    
    // Check piece at (1,0) which should be a Pawn
    auto piece = board.get_piece(1, 0);
    if (piece) {
        std::cout << "Piece at A2 is: " << piece->get_name() << std::endl;
    }

    // Check notation conversion
    std::cout << "Notation for (0,0): " << board.to_notation(0, 0) << std::endl;
    std::cout << "Notation for (7,7): " << board.to_notation(7, 7) << std::endl;
    std::cout << "Notation for index 0: " << board.to_notation(0) << std::endl;
    std::cout << "Notation for index 63: " << board.to_notation(63) << std::endl;

    std::cout << "\nBoard State:" << std::endl;
    board.draw();

    return 0;
}
