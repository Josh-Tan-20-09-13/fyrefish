#!/usr/bin/env python3

import random

# Seed to allow repeatable random starts
SEED=10
random.seed(SEED)

# Build board
board_size = 8
board = []
for _ in range(0, board_size):
    board.append([0] * board_size)

# Check if is valid move
def valid_move(row, col):
    if 0 <= row < board_size and 0 <= col < board_size and board[row][col] == 0:
        return True
    else:
        return False

# Make a next move
def next_move(row, col, iteration):
    if iteration == board_size ** 2 + 1:
        return True

    moves = [
        (row + 1, col + 2),
        (row + 2, col + 1),
        (row + 2, col - 1),
        (row + 1, col - 2),
        (row - 1, col - 2),
        (row - 2, col - 1),
        (row - 2, col + 1),
        (row - 1, col + 2)
    ]

    for candidate in moves:
        next_row, next_col = candidate
        if valid_move(next_row, next_col):
            board[next_row][next_col] = iteration 

            # DFS next move and see if this tree is valid
            if next_move(next_row, next_col, iteration + 1):
                return True

            # Entire tree is bad, moving on
            board[next_row][next_col] = 0
    return False

if __name__ == "__main__":
    start_row = int(random.random() * board_size)
    start_col = int(random.random() * board_size)
    board[start_row][start_col] = 1
    iteration = 1 
    next_move(start_row, start_col, iteration + 1)
    print(*board, sep='\n')
