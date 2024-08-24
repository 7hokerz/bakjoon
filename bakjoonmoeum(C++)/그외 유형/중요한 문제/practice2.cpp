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
        vector<string> command;
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
            
            for (string cmd: command) {
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
                else if(cmd == "SWP"){//첫번째수와 두번째수 스왑
                    first = gst.top();
                    gst.pop();
                    second = gst.top();
                    gst.pop();//이걸 안써서??
                    gst.push(first);
                    gst.push(second);
                }
                else if(cmd == "ADD"){//더하기
                    first = gst.top();
                    gst.pop();
                    second = gst.top();
                    gst.pop();
                    if(first+second > 1'000'000'000 ||
                    first+second < -1'000'000'000){
                        errcnt++;
                        break;
                    }
                    gst.push(first+second);
                }
                else if(cmd == "SUB"){//빼기
                    first = gst.top()*1LL;
                    gst.pop();
                    second = gst.top()*1LL;
                    gst.pop();
                    if(second-first > 1'000'000'000 ||
                    second-first < -1'000'000'000){
                        errcnt++;
                        break;
                    }
                    gst.push(second-first);
                }
                else if(cmd == "MUL"){//곱하기
                    first = gst.top()*1LL;
                    gst.pop();
                    second = gst.top()*1LL;
                    gst.pop();
                    if(first*second > 1'000'000'000 ||
                    first*second < -1'000'000'000){
                        errcnt++;
                        break;
                    }
                    gst.push(first*second);
                }
                else if(cmd == "DIV"){//나누기
                    first = gst.top()*1LL;
                    if(first == 0){
                        errcnt++;
                        break;
                    }
                    gst.pop();
                    second = gst.top();
                    gst.pop();

                    val = abs(second)/abs(first);
                    if (second*first < 0) val *= -1;

                    if(val > 1'000'000'000 || 
                    val < -1'000'000'000){
                        errcnt++;
                        break;
                    }
                    gst.push(val);
                }
                else if(cmd == "MOD"){
                    first = gst.top()*1LL;
                    if(first == 0){
                        errcnt++;
                        break;
                    }
                    gst.pop();
                    second = gst.top();
                    gst.pop();

                    val = abs(second)%abs(first);
                    if (second < 0) val *= -1;
                    if(val > 1'000'000'000 || val < -1'000'000'000){
                        errcnt++;
                        break;
                    }
                    gst.push(val);
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