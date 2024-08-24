#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <char> dq;
    //deque <char> tmp;
    int countB = 0, cnt = 0, allcountB = 0;
    string input;
    cin >> input;
    for(int i = 0;i<input.length();i++){
        dq.push_back(input[i]);
        if(input[i] == 'C' && countB > 0){
            countB--;
            cnt++; 
        }else if(input[i] == 'B'){
            countB++;
            allcountB++;
        }
    }
    
    input = "";
    while(!dq.empty()){
        if(dq.front() != 'C'){
            if(dq.front() == 'B' && allcountB>countB){
                countB++;
            }
            else input += dq.front();
        }
        dq.pop_front();
    }
    
    dq.push_back(input[0]);
    for(int i = 1;i<input.length();i++){
        if(!dq.empty() && dq.back() == 'A' && input[i] == 'B'){
            dq.pop_back();
            cnt++;
        }else{
            dq.push_back(input[i]);
        }
    }
    cout << cnt;
}
/*
AB보다 BC를 먼저 지우는 게 유리하다.
먼저 BC를 지울 때 B보다 뒤에 있는 C 중 제일 가까운 것을 지운다.
지울 수 있는 BC를 모두 지운 후 AB를 지운다.
**B가 여러개 있으면 C가 하나 발견됐을 때 가장 최상단에 있는 B를 지워준다.

+ 기존에 tmp에 옮기고 빼고 하는 작업이 있어서 시간초과가 되었다.
하여 이 부분을 지우고, countB를 이용하면서 allcountB를 추가하여 풀었다.
어차피 항상 앞에 있는 B가 먼저 없어지고 뒤에 있는 B가 남기 때문에 가능한 풀이였다.

포인트: 자료구조를 이용하여 쓰는 것도 좋지만 그 외 방법으로 간단하게 가능하면 꼭 쓸 필요는 없다.

ABCBA 0
ABA 1
A 2

ABCBBACBABB 0
ABBACBABB 1
ABABABB 2
ABABB 3
ABB 4
B 5

while(!dq.empty() && dq.front() != 'B'){
                tmp.push_front(dq.front());
                dq.pop_front();
            }

while(!tmp.empty()){
                dq.push_front(tmp.front());
                tmp.pop_front();
            }
*/