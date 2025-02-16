class Solution {
 public:
  int numberOfDays(int year, int month) {
    const vector<int> days = {0,  31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};
    return month == 2 && isLeapYear(year) ? 29 : days[month];
  }

 private:
  bool isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  };
};