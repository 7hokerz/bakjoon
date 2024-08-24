#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp; ll ret = 0;
string str;

vector <int> gr[1'000'001];
bool visited[1'000'001];
int countarr[2][1'000'001];//가는, 오는
int mx = 0, genv, one = 0, two = 0, three = 0;

void dfs(int x){
    if(!gr[x].size()){//출발하는 간선이 0개
        two++; return;
    }
    if(gr[x].size() == 2){//출발하는 간선이 2개
        three++; return;
    }
    
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];
        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx);
        }
        else{//출발하는 간선이 1개
            one++; return;
        }
    }
}

vector<int> solution(vector<vector<int>> edges) {
    for(int i = 0;i<edges.size();i++){
        int f = edges[i][0];
        int s = edges[i][1];
        countarr[0][f]++; countarr[1][s]++;
        mx = max(mx, max(f,s));//최대 정점 번호 파악
        
        gr[f].push_back(s);
    }
    
    //생성 정점 찾기
    for(int i = 1;i<mx + 1;i++){
        if(countarr[0][i] >= 2 && !countarr[1][i]){
            genv = i; break;
        }
    }
    
    //생성 정점으로부터 가능한 지점으로 탐색
    for(int i = 0;i<gr[genv].size();i++){
        int nx = gr[genv][i];
        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx);
        }
    }
    
    vector<int> answer;
    answer.push_back(genv);
    answer.push_back(one);
    answer.push_back(two);
    answer.push_back(three);
    
    return answer;
}

/*
가는 건 있고, 오는 건 없는데, 그 중 가는 것의 개수가 2개 이상인 정점을 선택하면 된다.
도넛 모양: 항상 간선의 개수가 1인 경우만 존재
팔자 모양: 간선의 개수가 2인 경우가 적어도 1개 존재
직선 모양: 간선이 없는 경우가 적어도 1개 존재
*/

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    
    
}
