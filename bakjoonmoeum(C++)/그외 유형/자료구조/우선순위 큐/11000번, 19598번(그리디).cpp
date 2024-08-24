#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int N, s, e;
struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
};

vector <pair<int,int>> vt;//시작 끝
priority_queue <int, vector<int>, cmp> pq;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> s >> e;
        vt.push_back({s, e});
    }
    sort(vt.begin(),vt.end());

    int cnt = 0;
    for(int i = 0;i<N;i++){
        if(!pq.empty() && pq.top() <= vt[i].first){   
            pq.pop();
        }else{
            cnt++;
        }
        pq.push(vt[i].second);
    }
    cout << cnt;
}
/*
1. 우선순위 큐에는 끝나는 시간을 넣어준다.
2. 벡터엔 모두 넣어주고, 우큐와 비교하여 시작 시간이 top보다 작으면 cnt++ 후 끝나는 시간 pq에 삽입.
2.1 시작 시간이 top과 같거나 크면 top을 지우고, 끝나는 시간 pq에 삽입

3 (정렬시켜서 받으면)
0 40
5 10
15 30

우선순위 큐엔 끝나는 시간을 넣는다.

0 40>> 우큐는 비었으므로 cnt+1, 40 추가
5 10>> 시작 시간이 40보다 작으므로 cnt+1, 10 추가
15 30>> 시작 시간이 10보다 크므로 카운트X, 10 제거 및 30 추가

2
5 10
10 20

5 10>> cnt+1, 10 add
10 15>> 시작 시간이 10과 같으므로 카운트X, 10 제거 및 15 추가 
*/