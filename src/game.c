#include "../include/game.h"
#include <string.h>

static void add_pieces(square_t board[MAX_W][MAX_H], piece_t p[], piece_t *w, piece_t *b, int x)
{
    w->pos.x = b->pos.x = x;
    memcpy(&p[w->id], w, sizeof(piece_t));
    memcpy(&p[b->id], b, sizeof(piece_t));
    board[x][w->pos.y].occupied = ++w->id;    // these are offset by +1
    board[x][b->pos.y].occupied = ++b->id;
}

void init_game(square_t board[MAX_W][MAX_H], piece_t pieces[])
{
    int     start   = INIT_POS;
    int     end     = INIT_POS + INIT_W;
    piece_t w_piece = {0, PAWN, 0, INIT_POS + INIT_H - 2, 0};
    piece_t b_piece = {N_PIECES_PER_SIDE, PAWN, 0, INIT_POS + 1, 1};
    for(int i = start; i < end; i++)
    {
        add_pieces(board, pieces, &w_piece, &b_piece, i);
    }
    w_piece.pos.y++;
    b_piece.pos.y--;
    w_piece.type = b_piece.type = ROOK;
    add_pieces(board, pieces, &w_piece, &b_piece, start++);
    add_pieces(board, pieces, &w_piece, &b_piece, --end);
    w_piece.type = b_piece.type = KNIGHT;
    add_pieces(board, pieces, &w_piece, &b_piece, start++);
    add_pieces(board, pieces, &w_piece, &b_piece, --end);
    w_piece.type = b_piece.type = BISHOP;
    add_pieces(board, pieces, &w_piece, &b_piece, start++);
    add_pieces(board, pieces, &w_piece, &b_piece, --end);
    w_piece.type = b_piece.type = QUEEN;
    add_pieces(board, pieces, &w_piece, &b_piece, start++);
    w_piece.type = b_piece.type = KING;
    add_pieces(board, pieces, &w_piece, &b_piece, start);
}
