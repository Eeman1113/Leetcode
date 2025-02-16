class Solution {
 public:
  string lastSubstring(string s) {
    int i = 0;
    int j = 1;
    int k = 0;  // the number of the same letters of s[i..n) and s[j..n)

    while (j + k < s.length()) {
      if (s[i + k] == s[j + k]) {
        ++k;
      } else if (s[i + k] > s[j + k]) {
        // s[i..i + k] == s[j..j + k] and s[i + k] > s[j + k] means that we
        // should start from s[j + k] to find a possible larger substring.
        j += k + 1;
        k = 0;
      } else {
        // s[i..i + k] == s[j..j + k] and s[i + k] < s[j + k] means that either
        // starting from s[i + k + 1] or s[j] has a larger substring.
        i = max(i + k + 1, j);
        j = i + 1;
        k = 0;
      }
    }

    return s.substr(i);
  }
};