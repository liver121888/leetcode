// The back is the lsb
// we traverse from back of the string
// if carry

#include <sstream>

class Solution {
public:
    string addBinary(string a, string b) {


        // start from the least significant bit
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int aLen = a.length();
        int bLen = b.length();
        int longerLen = aLen > bLen ? aLen : bLen;

        ostringstream out;
        int carry = 0;
        for (int i = 0; i < longerLen; i++) {
            int sum = carry;
            if (i < aLen)
                sum += a[i] - '0';
            if (i < bLen)
                sum += b[i] - '0';
            cout << sum << endl;
            carry = sum/2;
            out << to_string(sum%2);
        }
        if (carry)
            out << to_string(carry);
        string ans = out.str();
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};