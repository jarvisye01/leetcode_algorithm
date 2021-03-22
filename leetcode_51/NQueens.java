package leetcode_51;

import java.util.*;

public class NQueens {
    private int[][] arr;
    private int N;
    List<int[][]> result;
    private static final boolean isDebug = true;
    private static final int[][] test = new int[][]{
            {1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0}
    };

    public NQueens(int n) {
        N = n;
        arr = new int[N][N];
        result = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                arr[i][j] = 0;
            }
        }
        if(isDebug) {
            displayQs();
            if(isLeaf(test, 3, 5)) {
                System.out.println("Leaf!");
            } else {
                System.out.println("NoLeaf!");
            }
            if(isGoodLeaf(test, 5, 5)) {
                System.out.println("Good!");
            } else {
                System.out.println("Bad!");
            }
        }
    }

    private void displayQs() {
        displayArr(arr, N, N);
    }

    private void displayArr(int[][] arr, int m, int n) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == 1) {
                    System.out.print("Q ");
                } else {
                    System.out.print("- ");
                }
            }
            System.out.println("");
        }
    }

//    暂时检查前r行和前r列的合格与否
    private boolean isGoodLeaf(int[][] pos, int r, int c) {
        int count = 0;
        Map<Integer, Integer> r_map = new HashMap<>(r);
        Map<Integer, Integer> c_map = new HashMap<>(c);
        Map<Integer, Integer> f_slash = new HashMap<>(c + r - 1);
        Map<Integer, Integer> b_slash = new HashMap<>(c + r - 1);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if( pos[i][j] == 1) {
                    if(r_map.getOrDefault(i,  0) > 0 || c_map.getOrDefault(j, 0) > 0 || f_slash.getOrDefault(i + j, 0) > 0 || b_slash.getOrDefault(i - j, 0) > 0) {
                        return false;
                    } else {
                        r_map.put(i, 1);
                        c_map.put(j, 1);
                        f_slash.put(i + j, 1);
                        b_slash.put(i - j, 1);
                        count++;
                    }
                }
            }
        }
        return count == r;
    }

    private boolean isLeaf() {
        return isLeaf(arr, N - 1, N);
    }

    private boolean isLeaf(int[][] pos, int r, int n) {
        int l = pos.length;
        return r >= 0 && r < l ? isContainQ(pos[r], n) : false;
    }

    private boolean isContainQ(int[] r, int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(r[i] == 1) {
                count++;
            }
        }
        return count == 1;
    }

    private List<int[][]> getNextP(int[][] cur, int m, int n) {
        List<int[][]> next = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            int[][] temp = new int[m + 1][n];
            for(int k = 0; k < m; k++) {
                temp[k] = Arrays.copyOf(cur[k], n);
            }
            int[] r = getARow(n, i);
            temp[m] = r;
            if(isGoodLeaf(temp, m + 1, n)) {
                next.add(temp);
            }
        }
        return next;
    }

    private int[] getARow(int n, int i) {
        int[] r = new int[n];
        r[i] = 1;
        return r;
    }

    private void solveNQueensByNext(List<int[][]> result, int[][] s, int m, int n) {
        if(m == n && isLeaf(s, m - 1, n)) {
            if(isGoodLeaf(s, m, n)) {
                int[][] t = new int[m][n];
                for(int i = 0; i < m; i++) {
                    t[i] = Arrays.copyOf(s[i], n);
                }
                result.add(t);
            }
        } else {
            List<int[][]> next = getNextP(s, m, n);
            for (int[][] a :
                    next) {
                solveNQueensByNext(result, a, m + 1, n);
            }
        }
    }

    private void solveNQueens(List<int[][]> result, int[][] solution, int m, int n) {
        if(isLeaf()) {
            if(isGoodLeaf(solution, m, n)) {
                int[][] t = new int[m][n];
                for(int i = 0; i < m; i++) {
                    t[i] = Arrays.copyOf(solution[i], n);
                }
                result.add(t);
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(isDebug) {
                    System.out.println(m + "   " + n);
                    displayArr(solution, m, n);
                }
                solution[m][i] = 1;
                if(isGoodLeaf(solution, m + 1, n)) {
                    solveNQueens(result, solution, m + 1, n);
                }
                solution[m][i] = 0;
            }
        }
    }

    private void solveNQueens(List<int[][]> result) {
        solveNQueens(result, arr, 0, N);
    }

    public List<int[][]> getSolutionByNext() {
        List<int[][]> result = new ArrayList<>();
        solveNQueensByNext(result, new int[][]{}, 0, N);
        if(isDebug) {
            result.forEach(item -> {
                displayArr(item, N, N);
                System.out.println("");
            });
            System.out.println(result.size());
        }
        return result;
    }

    public List<int[][]> getSolution() {
        solveNQueens(result);
        if(isDebug) {
            result.forEach(item -> {
                displayArr(item, N, N);
                System.out.println("");
            });
            System.out.println(result.size());
        }
        return result;
    }

    public static void main(String[] args) {
        NQueens queens = new NQueens(8);
        List<int[][]> r = queens.getSolution();
        List<int[][]> tr = queens.getSolutionByNext();
    }

}
