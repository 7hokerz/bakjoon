#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int dx[] = {0, 1, 0, -1}; int dy[] = {-1, 0, 1, 0};

int N, M, X, Y, A, B, res = -1, visited[100101];
//방문 배열이면서 역추적 배열(이전 노드 저장)
queue <pii> q;
vector <int> gr[100101], backtrack;

void bfs(){
    visited[A] = -1;
    q.push({A,0});

    while(!q.empty()){
        int x = get<0>(q.front());
        int cnt = get<1>(q.front());

        q.pop();

        if(x == B){ res = cnt; return;}

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i];

            if(!visited[nx]){
                visited[nx] = x;

                if(nx > N) q.push({nx, cnt + 1});//엘리베이터를 탄 경우
                else q.push({nx, cnt});//엘리베이터에서 내린 경우
            }
        }
    }
}

int main(){
    cin >> N >> M;//N층, M개의 엘리베이터
    for(int i = 1;i<M+1;i++){
        cin >> X >> Y;
        for(int j = X;j<N+1;j += Y){
            gr[N+i].push_back(j);
            gr[j].push_back(N+i);
        }
    }
    cin >> A >> B; 
    bfs(); cout << res << '\n';

    if(res == -1) return 0;

    int prev = B;
    while(prev != A){
        if(prev > N){
            backtrack.push_back(prev - N);
            //cout << pre - N << '\n';
        }
        prev = visited[prev];
    }
    reverse(backtrack.begin(), backtrack.end());
    //경로 출력
    for(int val: backtrack) cout << val << '\n';
}
/*
for(int k = 1;k<N+M+1;k++){
        for(int i = 0;i<gr[k].size();i++){
            cout << gr[k][i] << ' ';
        }cout << '\n';
    }



*/