#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piece.h"

#define N_PLAYERS 2
#define MAX_VALID 100
#define WHITE 0
#define BLACK 1

typedef struct GameState
{
    int check;
    int enpassant;
    int castle;
}gstate_t;

/**
 * Initializes the state of the two players.
 * @state: array holding the two GameState structs.
 */
void init_state(gstate_t state[N_PLAYERS]);

/**
 *
 */
void init_game(square_t board[MAX_W][MAX_H], piece_t pieces[N_PIECES]);

/**
 *
 */
void get_moves(gstate_t state[N_PLAYERS], model_t models[N_PTYPE], square_t board[MAX_W][MAX_H], const bounds_t* bounds, piece_t pieces[N_PIECES], coord_t valid_moves[MAX_VALID], coord_t selected, int p_id);

#endif
