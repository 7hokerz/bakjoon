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
int N;
vector <int> vt;
bool visited[11];

void print(){
    for(int i = 1;i<11;i++){
        if(visited[i]){
            cout << vt[i-1] << ' ';
        }
    }
    cout << '\n';
}

void dfs(int idx, int sum){
    if(sum == N){
        print();
        return;
    }
    for(int i = idx;i<N+1;i++){
        if(sum + vt[i-1] <= N){
            if(!visited[i]){
                visited[i] = !visited[i];
            }
            dfs(i+1 ,sum + vt[i-1]);
            visited[i] = !visited[i];
        }  
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++) vt.push_back(i);
    dfs(1,0);
}