#include <iostream>//처음으로 한 번에 맞힘!
#include <string>
#include <stack>
using namespace std;

int main(){
    stack <char> stack;
    string S;
    string res;
    int count = 0;
    getline(cin, S);

    for(int i = 0;i<S.length();i++){
        
        if(S[i] == ' '){//공백이 등장하면
            while(!stack.empty()){   
                //스택이 빌 때까지 요소를 모두 res에 넣는다.
                res += stack.top();
                stack.pop();
            }
            res += ' ';
        }else if(S[i] == '<'){//태그가 등장하면
            while(!stack.empty()){   
                //스택이 빌 때까지 요소를 모두 res에 넣는다.
                res += stack.top();
                stack.pop();
            }
            int j;
            for(j = i;S[j] != '>';j++){
                //태그가 닫힐 때까지
                res += S[j];//요소를 모두 res에 넣는다.
            }
            res += '>';
            i = j;

        }else{stack.push(S[i]);}//문자요소를 모두 스택에 넣는다.}

    }
    while(!stack.empty()){   
        //스택이 빌 때까지 요소를 모두 res에 넣는다.
        res += stack.top();
        stack.pop();
    }
    cout << res << endl;
}
/*문자열이 주어진다.
아래의 조건이 아닌 경우에 문자를 우선 스택에 차례차례 넣는다.
1. 공백이 등장하면 스택에서 모든 요소를 빼내어 res에 삽입
2. <가 등장하면 >가 나올 때까지 요소 하나하나를 res에 직접 삽입
*/