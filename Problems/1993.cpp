class Solution {
 public:
  int countQuadruplets(std::vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;

    for (int a = 0; a < n; ++a)
      for (int b = a + 1; b < n; ++b)
        for (int c = b + 1; c < n; ++c)
          for (int d = c + 1; d < n; ++d)
            if (nums[a] + nums[b] + nums[c] == nums[d])
              ++ans;

    return ans;
  }
};