from enum import Enum
from collections import namedtuple

class PieceColor(Enum):
    WHITE = 1
    BLACK = -1

class PieceType(Enum):
    P = 1
    N = 2
    B = 3
    R = 4
    Q = 5
    K = 6

class Column(Enum):
    a = 0
    b = 1
    c = 2
    d = 3
    e = 4
    f = 5
    g = 6
    h = 7

if __name__ == '__main__':
    print(Column(7).name)
    a = PieceType(1)
    print(isinstance(a, PieceType))