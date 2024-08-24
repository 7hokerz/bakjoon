#include <iostream>
using namespace std;
//재귀 및 dfs로 조합 구현해보기

int arr[5];//요소가 들어갈 배열
bool visited[5];//인덱스의 방문 처리 구현

void print(){
    for(int i = 0;i<5;i++){
        if(visited[i]) cout << arr[i] << ' ';//뽑은 요소에 대해서 출력
    }
    cout << '\n';
}

//idx: 시작점을 결정하는 변수, cnt: 현재 뽑은 원소의 개수를 결정하는 변수
void dfs(int idx, int cnt){
    if(cnt == 3){//원소의 개수가 n개가 되면 출력 후 리턴
        print();
        return;
    }

    for(int i = idx;i<5;i++){
        if(visited[i])continue;//뽑힌 수면 continue;
        visited[i] = true;//뽑히지 않았다면 뽑기

        dfs(i,cnt+1);//다음 수를 뽑으러 재귀 호출
        visited[i] = false;//출력 및 재귀가 리턴된 후 다음 계산을 위해 뽑지 않은 것으로 처리
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0;i<5;i++){
        arr[i] = i+1;
    }
    dfs(0,0);
}
/*
과정:(5개의 원소 중 3개를 뽑는데 중복하지 않고)
idx cnt
0,0 idx0 방문 처리 및 dfs(0,1) 재귀함수 호출
>>
0,1 idx0은 방문했으므로 지나가기. idx1 방문 처리 및 dfs(1,2) 호출
>>
1,2 idx1은 방문했으므로 지나가기. idx2 방문 처리 및 dfs(2,3) 호출
>>
2,3 cnt = 3이므로 출력 및 리턴(1,2,3)
>>
1,2로 돌아옴. idx2를 방문 처리 취소 및 i = 3
>>
idx3 방문 처리 및 dfs(3,3) 호출
>>
3,3 cnt = 3이므로 출력 및 리턴(1,2,4)
>>
1,3로 돌아옴. idx3을 방문 처리 취소 및 i = 4
....반복

*/