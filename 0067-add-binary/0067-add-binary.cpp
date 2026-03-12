// The back is the lsb
// we traverse from back of the string
// if carry

#include <sstream>

class Solution {
public:

    // a popular Facebook variation of this problem when the interviewer 
    // provides you with two numbers and asks to sum them up without 
    // using the addition operation.



    string addBinary(string a, string b) {

        // start from the least significant bit
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int aLen = a.length();
        int bLen = b.length();
        int longerLen = aLen > bLen ? aLen : bLen;

        // Clever
        // int n = a.size(), m = b.size();
        // // Ensure 'a' is always the longer string
        // if (n < m)
        //     return addBinary(b, a);

        ostringstream out;
        int carry = 0;
        for (int i = 0; i < longerLen; i++) {
            int sum = carry;
            if (i < aLen)
                sum += a[i] - '0';
            if (i < bLen)
                sum += b[i] - '0';
            // cout << sum << endl;
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

// built in
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int numA = stoi(a, nullptr, 2);  // Convert binary string to integer
//         int numB = stoi(b, nullptr, 2);  // Convert binary string to integer
//         int sum = numA + numB;           // Sum the integers
//         if (sum == 0) return "0";
//         string binary =
//             bitset<32>(sum).to_string();  // Convert sum to binary string
//         return binary.substr(binary.find('1'));
//     }
// };