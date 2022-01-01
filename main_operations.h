#ifndef ANDROSIX_MAIN_OPERATIONS_H
#define ANDROSIX_MAIN_OPERATIONS_H

#include "main_commands.h"
#include "includes.h"

int adb_installed_at(const char* atPath);
int open_tcpip_connection(char* device, char* port, int stdout_fd, int stderr_fd);
int open_tcpip(char* port, int stdout_fd, int stderr_fd);
int connect_to(char* device, char* port, int stdout_fd, int stderr_fd);
int disconnect_from(char* device, char* port, int stdout_fd, int stderr_fd);
int get_device_list(int stdout_fd, int stderr_fd);
int send_shell_command(char* device, char* port, char* command, int stdout_fd, int stderr_fd);
int start_server(int stdout_fd, int stderr_fd);
int reconnect_server(int stdout_fd, int stderr_fd);
int kill_server(int stdout_fd, int stderr_fd);

#endif