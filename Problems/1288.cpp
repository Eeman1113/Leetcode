class Solution {
 public:
  int getDecimalValue(ListNode* head) {
    int ans = 0;

    for (; head; head = head->next)
      ans = ans * 2 + head->val;

    return ans;
  }
};