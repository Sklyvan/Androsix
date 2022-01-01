# Androsix

Androsix is a set of functions written in C & [POSIX ](https://en.wikipedia.org/wiki/POSIX) to facilitate the communication with [Android Debug Bridge](https://developer.android.com/studio/command-line/adb) inside a C or C++ application.

The majority of the functions have an argument to indicate where you want to send the standard output and the standard error. If you pass a -1, it uses default values.



## Function Structure

```c
int function_name(...., int stdout_fd, int stderr_fd);
```

All this functions are creating a child process to do the work. Father process just sets the default stdout and stderr in case of -1, creates the child process and returns the child exit status.

All the functions return an integer that tells the user the exit status of the ADB process that has been created. If the functions returns 0, it means that everything went good, otherwise, something went wrong.

After the function arguments, we get an integer to send the standard output and an integer to send the standard error. If this values are -1, the output goes to the default value (1 for stdout and 2 for stderr). In case that you want to save the output to a text buffer, you can use a [pipe](https://linux.die.net/man/2/pipe).



## Functions

Now, there's going to be a small explanation on the parameters of each funcion and what does it do.

##### Check for ADB Installation

```c
int adb_installed_at(const char* atPath);
```

This function is the only one that does not recieve the stdout and stderr parameters, thats because this funcion does not use any ADB utility and it does not generate any output. That's just a function to know if adb is installed at *atPath* location. It returns 0 if its installed.



##### Open TCPIP on Port (adb tcpip port, adb -s device tcpip port)

```c
int open_tcpip(char* port, int stdout_fd, int stderr_fd);
```

This function is the way to start ADB lisening on TCP on *port*. This function is used when there's one or zero devices connected. 

```c
int open_tcpip_connection(char* device, char* port, int stdout_fd, int stderr_fd);
```

This functions does the same thing as the previous one, but in this case, it does the TCPIP connection to a specific device. This function is useful when more than one device is connected.



##### Connect to Device (adb connect device:port)

```c
int connect_to(char* device, char* port, int stdout_fd, int stderr_fd);
```

With this function we can connect ADB to our device by its IP address.



##### Disconnect from Device (adb disconnect device:port)

```c
int disconnect_from(char* device, char* port, int stdout_fd, int stderr_fd);
```

With this function we can disconnect our device port from the ADB connection.

##### 

##### Get List of Devices (adb devices)

```c
int get_device_list(int stdout_fd, int stderr_fd);
```

This function does not recieve any parameter, since it just sends a list of the connected devices with ADB to the stdout_fd.



##### Send a Shell Command to Device (adb -s device shell command)

```c
int send_shell_command(char* device, char* port, char* command, int stdout_fd, int stderr_fd);
```

This function allows us to send any UNIX command to the ADB shell of a specific device using the selected port. The command can be something without arguments like *ls* or something with arguments like *ls -l*, command should be a string, for example: "ls -l".

Have in mind that the shell uses stdout and stderr, so if the command goes wrong, the error message is going through stderr,



##### Kill Server (adb kill-server)

```c
int kill_server(int stdout_fd, int stderr_fd);
```

Simple function, it just calls to the command to kill the server if its running.
