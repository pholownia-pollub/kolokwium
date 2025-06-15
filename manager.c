#include "manager.h"
#include "worker.h"
#include <stdlib.h>
#include <unistd.h>

void create_workers() {
	const char *names[] = {"Alice", "Bob", "Eve", "Tom"};
	int pipes[4][2];
	pid_t pids[4];
	for(int i = 0; i < 4; i++) {
		pid_t pid = fork();
		pids[i] = pid;
		pipe(pipes[i]);

		switch(pid) {
			case 0:
			worker_process(names[i], pipes[i][0]);
				break;	
		}
	}



	for (int i = 0; i < 4; ++i) {
        	wait(pids[i]);
	}

}
