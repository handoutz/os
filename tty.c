#include <system.h>
#include <io/tty.h>
#include <fs/vfs.h>

#define TTY_INPUT_MAXLEN 512

char cur_input[TTY_INPUT_MAXLEN];
int cur_input_n=0;

void tty_init() {
	hook_keyboard(tty_key_down);
	tty_show_prompt();
}
void tty_show_prompt() {
	puts("> ");
}
void tty_key_down(char c) {
	putch(c);
	cur_input[cur_input_n]=c;
	cur_input_n++;
	if(c == '\n') {
		tty_on_enter();
	}
}
void tty_on_enter() {
	cur_input[cur_input_n]='\0';
	cur_input_n = 0;
	int i;

	char* cmd = malloc(32);
	char* rest = malloc(TTY_INPUT_MAXLEN - 32);
	int foundCmd = 0;
	int r=0;
	int cmdLen = 0;
	for(i=0;i<TTY_INPUT_MAXLEN;i++) {
		char cur = cur_input[i];
		if(cur == '\0'){
			break;
		}
		if(foundCmd == 0 && cur != ' ') {
			cmd[i] = cur;
			cmdLen++;
		} 
		if(foundCmd == 0 && cur == ' ') {
			foundCmd = 1;
			cmd[i] = '\0';
		} else if(foundCmd == 1 && cur != '\n' && cur != '\r'){
			rest[r++] = cur;
		}
	}
	rest[r] = '\0';
	if(foundCmd == 0) {
		cmd[cmdLen] = '\0';
	}
	if(strcmp(cmd, "echo")) {
		printl(rest);
	} else if(strcmp(cmd, "ls")) {
		vfs_node *node = vfs_map(rest);
		puts("Directory ");
		puts(node->name);
		printl("");
		vfs_node *child = node->first_child;
		while(child != NULL) {
			printl(child->name);
			child = child->next;
		}
	}

	for(i=0;i<TTY_INPUT_MAXLEN;i++){
		cur_input[i]='\0';
	}
	tty_show_prompt();
}
