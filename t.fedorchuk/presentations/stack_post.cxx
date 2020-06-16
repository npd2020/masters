#include <iostream>
#include <string>
#include <stack>
using namespace std;


void myStk(int &m, int &n, stack<int> &st) {
    m = st.top();
    st.pop();
    n = st.top();
    st.pop();
}
 
int main() {
    string S;
    cout << "Input string:" << endl;
    getline(cin, S);
    stack<int> stc;
    for (auto &r : S) {
        if (r == '*') {
            int a, b;
            myStk(a, b, stc);
            stc.push(a * b);
        }
        else if (r == '+') {
            int a, b;
            myStk(a, b, stc);
            stc.push(a + b);
        }
        else if (r == '-') {
            int a, b;
            myStk(a, b, stc);
            stc.push(a - b);
        }
        else{
            stc.push((int)r - 48);
	}
    }
    cout << stc.top() << endl;
    return 0;
}
