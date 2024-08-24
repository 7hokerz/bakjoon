#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//30의 배수 즉 30으로 나눴을 때 나머지가 0인 수를 구해야 한다.
//필수로 마지막 자리수는 0이 있어야 한다. 0이 없는 수는 -1을 출력하도록 한다.

//**자릿수의 합으로 배수를 구할 수 있다. 우선 합이 3의 배수여야 하는데, 마지막 자리는 0이 있기 때문에 자동으로 30의 배수가 성립된다

bool compare(char a, char b) {//내림차순 정렬용
    return a > b;
}

int main() {
    string num;
    cin >> num;

    sort(num.begin(), num.end(), compare);//배열의 시작점 주소, 배열의 마지막 주소 + 1을 가리킨다.

    int sum = 0;
    for (char c : num) {//콜론의 기능: num에서 차례대로 하나씩 꺼내어 c에 넣겠다는 의미
        sum += c - '0';//**문자를 숫자로 만들어 합에 더한다.
    }

    if (sum % 3 == 0 && num.back() == '0') {//num.back(): 배열의 마지막 원소를 가리킨다.
        cout << num << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
