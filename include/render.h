#ifndef RENDER_H
#define RENDER_H

#include "board.h"
#include "piece.h"
#include <ncurses.h>

#define N_WIN 3

enum ColorPairs
{
    WW = 1,
    BW,
    WB,
    BB
};

enum W_NAME
{
    BOARD,
    PLAYER,
    OPPONENT
};

int  start(WINDOW *windows[N_WIN]);
void render_board(WINDOW *win, model_t models[N_PTYPE], square_t board[MAX_H][MAX_W], piece_t pieces[N_PIECES]);
void cleanup(WINDOW *windows[N_WIN]);

#endif
