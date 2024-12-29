#include "../include/game.h"
#include "../include/render.h"
#include <ncurses.h>
#include <stdio.h>

int main(void)
{
    gstate_t state[N_PLAYERS];
    model_t  models[N_PTYPE];
    square_t board[MAX_W][MAX_H];
    piece_t  pieces[N_PIECES];
    WINDOW  *windows[N_WIN];

    init_state(state);
    init_models(models);
    init_board(board);
    init_game(board, pieces);

    if(start(windows) != 0)
    {
        endwin();
        perror("render.start");
        return -1;
    }

    render_board(windows[W_BOARD], models, board, pieces);

    get_input();
    cleanup(windows);
    return 0;
}
