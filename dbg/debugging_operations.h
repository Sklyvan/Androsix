#ifndef ANDROSIX_DEBUGGING_OPERATIONS_H
#define ANDROSIX_DEBUGGING_OPERATIONS_H

#include "debugging_commands.h"
#include "../includes.h"

int export_bugreport(char* device, char* port, char* path, int stdout_fd, int stderr_fd);
int wait_for_state(char* device, char* port, char* state, char* transport, int stdout_fd, int stderr_fd);
int get_state(char* device, char* port, int stdout_fd, int stderr_fd);
int get_serialnumber(char* device, char* port, int stdout_fd, int stderr_fd);
int get_devicepath(char* device, char* port, int stdout_fd, int stderr_fd);

int remount_partitions(char* device, char* port, int reboot, int stdout_fd, int stderr_fd);
int reboot_atmode(char* device, char* port, char* mode, int stdout_fd, int stderr_fd);
int enter_root(char* device, char* port, int stdout_fd, int stderr_fd);
int exit_root(char* device, char* port, int stdout_fd, int stderr_fd);
int listen_usb(char* device, char* port, int stdout_fd, int stderr_fd);

#endif