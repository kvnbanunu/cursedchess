#include "../include/game.h"
#include "../include/board.h"
#include <string.h>

static int add_pieces(piece_t p[], piece_t *w, piece_t *b, int id, int x)
{
    w->id++;
    b->id++;
    w->pos.x = b->pos.x = x;
    memcpy(&p[id], w, sizeof(piece_t));
    memcpy(&p[id + N_PIECES_PER_SIDE], b, sizeof(piece_t));
    return id + 1;
}

void init_game(piece_t pieces[])
{
    int     id      = 0;
    int     start   = INIT_POS;
    int     end     = INIT_POS + INIT_W;
    piece_t w_piece = {id, PAWN, 0, INIT_POS + INIT_H - 1, 0};
    piece_t b_piece = {id + N_PIECES_PER_SIDE, PAWN, 0, INIT_POS + 1, 1};
    for(int i = start; i < end; i++)
    {
        id = add_pieces(pieces, &w_piece, &b_piece, id, i);
    }
    w_piece.pos.y++;
    b_piece.pos.y--;
    id           = add_pieces(pieces, &w_piece, &b_piece, id, --start);
    id           = add_pieces(pieces, &w_piece, &b_piece, id, --end);
    w_piece.type = b_piece.type = KNIGHT;
    id                          = add_pieces(pieces, &w_piece, &b_piece, id, --start);
    id                          = add_pieces(pieces, &w_piece, &b_piece, id, --end);
    w_piece.type = b_piece.type = BISHOP;
    id                          = add_pieces(pieces, &w_piece, &b_piece, id, --start);
    id                          = add_pieces(pieces, &w_piece, &b_piece, id, --end);
    w_piece.type = b_piece.type = QUEEN;
    id                          = add_pieces(pieces, &w_piece, &b_piece, id, --start);
    w_piece.type = b_piece.type = KING;
    id                          = add_pieces(pieces, &w_piece, &b_piece, id, --end);
}
