#include <iostream>
#include <string>

using std::string;

class Solution 
{
public:
    string originalDigits(string s) 
    {
        int arr[10], len = s.length();
        for (int& x: arr)
            x = 0;
        
        int numR = 0, numV = 0, numO = 0, numF = 0, numI = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'z')
                arr[0]++;
            if (s[i] == 'w')
                arr[2]++;
            if (s[i] == 'u')
                arr[4]++;
            if (s[i] == 'x')
                arr[6]++;
            if (s[i] == 'g')
                arr[8]++;
            if (s[i] == 'r')
                numR++;
            if (s[i] == 'v')
                numV++;
            if (s[i] == 'o')
                numO++;
            if (s[i] == 'f')
                numF++;
            if (s[i] == 'i')
                numI++;
        }

        arr[3] = numR - arr[4] - arr[0];
        arr[1] = numO - arr[0] - arr[2] - arr[4];
        arr[5] = numF - arr[4];
        arr[7] = numV - arr[5];
        arr[9] = numI - arr[5] - arr[6] - arr[8];

        int sum = 0;
        for (int x: arr)
            sum += x;
        
        string ret(sum, 0);
        int idx = 0;
        char ch = '0';
        for (int x: arr)
        {
            for (int i = 0; i < x; i++)
                ret[idx++] = ch;
            ch++;
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string str = "owoztneoer";
    auto ret = s.originalDigits(str);
    std::cout << ret << std::endl;
    return 0;
}