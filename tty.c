#include <system.h>
#include <fs/fs.hpp>
#include <io/tty.h>
#include <fs/vfs.h>
#include <syslog.h>
#include "cppos/services.h"
#include <arraylist.h>

#define TTY_INPUT_MAXLEN 512

char cur_input[TTY_INPUT_MAXLEN];
int cur_input_n = 0;

void tty_timer_tick(int tick) {
    POINT savedLoc = getcursorloc();
    STRING str = sprintf("%is since boot", seconds_from_boot());
    setcursorloc(SCREEN_WIDTH - strlen(str), SCREEN_HEIGHT - 1);
    puts(str);
    setcursorloc_pt(savedLoc);
}

void tty_init() {
    hook_keyboard(tty_key_down);
    register_to_timer(&tty_timer_tick);
    initialize_svcs();
    tty_show_prompt();
}

void tty_show_prompt() {
    puts("> ");
}

void tty_key_down(char c) {
    putch(c);
    cur_input[cur_input_n] = c;
    cur_input_n++;
    if (c == '\n') {
        tty_on_enter();
    }
}

void tty_on_enter() {
    cur_input[cur_input_n] = '\0';
    cur_input_n = 0;
    int i;

    char *cmd = malloc(32);
    char *rest = malloc(TTY_INPUT_MAXLEN - 32);
    int foundCmd = 0;
    int r = 0;
    int cmdLen = 0;
    for (i = 0; i < TTY_INPUT_MAXLEN; i++) {
        char cur = cur_input[i];
        if (foundCmd == 0 && cur != ' ' && cur != '\0' && cur != '\n' && cur != '\r') {
            //putch(cur);
            cmd[i] = cur;
            cmdLen++;
        }
        if (foundCmd == 0 && (cur == ' ' || cur == '\0')) {
            foundCmd = 1;
            cmd[i] = '\0';
        } else if (foundCmd == 1 && cur != '\n' && cur != '\r' && cur != '\0') {
            rest[r++] = cur;
        }
        if (cur == '\0') {
            break;
        }
    }
    rest[r] = '\0';
    if (foundCmd == 0) {
        cmd[cmdLen] = '\0';
    }
    //TRACE("path=%s", combinePath("lol", "brah"));
    //TRACE("sprintr=%s", sprintf("secs from boot=%i", seconds_from_boot()));
    //TRACE("yeah!!%s", " cool");
    /*_llnode *node = _llcreate_val("asdf");
    _lladd(node, "yes");
    _lladd(node, "no");
    _lladd(node, "no2");
    TRACE("node[0]=%s", (char *) _llget(node, 0));
    TRACE("node[1]=%s", (char *) _llget(node, 1));
    TRACE("node[2]=%s", (char *) _llget(node, 2));
    TRACE("node[3]=%s", (char *) _llget(node, 3));*/

    //DEBUG("(%i,%i)", loc.x, loc.y);
    //DEBUG("cmd=[%s], rest=[%s]", cmd, rest);
    //DEBUG("inrange: %i", CHARINRANGE('c', 'a', 'b', 'c'));
    //DEBUG("this should say 'yes': [%s], 9=[%i]", "yes", 9);
    if (strcmp(cmd, "echo")) {
        printl(rest);
    } else if (strcmp(cmd, "ls")) {
        vfs_node *node = vfs_map(rest);
        puts("Directory ");
        puts(node->name);
        printl("");
        vfs_node *child = node->first_child;
        while (child != NULL) {
            printl(child->name);
            child = child->next;
        }
    } else if (strcmp(cmd, "exit")) {
        DEBUG("yeah we're in here", "");
        asm("cli");
        asm("hlt");
    }

    for (i = 0; i < TTY_INPUT_MAXLEN; i++) {
        cur_input[i] = '\0';
    }
    tty_show_prompt();
}
