class Solution 
{
public:
    bool canWin(string currentState) 
    {
        mState = currentState;
        return helper();        
    }
    
    bool helper()
    {
        for (size_t i = 0; i < mState.length() - 1; i++)
        {
            if (mState[i] == '+' && mState[i+1] == '+')
            {
                mState[i]   = '-';
                mState[i+1] = '-';
                
                bool res = !helper();

                mState[i]   = '+';
                mState[i+1] = '+';
                
                if (res) return true;
            }
        }
        return false;
    }
    
private:
    std::string mState;
};
