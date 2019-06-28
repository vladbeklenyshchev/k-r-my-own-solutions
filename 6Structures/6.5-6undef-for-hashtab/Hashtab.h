#define HASHSIZE 101

typedef struct nlist *PtrToListInHashTab;

typedef struct nlist   
{
	PtrToListInHashTab    next; /*next entry in chain*/
	char *name; /*defined name*/
	char *defn; /*replacement text*/
}ListInHashTab;

PtrToListInHashTab hashtab[HASHSIZE]; /*pointer table*/

unsigned hash(char *s);
PtrToListInHashTab lookup(char *s);
PtrToListInHashTab install(char *name, char *defn);
PtrToListInHashTab undef(char *name);