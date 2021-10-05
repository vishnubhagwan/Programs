int minDeletions(vector<int> a) {
    int n = a.size(), ans = 0;
    vector<int> T, R(n,-1);
    for(int i = 0 ; i < n ; i++) {
        int l = 0, r = T.size();
        while(l < r) {
            int m = (l+r)>>1;
            if(a[T[m]] <= a[i])
                l = m+1;
            else r = m;
        }
        ans = max(ans, l + 1);
        if(l < T.size())
            T[l] = i;
        else T.push_back(i);
        R[i] = l > 0 ? T[l-1] : -1;
    }
    return ans == n ? 0 : n - ans - 1;
}


