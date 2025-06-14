#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s; cin >> s;
    int b[5001] = {0};

    b[0] = 1; b[1] = 1;
    for(int i = 2; i <= s.size(); i++) {
        if(10 <= stoi(s.substr(i - 2, 2)) && stoi(s.substr(i - 2, 2)) <= 26) {
            b[i] = (b[i] + b[i - 2]) % 1000000;        
        }
        else {
            if(s[i - 1] == '0') {
                cout << '1' << endl;
                return 0;
            }
        }
        b[i] = (b[i] + b[i - 1]) % 1000000;
    }
    cout << b[s.size()] << endl;
    return 0;
}

1 0 0 0 1