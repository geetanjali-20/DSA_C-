void solve(int i,vector<int> &nums,vector<int> &ds,int k,int s,vector<vector<int>> &ans){
        if(i == nums.size())
        {
            if(k == s)
                ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        s+=nums[i];
        solve(i+1,nums,ds,k,s,ans);
        ds.pop_back();
        s-=nums[i];
        solve(i+1,nums,ds,k,s,ans);
    }
    
    int numSubseq(vector<int>& nums, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,nums,ds,target,0,ans);
        
        for(auto i: ans)
        {
            for(auto j: i)
                cout<<j<<" ";
            cout<<endl;
        }    
        return ans.size();
    }
};




//2nd method
int count(int i,vector<int> &nums,int k,int s){
        if(i == nums.size())
        {
            if(k == s)
                return 1;
            return 0;
        }
        
        s+=nums[i];
        int l=solve(i+1,nums,k,s);
        
        s-=nums[i];
        int r=solve(i+1,nums,k,s);
        return l+r;
    }


//Input: nums= [3,5,6,7,2,4]  target=9

//Output:
// 3 6 
// 3 2 4 
// 5 4 
// 7 2 

//ans=4
