#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> st[6];
    
    int N, P, input, count = 0;
    cin >> N >> P;
    
    for(int i = 0;i<N;i++){
        cin >> input;
        switch (input) {
            case 1:
            cin >> input;
            if(st[0].empty() || st[0].top() < input) {
                st[0].push(input);
                count++;
            }
            else if(st[0].top() > input){
                while(!st[1].empty() && st[1].top() > input){
                    st[0].pop();
                    count++;
                }
                if(st[0].empty() || (!st[0].empty() && st[0].top() != input)){
                    st[0].push(input);
                    count++;
                }
            }
                break;
            case 2:
            cin >> input;
             if(st[1].empty() || st[1].top() < input) {
                st[1].push(input);
                count++;
            }
            else if(st[1].top() > input){
                while(!st[1].empty() && st[1].top() > input){
                    st[1].pop();
                    count++;
                }
                if(st[1].empty() || (!st[1].empty() && st[1].top() != input)){
                    st[1].push(input);
                    count++;
                }
            }
                break;
            case 3:
            cin >> input;
            if(st[2].empty() || st[2].top() < input) {
                st[2].push(input);
                count++;
            }
            else if(st[2].top() > input){
                while(!st[2].empty() && st[2].top() > input){
                    st[2].pop();
                    count++;
                }
                if(st[2].empty() || (!st[2].empty() && st[2].top() != input)){
                    st[2].push(input);
                    count++;
                }
            }
                break;
            case 4:
            cin >> input;
            if(st[3].empty() || st[3].top() < input) {
                st[3].push(input);
                count++;
            }
            else if(st[3].top() > input){
                while(!st[1].empty() && st[1].top() > input){
                    st[3].pop();
                    count++;
                }
                if(st[3].empty() || (!st[3].empty() && st[3].top() != input)){
                    st[3].push(input);
                    count++;
                }
            }
                break;
            case 5:
            cin >> input;
            if(st[4].empty() || st[4].top() < input) {
                st[4].push(input);
                count++;
            }
            else if(st[4].top() > input){
                while(!st[4].empty() && st[4].top() > input){
                    st[4].pop();
                    count++;
                }
                if(st[4].empty() || (!st[4].empty() && st[4].top() != input)){
                    st[4].push(input);
                    count++;
                }
            }
                break;
            case 6:
            cin >> input;
            if(st[5].empty() || st[5].top() < input) {
                st[5].push(input);
                count++;
            }
            else if(st[5].top() > input){
                while(!st[5].empty() && st[5].top() > input){
                    st[5].pop();
                    count++;
                }
                if(st[5].empty() || (!st[5].empty() && st[5].top() != input)){
                    st[5].push(input);
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