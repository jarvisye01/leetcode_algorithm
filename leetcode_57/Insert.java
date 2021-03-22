package leetcode_57;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Insert {
    private static class Interval implements Comparable<Interval> {
        int left;
        int right;
        public Interval(int[] t) {
            left = t[0];
            right = t[1];
        }
        public int[] toArray() {
            return new int[]{left, right};
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
    public static int[][] Insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>(10);
        Queue<Interval> q = new PriorityQueue<>();
        int N = intervals.length;
        q.add(new Interval(newInterval));
        for(int[] item: intervals) {
            q.add(new Interval(item));
        }
        Interval inter1 = q.remove();
        while(!q.isEmpty()) {
            Interval inter2 = q.remove();
            if(inter1.right >= inter2.left) {
                q.add(new Interval(new int[]{inter1.left, Math.max(inter1.right, inter2.right)}));
            } else {
                res.add(inter1.toArray());
                q.add(inter2);
            }
            inter1 = q.remove();
        }
        res.add(inter1.toArray());
        int[][] resarray = new int[res.size()][2];
        int i = 0;
        for(int[] item: res) {
            resarray[i++] = item;
        }
        return resarray;
    }

    public static void main(String[] args) {
        int[][] test = new int[0][0];
        Insert(test, new int[]{3, 7});
    }

}
