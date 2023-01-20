class Solution {
public:
    bool checknondecre(vector<int> &inn){
        for(int i=0;i<inn.size()-1;i++){
            if(i+1<inn.size() and inn[i]>inn[i+1])
            return false;
        }
        return true;
    }
    void solve(vector<int>&nums,int i,set<vector<int>> &an,vector<int>&inner){
        if(i>=nums.size()){
            if(inner.size()>=2){
                // if(checknondecre(inner) and find(an.begin(),an.end(),inner)==an.end()){ //for when an is vector <vector<int>>
                if(checknondecre(inner)) { //working with set also to reduce the TC for find function but still not working
                    // an.push_back(inner);// when vector used
                    an.insert(inner); //for set
                    // return;
                }
            }
            return;
        }
        //if condition fulfills thenn only inlcude that ele else include , kyuki aage b bo ni bNEGA
        if(inner.size()==0 or nums[i]>=inner.back()){ 
            // for(int t=i;t<nums.size();t++){
            inner.push_back(nums[i]);
            solve(nums,i+1,an,inner);
            inner.pop_back();
            
        // }    
        
        }
                solve(nums,i+1,an,inner);
        // for(int t=i;t<nums.size();t++){  //not working ache se
        //     inner.push_back(nums[t]);
        //     solve(nums,t+1,an,inner);
        //     inner.pop_back();
        //     solve(nums,t+1,an,inner);
        // }
        return ;
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // nums = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
        vector<vector<int>> an;
        vector<int> inner;
        set<vector<int>> passed;
        solve(nums,0,passed,inner);
        // for(auto i:passed){ //instead of this ->do ,
        // ---vector(passed.begin(),passed.end());
        //     an.push_back(i);
        // }
        return vector(passed.begin(),passed.end());
    }
};
