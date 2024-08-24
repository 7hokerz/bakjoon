#include <iostream>
#include <queue>
using namespace std;
/*
선언 방법: queue <데이터타입> 이름 

queue.push(element):큐에 데이터 추가
*queue.pop(): 큐의 front 데이터 삭제
*queue.front(): 큐의 최상위 데이터(front) 반환
*queue.back(): 큐의 마지막 데이터(rear 또는 back) 반환
queue.size(): 큐의 현재 사이즈 반환
queue.empty(): 큐가 비어있는지 확인

(* 표시된 함수들은 스택이 빈 상태에서 사용시 에러 발생)
swap(queue1, queue2): 두 큐의 내용을 서로 바꿈

**queue도 결국 클래스니까 객체 배열, 객체 포인터 등 여러가지를 써먹을 수 있다는 걸 참고하자.

*/
int main(){
    queue <int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    // 요소 출력
    while (!q.empty()) {
        cout << q.front() << " "; // 맨 앞의 요소 출력
        q.pop(); // 맨 앞의 요소 제거
    }

}