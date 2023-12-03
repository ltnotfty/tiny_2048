#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "game_control.h"


int main( int argc, char *argv[])
{
    game_init(); 

    game_loop();
    
    game_end();
    return 0;
}
