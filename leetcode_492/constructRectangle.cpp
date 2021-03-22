#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

class Solution 
{
public:
    vector<int> constructRectangle(int area) {
        int border = static_cast<int>(sqrt(area));

        for (int i = border; i >= 1; i--)
        {
            if (area % i == 0)
                return vector<int>{area / i, i};
        }

        return vector<int>{0, 0};
    }
};

int main(int argc, char **argv)
{
    return 0;
}