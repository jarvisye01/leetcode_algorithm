package leetcode_44;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class IsMatch {
//    private static class Status {
//        int start;
//        Map<String, Integer> to;
//        public Status(int start) {
//            this.start = start;
//            to = new HashMap<>();
//        }
//        public void toNext(String path, int next) {
//            to.put(path, next);
//        }
//    }
    public static boolean isMatch(String s, String p) {
//        Status status = new Status(0);
        Map<Integer, Map<String, Integer>> status = new HashMap<>();
        int curS = 0;
        for(int i = 0; i < p.length(); i++) {
            if(!status.containsKey(curS)) {
                status.put(curS, new HashMap<>());
            }
            if(!"*".equals(p.substring(i, i + 1))) {
                status.get(curS).put(p.substring(i, i + 1), curS + 1);
                curS++;
            } else {
                status.get(curS).put("*", curS);
            }
        }
//        这是为状态
        int tailS = curS;
        curS = 0;
        Set<Integer> canReach = new HashSet<>();
        canReach.add(curS);
        for(int i = 0; i < s.length(); i++) {
            Set<Integer> newReach = new HashSet<>();
            for(Integer to: canReach) {
                boolean flag = false;
                Map<String, Integer> toNext = status.get(to);
//                null说明是最后一个状态
                if(toNext == null) {
                    continue;
                }
//                canReach.remove(to);
//                不能一边迭代一边修改
                for(String path: toNext.keySet()) {
                    String subS = s.substring(i, i + 1);
                    if(path.equals(subS) || path.equals("?") || path.equals("*")) {
                        newReach.add(status.get(to).get(path));
                    }
                }
            }
            canReach = newReach;
        }
        if(canReach.contains(tailS)) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(isMatch("aa", "a"));
    }
}
