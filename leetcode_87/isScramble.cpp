#include <iostream>
#include <vector>
#include <unordered_map>

using std::string;
using std::unordered_map;

struct Interval{
    int a, b, c, d;
    Interval(int aa, int bb, int cc, int dd): a(aa), b(bb), c(cc), d(dd) {}
    bool operator== (const Interval& other) const {
        return a == other.a && b == other.b && c == other.c && d == other.d;
    }
};

struct Hash {
    size_t operator() (const Interval& v) const {
        return v.a * v.b * v.c * v.d + (v.a ^ v.b ^ v.c ^ v.d);
    }
};

class Solution {
    unordered_map<Interval, bool, Hash> info;
    // s1[a, b]
    // s2[c, d]
    bool isScrambleAux(
        const string& s1, const string& s2, 
        int a, int b, int c, int d
    ) {
        if (info.find(Interval(a, b, c, d)) != info.end()) return (*info.find(Interval(a, b, c, d))).second;
        if (a == b) return s1[a] == s2[c];

        int len = b - a + 1;

        for (int i = 0; i < len - 1; i++) {
            // s1[a, a + i], s2[c, c + i]
            // s1[a + i + 1, b], s2[c + i + 1, d]
            if (isScrambleAux(s1, s2, a, a + i, c, c + i) && isScrambleAux(s1, s2, a + i + 1, b, c + i + 1, d)) {
                info.insert(std::pair<Interval, bool>(Interval(a, a + i, c, c + i), true));
                info.insert(std::pair<Interval, bool>(Interval(a + i + 1, b, c + i + 1, d), true));
                return true;  
            }

            // s1[a, a + i], s2[d - i, d]
            // s1[a + i + 1, b], s2[c, d - i - 1]
            if (isScrambleAux(s1, s2, a, a + i, d - i, d) && isScrambleAux(s1, s2, a + i + 1, b, c, d - i - 1)) {
                info.insert(std::pair<Interval, bool>(Interval(a, a + i, d - i, d), true));
                info.insert(std::pair<Interval, bool>(Interval(a + i + 1, b, c, d - i - 1), true));
                return true;
            }
        } 

        info.insert(std::pair<Interval, bool>(Interval(a, b, c, d), false));
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        int len;
        if ((len = s1.length()) == 0 && s2.length() == 0) return true;
        if (s1.length() != s2.length()) return false;

        return isScrambleAux(s1, s2, 0, len - 1, 0, len - 1);
    }
};

int main(int aegc, char **argv) {
    Solution s;
    string s1 = "abcdbdac";
    string s2 = "bdacabcd";
    // string s1 = "great";
    // string s2 = "tager";
    bool ret = s.isScramble(s1, s2);
    std::cout << (ret ? "true" : "false") << std::endl;
    return 0;
}