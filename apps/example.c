#include <stdio.h>

#include <c_logger.h>

int main(int argc, char *argv[]) {
    /* Pass NULL to a macro of the log type to output the message to the console */
    C_LOG_Write(C_LOG_INFO(NULL), "begin");

    C_LOG_Write(C_LOG_INFO("info.log"), "info %s", "message");
    C_LOG_Write(C_LOG_USER("user.log"), "user %d massage", 10);
    C_LOG_Write(C_LOG_ERROR("errors.log"), "error massage");
    C_LOG_Write(C_LOG_DEBUG("debug.log"), "debug massage (%f)", 123.5);
    C_LOG_Write(C_LOG_WARNING("warning.log"), "warning massage");

    /* A more detailed view of the function.
        FFL is a macro containing data about the file name, function name, and line number */
    C_LOG_Write("info.log", C_LOG_info, FFL, "a more detailed view of the function");

    /* You can use system macros to determine the file name, function, and line number */
    C_LOG_Write("errors.log", C_LOG_error, __FILE__, __func__, __LINE__, "you can use system macros");

    /* Pass "" to a macro of the log type to output the message to the console */
    C_LOG_Write(C_LOG_INFO(""), "end");

    return 0;
}