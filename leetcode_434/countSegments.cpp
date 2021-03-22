#include <iostream>
#include <string>

using std::string;

class Solution 
{
public:
    int countSegments(string s) 
    {
        int count = 0, j = 0, len = s.length();

        while (j < len) {
            while (j < len && s[j] == ' ')
                j++;
            if (j >= len)
                break;
            
            while (j < len && s[j] != ' ')
                j++;

            count++;
            j++;
        }

        return count;
    }
};

int main(int argc, char **argv) 
{
    Solution s;
    string str = "   hello, wordl!  jarvisye  ";
    auto ret = s.countSegments(str);
    std::cout << ret << std::endl;
    return 0;
}