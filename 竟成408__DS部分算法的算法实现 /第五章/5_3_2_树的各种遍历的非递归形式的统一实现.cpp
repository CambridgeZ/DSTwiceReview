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

void  CreateBiTree(BiTree &T) {
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

void traverse(BiTree T,int type) {
    if(T==NULL) return;
    stack<BiTree> s;
    stack<bool> tags;

    s.push(T);
    tags.push(true);
    while(!s.empty()){
        BiTree p=s.top();
        bool tag=tags.top();
        s.pop();
        tags.pop();
        if(!tag){
            cout<<p->data<<" ";
        }else{
          if(type==0){
              s.push(p);
              tags.push(false);
          }
          if(p->rchild!=NULL){
              s.push(p->rchild);
              tags.push(true);
          }
          if(type==1){
                s.push(p);
                tags.push(false);
          }
            if(p->lchild!=NULL){
                s.push(p->lchild);
                tags.push(true);
            }
            if(type==2){
                s.push(p);
                tags.push(false);
            }
        }
    }
}

// test
/*
 * ABD##E##CF###
 */

int main() {
    BiTree T;
    CreateBiTree(T);
    traverse(T,1);
    cout<<endl;
    traverse(T,2);
    cout<<endl;
    traverse(T,3);
    return 0;
}


