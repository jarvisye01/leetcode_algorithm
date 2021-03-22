#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverse(ListNode *head) {
        if (nullptr == head || nullptr == head->next) return head;
        ListNode *th = nullptr;
        while (nullptr != head) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = th;
            th = tmp;
        }
        return th;
    }

    bool isPalindrome(ListNode* head) {
        if (nullptr == head || nullptr == head->next) return true;
        int n = 0;
        ListNode *slow, *fast;
        slow = fast = head;
        while (nullptr != fast && nullptr != fast->next) {
            n++;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (nullptr == fast) n--;

        ListNode *head_last = reverse(slow);

        while (n-- >= 0) {
            if (head->val != head_last->val) return false;
            head = head->next;
            head_last = head_last->next;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ListNode *head = s.reverse(&l1);
    while (nullptr != head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    return 0;
}