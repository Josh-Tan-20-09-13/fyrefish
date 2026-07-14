from collections.abc import Iterable
from dataclasses import dataclass, field
from typing import Union

import numpy as np

from aliases import *
from board import Board, BoardState, Coord

@dataclass
class Move:
    piece: PieceType
    starting_pos: Coord
    ending_pos: Coord
    promotion_target: Union[PieceType, None] = None
    capture: bool = False
    castle: bool = False

# def get_lines(coords: Iterable[Coord], board: Board) -> tuple[list, bool]:
#     destinations = []
#     final_capture = False
#     for c in coords:
#         if board.board[c.row, c.col] < 0:
#             destinations.append(c)
#             final_capture = True
#             break
#         elif board.board[c.row, c.col] > 0:
#             break
#         else:
#             destinations.append(c)
#
#     return destinations, final_capture

def rook_moves(
        position: Coord, board: Board
) -> list[Move]:
    moves = []

    # up moves
    for i in range(position.row+1, 8):
        new_coord = Coord(i, position.col)
        my_move = Move(
            piece=PieceType['R'],
            starting_pos=position,
            ending_pos=new_coord
        )

        if board.board[*new_coord.list()] < 0:
            my_move.capture=True
            moves.append(my_move)
            break
        elif board.board[*new_coord.list()] > 0:
            break
        else:
            moves.append(my_move)

    # down moves
    for i in reversed(range(0, position.row)):
        new_coord = Coord(i, position.col)
        my_move = Move(
            piece=PieceType['R'],
            starting_pos=position,
            ending_pos=new_coord
        )

        if board.board[*new_coord] < 0:
            my_move.capture = True
            moves.append(my_move)
            break
        elif board.board[*new_coord.list()] > 0:
            break
        else:
            moves.append(my_move)

    # right  moves
    for i in range(position.col+1, 8):
        new_coord = Coord(position.row, i)
        my_move = Move(
            piece=PieceType['R'],
            starting_pos=position,
            ending_pos=new_coord
        )

        if board.board[*new_coord] < 0:
            my_move.capture = True
            moves.append(my_move)
            break
        elif board.board[*new_coord.list()] > 0:
            break
        else:
            moves.append(my_move)

    # left  moves
    for i in reversed(range(0, position.col)):
        new_coord = Coord(position.row, i)
        my_move = Move(
            piece=PieceType['R'],
            starting_pos=position,
            ending_pos=new_coord
        )

        if board.board[*new_coord.list()] < 0:
            my_move.capture = True
            moves.append(my_move)
            break
        elif board.board[*new_coord.list()] > 0:
            break
        else:
            moves.append(my_move)

    return moves