class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int currentPassengers = 0;
    map<int, int> line;

    for (const vector<int>& trip : trips) {
      const int nPassengers = trip[0];
      const int start = trip[1];
      const int end = trip[2];
      line[start] += nPassengers;
      line[end] -= nPassengers;
    }

    for (const auto [_, passengerChange] : line) {
      currentPassengers += passengerChange;
      if (currentPassengers > capacity)
        return false;
    }

    return true;
  }
};