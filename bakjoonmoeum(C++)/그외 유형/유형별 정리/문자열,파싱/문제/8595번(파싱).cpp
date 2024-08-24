#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    string input;
    cin >> input;
    input += "E";
    
    long long res = 0LL;
    string sum = "";
    for(int i = 0;i<input.length()-1;i++){
        if(isdigit(input[i]) && isdigit(input[i+1])){
            sum += input[i];
        }
        else if(isdigit(input[i]) && !isdigit(input[i+1])){
            sum += input[i];
            res += stoi(sum)*1LL;
            sum = "";
        }
    }
    cout << res;
}
/*

*/