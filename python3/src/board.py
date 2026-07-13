#!/usr/bin/env python3

from enum import Enum

import numpy as np
from numpy.typing import ArrayLike

class PieceColor(Enum):
    WHITE = 1 
    BLACK = -1

class PieceType(Enum):
    PAWN = 1
    KNIGHT = 2
    BISHOP = 3
    ROOK = 4
    QUEEN = 5
    KING = 6

class Board:
    
    def __init__(self) -> None:
        self.board: np.array = np.zeros([8, 8], dtype=np.int8) 
    
    def reset(self) -> None:
        self.board[1, :] = 1
        self.board[0, :] = [4, 2, 3, 5, 6, 3, 2, 4]
        self.board[6] = -1
        self.board[7] = -1 * self.board[0]

    def add_piece(self, row: int, col: int, color: PieceColor, piece_type: PieceType) -> None:
        self.board[row-1, col-1] = piece_type.value * color.value 

    def remove_piece(self, row: int, col: int) -> None:
        self.board[row-1, col-1] = 0 

    def is_board_valid(self) -> bool:
        # check each side has only 1 king
        if np.count_nonzero(self.board == 5) != 1:
            return False
        if np.count_nonzero(self.board == -5) != 1:
            return False

        # check each side pawns are not on back rank
        if np.any(self.board[0, :] == 1):
            return False
        if np.any(self.board[7, :] == -1):
            return False


def rook_moves(board: Board, row: int, col: int) -> list[tuple[int, int]]:


if __name__ == '__main__':
    b1 = Board()
    b1.add_piece(row=1, col=2, color=PieceColor['BLACK'], piece_type=PieceType['PAWN'])
    print(b1.board)
    b2 = PieceColor(1)
    b3 = PieceColor['WHITE']
    print(b2, b2.value)
    print(b3, b3.value)
