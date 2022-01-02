# Debugging Operations

These operations are for a more technical use since we are going to be able to export a bug report, work with device states, remount the partitions, reboot and enter as root.

##### Export Bug Report (adb bugreport path)

```c
int export_bugreport(char* device, char* port, char* path, int stdout_fd, int stderr_fd);
```

This function allows us to write the device bug reports to the path, the path can be a directory or a file path (.zip file).

##### Wait for State (adb wait-for-transport-state)

```c
int wait_for_state(char* device, char* port, char* state, char* transport, int stdout_fd, int stderr_fd);
```

This function waits for device to be in the given state (device, recovery, rescue, sideload, bootloader, disconnect) using the given transport (usb, local, any).

##### Get State (adb get-state)

```c
int get_state(char* device, char* port, int stdout_fd, int stderr_fd);
```

Sends through the stdout the device state.

##### Get Serial Number (adb get-serialno)

```c
int get_serialnumber(char* device, char* port, int stdout_fd, int stderr_fd);
```

Sends through the stdout the device serial number.

##### Get Device Path (adb get-devpath)

```c
int get_devicepath(char* device, char* port, int stdout_fd, int stderr_fd);
```

Sends through the stdout the device path.

##### Remount Partitions (adb remount)

```c
int remount_partitions(char* device, char* port, int reboot, int stdout_fd, int stderr_fd);
```

Remounts the device partitions read-write, if reboot=1, the device is going to be rebooted after the remount operation.

##### Reboot Device (adb reboot mode)

```c
int reboot_atmode(char* device, char* port, char* mode, int stdout_fd, int stderr_fd);
```

Reboots the device into the selected mode, the mode can be bootloader, recovery, sideload, sideload-auto-reboot.

##### Root Mode (adb root, adb unroot)

```c
int enter_root(char* device, char* port, int stdout_fd, int stderr_fd);
int exit_root(char* device, char* port, int stdout_fd, int stderr_fd);
```

The first function restarts ADB with root permissions (Device should be rooted) and the second function restarts ADB without root permissions.

##### USB Mode (adb usb)

```c
int listen_usb(char* device, char* port, int stdout_fd, int stderr_fd);
```

Restarts the ADB listening on USB instead of the TCP/IP connection.
