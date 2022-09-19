#define vi vector<int>

vi fun(string exp){
    vi ans;
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='*' || exp[i] == '-' || exp[i] == '/' || exp[i] == '+'){
            vi ans1 = fun(exp.substr(0,i));
            vi ans2 = fun(exp.substr(i+1));
            cout<<ans1.size()<<" "<<ans2.size()<<endl;
            for(int k = 0;k < ans1.size() ; k++){
                for(int j = 0;j<ans2.size();j++){
                    if(exp[i] == '+') ans.push_back(ans1[k] + ans2[j]);
                    else if(exp[i] == '-') ans.push_back(ans1[k]-ans2[j]);
                    else if(exp[i] == '*') ans.push_back(ans1[k]*ans2[j]);
                    else if(exp[i] == '/') ans.push_back(ans1[k]/ans2[j]);
                }
            }
            
        }
    }
    
    if(ans.size() == 0) ans.push_back(stoi(exp));
    
    return ans ;
}

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        return fun(expression);

    }
};

/*


Lets Take exp : 2 * 3 - 4 * 5

and at the first i pointer pointing to 1th position 
  i
  |
2 * 3 - 4 * 5

ans1 = {2}
ans2 = {-5,-17}

--> (3-4) * 5
--> 3 - (4*5)

resulting in {-5*2 , -17*2} for stopping at i = 1

*/