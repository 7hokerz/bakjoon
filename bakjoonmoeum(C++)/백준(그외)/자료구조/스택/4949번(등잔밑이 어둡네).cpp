#include <iostream>
#include <string>
#include <stack>
using namespace std;
//55번줄에서 실수...
int main() {
    string input;//문자열
    stack <char> stack;
    long long res[10000];
    int count = 0;
    while(1){
        getline(cin, input, '\n');
        if(input == "."){//맨 마지막 줄에 . 하나가 들어오면 종료
            break;
        }

        for(int i = 0;i<input.length();i++){
            if(input[i] == '('){
                stack.push('(');
            }//왼쪽 괄호가 들어오면 스택에 삽입
            if(input[i] == '['){
                stack.push('[');
            }
            
            //스택에 아무것도 없는데 오른쪽 괄호가 들어오려는 경우 스택에 삽입하고 중지
            if(stack.empty() && ((input[i] == ')') || (input[i] == ']'))){
                stack.push(')');//어차피 어느 괄호를 넣어도 상관없음.
                break;
            }

            if(stack.empty()){continue;}//stack.top() 예외오류 방지

            //괄호의 짝이 맞지 않는 경우 검사 중지
            if(((stack.top() == '(') && (input[i] == ']')) || ((stack.top() == '[') && (input[i] == ')'))){
                break;
            }

            //짝이 맞는 괄호가 들어오면 스택에서 왼쪽 괄호 제거
            if(((stack.top() == '(') && (input[i] == ')')) || ((stack.top() == '[') && (input[i] == ']'))){
                stack.pop();
            }
        }

        
        if(!stack.empty()){//스택이 비어있지 않으면
            res[count] = 1;
            count++;
            //cout << "no" << '\n'; 
        }else{//스택이 비어있으면
            res[count] = 0;
            count++;
            //cout << "yes" << '\n';
        }

        while(!stack.empty()){//다음 문자열 계산을 위해 스택 비우기<<if로 잘못썼는데 몰랐네...
            stack.pop();
        }
    }

    for(int i = 0;i<count;i++){
        if(res[i] == 1){
            cout << "no" << '\n';
        }else if(res[i] == 0){
            cout << "yes" << '\n';
        }
    }
}
