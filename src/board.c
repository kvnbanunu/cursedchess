#include "../include/board.h"
#include <string.h>

void init_board(square_t board[MAX_H][MAX_W], bounds_t* bounds)
{
    memset(board, 0, sizeof(square_t) * MAX_H * MAX_W);
    for(int i = 0; i < MAX_W; ++i)
    {
        for(int j = 0; j < MAX_H; ++j)
        {
            if(i >= INIT_POS && i < INIT_POS + INIT_W && j >= INIT_POS && j < INIT_POS + INIT_H)
            {
                board[i][j].active = 1;
            }
            board[i][j].color = (i + j) % 2;
        }
    }
    bounds->x_min = INIT_POS;
    bounds->x_max = INIT_POS + INIT_W;
    bounds->y_min = INIT_POS;
    bounds->y_max = INIT_POS + INIT_H;
}
