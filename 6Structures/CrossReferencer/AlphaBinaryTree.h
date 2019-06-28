#pragma once
struct tnode
{
	struct tnode * left;
	struct tnode * right;
	char * word;
	struct node * first;
};

char noisewords[][19];

struct tnode *addtree(struct tnode *, char *, int);
struct tnode * find(struct tnode *p, const char * word);
struct tnode * removetreenode(struct tnode * p, char * word);
struct tnode *uniontree(struct tnode *root, struct tnode *p);
void treeprint(struct tnode*);
struct tnode *talloc(void);