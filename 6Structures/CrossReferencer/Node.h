#pragma once
struct node
{
	struct node * next;
	int snum;
};

void listprint(struct node *cur);
struct node *addnode(struct node * cur, int snum);
struct node *lalloc(void);