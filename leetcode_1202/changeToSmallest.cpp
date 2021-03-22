#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::set;
using std::unordered_map;

class UF {
    int N;
    int *arr;
    int *sz;

    int root(int);

public:
    // constructor
    UF(int);
    // copy constructor
    UF(const UF&);
    // operator =
    UF& operator=(const UF&);
    // deconstructor
    ~UF() {
        delete []arr;
        delete []sz;
    }

    class range_err;
    // union two keys
    void unions(int, int);
    // is two keys connected?
    bool connected(int, int);
    // find the component identifier of p
    int find(int);
    // count of components
    int count();
    // get components
    vector<vector<int>> components();
};

int UF::root(int i) {
    while (i != arr[i]) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

UF::UF(int n): N(n) {
    arr = new int[n];
    sz = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        sz[i] = 1;
    }
}

UF::UF(const UF& uf) {
    N = uf.N;
    arr = new int[N];
    sz = new int[N];
    for (int i = 0; i < N; i++) {
        arr[i] = uf.arr[i];
        sz[i] = uf.sz[i];
    }
}

UF& UF::operator=(const UF& uf) {
    N = uf.N;
    for (int i = 0; i < N; i++) {
        arr[i] = uf.arr[i];
        sz[i] = uf.sz[i];
    }
    return *this;
}

class UF::range_err {
    string msg;
public:
    // constructor
    range_err(string s): msg(s) {}
    // copy constructor
    range_err(const range_err& e) {
        msg = e.msg;
    }
    // operator =
    range_err& operator=(const range_err& e) {
        msg = e.msg;
        return *this;
    }
    string get_msg() {
        return msg;
    }
};

void UF::unions(int p, int q) {
    if (p < 0 || p > N - 1 || q < 0 || q > N - 1) {
        throw range_err("out of range!");
    }
    int root_p = root(p);
    int root_q = root(q);
    
    if (connected(p, q)) return;
    
    if (sz[root_p] > sz[root_q]) {
        sz[root_q] += sz[root_p];
        arr[root_p] = arr[root_q];
    } else {
        sz[root_p] += sz[root_q];
        arr[root_q] = arr[root_p];
    }
}

bool UF::connected(int p, int q) {
    if (p < 0 || p > N - 1 || q < 0 || q > N - 1) {
        throw range_err("out of range!");
    }
    return root(p) == root(q);
}

int UF::find(int p) {
    if (p < 0 || p > N - 1) {
        throw range_err("out of range!");
    }
    return root(p);
}

int UF::count() {
    set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(arr[i]);
    }
    return s.size();
}

vector<vector<int>> UF::components() {
    int num = count();
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < N; i++) {
        int component = find(i);
        map[component].push_back(i);
    }
    vector<vector<int>> ret;
    for (auto& pair: map) {
        ret.push_back(pair.second);
    }

    return ret;
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if (s.length() == 0 || pairs.size() == 0) return s;
        
        // build uf
        UF uf(s.length());
        for (vector<int>& vec: pairs) {
            uf.unions(vec[0], vec[1]);
        }

        // get components
        vector<vector<int>> components = uf.components();
        // process each component
        for (vector<int>& cp: components) {
            int sz;
            char chs[(sz = cp.size())];
            // get the sequence represented by the component
            for (int i = 0; i < sz; i++) 
                chs[i] = s[cp[i]];
            
            // sort the chars
            std::sort(chs, chs + sz);

            // sort the component
            std::sort(cp.begin(), cp.end());
            // assign
            for (int i = 0; i < sz; i++) 
                s[cp[i]] = chs[i];
        }

        return s;
    }
};

int main(int agrc, char **argv) {
    Solution s;
    string str = "msuxqdwokclqfjvlwrtixsqrdmlufqysphnyxjpozxqryvjpacrwzxuxtghagvgkptqhubfherxnapoohdpostuoqiemqqumbxtmlevskbfgklkiraigmuxwvlvutqgcugmutzupkixefjpddpsfnajytsikeyffvpxetoqfvnimgepwzswulgfkofktffhrvajmyhjmjtswsmlagylbobuiudtewlvbwaadwoqgoizynhrioidcqxgtmhpurqbcfelijsrobscjwnsgkdunrkogbbjaujxyttsztlnskfeq";
    vector<vector<int>> pairs{{126,282},{131,5},{279,251},{46,156},{36,259},{249,14},{123,84},{90,283},{178,237},{231,290},{295,154},{287,167},{255,142},{95,134},{251,285},{131,173},{147,78},{202,203},{131,229},{199,266},{91,228},{234,79},{198,8},{113,104},{258,96},{134,102},{104,140},{26,146},{245,158},{283,105},{18,109},{262,0},{93,163},{253,294},{151,213},{256,125},{159,153},{189,160},{137,292},{120,272},{194,23},{73,179},{159,111},{214,46},{113,99},{143,208},{233,207},{79,234},{98,169},{208,39},{122,62},{73,76},{3,231},{80,243},{191,176},{298,201},{228,31},{89,258},{238,132},{267,121},{254,159},{120,134},{2,120},{35,57},{2,211},{260,10},{109,140},{135,99},{285,56},{30,94},{16,51},{271,63},{275,85},{284,21},{23,32},{50,227},{165,118},{25,275},{70,108},{69,84},{135,211},{282,63},{221,39},{130,80},{230,167},{85,268},{33,244},{275,48},{139,108},{150,131},{247,162},{212,104},{83,252},{258,16},{168,228},{7,138},{148,138},{30,197},{180,186},{250,151},{40,28},{186,196},{67,118},{50,12},{144,239},{246,262},{175,294},{284,51},{19,107},{111,86},{205,187},{113,124},{131,297},{149,223},{198,249},{71,217},{259,40},{255,230},{206,84},{33,137},{22,175},{57,231},{113,62},{154,10},{212,38},{5,10},{0,272},{236,272},{213,144},{166,84},{7,299},{91,55},{259,232},{50,58},{211,261},{112,250},{30,213},{219,277},{242,216},{167,160},{260,262},{55,138},{268,8},{229,222},{109,215},{185,67},{32,23},{174,49},{120,43},{30,221},{122,242},{172,121},{147,130},{266,297},{31,211},{63,247},{175,152},{114,115},{228,171},{220,161},{250,6},{189,138},{15,161},{53,221},{184,92},{20,22},{292,177},{154,216},{100,149},{27,274},{25,115},{88,82},{192,215},{216,85},{51,101},{270,55},{107,124},{69,129},{61,53},{79,226},{5,79},{268,8},{76,90},{27,21},{163,63},{108,64},{153,170},{253,14},{262,286},{73,110},{166,27},{89,36},{284,67},{271,87},{171,8},{194,240},{180,102},{168,152},{142,39},{239,216},{246,285},{40,157},{132,33},{206,135},{96,83},{49,54},{244,195},{27,274},{36,135},{68,273},{193,128},{50,109},{218,192},{120,280},{45,109},{173,136},{165,231},{143,132},{69,187},{182,145},{224,130},{181,209},{90,170},{163,295},{230,115},{43,187},{234,116},{285,268},{54,279},{291,154},{207,59},{292,83},{206,82},{248,247},{220,182},{158,171},{264,264},{124,102},{242,111},{60,55},{46,133},{43,26},{258,27},{248,174},{266,48},{63,98},{56,158},{40,142},{230,233},{209,159},{69,150},{195,169},{230,0},{62,31},{9,213},{288,98},{156,273},{156,294},{205,120},{80,190},{130,70},{149,201},{141,217},{205,58},{146,2},{216,233},{257,253},{243,184},{203,87},{96,251},{152,52},{72,88},{185,96},{166,219},{159,100},{271,210},{7,168},{196,255},{46,173},{128,51},{271,148},{170,297},{219,108},{202,201},{270,167},{210,33},{191,29},{148,54},{181,214},{117,181},{215,164},{28,45},{151,173},{129,81},{280,67},{237,76},{22,252},{56,125},{209,89},{85,265}};
    
    std::cout << "test uf<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    UF uf(str.length());
    for (vector<int>& vec: pairs) {
        uf.unions(vec[0], vec[1]);
    }

    auto components = uf.components();
    for (vector<int>& vec: components) {
        for (int x: vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "test <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    string ret = s.smallestStringWithSwaps(str, pairs);
    std::cout << ret << std::endl;
    return 0;
}