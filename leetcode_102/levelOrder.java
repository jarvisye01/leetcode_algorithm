package leetcode_102;

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {
        val = x;
    }
}

public class levelOrder {
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>(100);
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
//            栈中的初始元素一般都是同一层的元素
            int levelSize = q.size();
            List<Integer> currentLevel = new ArrayList<>();

            for(int i = 0; i < levelSize; i++) {
                TreeNode t = q.poll();
                currentLevel.add(t.val);
                if(null != t.left) {
                    q.add(t.left);
                }
                if(null != t.right) {
                    q.add(t.right);
                }
            }
            res.add(currentLevel);
        }
//        Queue<Integer> l = new LinkedList<>();
//        int level = 1;
//
//        q.add(root);
//        l.add(level);
//        List<Integer> eLevel = new ArrayList<>();
//
//        while(q.size() > 0) {
//            TreeNode t = q.remove();
//            if(t == null) {
//                continue;
//            }
//            int tl = l.remove();
//            if(tl != level) {
//                level = tl;
//                res.add(eLevel);
//                eLevel= new ArrayList<>();
//            }
//            eLevel.add(t.val);
//            if(t.left != null) {
//                q.add(t.left);
//                l.add(tl + 1);
//            }
//            if(t.right != null) {
//                q.add(t.right);
//                l.add(tl + 1);
//            }
//        }
//        if(eLevel.size() > 0) {
//            res.add(eLevel);
//        }
        return res;
    }


    public static void dfs(TreeNode r, int level, SortedMap<Integer, List<Integer>> info) {
        if(r == null) {
            return;
        }
        List<Integer> t = info.getOrDefault(level
                , new ArrayList<>());
        t.add(r.val);
        info.put(level, t);
        dfs(r.left, level + 1, info);
        dfs(r.right, level + 1, info);
    }

    public static List<List<Integer>> levelOrderDFS(TreeNode root) {
        SortedMap<Integer, List<Integer>> t = new TreeMap<>();
        dfs(root, 1, t);
        List<List<Integer>> res = new ArrayList<>();
        for(Integer k: t.keySet()) {
            res.add(t.get(k));
        }
        return res;
    }

    public static void main(String[] args) {
        TreeNode t1 = new TreeNode(3);
        TreeNode t2 = new TreeNode(9);
        TreeNode t3 = new TreeNode(20);
        TreeNode t4 = new TreeNode(15);
        TreeNode t5 = new TreeNode(7);
        t1.left = t2;
        t1.right = t3;
        t3.left = t4;
        t3.right = t5;

        levelOrder(null);
    }
}
