#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, input;

priority_queue <pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> big;//최대 힙
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> small;//최소 힙
deque <int> q[1001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 0;j<M;j++){
            cin >> input;
            q[i].push_back(input);
        }
        sort(q[i].begin(),q[i].end());
    }
    
    for(int i = 1;i<N+1;i++){
        big.push({q[i].front(),i});
        small.push({q[i].front(),i});
        q[i].pop_front();
    }

    int min = 1'000'000'000;
    while(1){
        int val = big.top().first - small.top().first;
        min = (min>val)?val:min;
        if(!q[small.top().second].empty()){
            small.push({q[small.top().second].front(),small.top().second});
            big.push({q[small.top().second].front(),small.top().second});
            q[small.top().second].pop_front();
            small.pop();
        }else break;
    }
    cout << min;
}
/*
행의 값 하나를 골라서 뽑았을 때 중 최댓값 - 최솟값의 차이가 최소가 되려면?
우선 값을 구하고, 행의 최솟값을 제거 후 다음 값을 우큐에 삽입

3 4
12 16 67 43
7 17 68 48
14 15 77 54

>>정렬
12 16 43 67
7 17 48 68
14 15 54 77

min = 
7(7,12,14)
5(17,12,14)
3(17,16,14)
2(17,16,15) 정답
>>(이후는 알고리즘을 살펴보는 용도)
38(17,16,54)
37(17,43,54)
11(48,43,54)
6(48,67,54)
12(68,67,54)
9(68,67,77)

결국 값을 구한 후 최솟값을 우큐에서 제거하고 해당 행의 다음 값을 불러오고를 반복시키면 된다.
최소 힙, 최대 힙 2개가 필요함.

최대 힙은 해당 최솟값을 지우지 않는다. 지우지 않아도 특별한 문제는 없을 것

4 3
10 20 30
40 50 60
70 80 90
100 110 120

90(10,40,70,100)
80(20,40,70,100)
70(20,40,70,100)
*/