#ifndef _ACAUTO_H_
#define _ACAUTO_H_


typedef struct Trie
{
	int next[500010][26],fail[500010],end[500010];
	int root,L;
}Trie;

Trie* init(Trie *T);
Trie* insert(char buf[],Trie *T);
Trie* build(Trie *T);
int query(char buf[],Trie *T);
void debug(Trie *T);
#endif
