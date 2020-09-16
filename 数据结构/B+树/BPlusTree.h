#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#define BPLUSTREE_SIZE  4
#define BPLUSTREE_LIMIT BPLUSTREE_SIZE / 2

typedef int KeyType;
typedef struct _BPlusTreeNode {
    unsigned int keyNum;
    KeyType keys[BPLUSTREE_SIZE + 1];
    struct _BPlusTreeNode *children[BPLUSTREE_SIZE + 1];
    struct _BPlusTreeNode *next;
} BPlusTreeNode;
typedef BPlusTreeNode * BPlusTree;

typedef enum {
    SUCCESS,
    FAILURE
} Status;

Status BPlusTreeInit(BPlusTree *rootNode);
Status BPlusTreeInsert(BPlusTree *rootNode, KeyType key);
Status BPlusTreeDelete(BPlusTree *rootNode, KeyType key);
Status BPlusTreeDestroy(BPlusTree *rootNode);
void BPlusTreeTraverse(BPlusTree rootNode);

#endif
