/*
Project   : Stack project
Name      : Hyunsoo Lee
Course    : CSC331, Spring 2021, BMCC
Professor : Anna Salvati
Date      : 04-02-2021
*/

#include <iostream>
#include <stack>
#include <string.h>
#include <unistd.h>
#include <vector>
class pj
{
public:
    void GetResultFromInfixNotation()
    {
        std::cout << "Type an infix notation" << std::endl;
        std::cin >> mInfix;
        printf("Result: %f\n", this->Evaluation());
    }

private:
    void PrintVector(const std::vector<std::string> &vec)
    {
        std::cout << "Print Vector: ";
        for (auto &x : vec)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    void PrintStack(std::stack<std::string> &s)
    {
        if (s.empty())
            return;
        std::string x = s.top();
        s.pop();
        PrintStack(s);
        std::cout << x << " ";
        s.push(x);
    }
    double Evaluation()
    {
        //std::string mInfix = "(14/(8/2-2))*(3-1)-(4*2-3)*(5*2)/10"; //Just example
        double ans{0};
        std::string tempStr = "";
        for (int i = 0; (size_t)i < mInfix.length(); i++) //Here's where the process begins by iterating N(length of string) times
        {
            PrintVector(mVec);
            std::cout << "Print Stack: ";
            PrintStack(mStack);
            std::cout << std::endl;
            if (mInfix[i] == ' ')
            {
                continue;
            }
            else if (mInfix[i] == '(')
            {
                tempStr += mInfix[i];
                mStack.push(tempStr);
                tempStr = "";
            }
            else if (mInfix[i] == ')')
            {
                while (mStack.top()[0] != '(')
                {
                    mVec.push_back(mStack.top());
                    mStack.pop();
                    Calc();
                }
                mStack.pop();
            }
            else if (isOperator(mInfix[i]))
            {
                if (mStack.empty() || mStack.top()[0] == '(' || Precedence(mInfix[i], mStack.top()[0]))
                {
                    tempStr += mInfix[i];
                    mStack.push(tempStr);
                    tempStr = "";
                }
                else
                {
                    while (!mStack.empty() && !Precedence(mInfix[i], mStack.top()[0]) && mStack.top()[0] != '(')
                    {
                        mVec.push_back(mStack.top());
                        mStack.pop();
                        Calc();
                    }
                    
                    tempStr += mInfix[i];
                    mStack.push(tempStr);
                    tempStr = "";
                }
            }
            else if ('0' <= mInfix[i] && mInfix[i] <= '9')
            {
                while ((size_t)i < mInfix.length())
                {
                    tempStr += mInfix[i];
                    i++;
                    if (!('0' <= mInfix[i] && mInfix[i] <= '9'))
                    {
                        i--;
                        break;
                    }
                }
                mVec.push_back(tempStr);
                tempStr = "";
            }
        }
        while (!mStack.empty())
        {
            mVec.push_back(mStack.top());
            mStack.pop();
            Calc();
        }
        ans = atof(mVec.back().c_str());
        return ans;
    }
    void Calc()
    {
        std::string op = mVec.back(); //Get an operator positioned at the last in the vector
        mVec.pop_back();
        double n2 = atof(mVec.back().c_str()); //Get an operand positioned at the last second in the vector
        mVec.pop_back();
        double n1 = atof(mVec.back().c_str()); //Get an operand positioned at the third second in the vector
        mVec.pop_back();
        double res{0};
        printf("n1: %f, n2: %f, op: %s\n", n1, n2, op.c_str());
        if (op[0] == '+')
        {
            res = n1 + n2;
        }
        else if (op[0] == '-')
        {
            res = n1 - n2;
        }
        else if (op[0] == '*')
        {
            res = n1 * n2;
        }
        else if (op[0] == '/')
        {
            res = n1 / n2;
        }

        mVec.push_back(std::to_string(res));
    }
    bool Precedence(const char o1, const char o2)
    {
        if ((o1 == '*' || o1 == '/') && (o2 == '+' || o2 == '-'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isOperator(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

private:
    std::string mInfix;
    std::vector<std::string> mVec;
    std::stack<std::string> mStack;
};