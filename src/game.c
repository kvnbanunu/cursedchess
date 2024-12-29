#include "../include/game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_state(gstate_t state[N_PLAYERS])
{
    memset(state, 0, sizeof(gstate_t) * N_PLAYERS);
    for(int i = 0; i < N_PLAYERS; ++i)
    {
        state[i].castle = 1;
    }
}

static void add_pieces(square_t board[MAX_W][MAX_H], piece_t p[N_PIECES], piece_t *w, piece_t *b, int x)
{
    w->pos.x = b->pos.x = x;
    memcpy(&p[w->id], w, sizeof(piece_t));
    memcpy(&p[b->id], b, sizeof(piece_t));
    board[x][w->pos.y].occupied = ++w->id;    // these are offset by +1
    board[x][b->pos.y].occupied = ++b->id;
}

void init_game(square_t board[MAX_W][MAX_H], piece_t pieces[N_PIECES])
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

static void get_moves_king(int castle, model_t model, square_t board[MAX_W][MAX_H], piece_t p, coord_t valid_moves[MAX_VALID])
{
    
}

static void get_moves_queen()
{

}

static void get_moves_rook()
{

}

static void get_moves_bishop()
{

}

static void get_moves_knight()
{

}

static void get_moves_pawn()
{

}

void get_moves(gstate_t state[N_PLAYERS], model_t models[N_PTYPE], square_t board[MAX_W][MAX_H], piece_t pieces[N_PIECES], coord_t valid_moves[MAX_VALID], coord_t selected)
{
    piece_t p = pieces[board[selected.x][selected.y].occupied];
    memset(valid_moves, 0, sizeof(coord_t) * MAX_VALID);
    switch(p.type)
    {
        case KING:
            get_moves_king(state[PLAYER].castle, models[KING], board, p, valid_moves);
            break;
        case QUEEN:
            break;
        case ROOK:
            break;
        case BISHOP:
            break;
        case KNIGHT:
            break;
        case PAWN:
            break;
        default:
            fprintf(stderr, "Invalid ptype: %d\n", p.type);
            exit(EXIT_FAILURE);
    }
}

