#pragma once
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;/* next free position in buf */

int getch();
void ungetch(int c);