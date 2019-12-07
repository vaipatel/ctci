#include <iostream>
#include <string>
using namespace std;


/*!
 * \pre 0 <= a.length()
 * \pre a.length() == b.length
 * \pre a.length() == b.length() - 1
 */
bool checkOneEdit(string a, string b)
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

bool isOneEditAway(string s1, string s2)
{
    int s1Len = s1.length(), s2Len = s2.length();
    if (s1Len == s2Len)
    {
        return checkOneEdit(s1, s2);
    }
    if (s1Len == s2Len - 1)
    {
        return checkOneEdit(s1, s2);
    }
    if (s2Len == s1Len - 1)
    {
        return checkOneEdit(s2, s1);
    }
    return false;
}

int main()
{
    cout << isOneEditAway("appee", "apple") << endl;
    cout << isOneEditAway("", "") << endl;
    cout << isOneEditAway("a", "") << endl;
    cout << isOneEditAway("", "x") << endl;
    cout << isOneEditAway("latte", "late") << endl;
    cout << isOneEditAway("lass", "lasso") << endl;
    cout << !isOneEditAway("hello", "helen") << endl;
    cout << !isOneEditAway("apppl", "apl") << endl;
    return 0;
}
