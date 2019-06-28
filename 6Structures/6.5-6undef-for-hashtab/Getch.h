#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;/* next free position in buf */

int getch();
void ungetch(int c);