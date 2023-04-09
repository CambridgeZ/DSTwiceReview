//
// Created by Mac on 2023/4/9.
//

# include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

void CreateList(ListNode *head,int n){
    ListNode *p=head;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode *node=new ListNode(x);
        p->next=node;
        p=p->next;
    }
}

void ReverseLinkList(ListNode *head){
    ListNode* p=head->next;
    head->next=::nullptr;
    ListNode* pnext=p->next;
    while(p){
        p->next=head->next;
        head->next=p;
        p=pnext;
        if(p)
            pnext=p->next;
    }
}

//test
int main(){
    ListNode *head=new ListNode(0);
    int n;
    cin>>n;
    CreateList(head,n);
    ReverseLinkList(head);
    ListNode *p=head->next;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    return 0;
}
