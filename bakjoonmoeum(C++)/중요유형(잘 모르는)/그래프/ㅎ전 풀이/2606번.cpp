#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int v, bool visited[], vector <int> graph[], int &result){
    queue <int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        result++;
        //cout << x << ' ';

        for(int i = 0;i<graph[x].size();i++){
            int y = graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, num1, num2;
    int result = 0;
    cin >> v >> e;
    bool visited[v+1];
    for(int i = 1;i<v+1;i++) visited[i] = false;
    vector <int> vt[v+1];

    for(int i = 0;i<e;i++){
        cin >> num1 >> num2;
        vt[num1].push_back(num2);
        vt[num2].push_back(num1);
    }
    
    bfs(1, visited, vt, result);
    cout << result - 1;
}
/*
1260번 문제와 매우 비슷하지만 다른 점은 개수를 출력해야 한다. 즉 연결된 노드의 총 개수
너비 우선 탐색을 이용하여 큐에서 제거되는 순간 카운트를 증가시키면 총 개수를 알 수 있다.
단, 1번 노드는 빼고.
*/
