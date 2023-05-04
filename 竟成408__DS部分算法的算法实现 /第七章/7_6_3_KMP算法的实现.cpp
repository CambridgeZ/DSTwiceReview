//
// Created by Mac on 2023/4/29.
//

/*
 * KMP算法的实现
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//求next数组
void getNext(string s, vector<int> &next) {
    int i = 0, j = -1;//j表示前缀，i表示后缀
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    while (i < s.size()) {//因为next[i]对应s[i+1]之前的字符串，所以i < s.size()
        if (j == -1 || s[i] == s[j]) {//匹配
            i++;
            j++;//j和i同时向后移动
            next[i] = j;//如果匹配成功，那么next[i]就是j
            //为什么匹配成功next[i]就是j:
            // 因为next[i]对应s[i+1]之前的字符串，而next[i]表示的是最大相同前后缀的长度，所以next[i]就是j
        } else {
            j = next[j];//如果失配，那么j就变成next[j]
        }
    }
}

//KMP算法
int KMP(string s, string p) {
    vector<int> next(p.size() + 1);//next数组
    getNext(p, next);//求next数组
    int i = 0, j = 0;//i表示s的下标，j表示p的下标
    while (i < s.size() && j < p.size()) {//i和j不能超过字符串的长度
        if (j == -1 || s[i] == p[j]) {//匹配成功
            i++;
            j++;
        } else {
            j = next[j];//匹配失败，j变成next[j]
        }
    }
    if (j == p.size())//匹配成功
        return i - j;
    else
        return -1;
}

//test
int main() {
    string s, p;
    cin >> s >> p;
    cout << KMP(s, p) << endl;
    return 0;
}
