#include <iostream>
#include <vector>
using namespace std;
//재귀 및 dfs로 순열 구현해보기

int arr[5];//요소가 들어갈 배열
bool visited[5];//인덱스의 방문 처리 구현
vector <int> v;//요소를 저장(순서를 고려함)

void print(){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

//cnt: 현재 뽑은 원소의 개수를 결정하는 변수
void dfs(int cnt){
    if(cnt == 3){//원소의 개수가 n개가 되면 출력 후 리턴
        print();
        return;
    }

    for(int i = 0;i<5;i++){
        if(visited[i]) continue;//뽑힌 수면 continue;
        visited[i] = true;//뽑히지 않았다면 뽑기
        v.push_back(arr[i]);//요소를 벡터에 추가

        dfs(cnt+1);//다음 수를 뽑으러 재귀 호출
        v.pop_back();//벡터에서 제거
        visited[i] = false;//출력 및 재귀가 리턴된 후 다음 계산을 위해 뽑지 않은 것으로 처리
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0;i<5;i++){
        arr[i] = i+1;
    }
    dfs(0);
}
/*
cnt
0 v에 0을 넣고 재귀 호출
>>
1 0은 방문했으므로 지나가기. 1을 넣고 재귀 호출
>>
2 0,1은 방문했으므로 지나가기. 2를 넣고 재귀 호출
>>
cnt = 3이므로 출력 및 리턴(1,2,3)
>>
2 2제거 및 i+1
>>
2 3을 넣고 재귀 호출
>>
cnt = 3이므로 출력 및 리턴(1,2,4)
>>
반복...
*/