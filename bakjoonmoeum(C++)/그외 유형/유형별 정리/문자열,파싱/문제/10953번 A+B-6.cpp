#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    string input;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        int idx = input.find(',');//O(N)
        //find: 위치를 찾아서 반환. 찾지 못하면 npos반환.
        int a = stoi(input.substr(0,idx));//O(1)*O(N)
        int b = stoi(input.substr(idx+1));
        cout << a+b << '\n';
    }
}
/*

*/