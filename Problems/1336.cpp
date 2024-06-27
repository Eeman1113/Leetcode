class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    const int n = arr.size();
    int sum = 0;
    unordered_map<int, int> map;
    vector<pair<int, int>> count;

    for (const int a : arr)
      ++map[a];

    for (const auto& [a, freq] : map)
      count.push_back(make_pair(a, freq));

    ranges::sort(count, [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.second > b.second;
    });

    for (int i = 0; i < count.size(); ++i) {
      sum += count[i].second;
      if (sum >= n / 2)
        return i + 1;
    }

    throw;
  }
};