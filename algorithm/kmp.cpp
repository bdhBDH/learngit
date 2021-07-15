#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyString{
    vector<int> getNext(string t)
    {
        int n = t.size();
        vector<int> next(n, 0);
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j > 0 && t[i] != t[j])
            {
                j = next[j];
            }
            if (t[i] == t[j])
                next[i] = ++j;
        }
        return next;
    }
public:
    int kmp(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<int> next(n);
        next = getNext(p);
        for (int i = 0, j = 0; i < m; i++)
        {
            while (j > 0 && s[i] != p[j])
            {
                j = next[j];
            }
            if (s[i] == p[j]) ++j;
            if (j == n) return i-n+1;
        }
        return false;
    }
};

int main()
{
    string t = "ABAB";
    string s = "ccuuABAB";
    MyString kpm;
    int i = kpm.kmp(s, t);
    cout << i << endl;
    return 0;
}