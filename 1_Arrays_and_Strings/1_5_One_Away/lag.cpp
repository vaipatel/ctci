#include <iostream>
#include <string>
using namespace std;


/*!
 * \pre 0 <= a.length()
 * \pre a.length() == b.length
 * \pre a.length() == b.length() - 1
 */
bool oneEdit(string a, string b)
{
    int lag = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i - lag] != b[i])
        {
            if (lag == 1) return false;
            // lag shorter str's idx by 1
            lag = 1;
        }
    }
    return true;
}

bool checkOneEdit(string s1, string s2)
{
    int s1Len = s1.length(), s2Len = s2.length();
    if (s1Len == s2Len)
    {
        return oneEdit(s1, s2);
    }
    if (s1Len == s2Len - 1)
    {
        return oneEdit(s1, s2);
    }
    if (s2Len == s1Len - 1)
    {
        return oneEdit(s2, s1);
    }
    return false;
}

int main()
{
    cout << checkOneEdit("appee", "apple") << endl;
    cout << checkOneEdit("", "") << endl;
    cout << checkOneEdit("a", "") << endl;
    cout << checkOneEdit("", "x") << endl;
    cout << checkOneEdit("latte", "late") << endl;
    cout << checkOneEdit("lass", "lasso") << endl;
    cout << !checkOneEdit("hello", "helen") << endl;
    cout << !checkOneEdit("apppl", "apl") << endl;
    return 0;
}
