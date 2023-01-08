#include "gui.h"

void gui(){
    initscr();

    int height, width, start_x, start_y;
    height = 10;
    width = 20;
    start_x = start_y = 0;

    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Hello!");
    wrefresh(win);

    int c = getch();

    endwin();
}