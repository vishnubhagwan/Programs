class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int> > ans;
        for(int i = 0 ; i < n ; i++) {
            if(i > 0 && a[i] == a[i-1])
                continue;
            for(int j = i+1 ; j < n ; j++) {
                    if(j > i+1 && a[j] == a[j-1])
                        continue;
                    int l = j+1, r = n-1;
                    int p = target-a[i]-a[j];
                    while(l < r) {
                        if(a[l] + a[r] < p)
                            l++;
                        else if(a[l] + a[r] > p)
                            r--;
                        else {
                            if((l > j+1 && a[l] == a[l-1]) || (r+1 < n && a[r] == a[r+1])) {
                                if(a[l] == a[l-1] && l > j+1)
                                    l++;
                                if(a[r] == a[r+1] && r+1 < n)
                                    r--;
                            }
                            else
                                ans.push_back({a[i],a[j],a[l++],a[r--]});
                        }
                    }
                }
        }
        return ans;
    }
};
