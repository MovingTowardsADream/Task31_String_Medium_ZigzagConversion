#include <iostream>
#include <vector>

// It's second solution

class Solution {
public:
    static std::string convert(std::string s, int numRows) {
        if (numRows == 1)
            return s;
        std::vector<std::string> result(numRows);
        int n = s.length(), count = 0, tmp = 0, direction = 1;
        std::string res;
        while (count < n) {
            result[tmp].push_back(s[count]);
            if (tmp >= numRows - 1) {
                direction = -1;
            }
            if (tmp <= 0) {
                direction = 1;
            }
            tmp += direction;
            count++;
        }
        for (auto i : result) {
            res.append(i);
        }
        return res;
    }
};

// It's fast solution

//class Solution {
//public:
//    static std::string convert(std::string s, int numRows) {
//        if (numRows == 1)
//            return s;
//
//        int in_row = (numRows * 2) - 2, n = s.length();
//        std::string result;
//
//        int count = 0;
//        while (count < n) {
//            result.push_back(s[count]);
//            count += in_row;
//        }
//
//        for (int i = 1;i < numRows - 1;i++) {
//            count = i;
//            while (count < n) {
//                result.push_back(s[count]);
//                count += (numRows - i - 1) * 2;
//                if (count < n) {
//                    result.push_back(s[count]);
//                    count += in_row - (numRows - i - 1) * 2;
//                }
//            }
//        }
// 
//        count = numRows - 1;
//        while (count < n) {
//            result.push_back(s[count]);
//            count += in_row;
//        }
// 
//        return result;
//    }
//};

int main()
{
    std::cout << Solution::convert("PAYPALISHIRING", 3);
}
