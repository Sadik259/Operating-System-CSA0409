#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Error in fork
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("PID  = %d\n", getpid());   // Get child's process ID
        printf("PPID = %d\n", getppid());  // Get parent process ID
    }
    else {
        // Parent process
        printf("Parent Process:\n");
        printf("PID  = %d\n", getpid());   // Get parent's process ID
        printf("PPID = %d\n", getppid());  // Get parent's parent process ID (usually the shell)
    }

    return 0;
}
