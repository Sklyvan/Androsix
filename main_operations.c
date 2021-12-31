#include <string.h>
#include "main_operations.h"

int adb_installed_at(const char* atPath)
{
    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        if (access(atPath, F_OK) != -1)
            exit(0);
        else
            exit(1);
    }
    else
    {
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}

int open_tcpip_connection(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* argv[] = {ADB_MAIN_CALL, "-s", device, ADB_OPEN_CONNECTION, port, NULL};
        dup2(stdout_fd, 1); // Redirect stdout to the pipe.
        dup2(stderr_fd, 2); // Redirect stderr to the pipe.
        execvp(argv[0], argv);
        exit(-1);
    }
    else
    {
        // Wait for the child process to finish
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}

int open_tcpip(char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* argv[] = {ADB_MAIN_CALL, ADB_OPEN_CONNECTION, port, NULL};
        dup2(stdout_fd, 1); // Redirect stdout to the pipe.
        dup2(stderr_fd, 2); // Redirect stderr to the pipe.
        execvp(argv[0], argv);
        exit(-1);
    }
    else
    {
        // Wait for the child process to finish
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}

int connect_to(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, ADB_CONNECT_DEVICE, deviceInformation, NULL};
        dup2(stdout_fd, 1); // Redirect stdout to the pipe.
        dup2(stderr_fd, 2); // Redirect stderr to the pipe.
        execvp(argv[0], argv);
        free(deviceInformation);
        exit(-1);
    }
    else
    {
        // Wait for the child process to finish
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}

int disconnect_from(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, ADB_DISCONNECT_DEVICE, deviceInformation, NULL};
        dup2(stdout_fd, 1); // Redirect stdout to the pipe.
        dup2(stderr_fd, 2); // Redirect stderr to the pipe.
        execvp(argv[0], argv);
        free(deviceInformation);
        exit(-1);
    }
    else
    {
        // Wait for the child process to finish
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}

int get_device_list(int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* argv[] = {ADB_MAIN_CALL, ADB_GET_DEVICES, NULL};
        dup2(stdout_fd, 1); // Redirect stdout to the pipe.
        dup2(stderr_fd, 2); // Redirect stderr to the pipe.
        execvp(argv[0], argv);
        exit(-1);
    }
    else
    {
        // Wait for the child process to finish
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}

int send_shell_command(char* device, char* port, char* command, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, ADB_SHELL_COMMAND, command, NULL};
        dup2(stdout_fd, 1); // Redirect stdout to the pipe.
        dup2(stderr_fd, 2); // Redirect stderr to the pipe.
        execvp(argv[0], argv);
        free(deviceInformation);
        exit(-1);
    }
    else
    {
        // Wait for the child process to finish
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}

int kill_server(int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* argv[] = {ADB_MAIN_CALL, ADB_KILL_SERVER, NULL};
        dup2(stdout_fd, 1); // Redirect stdout to the pipe.
        dup2(stderr_fd, 2); // Redirect stderr to the pipe.
        execvp(argv[0], argv);
        exit(-1);
    }
    else
    {
        // Wait for the child process to finish
        waitpid(childID, &childStatus, 0);
    }
    return childStatus;
}
