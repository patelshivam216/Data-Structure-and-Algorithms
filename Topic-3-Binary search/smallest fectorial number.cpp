
bool check(int number,int n){
    int f = 5;
    int count = 0;
    while((number/f)>0){
        count += (number/f);
        if(count >= n){
            return true;
        }
        f *= 5;
    }
    if(count>=n){
        return true;
    }
    
    return false;
}

class Solution
{
    public:
        int findNum(int n)
        {
            int low = 0;
            int high = n*5;
            while(low<high){
                int mid = (low+high)/2;
                if(check(mid,n)){
                    high = mid;
                }else low = mid+1;
            }
            return low;
            
        }
};