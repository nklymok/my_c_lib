#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    if (c < 0x80) {
        char res[1];
        res[0] = (c >> 0 & 0x7F) | 0x00;
        write(1, res, 1);
    }
    else if (c < 0x0800) {
        char res[2];
        res[0] = (c >> 6 & 0x1F) | 0xC0;
        res[1] = (c >> 0 & 0x3F) | 0x80;
        write(1, res, 2);
    }
    else if (c < 0x010000) {
        char res[3];
        res[0] = (c >> 12 & 0x0F) | 0xE0;
        res[1] = (c >> 6 & 0x3F) | 0x80;
        res[2] = (c >> 0 & 0x3F) | 0x80;
        write(1, res, 3);
    }
    else {
        char res[4];
        res[0] = (c >> 18 & 0x07) | 0xF0;
        res[1] = (c >> 12 & 0x3F) | 0x80;
        res[2] = (c >> 6 & 0x3F) | 0x80;
        res[3] = (c >> 0 & 0x3F) | 0x80;
        write(1, res, 4);
    }
}

