#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AlphaBinaryTree.h"
#include "Node.h"
#include "Strdup.h"

char noisewords[][19] = { "the", "a",
"and", "or", "either", "as", "before", "because", "that", "nor", "neither",
"only", "just", "not", "else",
"along", "in", "on", "for"
};

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
		p->word = mystrdup(word);
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

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}