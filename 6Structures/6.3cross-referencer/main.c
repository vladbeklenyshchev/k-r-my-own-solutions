#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct node
{
	struct node * next;
	int snum;
};

struct tnode
{
	struct tnode * left;
	struct tnode * right;
	/*--------------------*/
	char * word;
	struct node * first; 
};

char * noisewords[] = {"the", "a", 
	"and", "or", "either", "as", "before", "because", "that", "nor", "neither",
	"only", "just", "not", "else", 
	"along", "in", "on", "for"
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode*);
struct tnode * find(struct tnode *p, const char * word);
struct tnode * removetreenode(struct tnode * p, char * word);

int getword(char *, int);

int main(int argc, char const *argv[])
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	int snum = 1;
	int c;
	while((c = getword(word, MAXWORD)) != EOF)
	{
		if(c == '\n')
			++snum;
		if(isalpha(word[0]))
			root = addtree(root, word, snum); // we works only with root
	}

	/*for (int i = 0; i < 19; ++i)
		root = removetreenode(root, noisewords[i]);
	*/
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
struct node *lalloc(void);
char 		 *strdup(const char *);

struct node *addnode(struct node * cur, int snum)
{
	if(cur->next == NULL) // Base case for list
	{
		cur->next = lalloc();
		cur = cur->next;
		cur->next = NULL;
		cur->snum = snum;
		return cur;
	}
	return addnode(cur->next, snum);
}

struct tnode * find(struct tnode *p, const char * word)
{
	int cond;

	if (p == NULL) return p;
	else if ((cond = strcmp(word, p->word)) == 0) return p; // found!!!
	else if (cond < 0) return find(p->left, word); // look up in left subtree
	else 			  return find(p->right, word); // look up in right subtree
												   //return NULL; // item not found
}

struct tnode *addtree(struct tnode *p, char * word, int snum)
{
	int cond;
	if (p == NULL) /*BASE CASE: a new word has arrived*/
	{
		p = talloc(); // create a new node
		p->word = strdup(word);
		p->left = p->right = NULL;
		/*------------------------*/
		p->first = lalloc();
		p->first->next = NULL;
		p->first->snum = snum;
	} 
	else if ((cond = strcmp(word, p->word)) == 0)
		addnode(p->first, snum);
	else if (cond < 0) /*less than into left subtree*/
		p->left = addtree(p->left, word, snum);
	else
		p->right = addtree(p->right, word, snum);
	return p;
}

struct tnode *uniontree(struct tnode *root, struct tnode *p)
{
	int cond;
	if (root == NULL || (root->first == NULL &&
		root->word == NULL && root->left == NULL && root->right == NULL))
		root = p;
	else if ((cond = strcmp(p->word, root->word)) == 0)
		;
	else if (cond < 0)
		root->left = uniontree(root->left, p);
	else
		root->right = uniontree(root->right, p);
	return root;
}

struct tnode * removetreenode(struct tnode * root, char * word)
{
	struct tnode * found;
	found = find(root, word);
	if (found != NULL)
	{
		struct tnode * tleft = found->left;
		struct tnode * tright = found->right;
		
		// 1. Kludge solution :)
		found->left = found->right = NULL;
		found->first = NULL; found->word = NULL;
		
		if (tleft != NULL)
			root = uniontree(root, tleft);
		if (tright != NULL)
			root = uniontree(root, tright);
	}
	return root;
}


void listprint(struct node *cur)
{
	if (cur != NULL)
	{
		printf("%d ", cur->snum);
		listprint(cur->next);
	}
}

void treeprint(struct tnode *p)
{
	// 2. Kludge solution :)
	if (p != NULL && p->word != NULL)
	{
		treeprint(p->left);
		printf("%s ", p->word);
		listprint(p->first);
		printf("\n");
		treeprint(p->right);
	}
}

/**********************************************************/

struct tnode *talloc(void)
{
	//printf("sizeof(struct tnode) = %d\n", sizeof(struct tnode));
	return (struct tnode *) malloc (sizeof(struct tnode));
}

struct node *lalloc(void)
{
	//printf("sizeof(struct tnode) = %d\n", sizeof(struct node));
	return (struct node *) malloc (sizeof(struct node));
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
	while (isspace(c = getch()) && c != '\n') /*SIMPLIFICATION*/
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

/* Possible input 1:

To find out whether a new word is already in the tree, start at the root and compare the new
word to the word stored at that node. If they match, the question is answered affirmatively. If
the new record is less than the tree word, continue searching at the left child, otherwise at the
right child. If there is no child in the required direction, the new word is not in the tree, and in
fact the empty slot is the proper place to add the new word. This process is recursive, since
the search from any node uses a search from one of its children. Accordingly, recursive
routines for insertion and printing will be most natural.
*/

/* Possible input 2:

now is the time for all good men to come to the aid of their party
*/