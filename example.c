#include <ncurses.h>

#define N_WIN 3

enum W_NAME
{
    BOARD,
    PLAYER,
    OPPONENT
};

int start(WINDOW *windows[N_WIN], int h, int w);
void pieces(WINDOW *win);
void board(WINDOW *win, int h, int w);
void cleanup(WINDOW *windows[N_WIN]);
void players(WINDOW *windows[N_WIN], int h, int w);

int main(void)
{
    int height = 8;
    int width = 8;
    WINDOW *windows[N_WIN];

    if(start(windows, height, width) != 0)
    {
        endwin();
        return -1;
    }

    board(windows[BOARD], height, width);
    pieces(windows[BOARD]);
    players(windows, height, width);
    getch();
    cleanup(windows);
    return 0;
}

void players(WINDOW *windows[N_WIN], int h, int w)
{
    wprintw(windows[PLAYER], "Player");
    wprintw(windows[OPPONENT], "Opponent");
    wrefresh(windows[PLAYER]);
    wrefresh(windows[OPPONENT]);
}

void pieces(WINDOW *win)
{
    mvwaddch(win, 1, 1, 'K' | COLOR_PAIR(1));
    mvwaddch(win, 1, 2, 'Q' | COLOR_PAIR(2));
    mvwaddch(win, 1, 3, 'B' | COLOR_PAIR(3));
    mvwaddch(win, 1, 4, 'N' | COLOR_PAIR(4));
    wrefresh(win);
}

void cleanup(WINDOW *windows[N_WIN])
{
    for (int i = 0; i < N_WIN; i++)
    {
        delwin(windows[i]);
    }
    endwin();
}

void board(WINDOW *win, int h, int w)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if((i + j) % 2 == 0)
            {
                mvwaddch(win, i+1, j+1, ' ' | COLOR_PAIR(1));
            }
            else
            {
                mvwaddch(win, i+1, j+1, ' ' | COLOR_PAIR(2));
            }
        }
    }
    wrefresh(win);
}

int start(WINDOW *windows[N_WIN], int h, int w)
{
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    if(has_colors() == FALSE)
    {
        printw("No color");
        getch();
        return -1;
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_CYAN);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_CYAN);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);

    box(stdscr, 0, 0);
    refresh();
    windows[BOARD] = newwin(h+2, w+2, 2, 1);
    windows[PLAYER] = newwin(1, w+2, h+4, 1);
    windows[OPPONENT] = newwin(1, w+2, 1, 1);
    wborder(windows[BOARD], ACS_BLOCK, ACS_BLOCK, ACS_BLOCK, ACS_BLOCK, ACS_BLOCK, ACS_BLOCK, ACS_BLOCK, ACS_BLOCK);
    return 0;
}
