#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int money;
    int result;
    cin >> money;

    money = 1000 - money;
    
    result += money / 500;
    money = money % 500;
    result += money / 100;
    money = money % 100;
    result += money / 50;
    money = money % 50;
    result += money / 10;
    money = money % 10;
    result += money / 5;
    money = money % 5;
    result += money / 1;

    cout << result;
}