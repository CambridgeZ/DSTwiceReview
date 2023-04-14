//
// Created by Mac on 2023/4/14.
//

#include <iostream>

using namespace std;

/*
 * 交换二叉树的左右子树
 */

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = NULL;
    } else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void swap1(BiTree &T) {
    if (T == NULL) {
        return;
    }
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    swap1(T->lchild);
    swap1(T->rchild);
}

void swap2(BiTree &T) {
    if (T == NULL) {
        return;
    }
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    swap2(T->lchild);
    swap2(T->rchild);
}

void PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    cout << T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//test
/*
 *  ABD##E##CF###
 */
int main() {
    BiTree T;
    CreateBiTree(T);
    swap1(T);
    PreOrderTraverse(T);
    cout << endl;
    swap2(T);
    PreOrderTraverse(T);
    return 0;
}