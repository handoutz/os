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
    STRING restr = vsprintf((char *) fmt, lst);
    puts(restr);
    printl("");
    va_end(lst);
}