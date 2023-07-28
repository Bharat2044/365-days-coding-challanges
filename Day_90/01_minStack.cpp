// Question Link: https://www.interviewbit.com/problems/min-stack/

/*
Min Stack

Problem Description:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1

NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.
*/



vector<pair<int, int>> v;

MinStack::MinStack() {
    v.clear();
}

void MinStack::push(int x) {
    if(v.size() == 0)
        v.push_back({x, x});
        
    else 
        v.push_back({x, min(x, v.back().second)});
}

void MinStack::pop() {
    if(v.size() == 0)
        return;
        
    v.pop_back();
}

int MinStack::top() {
    if(v.size() == 0) 
        return -1;
   
    return v.back().first;
}

int MinStack::getMin() {
    if(v.size() == 0) 
        return -1;
        
    return v.back().second;
}

