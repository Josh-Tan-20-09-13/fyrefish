#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

bool Knight::valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const { return false; }
bool Bishop::valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const { return false; }
bool Rook::valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const { return false; }
bool Queen::valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const { return false; }
bool King::valid_move(const Board& board, int from_rank, int from_file, int to_rank, int to_file) const { return false; }
