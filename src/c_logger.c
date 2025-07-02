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

#include <c_logger.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>


char *get_msg_type_string(C_LOG_MESSAGE_TYPE messageType) {
    switch (messageType) {
        case C_LOG_info:
            return "INFO";
        case C_LOG_user:
            return "USER";
        case C_LOG_error:
            return "ERROR";
        case C_LOG_debug:
            return "DEBUG";
        case C_LOG_warning:
            return "WARNING";
    }

    return NULL;
}
int C_LOG_Write(const char *logFilePath, C_LOG_MESSAGE_TYPE messageType, const char *cFilePath, const char *function, int line, const char *fmt, ...) {
    FILE *fp = stdout;

    va_list ap;
    char *p, *sval;
    int ival, uval;
    long lival, luval;
    double dval;

    time_t t = time(NULL);
    char strTime[32] = "";

    if (NULL == cFilePath) return 1;
    if (1 > strlen(cFilePath)) return 1;

    if (NULL == function) return 1;
    if (1 > strlen(function)) return 1;

    if (NULL != logFilePath)
        if (1 < strlen(logFilePath))
            fp = fopen(logFilePath, "a");


    sprintf(strTime, "%s", ctime(&t));
    p = strrchr(strTime, '\n');
    if (NULL != p)
        *p = '\0';


    fprintf(fp, "[%s] %s %s: %s: %d: ", strTime, get_msg_type_string(messageType), cFilePath, function, line);

    va_start(ap, fmt);
    for (p = (char *)fmt; *p; p++) {
        if (*p != '%') {
            fputc(*p, fp);
            continue;
        }
        switch (*++p) {
            case 'l':
                switch (*++p) {
                    case 'd':
                        lival = va_arg(ap, long int);
                        fprintf(fp, "%ld", lival);
                        break;
                    case 'u':
                        luval = va_arg(ap, long unsigned int);
                        fprintf(fp, "%lu", luval);
                        break;
                    case 'x':
                        lival = va_arg(ap, long int);
                        fprintf(fp, "%lx", lival);
                        break;
                    case 'X':
                        lival = va_arg(ap, int);
                        fprintf(fp, "%lX", lival);
                        break;
                    case 'f':
                        dval = va_arg(ap, double);
                        fprintf(fp, "%lf", dval);
                        break;
                }
                break;
            case 'd':
                ival = va_arg(ap, int);
                fprintf(fp, "%d", ival);
                break;
            case 'u':
                uval = va_arg(ap, int);
                fprintf(fp, "%u", uval);
                break;
            case 'x':
                ival = va_arg(ap, int);
                fprintf(fp, "%x", ival);
                break;
            case 'X':
                ival = va_arg(ap, int);
                fprintf(fp, "%X", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                fprintf(fp, "%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    fputc(*sval, fp);
                break;
            default:
                fputc(*p, fp);
                break;
        }
    }
    va_end(ap);

    fprintf(fp, "\n");

    if (NULL != logFilePath)
        if (1 < strlen(logFilePath))
            fclose(fp);

    return 0;
}

int C_LOG_Write1(const char *logFilePath, C_LOG_MESSAGE_TYPE messageType, const char *cFilePath, const char *function, int line, const char *message) {
    FILE *fp = stdout;

    time_t t = time(NULL);
    char strTime[32] = "";
    char *p = NULL;


    if (NULL == cFilePath) return 1;
    if (1 > strlen(cFilePath)) return 1;

    if (NULL != logFilePath)
        if (1 < strlen(logFilePath))
            fp = fopen(logFilePath, "a");


    sprintf(strTime, "%s", ctime(&t));
    p = strrchr(strTime, '\n');
    if (NULL != p)
        *p = '\0';

    fprintf(fp, "[%s] %s %s: %s: %d: %s\n", strTime, get_msg_type_string(messageType), cFilePath, function, line, message);

    if (NULL != logFilePath)
        if (1 < strlen(logFilePath))
            fclose(fp);

    return 0;
}