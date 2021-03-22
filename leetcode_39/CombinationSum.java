package leetcode_39;

import java.util.*;

public class CombinationSum {

    private Node root;
    private List<Integer> combines = new LinkedList<>();
    private List<List<Integer>> result = new ArrayList<>();

    private class Node {
        int total = 0;
        Node[] children;
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        root = getCombine(root, candidates, target, 0, 0);
        getResult(root, candidates, target);
        return result;
    }

    public Node getCombine(Node x, int[] candidates, int target, int curt, int start) {
        int N = candidates.length;
        x = new Node();
        x.total = curt;
        x.children = new Node[N];
        for(int i = start; i < N; i++) {
            if(curt + candidates[i] <= target) {
                x.children[i] = getCombine(x.children[i], candidates, target, curt + candidates[i], i);
            } else {
                break;
            }
        }
        return x;
    }

    public void getResult(Node x, int[] candidates, int target) {
        if(x == null) {
            return;
        }
        if(isGood(x, target)) {
            result.add(List.copyOf(combines));
            for(Integer t: combines) {
                System.out.print(t + " ");
            }
            System.out.println();
        }
        for(int i = 0; x.children != null && i < x.children.length; i++) {
            combines.add(candidates[i]);
            getResult(x.children[i], candidates, target);
            combines.remove(combines.size() - 1);
        }
    }

    private boolean isGood(Node x, int target) {
        return x.total == target;
    }

    public static void main(String[] args) {
        int[] test = new int[]{10, 1, 2, 7, 6, 1, 5};
        CombinationSum com = new CombinationSum();
        com.combinationSum(test, 8);
    }
}
