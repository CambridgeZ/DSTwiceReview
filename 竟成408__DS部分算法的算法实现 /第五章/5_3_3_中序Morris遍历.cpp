//
// Created by Mac on 2023/4/13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
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

void inMorrisTra(BiTNode *root) {
    if(root==NULL) return;
    BiTNode *cur = root;
    BiTNode *pre = NULL;
    while (cur != NULL) {
        if (cur->lchild == NULL) {
            cout << cur->data << " ";
            cur = cur->rchild;
        } else {
            pre = cur->lchild;
            while (pre->rchild != NULL && pre->rchild != cur) {
                pre = pre->rchild;
            }
            if (pre->rchild == NULL) {
                pre->rchild = cur;
                cur = cur->lchild;
            } else {
                pre->rchild = NULL;
                cout << cur->data << " ";
                cur = cur->rchild;
            }
        }
    }
}

// test
/*
 *  ABD##E##CF###
 */

int main() {
    BiTree T;
    CreateBiTree(T);
    inMorrisTra(T);
    return 0;
}
