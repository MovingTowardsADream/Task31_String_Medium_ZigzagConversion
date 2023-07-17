#include <iostream>

class Solution {
public:
    static std::string convert(std::string s, int numRows) {
        if (numRows == 1)
            return s;

        int in_row = (numRows * 2) - 2, n = s.length();
        std::string result;

        int count = 0;
        while (count < n) {
            result.push_back(s[count]);
            count += in_row;
        }

        for (int i = 1;i < numRows - 1;i++) {
            count = i;
            while (count < n) {
                result.push_back(s[count]);
                count += (numRows - i - 1) * 2;
                if (count < n) {
                    result.push_back(s[count]);
                    count += in_row - (numRows - i - 1) * 2;
                }
            }
        }

        count = numRows - 1;
        while (count < n) {
            result.push_back(s[count]);
            count += in_row;
        }

        return result;
    }
};

int main()
{
    std::cout << Solution::convert("PAYPALISHIRING", 3);
}
