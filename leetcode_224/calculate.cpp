#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <deque>
#include <vector>

using std::string;
using std::unordered_set;
using std::deque;
using std::stack;
using std::vector;

const unordered_set<char> symbols = {'+', '-', '*', '/', '(', ')'};
const unordered_set<string> symbolsStr = {"+", "-", "*", "/", "(", ")"};

class Parser {
    int idx, sz, last;
    string str;
public:
    Parser(const string s = ""): str(s), idx(0), sz(s.length()), last(0) {}
    
    bool hasNext() {
        while (idx < sz && str[idx] == ' ') 
            idx++;
        return idx < sz;
    }

    string next() {
        if (!hasNext()) return "";
        int i = idx, j = idx;
        last = idx;

        // find next symbols
        while (j < sz && symbols.find(str[j]) == symbols.end() && str[j] != ' ') 
            j++;
        
        // str[j] is a symbol
        if (j == i) j++;

        idx = j;
        return str.substr(i, j - i);
    }

    void reset() {
        idx = last;
    }
};

class Solution {
    // 1 * (2 + 3)
    vector<string> toRPN(Parser& parser) {
        stack<string> s1;
        deque<string> s2;
        string lastToken = "";
        while (parser.hasNext()) {
            string token = parser.next();

            if ((token == "+" || token == "-") && (lastToken == "" || lastToken == "(")) {
                lastToken = "0";
                s2.push_back("0");
                parser.reset();
                continue;
            }

            lastToken = token;

            // number 
            if (symbolsStr.find(token) == symbolsStr.end()) {
                s2.push_back(token);
                continue;
            }

            if (token == "(" || s1.size() == 0) 
                s1.push(token);
            else if (token == "+" || token == "-") {
                while (s1.size() > 0 && s1.top() != "(") {
                    string tmp = s1.top();
                    s1.pop();
                    s2.push_back(tmp);
                }
                s1.push(token);
            } else if (token == "*" || token == "/") {
                while (s1.size() > 0 && (s1.top() == "*" || s1.top() == "/")) {
                    string tmp = s1.top();
                    s1.pop();
                    s2.push_back(tmp);
                }
                s1.push(token);
            } else {
                // ")"
                while (s1.top() != "(") {
                    string tmp = s1.top();
                    s1.pop();
                    s2.push_back(tmp);
                }
                s1.pop();
            }
        }

        while (s1.size() > 0) {
            s2.push_back(s1.top());
            s1.pop();
        }

        vector<string> ret;
        for (string s: s2) {
            std::cout << s << "";
            ret.push_back(s);
        }
        std::cout << std::endl;
        
        return ret;
    }

    int calculateRPN(const vector<string>& exp) {
        int sz;
        if ((sz = exp.size()) == 0) return 0;
        stack<string> s;
        for (int i = 0; i < sz; i++) {
            // number
            if (symbolsStr.find(exp[i]) == symbolsStr.end()) 
                s.push(exp[i]);
            else {
                string op2 = s.top();
                s.pop();
                string op1 = s.top();
                s.pop();
                s.push(calculateAux(op1, op2, exp[i]));
            }
        }

        if (s.size() == 1) 
            return std::stoi(s.top());

        return 0;
    }

    string calculateAux(string op1, string op2, string op) {
        int ret = 0;
        switch (op.c_str()[0]) {
        case '+':
            ret = std::stoi(op1) + std::stoi(op2);
            break;
        case '-':
            ret = std::stoi(op1) - std::stoi(op2);
            break;
        case '*':
            ret = std::stoi(op1) * std::stoi(op2);
            break;
        case '/':
            ret = std::stoi(op1) / std::stoi(op2);
            break;
        default:
            break;
        }
        return std::to_string(ret);
    }
public:
    int calculate(string s) {
        if (s.length() == 0) return 0;
        Parser parser(s);
        vector<string> retRPN = toRPN(parser);
        return calculateRPN(retRPN);
    }
};

int main(int argc, char **argv) {
    string str = "(-2 +1)";
    Parser parser(str);
    Solution s;
    int ret = s.calculate(str);
    std::cout << ret << std::endl;
    return 0;
}