double Solution::findMedianSortedArrays(const vector<int> &num1, const vector<int> &num2) {

    int n1 = num1.size();
    int n2 = num2.size();
    
    if(n1==0){
        if(n2%2 == 0) return (num2[n2/2] + num2[(n2/2)-1])/2.0;
        else return num2[n2/2];
    }else if(n2==0){
        if(n1%2 == 0) return (num1[n1/2] + num1[(n1/2)-1])/2.0;
        else return num1[n1/2];
    }
    
    int low = 0;
    int high = n1;
    
    while(low <= high){
        
        int mid = ( low + high )/2;
        int cut1 = mid;
        int cut2 = ((1+n1+n2)/2)-cut1;
        
        
        int l1;
        if(cut1==0) l1 = -1e9;
        else l1 = num1[cut1-1];
        
        int l2;
        if(cut2==0) l2 = -1e9;
        else l2 = num2[cut2-1];
        
        int r1;
        if(cut1==n1) r1 = 1e9;
        else r1 = num1[cut1];
        
        int r2;
        if(cut2==n2) r2 = 1e9;
        else r2 = num2[cut2];
        
        if(l1 <= r2 and l2 <= r1){
            if((n1+n2)%2 == 0)
                return (max(l1,l2)+min(r1,r2))/2.0;
            else
                return max(l1,l2);
        }else if(l1 > r2)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return 0.0;
}