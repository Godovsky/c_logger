# A simple logging library written in ANSI C (C89)

## How to use
Example:
```c
if (C_LOG_Write(C_LOG_INFO("info.log"), "info %s", "message")) {
    printf("logging error\n");
}
```
See the example.c file in the apps directory.

## Building
At the root of the project directory, type make or mingw32-make (if you are using mingw on windows):

```shell
make
```
Mingw:
```shell
mingw32-make
```
After that, you will see a list of available commands.

To bild libc_logger:
```shell
make lib
```
Mingw:
```shell
mingw32-make lib
```

To build all the binaries:
```shell
make apps
```
Mingw:
```shell
mingw32-make apps
```
After the build, all binary files will be saved to the bin directory.