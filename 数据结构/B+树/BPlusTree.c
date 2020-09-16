#include <stdlib.h>
#include <memory.h>
#include "BPlusTree.h"

static BPlusTreeNode *NewNode()
{
    BPlusTreeNode *newNode = (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
    if (newNode == NULL) {
        return NULL;
    }

    (void)memset(newNode, 0, sizeof(BPlusTreeNode));
    return newNode;
}

Status BPlusTreeInit(BPlusTree *rootNode)
{
    *rootNode = NewNode();
    if (*rootNode == NULL) {
        return FAILURE;
    }

    return SUCCESS;
}

static BPlusTreeNode *RecursiveInsert(BPlusTreeNode *childNode,
                                      KeyType key,
                                      unsigned int idxInParent,
                                      BPlusTreeNode *parentNode)
{
    int idx = 0;
    while ((idx < childNode->keyNum) && (key >= childNode->keys[idx])) {
        ++idx;
    }

    if (idx != 0) {
        --idx;
    }

    if (key == childNode->keys[idx]) {
        return childNode->children[idx];
    }

    // 叶子节点
    if (childNode->children[0] == NULL) {
        // 插入key
    } else {
        
    }
}

Status BPlusTreeInsert(BPlusTree *rootNode, KeyType key)
{
    
}