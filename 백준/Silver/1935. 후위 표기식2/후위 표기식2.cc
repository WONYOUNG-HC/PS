#include <iostream>
#include <stack>

using namespace std;

int n;
string s;
double arr[126];

int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> arr[i + 'A'];

    stack<double> st;
    for (char c : s) {
        if (isalpha(c)) {
            st.push(arr[c]);
        }
        else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            double k;
            if (c == '+')
                k = a + b;
            else if (c == '-')
                k = a - b;
            else if (c == '*')
                k = a * b;
            else
                k = a / b;

            st.push(k);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top();
}