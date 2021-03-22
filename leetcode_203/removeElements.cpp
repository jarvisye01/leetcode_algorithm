#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *vnode = new ListNode(-1);
        if (head == nullptr) return nullptr;
        vnode->next = head;

        ListNode *last = vnode, *th = head;
        while (th != nullptr) {
            if (th->val == val) {
                last->next = th->next;
                th->next = nullptr;
            } else {
                last = last->next;
            }
            th = last->next;
        }
        return vnode->next;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return 0;
}