#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> st1;
    stack <int> st2;
    stack <int> st3;
    stack <int> st4;
    stack <int> st5;
    stack <int> st6;

    int N, P, input, count = 0;
    cin >> N >> P;
    
    for(int i = 0;i<N;i++){
        cin >> input;
        switch (input) {
            case 1:
            cin >> input;
            if(st1.empty() || st1.top() < input) {
                st1.push(input);
                count++;
            }
            else if(st1.top() > input){
                while(!st1.empty() && st1.top() > input){
                    st1.pop();
                    count++;
                }
                if(st1.empty() || (!st1.empty() && st1.top() != input)){
                    st1.push(input);
                    count++;
                }
            }
                break;
            case 2:
            cin >> input;
            if(st2.empty() || st2.top() < input) {
                st2.push(input);
                count++;
            }
            else if(st2.top() > input){
                while(!st2.empty() && st2.top() > input){
                    st2.pop();
                    count++;
                }
                if(st2.empty() || (!st2.empty() && st2.top() != input)){
                    st2.push(input);
                    count++;
                }
            }
                break;
            case 3:
            cin >> input;
            if(st3.empty() || st3.top() < input) {
                st3.push(input);
                count++;
            }
            else if(st3.top() > input){
                while(!st3.empty() && st3.top() > input){
                    st3.pop();
                    count++;
                }
                if(st3.empty() || (!st3.empty() && st3.top() != input)){
                    st3.push(input);
                    count++;
                }
            }
                break;
            case 4:
            cin >> input;
            if(st4.empty() || st4.top() < input) {
                st4.push(input);
                count++;
            }
            else if(st4.top() > input){
                while(!st4.empty() && st4.top() > input){
                    st4.pop();
                    count++;
                }
                if(st4.empty() || (!st4.empty() && st4.top() != input)){
                    st4.push(input);
                    count++;
                }
            }
                break;
            case 5:
            cin >> input;
            if(st5.empty() || st5.top() < input) {
                st5.push(input);
                count++;
            }
            else if(st5.top() > input){
                while(!st5.empty() && st5.top() > input){
                    st5.pop();
                    count++;
                }
                if(st5.empty() || (!st5.empty() && st5.top() != input)){
                    st5.push(input);
                    count++;
                }
            }
                break;
            case 6:
            cin >> input;
            if(st6.empty() || st6.top() < input) {
                st6.push(input);
                count++;
            }
            else if(st6.top() > input){
                while(!st6.empty() && st6.top() > input){
                    st6.pop();
                    count++;
                }
                if(st6.empty() || (!st6.empty() && st6.top() != input)){
                    st6.push(input);
                    count++;
                }
            }
                break;
        }
    }
    cout << count;
}
/*

stack <int> st[6] 이런식으로 객체 배열을 만들 수 있네...?
stack도 클래스니까 가능한거긴 한데...허허 노가다로 풀어버렸네... ㅋㅋ

손가락으로 프렛을 한 번 누르거나 떼는 것을
손가락을 움직인 횟수 1

만약, 어떤 줄의 프렛을 여러 개 누르고 있다면, 
가장 높은 프렛의 음이 발생한다.

5 15
2 8
2 10
2 12
2 10
2 5

1
2
3
4 (8, 10을 누르고 있음)
7 (8,10을 떼고 5를 새로 누른다.)

7 15
1 5
2 3
2 5
2 7
2 4
1 5
1 3

1
2
3
4
7
7
9

*/