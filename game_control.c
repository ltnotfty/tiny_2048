#include "game_control.h"

int quit = 0;
int scores = 0;
int max_scores = 0;
int game_over = 0;


void game_init ( void )
{
    init_sys_settings();

    init_game();

}

void game_loop( void )
{
    int ch;
    
    draw_frame();
    while ( !quit ) {
        ch = getch();
	quit = process_input( ch );
        game_over = is_end();

	if (!quit && ch != 'r') {
		put_new_number( -1 );
	}	
        draw_frame();
    }
    clear();
    mvprintw(10, 10, "!PRESS ANY KEY to quit");
    getch();

}
void game_end( void )
{

    getch();
    endwin();
}


void init_ncurse_settings( void )
{
    initscr();
    start_color();

    for ( int i = 1; i < 12; ++i ) {
        init_pair( i, (i % 6) + 1, COLOR_BLACK );
    }
    // resizeterm( 50, 50);
    noecho();
}
void init_game( void )
{
    init_grid();
    game_over = 0;
    scores = 0;
}

void init_sys_settings( void ) 
{
    
    init_ncurse_settings();
    quit = 0;
    srand( time(NULL) );
}
int process_input( int ch )
{
    switch ( ch )
    {
        case 'a':
	case 'A':
		move_to( LEFT );
		break;
	case 's':
	case 'S':
		move_to( DOWN );
		break;
	case 'd':
	case 'D':
		move_to( RIGHT );
		break;
	case 'w':
	case 'W':
		move_to( UP );
		break;
	case 'r':
	case 'R':
                init_game( );
		break;
	case 'q':
	case 'Q':
		return 1;
	default:
		break;
    }

    return 0;
}

