#include <syslog.h>
#include <system.h>
#include <stdarg.h>

STRING padleft(STRING input, size_t padwidth) {
    auto inlen = strlen(input);
    auto diff = padwidth - inlen;
    if (diff <= 0)return input;
    STRING res = malloc((sizeof(CHAR) * padwidth) + 1);
    int i = 0, j = 0;
    for (i = 0; i < diff; i++)
        res[i] = ' ';
    for (; i < padwidth; i++)
        res[i] = input[j++];
}

void log_prefix_out(CSTRING src, CSTRING level) {
    puts(i2s(seconds_from_boot()));
    puts(": ");
    settextcolor(COLOR_CYAN, COLOR_BLACK);
    putch('[');
    puts((char *) padleft((char *) src, 10));
    puts("] ");
    settextcolor(COLOR_WHITE, COLOR_BLACK);
    if (strcmp((char *) level, "DEBUG"))
        settextcolor(COLOR_LBLUE, COLOR_BLACK);
    if (strcmp((char *) level, "TRACE"))
        settextcolor(COLOR_MAGENTA, COLOR_BLACK);
    puts((char *) level);
    settextcolor(COLOR_WHITE, COLOR_BLACK);
    putch(' ');
}

void log_output(int line, const char *file, const char *level, const char *fmt, ...) {
    log_prefix_out((const unsigned char *) "logging", (const unsigned char *) level);
    puts((char *) file);
    putch(':');
    puts(i2s(line));
    puts(" - ");
    va_list lst;
    va_start(lst, fmt);
    STRING restr = vsprintf((char *) fmt, lst);
    puts(restr);
    printl("");
    va_end(lst);
}
void log_service(CSTRING svc, CSTRING fmt, ...) {
    log_prefix_out((const unsigned char *) "SVCMGR", svc);
    puts(" - ");
    va_list lst;
    va_start(lst, fmt);
    STRING restr = vsprintf((char *) fmt, lst);
    va_end(lst);
    puts((char *) restr);
    printl("");
}