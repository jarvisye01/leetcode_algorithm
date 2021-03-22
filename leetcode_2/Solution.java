package leetcode_2;

public class Solution {
//    数字过大，不能直接组成数字，否则空间不够用
//    利用线性表的遍历完成
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null;
        ListNode head_t = null;
        boolean flag = true;
        int add_count = 0;
        while(l1 != null && l2 != null) {
            ListNode temp_node = new ListNode((l1.val + l2.val + add_count) % 10);
            add_count = (l1.val + l2.val + add_count) / 10;
            if(flag) {
                head_t = temp_node;
                head = head_t;
                flag = false;
            }
            else {
                head_t.next = temp_node;
                head_t = head_t.next;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1 != null) {
            ListNode temp_node = new ListNode((l1.val + add_count) % 10);
            add_count = (l1.val + add_count) / 10;
            head_t.next = temp_node;
            head_t = head_t.next;
            l1 = l1.next;
        }
        while(l2 != null) {
            ListNode temp_node = new ListNode((l2.val + add_count) % 10);
            add_count = (l2.val + add_count) / 10;
            head_t.next = temp_node;
            head_t = head_t.next;
            l2 = l2.next;
        }
        if(add_count != 0) {
            ListNode temp_node = new ListNode(add_count % 10);
            temp_node.next = null;
            head_t.next = temp_node;
            head_t = head_t.next;
        }
        return head;
    }

    public static void main(String [] args) {

    }
}
