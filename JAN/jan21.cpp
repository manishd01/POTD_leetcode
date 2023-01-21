
class Solution {
public:
    bool isvalid(string t){
        //three condtions to check
        
          //if t ka size() is 4 digits or if empty string
        if(  t.size()>3 or t.size()==0) return false;

        // if t>255 out of range
         if(t.size() && stoi(t)>255) return 0; //first check size of t then check for stoi() func
         // if if checks direct and let say if size()==0  and  we keep check forn stoi() leads to dikkat:)


          //first char is zero means trailing zero bali condition
        if(t.size()>1 and t[0]=='0') return 0;
       
       
        return true;

    }
    void solve(string &s,int in,int dots,vector<string>& an,string inner){
        if(dots==3){ //BC
            if(isvalid(s.substr(in))){
                an.push_back(inner+s.substr(in));
            }
            return;
        }

        //recur calls
        for(int i=in;i<s.size();i++){
            if(isvalid(s.substr(in,i-in+1))){
                //if is valid  returns true then
                inner.push_back(s[i]);
                inner.push_back('.');
                solve(s,i+1,dots+1,an,inner);
                inner.pop_back();
            }
        }
        return ;

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> an;
        // int si=s.size();
        string inner;

        solve(s,0,0,an,inner); //first zero for index, second foer number of dots ,, when dots==3 then return ki condition chl pdegi

        
        return an;
    }

};
