#include <iostream>

class Solution {
    bool isPointInRec(int x, int y, int A, int B, int C, int D) {
        if ((x >= A && x <= C) && (y >= B && y <= D)) return true;
        return false;
    }

    int computeArea(int A, int B, int C, int D) {
        return std::abs(C - A) * std::abs(D - B);
    }

    // (A, B) (A, D) (C, D) (C, B)
    // (E, F) (E, H) (G, H) (G, F)
    int computeOverlap(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (B >= H || D <= F || A >= G || C <= E) return 0;
        int l1 = C - A, w1 = D - B, l2 = G - E, w2 = H - F;
        int a1 = isPointInRec(A, B, E, F, G, H);
        int a2 = isPointInRec(A, D, E, F, G, H);
        int a3 = isPointInRec(C, D, E, F, G, H);
        int a4 = isPointInRec(C, B, E, F, G, H);

        int b1 = isPointInRec(E, F, A, B, C, D);
        int b2 = isPointInRec(E, H, A, B, C, D);
        int b3 = isPointInRec(G, H, A, B, C, D);
        int b4 = isPointInRec(G, F, A, B, C, D);

        // case 1
        if (a4 && b2) return computeArea(C, B, E, H);
        if (a1 && b3) return computeArea(A, B, G, H);
        if (a3 && b1) return computeArea(C, D, E, F);
        if (a2 && b4) return computeArea(A, D, G, F);

        // case 2
        if (a1 && a4) {
            if (a3) { return computeArea(A, B, C, D); }
            return computeArea(A, B, C, H);
        }
        if (a2 && a3) {
            if (a1) { return computeArea(A, B, C, D); } 
            return computeArea(A, F, C, D);
        }
        if (a1 && a2) {
            if (a3) { return computeArea(A, B, C, D); } 
            return computeArea(A, B, G, D);
        }
        if (a4 && a3) {
            if (a1) { return computeArea(A, B, C, D); } 
            return computeArea(E, B, C, D);
        }

        // case 3
        if (b1 && b2) {
            if (b3) { return computeArea(E, F, G, H); } 
            return computeArea(E, F, C, H);
        }
        if (b3 && b4) {
            if (b1) { return computeArea(E, F, G, H); } 
            return computeArea(A, F, G, H);
        }
        if (b1 && b4) {
            if (b3) { return computeArea(E, F, G, H); }
            return computeArea(E, F, G, D);
        }
        if (b2 && b3) {
            if (b1) { return computeArea(E, F, G, H); }
            return computeArea(G, H, E, B);
        }

        return std::min(l1, l2) * std::min(w1, w2);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        uint64_t s = 0;
        s += computeArea(A, B, C, D);
        s += computeArea(E, F, G, H);
        int delta = computeOverlap(A, B, C, D, E, F, G, H);
        return s - delta;
    }
};

int main(int argc, char **argv) {
    Solution s;
    int ret = s.computeArea(-5, -2, 5, 1, -3, -3, 3, 3);
    std::cout << ret << std::endl;
    return 0;
}