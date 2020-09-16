#ifndef BPLUSTREE_T
#define BPLUSTREE_T
 
#define M (4)
#define LIMIT_M_2 (M % 2 ? (M + 1) / 2 : M / 2)
 
typedef int KeyType;
typedef struct BPlusTreeNode {
    int KeyNum;
    KeyType Key[M + 1];
    struct BPlusTreeNode *Children[M + 1];
    struct BPlusTreeNode *Next;
} BPlusTreeNode;

typedef BPlusTreeNode *BPlusTree, *Position;
 
/* 初始化 */
BPlusTree Initialize();
/* 插入 */
BPlusTreeNode *Insert(BPlusTree T, KeyType Key);
/* 删除 */
BPlusTree Remove(BPlusTree T,KeyType Key);
/* 销毁 */
BPlusTree Destroy(BPlusTree T);
/* 遍历节点 */
void Travel(BPlusTree T);
/* 遍历树叶节点的数据 */
void TravelData(BPlusTree T);
 
#endif
