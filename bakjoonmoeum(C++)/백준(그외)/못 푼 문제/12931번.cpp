#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector <int> vt, arr;
    int N, input;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        vt.push_back(input);
        arr.push_back(0);
    }
    int cnt = 0;
    while(!vt.empty()){
        int check = 0;
        for(int i = vt.size()-1;i>=0;i--){
            if(vt[i] == arr[i]){
                vt.erase(vt.begin()+i); arr.erase(arr.begin()+i);
            }else if(arr[i] != 0 && arr[i] * 2 <= vt[i]){
                check++;
            }else{
                arr[i]++;
                cnt++;
            }
        }
        if(!arr.empty() && check == arr.size()){
            for(int i = vt.size()-1;i>=0;i--){
                arr[i] *= 2;
            }
            cnt++;
        }
    }
    cout << cnt;
}
/* 
예제 3에서 틀린다. 이유는 무조건 곱하는 것만이 좋은 건 아님. 먼저 더하고 어느 정도 수가 커진 뒤 곱하는 게 더 최소일 수 있음.
*/