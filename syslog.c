#include <syslog.h>
#include <system.h>
#include <stdarg.h>

void log_output(int line, const char *file, const char *level, const char *fmt, ...) {
    puts("[");
    puts(i2s(seconds_from_boot()));
    puts("] ");
    puts((char *) file);
    putch(':');
    puts(i2s(line));
    putch(' ');
    if (strcmp((char *) level, "DEBUG"))
        settextcolor(COLOR_LBLUE, COLOR_BLACK);
    if (strcmp((char *) level, "TRACE"))
        settextcolor(COLOR_MAGENTA, COLOR_BLACK);
    puts((char *) level);
    settextcolor(COLOR_WHITE, COLOR_BLACK);
    puts(" - ");
    va_list lst;
    va_start(lst, fmt);
    BOOL expecting_fmt = FALSE;
    while (*fmt != '\0') {
        if (*fmt == '%') {
            expecting_fmt = TRUE;
        } else if (expecting_fmt == TRUE) {
            expecting_fmt = FALSE;
            switch (*fmt) {
                case 's': {
                    char *s = va_arg(lst, char*);
                    puts(s);
                    break;
                }
                case 'i': {
                    int i = va_arg(lst, int);
                    puts(itoa(i, 10));
                    break;
                }
                case 'c': {
                    int i = va_arg(lst, int);
                    putch((unsigned char) i);
                    break;
                }
            }
        } else {
            putch(*fmt);
        }
        ++fmt;
    }
    va_end(lst);
    printl("");
}