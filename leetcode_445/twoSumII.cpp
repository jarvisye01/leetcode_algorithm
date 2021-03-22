#include <iostream>
#include <stack>

using std::stack;

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
  void toStack(ListNode *list, stack<int>& stk) 
  {
    while (list != NULL)
    {
      stk.push(list->val);
      list = list->next;
    }
  }
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
  {
    stack<int> stk1, stk2, ret;
    toStack(l1, stk1), toStack(l2, stk2);

    int carry = 0, tmp;
    while (stk1.size() > 0 && stk2.size() > 0)
    {
      tmp = stk1.top() + stk2.top() + carry;
      carry = tmp / 10;
      ret.push(tmp % 10);
      stk1.pop(), stk2.pop();
    }

    while (stk1.size() > 0)
    {
      tmp = stk1.top() + carry;
      carry = tmp / 10;
      ret.push(tmp % 10);
      stk1.pop();
    }

    while (stk2.size() > 0)
    {
      tmp = stk2.top() + carry;
      carry = tmp / 10;
      ret.push(tmp % 10);
      stk2.pop();
    }

    if (carry || ret.size() == 0)
      ret.push(carry);

    ListNode vhead(-1), *th = &vhead;
    while (ret.size() > 0)
    {
      auto tmpNode = new ListNode(ret.top());
      th->next = tmpNode;
      th = th->next;
      ret.pop();
    }

    return vhead.next;
  }
};

int main(int argc, char **argv) 
{
  Solution s;
  ListNode l1(7);
  ListNode l2(2);
  ListNode l3(4);
  ListNode l4(3);
  ListNode l5(5);
  ListNode l6(6);
  ListNode l7(4);

  l1.next = &l2, l2.next = &l3, l3.next = &l4;
  l5.next = &l6, l6.next = &l7;

  auto ret = s.addTwoNumbers(&l1, &l5);
  while (ret != nullptr)
  {
    std::cout << ret->val << " ";
    auto tmp = ret;
    ret = ret->next;
    delete tmp;
  }
  std::cout << std::endl;
  return 0;
}