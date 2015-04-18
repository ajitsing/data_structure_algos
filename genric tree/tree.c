#include "tree.h"

Tree* createTree(Comparator comparator){
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->start = (struct treeNode*)malloc(sizeof(struct treeNode));
	tree->start->parent = NULL;
	tree->comparatorFun = comparator;
	return tree;
}

void destroyTree(Tree* tree){
	free(tree->start);
	free(tree);
}

struct treeNode* createTreeNode(){
	struct treeNode* newNode = malloc(sizeof(struct treeNode));
	newNode->parent = (struct treeNode*)malloc(sizeof(struct treeNode));
	newNode->child = NULL;
	return newNode;
}

struct treeNode* findChildNode(Tree* tree ,struct Node* ptr, void* key){
	ptr = ptr->value->child;
	while(ptr != NULL){
		if(tree->comparatorFun(ptr->value->employee ,key))return ptr->value;
		if(ptr->value->child != NULL && findChildNode(tree, ptr, key) != NULL){
			return findChildNode(tree, ptr, key);
		}
		ptr = ptr->next;
	}

	return NULL;
}

struct treeNode* findNode(Tree* tree, void* key){
	struct Node* ptr = tree->start->child;
	
	if(tree->comparatorFun(tree->start->employee ,key))return tree->start;

	while(ptr != NULL){
		if(tree->comparatorFun(ptr->value->employee ,key))return ptr->value;
		
		if(ptr->value->child != NULL){
			if(findChildNode(tree, ptr, key) != NULL)return findChildNode(tree, ptr, key);
		}

		ptr = ptr->next;
	}
	return NULL;
}

void insertNode(Tree* tree, void* emp, void* boss){
	struct treeNode* ptr = tree->start;
	struct Node* Nodeptr = tree->start->child;
	struct treeNode* newNode;
	if(ptr->parent == NULL){
		newNode = createTreeNode();
		newNode->employee = emp;
		tree->start = newNode;
		tree->start->child = NULL;
		tree->start->parent = (struct treeNode*)malloc(sizeof(struct treeNode));
		return;
	}
	ptr = findNode(tree, boss);
	if(ptr->child == NULL){
		newNode = createTreeNode();
		newNode->employee = emp;
		ptr->child = (struct Node*)malloc(sizeof(struct Node));
		ptr->child->value = newNode;
		ptr->child->next = NULL;
		ptr->child->value->parent = findNode(tree, boss);
		ptr->child->value->child = NULL;
	}
	else{
		while(Nodeptr->next != NULL){
			Nodeptr = Nodeptr->next;
		}
		newNode = createTreeNode();
		newNode->employee = emp;
		Nodeptr->next = (struct Node*)malloc(sizeof(struct Node));
		Nodeptr->next->value = newNode;
		Nodeptr->next->value->parent = findNode(tree, boss);
		Nodeptr->next->value->child = NULL;
		Nodeptr->next->next = NULL;
	}
}

void removeNode(Tree* tree, void* emp){
	struct treeNode* kickOut =  findNode(tree, emp);
	if(kickOut == NULL)return;

	if(kickOut->child != NULL){
		while(kickOut->child != NULL){

			while(kickOut->parent->child != NULL){
				kickOut->parent->child = kickOut->parent->child->next;
			}

			kickOut->parent->child = (struct Node*)malloc(sizeof(struct Node));
			kickOut->parent->child = kickOut->child;
			kickOut->child->value->parent = kickOut->parent;

			kickOut->child = kickOut->child->next;
		}
		free(kickOut);
	}
	else{
		findNode(tree, kickOut->parent->employee)->child = NULL;
		free(kickOut);
	}
}