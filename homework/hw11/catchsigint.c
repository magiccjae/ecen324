#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler1(int sig)
{
    printf("Not so simple -- I can't be stopped with a ctr-c!\n");
}

void handler2(int sig)
{
    printf("Nope -- I refuse to be put in the background!\n");
}

void handler3(int sig)
{
    printf("Processes terminated!!\n");
    exit(0);
}

int main()
{
    /* install the SIGINT handlers */
    /* only code changes go right here! */
	signal(SIGINT, handler1);
	signal(SIGTSTP, handler2);
	signal(SIGQUIT, handler3);
	

    /* Don't change rest of code */
    printf("Just try to stop me!\n");
    while (1)
	sleep(1);
}
