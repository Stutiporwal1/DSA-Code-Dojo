bool Possible(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < stalls.size(); i++) {       // start from 1
        if(stalls[i] - lastPos >= mid) {           // fixed bug
            cowCount++;
            if(cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
    
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    
    int s = 1;                    // min distance
    int e = stalls.back();        // max possible distance
    int ans = -1;

    while(s <= e) {
        int mid = s + (e - s) / 2;

        if (Possible(stalls, k, mid)) {
            ans = mid;            // try for bigger distance
            s = mid + 1;
        } 
        else {
            e = mid - 1;          // try for smaller distance
        }
    }
    return ans;
}
