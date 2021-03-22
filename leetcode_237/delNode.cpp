#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    bool isTail(ListNode* node) {
        return node != nullptr && node->next == nullptr;
    }
public:
    void deleteNode(ListNode* node) {
        while (nullptr != node) {
            node->val = node->next->val;
            if (isTail(node->next)) {
                node->next = nullptr;
                return;
            }
            node = node->next;
        }
    }
};

void printList(ListNode *head) {
    while (nullptr != head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;

    printList(&l1);
    s.deleteNode(&l3);
    printList(&l1);

    return 0;
}