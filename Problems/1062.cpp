class Solution {
 public:
  int fixedPoint(vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;

    // Since arr[i] is strictly increasing, arr[i] - i will also be increasing.
    // Therefore, binary search `arr` for the first arr[i] - i = 0.
    while (l < r) {
      const int m = (l + r) / 2;
      if (arr[m] - m >= 0)
        r = m;
      else
        l = m + 1;
    }

    return arr[l] == l ? l : -1;
  }
};