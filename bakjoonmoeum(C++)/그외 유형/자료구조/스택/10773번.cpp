#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> stack;
    int K;//개수
    long long input;//입력값
    long long sum;//최종 합
    cin >> K;

    for(int i = 0;i<K;i++){
        cin >> input;
        if(input != 0){//0이 아닌 값이 입력되면 스택에 삽입
            stack.push(input);
        }else{//0이 입력되면 top을 스택에서 지운다.
            stack.pop();
        }
    }

    while(!stack.empty()){//스택에 남아있는 값을 더하여 합을 구한다.
        sum += stack.top();
        stack.pop();
    }

    cout << sum;
}//정수값의 범위가 클 경우 long 자료형 사용을 적극 권장한다.
