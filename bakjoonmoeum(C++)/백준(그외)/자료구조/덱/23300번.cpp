#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <int> front;//앞으로 가기
    deque <int> back;//뒤로 가기
    deque <int> back2;//압축 때 이용할 덱
    int N, Q, page = 0;//현재 페이지
    char input;
    cin >> N >> Q;

    for(int i = 0;i<Q;i++){
        cin >> input;
        if(input == 'B'){
            if(back.empty()){
                continue;
            }else{
                front.push(page);
                page = back.back();
                back.pop_back();
            }
        }
        else if(input == 'F'){
            if(front.empty()){
                continue;
            }else{
                back.push_back(page);
                page = front.top();
                front.pop();
            }
        }
        else if(input == 'A'){
            while(!front.empty()) front.pop();
            if(page != 0){
                back.push_back(page);
            }
            cin >> page;

        }   
        else if(input == 'C'){
            if(back.empty()) continue;
            back2.push_front(back.back());
            back.pop_back();
            while(!back.empty()){
                if(back2.front() == back.back()){
                    back.pop_back();
                }else{
                    back2.push_front(back.back());
                    back.pop_back();
                }
            }
            swap(back, back2);
        }
    }

    cout << page << '\n';

    if(back.empty()) cout << -1 << '\n';
    else{
        while(!back.empty()){
            cout << back.back() << ' ';
            back.pop_back();
        }
        cout << '\n';
    }

    if(front.empty()) cout << -1 << '\n';
    else{
        while(!front.empty()){
            cout << front.top() << ' ';
            front.pop();
        }
    }
}
/* 
(1) 뒤로 가기 B complete
1. 뒤로 가기 공간에 1개 이상의 페이지가 있을 시 2,3번 실행
2. 현재 페이지를 앞으로 가기 공간에 저장
3. 뒤로 가기 공간에서 가장 최근 페이지에 접속. 해당 페이지는 뒤로 가기에서 삭제

(2) 앞으로 가기 F complete
논리적으로 뒤로 가기와 같은 원리다.

(3) 웹 페이지에 접속 시 A i complete
1. 앞으로 가기 공간 모두 삭제
2. 현재 페이지를 뒤로 가기 공간에 추가, 다음에 접속할 페이지가 현재 페이지로 갱신
(처음으로 접속하는 거라면 현재 페이지를 뒤로 가기에 추가 X)

(4) 압축 C complete
뒤로 가기 공간에서 같은 페이지가 '연속해서' 2개 이상인 경우 최근것만 빼고 중복 삭제
*/