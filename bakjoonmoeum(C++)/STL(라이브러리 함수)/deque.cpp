#include <iostream>
#include <deque>
using namespace std;
/*
선언 방법: deque <int> deque;

deque.push_front(element): 덱의 제일 앞에 element를 추가
deque.push_back(element): 덱의 제일 뒤에 element를 추가
*deque.pop_front(): 덱의 제일 앞에 있는 원소 제거
*deque.pop_back(): 덱의 제일 뒤에 있는 원소 제거
*deque.front(): 덱의 앞 원소 반환
*deque.back(): 덱의 뒤 원소 반환
deque.empty(): 덱이 비어있는지 확인
deque.size(): 덱의 현재 크기를 반환

(* 표시된 함수들은 스택이 빈 상태에서 사용시 에러 발생)
swap(deque1, deque2): 두 덱의 내용을 바꿈

**deque도 결국 클래스니까 객체 배열, 객체 포인터 등 여러가지를 써먹을 수 있다는 걸 참고하자.

*/
int main(){
    deque<int> dq;

    // 덱의 맨 앞과 맨 뒤에 요소 추가
    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(5);

    // 덱의 맨 앞과 맨 뒤에 있는 요소 출력
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // 덱의 맨 앞과 맨 뒤에 있는 요소 제거
    dq.pop_front();
    dq.pop_back();

    // 덱의 크기 출력
    cout << "Size of deque: " << dq.size() << endl;

}