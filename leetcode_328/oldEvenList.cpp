#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode oldHead, evenHead, *toh = &oldHead, *teh = &evenHead;
        int i = 1; 
        while (nullptr != head) {
            ListNode *t = head;
            head = head->next;
            t->next = nullptr;

            if (i++ % 2 == 1) {
                toh->next = t;
                toh = toh->next;
                toh->next = nullptr;
            } else {
                teh->next = t;
                teh = teh->next;
                teh->next = nullptr;
            }
        }

        toh->next = evenHead.next;
        return oldHead.next;
    }
};

int main(int argc, char **argv) {
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

    Solution s;

    ListNode *head = &l1;
    std::cout << "before: ";
    while (nullptr != head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    head = s.oddEvenList(&l1);
    std::cout << "after: ";
    while (nullptr != head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    return 0;
}