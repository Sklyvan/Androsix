#ifndef ANDROSIX_FILETRANSFER_OPERATIONS_H
#define ANDROSIX_FILETRANSFER_OPERATIONS_H

int push_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd);
int push_sync_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd);
int pull_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd);

int install_package(char* device, char* port, char* filePath, int stdout_fd, int stderr_fd);
int install_multi_package(char* device, char* port, char* filePath, char* args, int stdout_fd, int stderr_fd);
int uninstall_package(char* device, char* port, char* packageName, int keepData, int stdout_fd, int stderr_fd);

#include "constants.h"
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include "filetransfer_commands.h"

#endif