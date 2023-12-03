CC= gcc
LDFLAGS= -lncurses

CFLAGS= -g 
TARGET=2048


OBJS = main.o
OBJS += game_core.o
OBJS += game_draw.o
OBJS += game_dir.o
OBJS += game_control.o

${TARGET}: ${OBJS} 
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)
main.o: main.c 
	$(CC) $(CFLAGS) -c $?   

game_control.o: game_control.c 
	$(CC) $(CFLAGS) -c $?   
game_core.o: game_core.c 
	$(CC) $(CFLAGS) -c $?   
game_draw.o: game_draw.c 
	$(CC) $(CFLAGS) -c $?   
game_dir.o: game_dir.c game_dir.h 
	$(CC) $(CFLAGS) -c $?   
test: ui_test.c game_dir.o game_core.o
	$(CC) $(CFLAGS)  $? -o $@ -lcunit   


.PHONY: clean all

all: ${TARGET} test

clean:
	-rm ${TARGET} test  *.o

