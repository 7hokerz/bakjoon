#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    cin.ignore();
    string input;
    string delimiter = ",";
    getline(cin,input);
    input += delimiter;
    
    int arr[N];
    
    //구분자를 통해 split할 수 있는 코드
    int curpos = 0;
    int pos, cnt = 0;
    //pos는 구분자를 찾은 위치며, 구분자가 나오지 않을 때까지 찾는다고 보면 됨.
    while((pos = input.find(delimiter, curpos)) != string::npos){
        int len = pos - curpos;
        arr[cnt] = stoi(input.substr(curpos, pos));
        cnt++;
        curpos = pos + 1;//현재 위치 + 1을 해야 구분자 다음 위치부터 탐색한다.
    }
    for(int j = 0;j<K;j++){
        for(int i=1;i<N;i++){
            arr[i-1] = arr[i] - arr[i-1];
        }
    }
    for(int i=0;i<N-K;i++){
        cout << arr[i];
        if(i != N-K-1) cout << ',';
    }
}
/*

*/