class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    stack<int> stack;  // a decreasing stack
    int ak = INT_MIN;  // We want to find a seq ai < ak < aj.

    for (int i = nums.size() - 1; i >= 0; --i) {
      // If ai < ak, we're done because ai must < aj.
      if (nums[i] < ak)
        return true;
      while (!stack.empty() && stack.top() < nums[i])
        ak = stack.top(), stack.pop();
      stack.push(nums[i]);  // `nums[i]` is a candidate of aj.
    }

    return false;
  }
};