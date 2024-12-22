#include "../include/render.h"
#include "../include/board.h"
#include "../include/piece.h"

int start(WINDOW *windows[N_WIN])
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    if(has_colors() == FALSE)
    {
        printw("No color");
        getch();
        return -1;
    }
    start_color();
    init_pair(WW, COLOR_WHITE, COLOR_CYAN);
    init_pair(BW, COLOR_BLACK, COLOR_CYAN);
    init_pair(WB, COLOR_WHITE, COLOR_BLUE);
    init_pair(BB, COLOR_BLACK, COLOR_BLUE);

    box(stdscr, 0, 0);
    refresh();
    windows[OPPONENT] = newwin(1, MAX_W, 1, 1);
    windows[BOARD]    = newwin(MAX_H, MAX_W, 2, 1);
    windows[PLAYER]   = newwin(1, MAX_W, MAX_H + 2, 1);
    keypad(windows[BOARD], TRUE);
    mousemask(BUTTON1_CLICKED, NULL);
    return 0;
}

void render_board(WINDOW *win, model_t models[N_PTYPE], square_t board[MAX_H][MAX_W], piece_t pieces[N_PIECES])
{
    wclear(win);
    for(int x = 0; x < MAX_W; ++x)
    {
        for(int y = 0; y < MAX_H; ++y)
        {
            square_t sq = board[x][y];
            piece_t  p;
            if(!sq.active)
            {
                continue;
            }
            if(!sq.occupied)
            {
                mvwaddch(win, y, x, ' ' | COLOR_PAIR((sq.color << 1) + 1));
                continue;
            }
            p = pieces[sq.occupied - 1];
            mvwaddch(win, y, x, models[p.type].ch | COLOR_PAIR(((sq.color << 1) | p.color) + 1) | A_BOLD);
        }
    }
    wrefresh(win);
}

void get_input()
{
    MEVENT e;
    int    ch;
    while((ch = getch()) != 'q')
    {
        if(ch == KEY_MOUSE)
        {
            if(getmouse(&e) == OK)
            {
                if(e.bstate & BUTTON1_CLICKED)
                {
                    move(e.y, e.x);
                    refresh();
                }
            }
        }
    }
}

void cleanup(WINDOW *windows[N_WIN])
{
    for(int i = 0; i < N_WIN; ++i)
    {
        delwin(windows[i]);
    }
    endwin();
}
