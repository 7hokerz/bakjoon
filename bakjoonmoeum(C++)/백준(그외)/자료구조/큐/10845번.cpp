#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <int> q;
    string com;
    int n, input; cin >> n;
    for(int i = 0;i<n;i++){
        cin >> com;
        if(com == "push"){
            cin >> input; q.push(input);
        }else if(com == "pop"){
            if(q.empty())cout << -1 <<'\n'; else {cout << q.front() <<'\n'; q.pop();}
        }else if(com == "size")cout << q.size() << '\n';
        else if(com == "empty")cout << q.empty() << '\n';
        else if(com == "front"){if(q.empty())cout << -1 <<'\n';else cout << q.front() << '\n';}
        else if(com == "back"){if(q.empty())cout << -1 <<'\n';else cout << q.back() << '\n';}
    }
}