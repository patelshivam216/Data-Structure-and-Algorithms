const int N = 1e5+2;    
class NumArray {
    int Tree[4*N];
    int arr[N];
    int n;
public:

    void buildTree(int node,int start,int end){
    if(start == end){
        Tree[node] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(node*2,start,mid);
    buildTree(2*node+1,mid+1,end);

    Tree[node] = Tree[2*node] + Tree[2*node + 1];
    return;
}
   int query(int node,int start,int end,int left,int right){
    if(end < left || right < start){
        return 0;
    }

    if(start >= left and end <= right){
        return Tree[node];
    }

    int mid = (start+end)/2;

    int q1 = query(node*2,start,mid,left,right);
    int q2 = query(2*node+1,mid+1,end,left,right);

    return q1+q2;
}
    void updateTree(int node,int start,int end,int index,int value){
    
    if(start == end and index == start){
        arr[start] = value;
        Tree[node] = value;
        return;
    }

    int mid = (start + end)/2;

    if(index <= mid)
        updateTree(node*2,start,mid,index,value);
    else if(index >= mid)
        updateTree(2*node+1,mid+1,end,index,value);


    Tree[node] = Tree[2*node] + Tree[2*node + 1];

    return ;

}
    void update(int index, int val) {
        
        updateTree(1,0,n-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
        
        int ans = query(1,0,n-1,left,right);
        return ans ;
        
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        for(int i=0;i<n;i++){
            arr[i] = nums[i];
        }
        
        buildTree(1,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */