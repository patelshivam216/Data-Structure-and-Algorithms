int findMissing(int a[], int n) {
        int d= (a[n-1]-a[0])/n;
        int l=0,h=n-1, mid;
        while(l<h){
            mid=(l+h)>>1;
            if(a[mid]+d!=a[mid+1]){
                return a[mid]+d;
            }else if(a[mid]-d!=a[mid-1]){
                return a[mid]-d;
            }
            else{
                if(a[mid]+(h-mid)*d!=a[h]){
                    l=mid;
                }else{
                    h=mid;
                }
            }
            
        }
    }