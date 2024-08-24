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

int N, M;
vector <int> vt;//순열을 담을 배열
int arr[101];
bool visited[101];

void print(){
    for(int i = 0;i<vt.size();i++){
        cout << vt[i] << ' ';
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
        //visited[i] = !visited[i];
        vt.push_back(arr[i]);
        
        dfs(1 ,cnt+1);

        //visited[i] = !visited[i];
        vt.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++) arr[i] = i;
    dfs(1,0);
}
/*

*/