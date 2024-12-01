#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    char buffer[128];  // Buffer to store messages
    int pid = fork();  // Create a child process

    if (pid < 0) {
        // Error case: fork failed
        printf(1, "Fork failed\n");
        exit();
    } else if (pid == 0) {
        // Child process: reader
        while (1) {
            int sender_pid = receive(buffer);  // Read message from the queue
            printf(1, "Received from PID %d: %s\n", sender_pid, buffer);
        }
    } else {
        // Parent process: writer
        while (1) {
            printf(1, "Enter a message: ");
            gets(buffer, sizeof(buffer));     // Get input from the user
            send(buffer);                     // Send message to the queue
        }
    }
    exit();
}
