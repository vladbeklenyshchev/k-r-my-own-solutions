#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tnode /*the tree node:*/
{
	char *word; /*points to the text*/
	int count;  /*number of occurrences*/
	struct tnode *left; /*left child*/
	struct tnode *right;/*right child*/
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode*);
int getword(char *, int);

/*now is the time for all good men to come to the aid of their party*/
int main(int argc, char const *argv[])
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while(getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char 		 *strdup(const char *);

struct tnode * addtree(struct tnode *p, char *w)
{
	int cond;
	if (p == NULL) /*a new word has arrived*/
	{
		p = talloc(); // create a new node
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++; /*repeated word*/
	else if (cond < 0) /*less than into left subtree*/
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	printf("sizeof(struct tnode) = %d\n", sizeof(struct tnode));
	return (struct tnode *) malloc (sizeof(struct tnode));
}

char *strdup(const char *s) /*make a duplicate of s*/
{
	char *p;

	p = (char *) malloc (strlen(s) + 1); /*+1 for '\0'*/
	if (p != NULL)
		strcpy(p, s);
	return p;
}

/***********************************************************/

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
	
	if (!isalpha(c)) 
	{
		*w = '\0';
		return c;
	}
	
	for ( ; --lim > 0; w++)
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
	return (bufp > 0) ? buf [--bufp] : getchar(); 
}

void ungetch(int c) /* возвращение символа в поток ввода */ 
{ 
	if (bufp >= BUFSIZE) 
		printf("ungetch: too many characters\n"); 
	else 
		buf [bufp++] = c; 
} 
