#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int N, R, Q;
string input;
char inp;

list <char> first, second, third, four;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R >> Q;
    cin >> input;
    for(int i = 0;i<R;i++) first.push_back(input[i]);
    for(int i = R;i<N;i++) second.push_back(input[i]);
    
    cin >> input;
    for(int i = 0;i<R;i++) third.push_back(input[i]);
    for(int i = R;i<N;i++) four.push_back(input[i]);
    
    bool chk = true;//true 1<->2. 3<->4(1이 1에, 3이 2에 위치) , false 1<->4. 3<->2(1이 2에, 3이 1에 위치)

    for(int i = 0;i<Q;i++){
        cin >> inp;
        if(inp == 'S') chk = !chk;
        else if(inp == 'I'){ if(four.empty() || second.empty()) continue;
            if(!chk){//1<->4. 3<->2
                first.push_back(four.front()); four.pop_front();
                third.push_back(second.front()); second.pop_front();
            }
            else{//1<->2. 3<->4
                first.push_back(second.front()); second.pop_front();
                third.push_back(four.front()); four.pop_front();
            }
        }
        else if(inp == 'D'){ if(first.size() < 2 || third.size() < 2) continue;
            if(!chk){//1<->4. 3<->2
                four.push_front(first.back()); first.pop_back();
                second.push_front(third.back()); third.pop_back();
            }
            else{//1<->2. 3<->4
                second.push_front(first.back()); first.pop_back();
                four.push_front(third.back()); third.pop_back();
            }
        }
        else if(inp == 'L'){
            cin >> inp;
            if(inp == '1'){
                if(!chk){//1<->4 2 3<->2 1
                    if(third.empty()) {second.push_back(second.front()); second.pop_front();}
                    else if(second.empty()) {third.push_back(third.front()); third.pop_front();}
                    else{
                        second.push_back(third.front()); third.pop_front();
                        third.push_back(second.front()); second.pop_front();
                    }
                }   
                else{///1<->2 1 3<->4 2
                    if(first.empty()) {second.push_back(second.front()); second.pop_front();}
                    else if(second.empty()) {first.push_back(first.front()); first.pop_front();}
                    else{
                        second.push_back(first.front()); first.pop_front();
                        first.push_back(second.front()); second.pop_front();
                    } 
                }
            }
            else{
                if(!chk){//3<->2
                    if(first.empty()) {four.push_back(four.front()); four.pop_front();}
                    else if(four.empty()) {first.push_back(first.front()); first.pop_front();}
                    else{
                        four.push_back(first.front()); first.pop_front();
                        first.push_back(four.front()); four.pop_front();
                    }
                }   
                else{//3<->4
                    if(third.empty()) {four.push_back(four.front()); four.pop_front();}
                    else if(four.empty()) {third.push_back(third.front()); third.pop_front();}
                    else{   
                        four.push_back(third.front()); third.pop_front();
                        third.push_back(four.front()); four.pop_front();
                    }
                }
            }
        }
        else if(inp == 'R'){
            cin >> inp;
            if(inp == '1'){
                if(!chk){//1<->4
                    if(third.empty()) {second.push_front(second.back()); second.pop_back();}
                    else if(second.empty()) {third.push_front(third.back()); third.pop_back();}
                    else{
                        second.push_front(third.back()); third.pop_back();
                        third.push_front(second.back()); second.pop_back();
                    }  
                }   
                else{///1<->2
                    if(first.empty()) {second.push_front(second.back()); second.pop_back();}
                    else if(second.empty()) {first.push_front(first.back()); first.pop_back();}
                    else{
                        second.push_front(first.back()); first.pop_back();
                        first.push_front(second.back()); second.pop_back();
                    }   
                }
            }
            else{
                if(!chk){//1<->4
                    if(four.empty()) {first.push_front(first.back()); first.pop_back();}
                    else if(first.empty()) {four.push_front(four.back()); four.pop_back();}
                    else{
                        first.push_front(four.back()); four.pop_back();
                        four.push_front(first.back()); first.pop_back();
                    }
                }   
                else{
                    if(third.empty()) {four.push_front(four.back()); four.pop_back();}
                    else if(four.empty()) {third.push_front(third.back()); third.pop_back();}
                    else{
                        four.push_front(third.back()); third.pop_back();
                        third.push_front(four.back()); four.pop_back();
                    }
                }
            }
        }
    }   
    if(chk) while(!first.empty()){cout << first.front(); first.pop_front();} 
    else while(!third.empty()){cout << third.front(); third.pop_front();}
    
    while(!second.empty()){cout << second.front(); second.pop_front();} cout << '\n'; 

    if(chk) while(!third.empty()){cout << third.front(); third.pop_front();}
    else while(!first.empty()){cout << first.front(); first.pop_front();} 
    
    while(!four.empty()){cout << four.front(); four.pop_front();}  
}
/*

처음엔 덱1 link 덱2, 덱3 link 덱4 상태

   앞뒤    앞뒤
1. 덱1  R  덱2
AB CDE

   앞뒤    앞뒤
2. 덱3  R  덱4
FG HIJ

S >> 리스트1 link 리스트4로 변경, 리스트3 link 리스트2로 변경
bool chk 변수 사용(false >> 덱12 덱34)(true >> 덱14 덱23)

L >> (chk == true) >> 리4.push_back(리1.front), 리1.pop_front
R >> (chk == true) >> 리3.push_back(리2.front), 리2.pop_front
 
I >> 리1.push_back(리4.front), 리4.pop_front 및 리3.push_back(리2.front), 리2.pop_front
D >> 반대로

FGCDE
ABHIJ

GCDEF
JABHI

JABEF
GCDHI
*/