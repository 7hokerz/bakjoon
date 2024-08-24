#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct compare{
    bool operator() (int a, int b){
        return a > b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue <int, vector<int>, compare> pq;
    int N;
    long long input, sum = 0, res = 0;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        pq.push(input*1LL);
    }
    if(N == 1){
        cout << 0;
        return 0;
    }
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        res += sum;
        if(pq.empty()) break;
        pq.push(sum);
        sum = 0;
    }
    cout << res;
}
/*
아직 배우지 않은 우선순위 큐를 사용한 방식.
값이 들어올 때마다 자동으로 정렬을 해준다.
기본적으로는 내림차순 정렬(최대 힙: 각 노드의 값이 자식 노드의 값보다
크거나 같은 힙. 루트 노드가 가장 큰 값)이므로,
오름차순 정렬(최소 힙: 각 노드의 값이 그 자식 노드의 값보다 
작거나 같은 힙. 따라서 루트 노드가 가장 작은 값을 가진다.)
을 해주려면 따로 연산자 함수를 만들어줘야 한다.
*/