#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define mod 1'000'000'009
#define INF 2'000'000'001

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, one, two, res = 0, visited[501];

bool dfs(int x, vector <int> gr[]){
    int chk = 0; 
    bool check = true;
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];
        if(!visited[nx]){
            visited[nx] = 1;
            check = check & dfs(nx, gr);
        }
        else chk++;
    }
    if(chk > 1 || !check) return false;
    else return true;
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt = 1;
    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        vector <int> gr[501];
        for(int i = 0;i<M;i++){
            cin >> one >> two;
            gr[one].push_back(two);
            gr[two].push_back(one);
        }
        
        for(int i = 1;i<N+1;i++){
            if(!visited[i]){
                visited[i] = 1;//이걸 왜 까먹어서....***
                if(dfs(i, gr)){
                    res++;
                }
            }
        }
        if(res == 0) cout << "Case " << cnt << ": No trees.\n";
        else if(res == 1) cout << "Case " << cnt << ": There is one tree.\n";
        else cout << "Case " << cnt << ": A forest of " << res << " trees.\n";
        cnt++; res = 0;
        fill(visited, visited+501, 0);
    }
}
/*
구현은 다 했는데 방문처리때문에 틀렸네...?ㅅㅂ

*/