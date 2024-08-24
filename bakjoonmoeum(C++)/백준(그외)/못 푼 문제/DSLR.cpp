#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
//북,동,남,서
//총 4 방향 탐색
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

int N, A, B;
string input;
bool visited[10001];

void bfs(int x){
    
    queue <pair<int,string>> q;
    q.push({x,""});
    
    while(!q.empty()){
        int itx = q.front().first;
        if(itx == B) {cout << q.front().second << '\n'; return;}

        visited[itx] = true;
        string stx = "";

        if(itx/10 == 0) {stx = "000"; stx += to_string(q.front().first);}
        else if(itx/100 == 0) {stx = "00"; stx += to_string(q.front().first);}
        else if(itx/1000 == 0) {stx = "0"; stx += to_string(q.front().first);}
        else stx = to_string(q.front().first);
        
        int D = (itx * 2) % 10000; 
        if(!visited[D]) q.push({D, q.front().second + 'D'});

        int S;
        if(itx == 0) S = 9999;
        else S = itx-1;
        if(!visited[S]) q.push({S, q.front().second + 'S'});
        
        string tmp = ""; if(stx.length() > 1) tmp = stx.substr(1); 

        int num = stoi(tmp+stx[0]);
        if(!visited[num]) q.push({num ,q.front().second + 'L'});

        num = stoi(stx[0]+tmp);
        if(!visited[num]) q.push({num ,q.front().second + 'R'});
        q.pop();
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> A >> B;
        bfs(A);
        fill(visited, visited+10001,0);
    }
}
/*


*/