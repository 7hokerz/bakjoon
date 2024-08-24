#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, D, H;
struct cmp{
    bool operator()(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if(a.first.second == b.first.second && a.first.first == b.first.first) return a.second%M > b.second%M;//1,2가 같으면 줄의 번호가 낮은 순으로 3

        if(a.first.first == b.first.first) return a.first.second < b.first.second;//1이 같으면 H가 높은 순으로 2

        return a.first.first < b.first.first;//기본적으로 근무 일수가 높은 순으로 1
    }
};

priority_queue <pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp> pq;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    int a,b,c;

    queue <pair<pair<int,int>,int>> q[M];//근무 일수, H, 줄의 번호

    for(int i = 0;i<N;i++){
        cin >> D >> H;
        if(i == K){a = D; b = H; c = i;}
        q[i%M].push({{D,H},i});
    }

    for(int i = 0;i<min(N,M);i++){
        if(!q[i%M].empty()){
            pq.push(q[i%M].front());
            q[i%M].pop();
        }
    }

    int cnt = 0;
    while(!pq.empty()){
        if(pq.top().first.first == a && pq.top().first.second == b && pq.top().second == c) break;
        //cout << pq.top().first.first << ' ' << pq.top().first.second << ' ' << pq.top().second << '\n';
        int line = pq.top().second % M;
        pq.pop();
        if(!q[line].empty()){
            pq.push(q[line].front());
            q[line].pop();
        }
        cnt++;
    }
    cout << cnt;
}
/*
처음에 우선순위 큐 하나만 가지고 풀려다가 실패했다.
애초에 우선순위 큐 + 다른 자료구조 한 개(큐 등..)이 필요했던 문제다.
그리고 구현 과정에서도 실수가 많았다.

과정:
1. 큐에 근무 일수, H, 줄의 번호를 구조로 하여 요소를 받는다.
2. 큐에는 먼저 온 순서대로 정렬되어 있으므로 큐가 비어있지 않는 한 줄의 개수 또는 사람의 명수 만큼 pq에 저장한다.
3. 우선적으로 들어갈 사람을 찾아 빼내고, 해당 줄의 큐에서 하나의 요소를 더 빼온다. cnt++
4. 위의 과정을 반복하고, K를 찾으면 cnt를 출력한다.
*/