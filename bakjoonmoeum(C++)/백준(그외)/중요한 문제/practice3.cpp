#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        vector <string> command;
        //큐 대신 벡터를 쓰면 꺼내고 넣고 할 필요 없이 순회만 하면 된다.
        int N;
        string input;
        long long val;
        long long first, second;
        while(1){
            getline(cin, input);
            if(input == "QUIT") return 0;
            command.push_back(input);
            if(input == "END"){
                break;
            } 
        }
        input = "";
        cin >> N;
        for(int i = 0;i<N;i++){//프로그램 실행
            stack <long long> gst;
            int errcnt = 0;
            cin >> val;
            gst.push(val);
            
            for(string cmd: command){
                if(cmd == "END" || errcnt){
                    break;
                }
                else if(cmd.substr(0,3) == "NUM"){//고스택에 val 추가
                    val = stoi(cmd.substr(4));
                    gst.push(val);
                }
                else if(gst.empty()){
                    errcnt++;
                }
                else if(cmd == "POP"){//고스택의 탑 제거
                    gst.pop();
                }
                else if(cmd == "INV"){//첫 번째 수의 부호 변경
                    val = -gst.top();
                    gst.pop();
                    gst.push(val);
                }
                else if(cmd == "DUP"){//탑 값을 하나 더 탑에 저장
                    gst.push(gst.top());
                }
                else if(gst.size() < 2){
                    errcnt++;
                }
                else{
                    first = gst.top();
                    gst.pop();
                    second = gst.top();
                    gst.pop();
                    if(cmd == "SWP"){//첫번째수와 두번째수 스왑
                        gst.push(first);
                        gst.push(second);
                        continue;
                    }
                    else if(cmd == "ADD"){//더하기
                        val = first+second;
                    }
                    else if(cmd == "SUB"){//빼기
                        val = second - first;
                    }
                    else if(cmd == "MUL"){//곱하기
                        val = first*second;
                    }
                    else if(cmd == "DIV"){//나누기
                        if(first == 0){
                            errcnt++;
                            break;
                        }
                        val = abs(second)/abs(first);
                        if (second*first < 0) val *= -1;
                    }
                    else if(cmd == "MOD"){
                        if(first == 0){
                            errcnt++;
                            break;
                        }
                        val = abs(second)%abs(first);
                        if(second < 0) val *= -1;
                    }
                    if(abs(val) > 1000000000) errcnt++;
                    else gst.push(val);
                }
            }
            if(gst.size() != 1 || errcnt){
                cout << "ERROR" << '\n';
            }else{
                cout << gst.top() << '\n';
            }
        }
        cout << '\n';
        getline(cin, input);
        cin.ignore();
    }
}
/*
NUM X: X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 109)     문제 없음
POP: 스택 가장 위의 숫자를 제거한다.
INV: 첫 번째 수의 부호를 바꾼다. (42 -> -42)
DUP: 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.   문제 없음
SWP: 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.              문제 없음
SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.              문제 없음
DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 
두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 
두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.


예외조건:
숫자가 부족해서 연산을 수행할 수 없을 때, O
0으로 나눴을 때 (DIV, MOD), O
연산 결과의 절댓값이 10^9를 넘어갈 때는 O
모두 프로그램 에러이다.
*/