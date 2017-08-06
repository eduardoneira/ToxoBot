#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int pipefd[2];

    pipe(pipefd);

    cout << "Starting ToxoBot" << endl;

    // Start stdin process
    pid_t pid = fork();
    if (pid == 0) {
        dup2(pipefd[0],0);
        execl("./pipe_in.sh", "./pipe_in.sh", (char *) 0);
        perror("execl failed");
        return -1;
    }

    cout << "TOXOBOT: pid stdin process: " << pid << endl;

    // Start stdout process
    pid = fork();
    if (pid == 0) {
        dup2(pipefd[1],1);
        execl("./pipe_out.sh","./pipe_out.sh", (char *) 0);
        perror("execl failed");
        return -1;
    }

    cout << "TOXOBOT: pid stdout process: " << pid << endl;

    // Wait for both process to finish
    wait(NULL);
    wait(NULL);

    cout << "Childs have stopped. Exiting" << endl;
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}