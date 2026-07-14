#!/usr/bin/env python3
"""board state representation"""
from dataclasses import dataclass, field
from typing import Union
from collections import namedtuple

import numpy as np

from aliases import *

INITIAL_BOARD = np.array([
    [4, 2, 3, 5, 6, 3, 2, 4],
    [1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [-1, -1, -1, -1, -1, -1, -1, -1],
    [-4, -2, -3, -5, -6, -3, -2, -4],
], dtype=np.int8)

@dataclass
class Coord:
    """represents coordinate"""
    row: int
    col: int

@dataclass
class Board:
    """
    grid: 8x8 array where (0,0) = a1 and (0, 1) = a2
    """
    board: np.array = field(default_factory=lambda: INITIAL_BOARD)

@dataclass
class BoardState:
    """information needed for unique position"""
    board: Board = field(default_factory=lambda: Board())
    castle_ability: np.array = field(default_factory=lambda: np.ones(shape=4, dtype=np.int8))
    enpassant_file: Union[int, None] = None
    turn: int = PieceColor['WHITE'].value


if __name__ == '__main__':
    b1 = Board()
    print(b1)

    print(b1.board.shape)
    print(INITIAL_BOARD[0, 1])
