#include <iostream>
using namespace std;

int main() {
    int k, first, second;
    long long chk1, chk2;
    cin >> k;
    
    cin >> first >> second;
    chk1 = first*1LL*k+second;

    cin >> first >> second;
    chk2 = first*1LL*k+second;

    if(chk1 == chk2) cout << "Yes " << chk1; 
    else cout << "No";
}
/*
수의 범위 때문에 int를 넘어갈 수 있는 걸 못봤다.
*/