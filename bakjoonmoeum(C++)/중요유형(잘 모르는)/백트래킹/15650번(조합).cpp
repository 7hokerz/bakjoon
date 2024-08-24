#include <iostream>
#include <vector>
using namespace std;
//조합
int N, M;
int arr[9];
int visited[9];

void print(){
    for(int i = 0;i<9;i++){
        if(visited[i]) cout << arr[i] << ' ';
    }
    cout << '\n';
}

void dfs(int idx, int cnt){
    if(cnt == M){
        print();
        return;
    }

    for(int i = idx;i<N;i++){
        if(visited[i]) continue;
        visited[i] = true;

        dfs(i, cnt+1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        arr[i] = i+1;
    }
    dfs(0, 0);
}