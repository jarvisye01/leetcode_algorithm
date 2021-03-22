package leetcode_206;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {

    public static ListNode recursion(ListNode l) {
//        在l.next为null时也要处理，否则会出现单个节点处理错误的情况
        if (null == l || l.next == null) {
            return l;
        }
        ListNode tail = l.next;
        ListNode th = recursion(l.next);
        if (null != tail) {
            tail.next = l;
        }
        l.next = null;
        return th;
    }

    public static ListNode iterate(ListNode h) {
        ListNode th = new ListNode(-1);
        ListNode t = null;
        while (h != null) {
            t = h;
            h = h.next;
            t.next = th.next;
            th.next = t;
        }
        return th.next;
    }

    public static ListNode reverseList(ListNode head) {
        return recursion(head);
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        ListNode l2 = new ListNode(2);
        ListNode l3 = new ListNode(3);
        ListNode l4 = new ListNode(4);
        ListNode l5 = new ListNode(5);
        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;

        ListNode t = reverseList(l1);
    }
}
