#include <iostream>
#include <vector>
using namespace std;
//순열
int N, M;
int arr[9];
int visited[9];
vector <int> v;

void print(){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void dfs(int cnt){
    if(cnt == M){
        print();
        return;
    }

    for(int i = 0;i<N;i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);

        dfs(cnt+1);
        visited[i] = false;
        v.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        arr[i] = i+1;
    }
    dfs(0);
}