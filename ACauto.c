#include <stdio.h>
#include <string.h>
#include "ACauto.h"
#include "queue.h"


int newnode(Trie *T)
{
	for(int i = 0;i <26;i++) T->next[T->L][i] = -1;
	T->end[T->L++] = 0;
	return T->L-1;
}
Trie* init(Trie *T){
	T->L = 0;
	T->root = newnode(T);
	return T;
}
Trie* insert(char buf[],Trie *T){
	int len = strlen(buf);
	int now = T->root;
	for(int i = 0;i < len;i++){
		if(T->next[now][buf[i]-'a'] == -1) T->next[now][buf[i]-'a'] = newnode(T);
		now = T->next[now][buf[i]-'a'];
	}
	T->end[now]++;
	return T;
}

Trie* build(Trie *T){
	queue *Head;
	Head = qInit(Head);
	T->fail[T->root] = T->root;
	for(int i = 0;i <26;i++)
		if(T->next[T->root][i] == -1) T->next[T->root][i] = T->root;
		else{
			T->fail[T->next[T->root][i]] = T->root;
			Head = qPush(Head,T->next[T->root][i]);
		}
	while(!qEmpty(Head)){
		int now = qFront(Head);
		Head = qPop(Head);
		for(int i = 0;i < 26;i++)
			if(T->next[now][i] == -1) T->next[now][i] = T->next[T->fail[now]][i];
			else{
				T->fail[T->next[now][i]] = T->next[T->fail[now]][i];
				Head = qPush(Head,T->next[now][i]);
			}
	}
	return T;
}

int query(char buf[],Trie *T){
	int len = strlen(buf);
	int now = T->root;
	int res = 0;
	for(int i = 0;i< len;i++){
		now = T->next[now][buf[i]-'a'];
		int temp = now;
		while(temp != T->root){
			res += T->end[temp];
			//T->end[temp] = 0;
			temp = T->fail[temp];
		}
	}
	return res;
}

void debug(Trie *T){
	for(int i = 0;i < T->L;i++){
		printf("id = %3d,fail = %3d,end = %3d,chi = [",i,T->fail[i],T->end[i]);
		for(int j = 0;j < 26;j++) printf("%2d",T->next[i][j]);
		printf("]\n");
	}
}


