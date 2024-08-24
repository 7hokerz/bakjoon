#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
//조합
int N, M;
vector <int> vt;
int visited[11];

void print(){
    for(int i = 0;i<M;i++){
        cout << visited[i] << ' ';
    }
    cout << '\n';
}

void dfs(int idx, int cnt){
    if(cnt == M){
        print();
        return;
    }
    
    for(int i = idx;i<N+1;i++){
        //if(visited[i]) continue;
        visited[cnt] = vt[i-1];
        
        dfs(i, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++) vt.push_back(i);
    dfs(1,0);
}