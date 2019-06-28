#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HASHSIZE 101

struct nlist
{
	struct nlist *next; /*next entry in chain*/
	char *name; /*defined name*/
	char *defn; /*replacement text*/
};

static struct nlist *hashtab[HASHSIZE]; /*pointer table*/

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

char *strdup(const char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if((np = lookup(name)) == NULL) /*name not found*/
	{
		np = (struct nlist *) malloc(sizeof(*np));
		if(np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}  else							/*already there, in the table*/
		free ((void*) np->defn); /*free previous defn*/
	if((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}


int getword(char *, int);

#define MAXWORD 100

int main(int argc, char const *argv[])
{
	char word[MAXWORD]; // to find #define directive
	char name[MAXWORD];
	char rtext[MAXWORD];
	struct nlist * result;

	while(getword(word, MAXWORD) > 0)
	{	
		/* can't support expressions like this one:
		#define max(A, B) ((A) > (B) ? (A) : (B))*/
		if(strcmp(word, "define") == 0)
		{
			getword(name, MAXWORD);
			getword(rtext, MAXWORD);
			printf("%s\n", rtext);
			install(name, rtext);
		}
	}

	if(argv[1] != NULL)
		if((result = lookup(argv[1])) != NULL)
			printf("Definition: %s\n", result->defn);
		else
			printf("FeelsBadMan :(\n");
	return 0;
}

/*--------------------------------------------------------------------*/

char *strdup(const char *s) /*make a duplicate of s*/
{
	char *p;

	p = (char *) malloc (strlen(s) + 1); /*+1 for '\0'*/
	if (p != NULL)
		strcpy(p, s);
	return p;
}

int getch();
void ungetch(int c);

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	while (isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = c;


	if (!isalpha(c) && !isdigit(c)) // for digits
	{
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;/* next free position in buf */

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* возвращение символа в поток ввода */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}