#include <iostream> // cout
#include <cctype> // tolower
#include <cstring> // strlen
#include <bitset> // bitset

bool isPermOfPalindrome(const char *s)
{
    int l = strlen(s);
    unsigned int b = 0;
    for (int i = 0; i < l; ++i)
    {
        // get the int for s[i]
        int c = tolower(s[i]) - 'a';
        // ignore non-letter chars
        if (c < 0) continue;
        // retoggle the bits for c using XOR
        b = b ^ (1 << c);
    }
    // b should have just one or no bits set to be a palindrome perm.
    std::bitset<26> bits(b);
    return (b == 0) || (bits.count() == 1);
}

int main()
{
    std::cout << isPermOfPalindrome("tACo Cat") << std::endl;
    std::cout << isPermOfPalindrome("xaabb") << std::endl;
    std::cout << isPermOfPalindrome("") << std::endl;
    std::cout << isPermOfPalindrome("a") << std::endl;
}
