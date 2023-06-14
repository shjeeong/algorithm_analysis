#include <bits/stdc++.h>
#define N 128
using namespace std;

int cnt[N];
priority_queue<int> pq;
int sum_of_inner_nodes;


void init(){
    int input, i;
    while((input = getchar()) != EOF)
        cnt[input]++;
    for(i = 0; i < N; i++)
        pq.push(-cnt[i]);
}

void calc(){
    int a, b;
    while(pq.size() > 1){
        a = -pq.top();
        pq.pop();
        b = -pq.top();
        pq.pop();
        sum_of_inner_nodes += (a+b);
        pq.push(-(a+b));
    }
}

int main(){
    init();
    calc();
    cout << "sum of inner nodes = " << sum_of_inner_nodes << '\n';
    cout << "size of compressed file = " << sum_of_inner_nodes / 8e6 << "MB\n";
    return 0;
}