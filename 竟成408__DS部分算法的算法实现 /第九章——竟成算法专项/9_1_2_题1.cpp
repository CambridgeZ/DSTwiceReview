//
// Created by Mac on 2023/5/4.
//
# include <iostream>

using namespace std;


void sortTheSeq(int a[],int n){
    int pre=0,post=n-1;//设置前后两个指针
    while(a[pre]==0) pre++;//指向前面第一个不是0的元素
    while(a[post]==2) post--;//指向后面第一个不是2的元素
    for(int i=pre+1;i<=post;i++){
        /*
         * 遍历，如果出现在pre后面的是0就和pre交换并且更改pre
         * 如果出现在post前面的是2就和post交换并且更改post
         */
        if(a[i]==0){
            swap(a[i],a[pre]);
            while(a[pre]==0) pre++;
            i= pre+1;
        }
        if(a[i]==2){
            swap(a[i],a[post]);
            while(a[post]==2) post--;
        }
    }
}

//test
int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];
    sortTheSeq(a,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

//算法时间负责度为 O(n)