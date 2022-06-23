vector<int> find(int a[], int n , int x )
{
    vector<int> ans;

    int start=0;
    int end=n-1;

    while(start<end){

        int mid=(start+end)/2;

        if(a[mid]==x){
            end=mid;
        }else if(a[mid]<x){
            start=mid+1;
        }else if(a[mid]>x){
            end=mid-1;
        }

    }
    
    if(a[start]==x){
        ans.push_back(start);
    }else if(a[end]==x){
        ans.push_back(end);
    }else {
        ans.push_back(-1);
    }

    start=0;
    end=n-1;

    while(start<end){
        int mid=(start+end)/2;
        
        if(a[mid]==x){
            if(start==mid){
                break;
            }
            start=mid;
        }else if(a[mid]<x){
            start=mid+1;
        }else if(a[mid]>x){
            end=mid-1;
        }
    }

    if(a[end]==x){
        ans.push_back(end);
    }else if(a[start]==x){
        ans.push_back(start);
    }else {
        ans.push_back(-1);
    }

    
    return ans;
   
}