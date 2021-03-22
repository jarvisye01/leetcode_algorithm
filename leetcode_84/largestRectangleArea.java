package leetcode_84;

import java.util.Stack;

public class largestRectangleArea {
    public static int monotonicStack(int[] h) {
        int maxA = 0;
        int N = h.length;
        Stack<Integer> s = new Stack<>();
        s.push(-1);
        for(int i = 0; i < N; i++) {
            int t = s.peek();
            while(s.peek() != -1 && h[i] < h[s.peek()]) {
                maxA = Math.max(h[s.pop()] * (i - s.peek() - 1), maxA);
            }
            s.push(i);
        }
        while(s.peek() != -1) {
            int tH = h[s.pop()];
            int tW = N - s.peek() -1;
            maxA = Math.max(tH * tW, maxA);
        }
        return maxA;
    }

    public static int divideConquer(int[] h, int i, int j) {
        if(i > j) {
            return 0;
        }
        if(i == j) {
            return h[i];
        }

        int m = i;
        for(int k = i; k <= j; k++) {
            if(h[k] < h[m]) {
                m = k;
            }
        }
        int maxArea_1 = h[m] * (j - i + 1);
        int maxArea_2 = Math.max(divideConquer(h, i, m - 1), divideConquer(h, m + 1, j));
        return Math.max(maxArea_1, maxArea_2);
    }

    public static int largestRectangleArea(int[] heights) {
        return monotonicStack(heights);
    }
    public static void main(String[] args) {
        int[] test = new int[]{2, 1, 5, 6, 2, 3};
        System.out.println(largestRectangleArea(test));
        System.out.println(divideConquer(test, 0, test.length - 1));
    }
}
