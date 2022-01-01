#include "filetransfer_operations.h"

int push_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd)
{
    if (access(filePath, F_OK) != 0) return 1;
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, PUSH_FILE,
                        filePath, devicePath, NULL};
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

int push_sync_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd)
{
    if (access(filePath, F_OK) != 0) return 1;
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, PUSH_FILE,
                        filePath, devicePath, SYNC_FLAG, NULL};
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

int pull_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, PULL_FILE,
                        filePath, devicePath, NULL};
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

int install_package(char* device, char* port, char* filePath, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, INSTALL_PCKG,
                        filePath, NULL};
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

int install_multi_package(char* device, char* port, char* filePath, char* args, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, INSTALL_ATOM_PCKGS,
                        filePath, args, NULL};
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

int uninstall_package(char* device, char* port, char* packageName, int keepData, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, UNINSTALL_PCKG,
                        packageName, keepData == 1 ? KEEP_DATA_FLAG : NULL, NULL};
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