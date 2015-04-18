#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Comparator)(void* item1, void* item2);

struct Node{
	struct treeNode* value;
	struct Node* next;
};

struct treeNode{
	struct treeNode* parent;
	struct Node* child;
	void* employee; 
};

typedef struct{
	struct treeNode* start;
	Comparator comparatorFun;
}Tree;

Tree* createTree(Comparator comparator);
void destroyTree(Tree* tree);
void insertNode(Tree* tree, void* emp, void* boss);
void removeNode(Tree* tree, void* emp);
struct treeNode* findNode(Tree* tree, void* key);