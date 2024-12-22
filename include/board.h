#ifndef BOARD_H
#define BOARD_H

#define INIT_POS 2
#define INIT_H 8
#define INIT_W 8
#define MAX_H 12
#define MAX_W 12

/*
 * You can bitshift the color once to the left then 'or' with the piece color to determine color pair.
 */
typedef struct Square
{
    int color;       // 0 white, 1 black
    int active;      // bool
    int occupied;    // 0=false, otherwise id of piece
} square_t;

void init_board(square_t board[MAX_H][MAX_W]);

#endif
