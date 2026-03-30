class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int n = points.size();
      if(n <= 2) return n;

      int ans = 0;

      for(int i = 0; i < n; i++) {
          unordered_map<long long, int> mp;
          int duplicate = 1;
          int maxi = 0;

          for(int j = i + 1; j < n; j++) {
              int dx = points[j][0] - points[i][0];
              int dy = points[j][1] - points[i][1];

              if(dx == 0 && dy == 0) {
                  duplicate++;
                  continue;
              }

              int g = __gcd(dx, dy);
              dx /= g;
              dy /= g;

              if(dy < 0) {
                  dx = -dx;
                  dy = -dy;
              } else if(dy == 0) {
                  dx = 1;
              }
              if(dx == 0) {
                  dy = 1;
              }

              long long key = ((long long)dx << 32) | dy;

              mp[key]++;
              maxi = max(maxi, mp[key]);
          }

          ans = max(ans, maxi + duplicate);
      }

      return ans;
  }
};