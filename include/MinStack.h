#include <stack>

template< typename T >
class MinStack 
{
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(T val) 
    {
        s1.push(val);
        if (s2.empty() || getMin() > val)
        {
            s2.push(val);
        }    
    }
    
    void pop() 
    {
        if (s2.top() == s1.top())
        {
            s2.pop();
        }    
        s1.pop();
    }
    
    T top() 
    {
       return s1.top(); 
    }
    
    T getMin() 
    {
        return s2.top();    
    }
private:
    std::stack<T> s1;
    std::stack<T> s2;
};