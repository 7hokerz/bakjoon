#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main(){
    stack <int> stack;

    int T;//개수
    cin >> T;
    char par[51];//입력되는 괄호(50이 아니라 51로 해야 통과)(아마도 개행문자 관련 문제인듯?)
    char data[T][51];//모든 괄호를 저장(같은 이유)
    
    for(int i = 0;i<T;i++){
        cin >> par;
        strcpy(data[i], par);
        for(int j = 0;j<strlen(data[i]);j++){//문자열 검사 및 스택에 저장

            if(data[i][j] == '('){//왼쪽 괄호는 스택에 삽입
                stack.push(data[i][j]);
            }
            else if((data[i][j] == ')') && (!stack.empty())){//오른쪽 괄호이면서 스택이 비어있지 않으면 스택에서 왼쪽 괄호를 제거
                stack.pop();
            }else{//오른쪽 괄호가 스택이 비어있는데 들어오려는 경우(스택에 '('을 삽입하고 반복문 탈출))
                stack.push(data[i][j]);
                break;
            }
        }   

        if(!stack.empty()) cout << "NO" << '\n';//스택이 비어있지 않으면 NO 출력(왼쪽 괄호가 남은 경우, 오른쪽 괄호가 들어온 경우 모두 해당)
        else cout << "YES" << '\n';//스택이 비어있는 경우(정상)

        while(!stack.empty()){//스택 비워주는 함수
            stack.pop();
        }
    }
}
