#include <iostream>
#include <string>
#include <stack>

using namespace std;


int Priority(char c)
{
    if (c=='-' || c=='+')
    {
        return 1;
    }
    else if (c== '*' || c== '/')
    {
        return 2;
    }
    else if (c=='^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    
    
    
}

string infix_to_postfix(string exp)
{
    stack<char> stk;
    string output = "";
    //--------------------------------
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ')  continue;
        if (isdigit(exp[i]) || isalpha(exp[i]))
        {
           output += exp[i];
        }
        else if (exp[i]=='(')
        {
            stk.push('(');
        }
        else if (exp[i]==')')
        {
            while (stk.top() != '(')
            {
                output += stk.top();
                stk.pop();
            }
            stk.pop();
            
        }
        else 
        {
            while (!stk.empty() && Priority(exp[i])<=Priority(stk.top()))
            {
                output += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
            
        }
        
        
    }
    while (!stk.empty())
    {
        output += stk.top();
        stk.pop();
    }
    return output;
    
}


float MathOperation(float op1,float op2,char c)
{
    if (c=='+')
    {
        return op1+op2;
    }
    else if (c=='-')
    {
        return op1-op2;
    }
     else if (c=='*')
    {
        return op1*op2;
    }
     else if (c=='/')
    {
        return op1/op2;
    }
    else
    {
        return 0;
    }
    
}

float postfix_evaluate(string exp)
{
    stack<float> stk;
    for (int i = 0; i < exp.length(); i++)
    {
       if(isdigit(exp[i]))
       {stk.push(exp[i]-'0');}
       else{
           float op2 = stk.top();
           stk.pop();
           float op1 = stk.top();
           stk.pop();
           float result = MathOperation(op1,op2,exp[i]);
           stk.push(result);
       }
    }
    return stk.top();
}

int main()
{
    
ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
    
    string infixExpression = ("(3+2)+7/2*((7+3)*2)");
    cout<<infix_to_postfix(infixExpression)<<endl;
    cout<<postfix_evaluate(infix_to_postfix(infixExpression))<<endl;
    cout<<postfix_evaluate("382/+5-");
  
  return 0; 
}