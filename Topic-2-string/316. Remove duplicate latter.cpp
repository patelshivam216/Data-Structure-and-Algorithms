class Solution {
public:
    string removeDuplicateLetters(string s) {

        map<char,int> mp; // frequancy for making sure that stack.top() char is more avalible after removing cur
        bool map[26] = {false}; //  keep for stack if its already is stack or not
        int n = s.size();
        for(auto ch : s) mp[ch]++;

        stack<char> stack;

        for(int i=0;i<n;i++){


            
            while(stack.size()>0 and stack.top()>s[i] and mp[stack.top()]>0 and map[s[i]-'a']==false ){
                /*
                    --> remove if there are more this type of char avalible 
                    --> and also is these type of char not already in stack
                */
                map[stack.top()-'a'] = false;
                stack.pop();

            }

            // if its in stack already then no need to push it

            if(map[s[i]-'a'] == false){
                stack.push(s[i]);
                map[s[i]-'a'] = true;
            }
            // always decrease freq as we move ahead

            mp[s[i]]-=1;
            
        }

        string temp(stack.size(),' ');
        int i = stack.size()-1;
        while(stack.size() > 0){
            char top = stack.top();
            stack.pop();
            temp[i] = top;
            i--;
        }

        return temp;

        
    }
};