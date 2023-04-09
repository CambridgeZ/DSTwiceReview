#include <iostream>

using namespace std;


int FindPatition(int a[],int begin,int end){
    int x=a[begin];
    while(begin<end){
        while(a[end]>x&&begin<end)
            end--;
        a[begin]=a[end];
        while(a[begin]<x&&begin<end){
            begin++;
        }
        a[begin]=a[end];
    }
    return begin;
}


int FindTheMidNum(int a[],int m,int b[],int n){
    int combined[m+n];
    int i=0,j=0,k=0;
    while(i<m&&j<n){
        if(a[i]<b[j]){
            combined[k++]=a[i++];
        }else{
            combined[k++]=b[j++];
        }
    }
    while(i<m){
        combined[k++]=a[i++];
    }
    while(i<n){
        combined[k++]=b[j++];
    }

    int mid;
    if((m+n)%2==0)
        mid = (m+n)/2-1;
    else
        mid = (m+n)/2;
    int patition=FindPatition(combined,0,m+n-1);
    while(patition!=mid){
        if(patition<mid){
            patition=FindPatition(combined,patition+1,m+n-1);
        }else{
            patition=FindPatition(combined,0,patition-1);
        }
    }
    return combined[patition];
}

void test(){
    int a[]={1,3,5,7,9};
    int b[]={2,4,6,8,10};
    int m=5,n=5;
    cout<<FindTheMidNum(a,m,b,n)<<endl;
}

int main()
{
    test();
    return 0;
}