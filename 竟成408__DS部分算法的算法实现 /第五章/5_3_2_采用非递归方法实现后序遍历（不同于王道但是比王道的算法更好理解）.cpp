//
// Created by Mac on 2023/4/13.
//

# include <iostream>
# include <stack>

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

void PreOrder(BiTree T) {
    stack<BiTree> s;
    BiTree p = T;
    s.push(p);
    stack<BiTree> auxStack;
    while(!s.empty()){
        p=s.top();
        s.pop();
        auxStack.push(p);
        if(p->lchild != NULL){
            s.push(p->lchild);
        }
        if(p->rchild != NULL) {
            s.push(p->rchild);
        }
    }
    while(!auxStack.empty()){
        cout<<auxStack.top()->data<<" ";
        auxStack.pop();
    }
}

// test
/*
 * ABD##E##CF###
 */

int main() {
    BiTree T;
    CreateBiTree(T);
    PreOrder(T);
    return 0;
}



