#include <iostream>
using namespace std;
//재귀 및 dfs로 중복조합 구현해보기(조합과 중복 조합의 차이는 뽑았던 수를 다시 중복해서 뽑을 수 있다는 점 (1,1)가능)

int arr[5];//요소가 들어갈 배열
int visited[5];//n번째 뽑은 요소를 저장

void print(){
    for(int i = 0;i<3;i++){
        cout << visited[i] << ' ';//뽑은 요소에 대해서 출력
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
        visited[cnt] = arr[i];//cnt번째 뽑은 요소를 저장

        dfs(i,cnt+1);//다음 수를 뽑으러 재귀 호출
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0;i<5;i++){
        arr[i] = i+1;
    }
    dfs(0,0);
}