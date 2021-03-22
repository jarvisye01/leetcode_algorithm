package leetcode_56;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Merge {
    private static class Interval implements Comparable<Interval> {
        int left;
        int right;
        public Interval(int l, int r) {
            left = l;
            right = r;
        }

        @Override
        public int compareTo(Interval o) {
            if(left == o.left) {
                return 0;
            } else if(left < o.left) {
                return -1;
            } else {
                return 1;
            }
        }
    }
    public static int[][] merge(int[][] intervals) {
        if(intervals.length == 0) {
            return new int[][]{};
        }
        List<int[]> res = new ArrayList<>(10);
        Queue<Interval> q = new PriorityQueue<>();
        int N = intervals.length;
        for(int i = 0; i < N; i++) {
            q.add(new Interval(intervals[i][0], intervals[i][1]));
        }
        Interval inter1 = q.remove();
        while(!q.isEmpty()) {
            Interval inter2 = q.remove();
            if(inter1.right >= inter2.left) {
                q.add(new Interval(inter1.left, Math.max(inter1.right, inter2.right)));
            } else {
                res.add(new int[]{inter1.left, inter1.right});
                q.add(inter2);
            }
            inter1 = q.remove();
        }
        res.add(new int[]{inter1.left, inter1.right});
        int[][] resarray = new int[res.size()][2];
        int i = 0;
        for(int[] item: res) {
            resarray[i++] = item;
        }
        return resarray;
    }

    public static void main(String[] args) {
        int[][] test = new int[4][2];
        test[0] = new int[]{1, 3};
        test[1] = new int[]{2, 6};
        test[2] = new int[]{8, 10};
        test[3] = new int[]{15, 18};
        merge(test);
    }
}
