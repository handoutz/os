#include <system.h>

unsigned short *txtMemPtr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void setcursorloc(int x, int y) {
    csr_x = x;
    csr_y = y;
}

void setcursorloc_pt(POINT pt) {
    setcursorloc(pt.x, pt.y);
}

POINT getcursorloc() {
    POINT l;
    l.x = csr_x;
    l.y = csr_y;
    return l;
}

void scroll(void) {
    unsigned blank, temp;
    blank = 0x20 | (attrib << 8);

    if (csr_y >= 25) {
        temp = csr_y - 25 + 1;
        memcpyw(txtMemPtr, txtMemPtr + temp * 80, (25 - temp) * 80 * 2);
        memsetw(((unsigned short *) txtMemPtr) + (25 - temp) * 80, blank, 80);
        csr_y = 25 - 1;
    }
}

void move_csr(void) {
    unsigned temp;
    //idx = [(y*width)+x]
    temp = csr_y * 80 + csr_x;

    outportb(0x3d4, 14);
    outportb(0x3d5, temp >> 8);
    outportb(0x3d4, 15);
    outportb(0x3d5, temp);
}

void cls(void) {
    unsigned blank;
    int i;
    blank = 0x20 | (attrib << 8);
    for (i = 0; i < 25; i++)
        memsetw(((unsigned short *) txtMemPtr) + i * 80, blank, 80);

    csr_x = 0;
    csr_y = 0;
    move_csr();
}

void putch(unsigned char c) {
    unsigned short *loc;
    unsigned att = attrib << 8;
    if (c == 0x08) {
        if (csr_x != 0)csr_x--;
    } else if (c == 0x09) {
        csr_x = (csr_x + 8) & ~(8 - 1);
    } else if (c == '\r') {
        csr_x = 0;
    } else if (c == '\n') {
        csr_x = 0;
        csr_y++;
    } else if (c >= ' ') {
        loc = txtMemPtr + (csr_y * 80 + csr_x);
        //*loc = att;
        //*++loc = c;
        *loc = c | att;
        //*loc = c;
        //*loc = att;
        csr_x++;
    }
    if (csr_x >= 80) {
        csr_x = 0;
        csr_y++;
    }
    scroll();
    move_csr();
}

void puts(char *txt) {
    putus((unsigned char *) txt);
}

void putus(unsigned char *txt) {
    int i, len;
    len = strlen(txt);
    for (i = 0; i < len; i++) {
        putch(txt[i]);
    }
}

void printf(char *txt, ...) {

}

void printl(char *txt) {
    puts(txt);
    putch('\r');
    putch('\n');
}

void settextcolor(unsigned char forecolor, unsigned char back) {
    attrib = (back << 4) | (forecolor & 0x0F);
}

/* Sets our text-mode VGA pointer, then clears the screen for us */
void init_video(void) {
    //txtMemPtr = (unsigned short *) 0xB8000;
    txtMemPtr = (unsigned short*) 0xC00B8000;
    cls();
}

