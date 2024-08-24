#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

int N, M, a, s, ret = 0;
vector <pii> vt;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> a >> s;
        vt.push_back({a,a+s});//시작, 끝
    }sort(vt.begin(), vt.end());

    for(int i = 0;i<vt.size();i++){
        //못 참고 다른 블로그 봤음. 그래서 어느정도 아이디어 얻긴 함. (아래의 식을 세울 때)
        while(!pq.empty() && pq.top() + M < vt[i].first) pq.pop();
        /*
            M분의 차이를 초과하는 경우 pq를 지움으로써 시작 시간과 가까워지게 된다.
            pq.top을 지워도 상관 없는 이유는 vt는 정렬되어있기 때문. 즉 시간 차이가 좁혀질 일이 없으니까
            이후에는 아래의 코드에 따라서 정리된다.
        */
       
        //1. 가장 작은 종료 시간이 현재 시작 시간보다 큰 경우
        //2. 가장 작은 종료 시간 + M이 현재 시작 시간 보다 작은 경우(자동 잠김을 막을 수 없는 경우)
        //위 코드 추가로 인해 (2) 조건을 여기에 걸어둘 필요가 사라짐.
        if(pq.empty() || pq.top() > vt[i].first /*(2)|| pq.top() + M < vt[i].first*/) ret++;

        //종료 시간 <= 시작 시간이면 이전 태스크를 지우면 됨.
        if(!pq.empty() && pq.top() <= vt[i].first) pq.pop();

        pq.push(vt[i].second);//현재 태스크의 종료 시간을 넣는다.
    }
    cout << N - ret;
}

/*
큰 틀로 봤을 때 어느 정도 아이디어를 찾았지만 끝맺음을 못한 점이 아쉽다.
그래도 pq까진 생각해냈다는 점이 괜찮았다.

답: n에서 빼야함.
m = 5
1~6 6~9 14~20
최대: 3
최소: 1
3 - 1 = 2
1 
m = 10
1~3 3~12 15~21 
2~8 17~24
최대: 5
최소: 2
5 - 2 = 3
*/