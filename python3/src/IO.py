import re

import numpy as np

from board import Board, BoardState
from aliases import *

number_pattern = re.compile(r'[12345678]')
white_pattern = re.compile(r'[PNBRKQ]')
black_pattern = re.compile(r'[pnbrkq]')

def fen_to_board(fen: str) -> Board:
    b = Board()
    fen_fields = fen.split(sep=' ')
    piece_position = fen_fields[0]
    piece_rows = piece_position.split('/')
    for i in (range(8)):
        fen_row = piece_rows[i]
        board_row_index = 7-i
        b.board[board_row_index, :] = parse_fen_row(fen_row)

    return b

def parse_fen_row(fen_row: str) -> np.array:
    arr = np.zeros(8)
    index = 7
    elements = list(fen_row)
    while len(elements) > 0:
        c = elements.pop()
        if number_pattern.match(c):
            n = int(c)
            index = index - n
        elif white_pattern.match(c):
            arr[index] = PieceType[c].value
            index = index - 1
        elif black_pattern.match(c):
            arr[index] = -1 * PieceType[c.upper()].value
            index = index - 1

    return arr

def piece_to_string(piece: int) -> str:
    mapping = {
        1: 'P', 2: 'N', 3: 'B', 4: 'R', 5: 'Q', 6: 'K',
        -1: 'p', -2: 'n', -3: 'b', -4: 'r', -5: 'q', -6: 'k',
        0: '.'
    }
    return mapping[piece]

def board_to_string(board: Board) -> str:
    row_str = ''
    for i in range(8):
        row_str = (
                row_str
                + str(8-i) + ' '
                + ' '.join(list(map(piece_to_string, q.board[7-i, :])))
                + '\n'
        )
    row_str = row_str + '  a b c d e f g h'
    return row_str

if __name__ == '__main__':
    a = 'rnbqkbnr/pppp1p1p/8/3K1Pp1/1KK1p3/6Q1/PPPPPKPP/RNBKKBNR w HAkq - 0 1'
    # print(parse_fen_row('rnb1kbnr'))
    q = fen_to_board(a)
    # print(list(map(piece_to_string, q.board[0, :])))
    print(board_to_string(q))
