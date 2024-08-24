#include <iostream>
#include <queue>
#include <functional>
using namespace std;
//우선순위 큐
/* 
기본 메서드
push(): 원소 추가
pop(): top의 원소 제거
top(): 우선순위가 높은 원소를 반환
empty(): 비어있는지 확인
size(): 원소의 수 반환
emplace(): 우선순위 큐에 구조를 삽입

우선순위 큐의 기본값: 가장 큰 값부터 출력. 즉 내림차순 정렬(최대 힙)
가장 작은 값부터 출력하게 하려면? functional 헤더의 greater 이용

직접 우선순위를 정하려면 구조체를 생성한다. 아래와 같은 구조
*/
struct cmp{
    bool operator()(int a, int b){
        return a > b;//이 때는 최소 힙 우선순위 큐
        //**벡터와 반대의 성질을 가짐. 벡터는 위와 같이 비교연산시 내림차순 정렬을 수행하지만
        //우선순위 큐는 a가 루트에 있는 값이므로 a가 더 크면 true를 반환하고, 그 말은 swap을 시행하기 때문에 a와 b가 바뀌게 됨.
        //즉 최소값이 루트에 위치
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //priority_queue <int> pq;(최대 힙)
    priority_queue <int, vector<int>, greater<int>> pq;//위와 같이 할 경우 작은 값이 우선된다. 즉 오름차순 정렬(최소 힙)
    priority_queue <int, vector<int>, cmp> pq2;

    pq.push(4);
    pq.push(7);
    pq.push(3);
    pq.push(1);
    pq.push(10);

    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }

}
/*

*/