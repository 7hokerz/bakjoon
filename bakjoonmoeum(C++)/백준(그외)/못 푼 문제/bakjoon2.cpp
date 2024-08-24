#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string input, tmp="";
    queue <string> res;
    string str;
    int cnt = 0;
    cin >> N;
    cin.ignore();
    queue <string> q[N];

    for(int i = 0;i<N;i++){
        getline(cin, input);
        for(int j = 0;j<input.length();j++){
            tmp += input[j];
            if(input[j+1] == ' ' || j == input.length() - 1){
                q[i].push(tmp);
                tmp = "";
                j++;
            }
        }
    } 
    getline(cin, str);
    tmp = "";
    for(int i = 0;i<str.length();i++){
        tmp += str[i];
        if(str[i+1] == ' ' || i == str.length() - 1){
            res.push(tmp);
            tmp = "";
            i++;
        }
    }

    while(!res.empty()){
        if(q[cnt].empty()){
            while(!q[cnt].empty() && q[cnt].front().compare(res.front()) != 0){
                cnt++;
                
            }
        }
        if(q[cnt].front().compare(res.front()) == 0){
            q[cnt].pop();
            res.pop();
        }

        if(res.empty()) break;

        if(cnt == N-1 && !q[cnt].empty() && q[cnt].front().compare(res.front()) != 0){
            cout << "Impossible";
            return 0;
        }
    }
    cout << "Possible";
}
/*
N개의 큐에 string input을 저장?

3
i want to see you
next week
good luck
i want next good luck week to see you

2
i found
an interesting cave
i found an cave interesting

2
please
be careful
pen pineapple apple pen

*/