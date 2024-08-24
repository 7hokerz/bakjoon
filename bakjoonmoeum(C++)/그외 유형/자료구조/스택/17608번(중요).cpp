#include <iostream>
#include <stack>
using namespace std;
/*
제일 높은 막대기를 우선 찾아야 한다. 그 막대기 뒤에는 절대 보이지 않기 때문이다.
마지막 막대기의 높이를 기준으로 다른 막대기> 마지막 막대기여야 한다.

즉 스택에 값을 저장할 때 스택 상단과 삽입될 값을 비교하여 스택 상단이 크면 X 삽입될 값이 크면 
스택 상단 값부터 모두 pop하여 빈 스택으로 만들고 새 값을 삽입하면 된다.

또 하나 할 것은 마지막 값이 중요하다.
마지막 값이랑 삽입될 값을 비교하여 마지막 값보다 크면 삽입, 작거나 같으면 삽입 X를 해야 된다.
*/
void stick(int input[], int size){
    stack <int> stack;
    stack.push(input[0]);//첫 번째 값 삽입
    int big = 0;
    for(int i = 1;i<size;i++){
        if((input[i] >= input[0]) && (input[i] >= big)){//알수 없으나 big 조건을 넣어야 통과
            //첫 번째 값보다 input[i]가 크거나 같으면서 big보다 크거나 같은 경우
            while(!stack.empty()){//스택의 모든 요소 제거
                stack.pop();
            }
            stack.push(input[i]);//제일 큰 값 삽입
            big = input[i];//큰 값 저장
        }else if(input[i] > input[size-1]){//마지막 값보다 input[i]가 클 때
            while(!stack.empty() && (stack.top() <= input[i])){//스택 상단 값이 input[i]보다 작거나 같은 경우에 요소 제거
                stack.pop();
            }
            stack.push(input[i]);//input[i] 삽입
        }else if(i == size - 1){//마지막 요소인 경우 삽입
            stack.push(input[i]);
        }
    }
    cout << stack.size();
}

int main(){
    int N;
    cin >> N;
    int input[N];

    for(int i = 0;i<N;i++){
        cin >> input[i];
    }
    stick(input, N);
}