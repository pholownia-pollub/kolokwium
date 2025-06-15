#include "worker.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

const char *worker_name;

void handle_signal(int s) {
	switch(s){
		case SIGHUP:
			printf("%s: Odpoczywam", worker_name);
			break;
		case SIGUSR1:
			printf("%s: Startuje!", worker_name);
			break;
		case SIGINT:
			printf("%s: Koncze", worker_name);
			break;
	}
}

void worker_process(const char * name, int fd) {
	worker_name = name;
	signal(SIGHUP, handle_signal);
	signal(SIGUSR1, handle_signal);
	signal(SIGINT, handle_signal);

	printf("%s: Gotowy do pracy", name);

	char buffer[128];
	while (1) {
		read(fd, buffer, sizeof(buffer) - 1);

        	if (strncmp(buffer, "Podaj imie", 10) == 0) {
            		printf("My name is %s\n", name);
        	} else if (strncmp(buffer, "PID?", 4) == 0) {
            		printf("%s: My PID is %d\n", name, getpid());
        	}
    }
}
