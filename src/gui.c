#include <unistd.h>
#include <sys/utsname.h>

#include "gui.h"
#include "cpuusage.h"

void displaySystem(WINDOW *win){
    struct utsname uts;

    uname(&uts);
    
    mvwprintw(win, 1, 2, "OS: %s", uts.sysname);
    mvwprintw(win, 2, 2, "CPU: %.1f%%", cpuusage_average());
}

void display(){
    initscr();
    noecho();
    cbreak();

    WINDOW *system_window = newwin(10, 20, 0, 0);

    while(1){
        box(system_window, 0, 0);
        displaySystem(system_window);
        wrefresh(system_window);
        refresh();
        sleep(1);
    }

    endwin();
}