#include "Hashtab.h"
#include <string.h>
#include <stdlib.h>

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

PtrToListInHashTab  lookup(char *s)
{
	PtrToListInHashTab  np;

	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

/* install: put (name, defn) in hashtab */
PtrToListInHashTab  install(char *name, char *defn)
{
	PtrToListInHashTab  np;
	unsigned hashval;

	if((np = lookup(name)) == NULL) /*name not found*/
	{
		np = (ListInHashTab   *) malloc(sizeof(*np));
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


PtrToListInHashTab  undef(char *name)
{
	PtrToListInHashTab  np;
	PtrToListInHashTab  prev;
	for(np = hashtab[hash(name)], prev = NULL; np != NULL;
	 prev = np, np->next)
		if(strcmp(name, np->name) == 0)
		{
			PtrToListInHashTab  res = (ListInHashTab   *) malloc(sizeof(*np));
			res->name = strdup(np->name);
			res->defn = strdup(np->defn);
			if(prev == NULL && np->next != NULL)
				hashtab[hash(name)] = np->next;
			else if(prev != NULL && np->next != NULL)
				prev->next = np->next;
			else if(prev != NULL && np->next == NULL)
				prev->next = NULL;
			else if(prev == NULL && np->next == NULL)
				hashtab[hash(name)] = NULL;
			free(np);
			return res;	
		}
	return NULL;
}