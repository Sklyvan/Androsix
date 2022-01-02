## File Transfer Operations

##### Push File (adb push filePath devicePath)

```c
int push_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd);
```

Function to send files or directories from local *filePath* to *devicePath*.

##### Push File Synchronization (adb push --sync filePath devicePath)

```c
int push_sync_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd);
```

Function to send files or directories from local *filePath* to *devicePath*, but only the files that are newer on the host that the device.

##### Pull File (adb pull filePath devicePath)

```c
int pull_file(char* device, char* port, char* filePath, char* devicePath, int stdout_fd, int stderr_fd);
```

This function is used to copy files or directories from *devicePath* to *filePath*.

##### Install & Uninstall Package

```c
int install_package(char* device, char* port, char* filePath, int stdout_fd, int stderr_fd);
int uninstall_package(char* device, char* port, char* packageName, int keepData, int stdout_fd, int stderr_fd);
```

Install function allows us to install a package located at *filePath* to our device, uninstall function allows us to uninstall a package called *packageName*. If keepData = 1, the uninstaller is going to keep the data and cache directories.

##### Install Package Atomically

```c
int install_multi_package(char* device, char* port, char* filePath, char* args, int stdout_fd, int stderr_fd);
```

Same function as *install_package* the main difference is that installs a package atomically. You can also add more arguments with args, for example "-r --instant".
