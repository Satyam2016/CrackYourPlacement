// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        char sum = '0';
        int carry = 0;
        string newstr = "";

        while (i >= 0 || j >= 0 || carry > 0) {
            int bitA = (i >= 0) ? a[i] - '0' : 0;
            int bitB = (j >= 0) ? b[j] - '0' : 0;

            int total = bitA + bitB + carry;
            sum = total % 2 + '0';
            carry = total / 2;

            newstr = sum + newstr;

            if (i >= 0) i--;
            if (j >= 0) j--;
        }

        return newstr;
    }
};
