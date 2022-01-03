#include "debugging_operations.h"

int export_bugreport(char* device, char* port, char* path, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);
        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, BUG_REPORT, path, NULL};
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

int wait_for_state(char* device, char* port, char* state, char* transport, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* transportState;
        if (strcmp(transport, "any") == 0) transportState = WAIT_FOR_ANY;
        else if (strcmp(transport, "usb") == 0) transportState = WAIT_FOR_USB;
        else if (strcmp(transport, "local") == 0) transportState = WAIT_FOR_LCL;
        strcat(transportState, state);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, transportState, NULL};
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

int get_state(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, GET_STATE, NULL};
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

int get_serialnumber(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, GET_SERIAL, NULL};
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

int get_devicepath(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation, GET_DEVPATH, NULL};
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

int remount_partitions(char* device, char* port, int reboot, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation,
                        REMOUNT, reboot == 1 ? REBOOT_FLAG : NULL, NULL};
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

int reboot_atmode(char* device, char* port, char* mode, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation,
                        REBOOT, mode, NULL};
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

int enter_root(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation,
                        START_ROOT, NULL};
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

int exit_root(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation,
                        EXIT_ROOT, NULL};
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

int listen_usb(char* device, char* port, int stdout_fd, int stderr_fd)
{
    // You can use -1 value to set the default value.
    stdout_fd = stdout_fd == -1 ? 1 : stdout_fd;
    stderr_fd = stderr_fd == -1 ? 2 : stderr_fd;

    pid_t childID = fork(); int childStatus = 1;
    if (childID == 0)
    {
        char* deviceInformation = malloc(strlen(device) + strlen(port));
        strcat(strcat(strcat(deviceInformation, device), ":"), port);

        char* argv[] = {ADB_MAIN_CALL, "-s", deviceInformation,
                        USB_MODE, NULL};
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
