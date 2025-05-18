#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
int main() {
	int i,j;
	initscr();
        for(i=0;i<9;i++)
	{
		for(j=0;j<40;j++)
		{
			printw("%s", "Hello World");
			move(j,i+12);
			refresh();
                        sleep(1);
		}
	}
	//	sleep(2);
	endwin();
	exit(EXIT_SUCCESS);
}
