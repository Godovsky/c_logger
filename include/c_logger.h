/* Copyright (c) 2025 Godov Andrey <andygodov@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef C_LOGGER
#define C_LOGGER

typedef enum { C_LOG_info, C_LOG_user, C_LOG_error, C_LOG_debug, C_LOG_warning } C_LOG_MESSAGE_TYPE;

#define FFL __FILE__, __func__, __LINE__

#define C_LOG_INFO(logFilePath)     (logFilePath), C_LOG_info, FFL
#define C_LOG_USER(logFilePath)     (logFilePath), C_LOG_user, FFL
#define C_LOG_ERROR(logFilePath)    (logFilePath), C_LOG_error, FFL
#define C_LOG_DEBUG(logFilePath)    (logFilePath), C_LOG_debug, FFL
#define C_LOG_WARNING(logFilePath)  (logFilePath), C_LOG_warning, FFL

/** The function of writing a log string to a file or to standard output
*
* @param    logFilePath The path to the log file
* @param    messageType Message type (info, user, error, debug or warning)
* @param    cFilePath   The path to the file from which the logger function was called
* @param    function    The name of the function in which the logger function was called
* @param    line        The line in the file from which the logger function was called
* @param    fmt         The format of the message to be written to a file or to standard output
* @param    ...         Arguments for formatted input, if needed
*
* @return               0 in case of success, 1 in case of error
*/
int C_LOG_Write(const char *logFilePath, C_LOG_MESSAGE_TYPE messageType, const char *cFilePath, const char *function, int line, const char *fmt, ...);

#endif /* C_LOGGER */