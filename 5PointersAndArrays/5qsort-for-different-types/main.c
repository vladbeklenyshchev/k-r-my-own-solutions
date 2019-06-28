#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 		/* max #lines to be sorted */
char *lineptr[MAXLINES]; 	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right,
			int (*comp) (void *, void *));

int numcmp(char *, char *);

int main(int argc, char *argv[])
{
	int nlines;			/* number of input lines read (число считанных строк)*/
	int numeric = 0; 	/* 1 if numeric sort*/

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	printf("numeric=%d\n", numeric);
	if((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		myqsort((void **) lineptr, 0, nlines-1,
			(int (*) (void*, void*)) (numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}

/* qsort: sort v[left]...v[right] into increasing order */
void myqsort(void *v[], int left, int right,
int (*comp)(void *, void *))
{
	int i, last;
	void myswap(void *v[], int, int);
	if (left >= right) /* do nothing if array contains */
		return; /* fewer than two elements */
	myswap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
		myswap(v, ++last, i);
	myswap(v, left, last);
	myqsort(v, left, last-1, comp);
	myqsort(v, last+1, right, comp);
	printf("Where???\n");
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	printf("Numcmp!!!\n");
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void myswap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXLEN 1000 /* max length of any input line */
int mygetline(char *, int);
char *myalloc(int);
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = myalloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for myalloc */
static char *allocp = allocbuf; /* next free position */

char *myalloc(int n) /* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else /* not enough room */
		return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}