#include <iostream>
#include <string>
#include <deque>

using std::string;
using std::deque;

class Solution {
public:
    int calculate(string s) {
        int i = 0, sz;
        if ((sz = s.length()) == 0) return 0;

        deque<int> nums;
        deque<char> ops;

        while (i < sz) {
            while (i < sz && s[i] == ' ') 
                i++;

            if (i >= sz) break;
            
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                // symbols
                ops.push_back(s[i++]);
            } else {
                // number
                int num = 0;
                while (i < sz && s[i] >= '0' && s[i] <= '9') 
                    num = num * 10 + static_cast<int>(s[i++] - '0');
                
                // 优先计算乘除法
                if (ops.size() > 0 && (ops.back() == '*' || ops.back() == '/')) {
                    char op = ops.back();
                    int tnum = ops.back() == '*' ? nums.back() * num : nums.back() / num;
                    nums.pop_back();
                    ops.pop_back();
                    nums.push_back(tnum); 
                } else 
                    nums.push_back(num);
            }
        }

        if (nums.size() != ops.size() + 1) return 0;
        while (ops.size() > 0) {
            int op1, op2;
            op1 = nums.front();
            nums.pop_front();
            op2 = nums.front();
            nums.pop_front();

            nums.push_front((ops.front() == '+' ? op1 + op2 : op1 - op2));
            ops.pop_front();
        }
        if (nums.size() == 1) return nums.back();
        return 0;
    }
};

int main(int argc, char **argv) {
    // string str = "  1  + 2   *   3  / 20  ";
    string str = "1 - 1 + 1";
    Solution s;
    int ret = s.calculate(str);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}