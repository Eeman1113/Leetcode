/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *  public:
 *   // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *   // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *   // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *   // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *   int compareSub(int l, int r, int x, int y);
 *
 *   // Returns the length of the array
 *   int length();
 * };
 */

class Solution {
 public:
  int getIndex(ArrayReader& reader) {
    int l = 0;
    int r = reader.length() - 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if ((r - l) % 2 == 0) {
        const int res = reader.compareSub(l, m - 1, m + 1, r);
        if (res == 0)
          return m;
        if (res == 1) {
          r = m - 1;
        } else {  // res == -1
          l = m + 1;
        }
      } else {
        const int res = reader.compareSub(l, m, m + 1, r);
        // res is either 1 or -1.
        if (res == 1) {
          r = m;
        } else {  // res == -1
          l = m + 1;
        }
      }
    }

    return l;
  }
};