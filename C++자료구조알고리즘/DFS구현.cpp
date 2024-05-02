#include <iostream>
#include <vector>
using namespace std;
//깊이 우선 탐색(스택 또는 재귀함수로 구현됨)(여기선 재귀함수로 구현됨)
/*
1. 탐색 시작 노드를 스택에 삽입하고 방문 처리한다.
2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 하나라도 있으면, 그 노드를 스택에 넣고 방문 처리한다. 
방문하지 않은 인접 노드가 없으면, 스택에서 최상단 노드를 꺼낸다.
3. 더 이상 2번의 과정을 수행할 수 없을 때까지 반복한다.
*/

bool visited[9];//전역으로 선언 시 모두 false로 초기화
vector<int> graph[9];//9로 선언된 이유는 0을 쓰지 않기 때문(물론 0을 쓰려면 쓸 수 있겠지만 불편한데 굳이?)

void dfs(int x){
    visited[x] = true;//방문 처리
    cout << x << ' '; 

    for(int i = 0;i<graph[x].size();i++){//벡터에 저장된 노드(인접 노드들)를 방문 시도
        int y = graph[x][i];
        if(!visited[y]) dfs(y);//방문하지 않았던 곳 재귀호출로 방문
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //번호가 낮은 인접 노드부터 방문하도록 저장됨
    graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	// 노드 2에 연결된 노드 정보 저장 
	graph[2].push_back(1);
	graph[2].push_back(7);

	// 노드 3에 연결된 노드 정보 저장 
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	// 노드 4에 연결된 노드 정보 저장 
	graph[4].push_back(3);
	graph[4].push_back(5);

	// 노드 5에 연결된 노드 정보 저장 
	graph[5].push_back(3);
	graph[5].push_back(4);

	// 노드 6에 연결된 노드 정보 저장 
	graph[6].push_back(7);

	// 노드 7에 연결된 노드 정보 저장 
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	// 노드 8에 연결된 노드 정보 저장 
	graph[8].push_back(1);
	graph[8].push_back(7);

	dfs(1);
    
}
/*

*/
