#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        
        set<char> s;
        bool flag = true;
        for (int j=0; j<(int)str.size(); j++) {
            if (j > 0 && str[j] == str[j-1])
                continue;
            
            auto pr = s.insert(str[j]);
            flag = pr.second;
            
            if (!flag) break;
        }
        
        if (flag) ans++;
    }
    
    cout << ans;
}