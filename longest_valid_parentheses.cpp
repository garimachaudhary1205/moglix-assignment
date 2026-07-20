#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Longest Balanced Parentheses
// Two-pass O(n) time, O(1) space approach.
int longestBalancedParentheses(string s) {
    int left = 0, right = 0, maxLen = 0;

    // Left-to-right pass: catches valid substrings where '(' are not in excess.
    for (char ch : s) {
        if (ch == '(') left++;
        else right++;

        if (left == right) maxLen = max(maxLen, 2 * right);
        else if (right > left) left = right = 0;
    }

    // Right-to-left pass: catches valid substrings where ')' are not in excess.
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') left++;
        else right++;

        if (left == right) maxLen = max(maxLen, 2 * left);
        else if (left > right) left = right = 0;
    }

    return maxLen;
}

int main() {
    // given examples
    cout << longestBalancedParentheses("(()") << endl;      // expect 2
    cout << longestBalancedParentheses(")()())") << endl;   // expect 4
    cout << longestBalancedParentheses("") << endl;         // expect 0

    // extra edge cases
    cout << longestBalancedParentheses(")(") << endl;       // expect 0
    cout << longestBalancedParentheses("()(()") << endl;    // expect 2
    cout << longestBalancedParentheses("(((((") << endl;    // expect 0

    return 0;
}
