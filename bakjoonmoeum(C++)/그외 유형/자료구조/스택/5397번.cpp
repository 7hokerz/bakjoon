#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    deque <char> left;
    deque <char> right;
    int T;
    string input;
    cin >> T;

    for(int i = 0;i<T;i++){
        cin >> input;
        for(int j = 0;j<input.length();j++){
            if(input[j] == '<'){
                if(left.empty()){
                    continue;
                }else{
                    right.push_back(left.back());
                    left.pop_back();
                }
            }else if(input[j] == '>'){
                if(right.empty()){
                    continue;
                }else{
                    left.push_back(right.back());
                    right.pop_back();
                }
            }else if(input[j] == '-'){
                if(left.empty()){
                    continue;
                }else{
                    left.pop_back();
                }
            }else{
                left.push_back(input[j]);
            }
        }
        while(!left.empty()){
            cout << left.front() ;
            left.pop_front();
        }
        while(!right.empty()){
            cout << right.back();   
            right.pop_back(); 
        }
        cout << '\n';
    }
}
/*
-: 백스페이스
<: 커서를 왼쪽으로 1칸 이동
>: 커서를 오른쪽으로 1칸 이동
(둘 다 움직일 수 있는 경우에만)

2
<<BP<A>>Cd-
ThIsIsS3Cr3t

BAPC
ThIsIsS3Cr3t
*/