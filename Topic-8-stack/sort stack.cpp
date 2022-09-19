void insert(stack<int> &stack,int temp){
    if(stack.size() == 0 || stack.top()<temp){
        stack.push(temp);
        return;
    }
    
    int val = stack.top();
    stack.pop();
    insert(stack,temp);
    stack.push(val);
}
void sortIt(stack<int> &stack){
    if(stack.size() == 0){
        return;
    }
    
    int temp = stack.top();
    stack.pop();
    sortIt(stack);
    insert(stack,temp);
}

void SortedStack :: sort()
{
  sortIt(s);
}