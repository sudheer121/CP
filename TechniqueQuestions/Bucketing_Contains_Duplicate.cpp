// Bucketing, is it common ? 
// https://leetcode.com/problems/contains-duplicate-iii/submissions/


#define ll long long 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      
        vector<ll> v; 
        map<ll,ll> mp; 
        int mn = 0;
        int n = nums.size();
         if(t<0 || n<2 || k<1) return 0; 
        for(int x:nums) {
            v.push_back(x); 
            mn = min(mn,x);
        }
        int i,j; 
        for(i=0;i<n;i++) { v[i]+=abs(mn); }
        
        for(i=0;i<n;i++) {
            
            ll b = v[i]/((ll)t+1);    
            if(mp.find(b)!=mp.end()) { return 1; }
            mp[b] = v[i]; 
            if(mp.find(b-1)!=mp.end() && abs(mp[b-1]-v[i])<=t){ return 1;}
            if(mp.find(b+1)!=mp.end() && abs(mp[b+1]-v[i])<=t){ return 1;}
            if(i>=k){
                ll rem = v[i-k]/((ll)(t)+1);
                mp.erase(rem); 
            }
        }
        return 0; 
    }
};
