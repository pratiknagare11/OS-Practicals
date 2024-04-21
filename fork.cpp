#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    // Fork to create a child process
    child_pid = fork();

    if (child_pid == -1) {
        // Error handling if fork fails
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        // Execute cp command
        printf("Child process (cp) PID: \n", getpid());
        execlp("cp", "cp", "source", "destination", NULL);
        
        // If exec fails
        perror("exec");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Wait for the child process to finish
        wait(&status);
        printf("Parent process PID: %d\n", getpid());
        printf("cp command executed successfully\n");
    }

    // Fork again to create another child process
    child_pid = fork();

    if (child_pid == -1) {
        // Error handling if fork fails
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        // Execute grep command
        printf("Child process (grep) PID: \n", getpid());
        execlp("grep", "grep", "keyword", "destination", NULL);
        
        // If exec fails
        perror("exec");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Wait for the child process to finish
        wait(&status);
        printf("Parent process PID: %d\n", getpid());
        printf("grep command executed successfully\n");
    }

    return 0;
}