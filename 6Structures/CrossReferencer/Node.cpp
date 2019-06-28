#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

struct node *addnode(struct node * cur, int snum)
{
	if (cur->next == NULL) // Base case for list
	{
		cur->next = lalloc();
		cur = cur->next;
		cur->next = NULL;
		cur->snum = snum;
		return cur;
	}
	return addnode(cur->next, snum);
}

void listprint(struct node *cur)
{
	if (cur != NULL)
	{
		printf("%d ", cur->snum);
		listprint(cur->next);
	}
}

struct node *lalloc(void)
{
	return (struct node *) malloc(sizeof(struct node));
}