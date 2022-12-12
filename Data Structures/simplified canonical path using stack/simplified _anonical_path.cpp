#include <iostream>
#include <string>
using namespace std;
 

int MAXSIZE =1000;

using namespace std;

template < class T>
class Stack
{
private:
    T *num = new T[MAXSIZE];
    int SIZE;  //Defines Size.
public:
    //Default Constructor.
    Stack()
    {
        SIZE = 0;
    }
    //constructs a stack having "initial_size" elements whose values are "value".
    Stack(T value , int initialSize)
    {
        SIZE = initialSize;
        for(int i = 0 ; i < SIZE ; i++)
        {
            num[i] = value;
        }
    }

    //a destructor to clear the stack and leave no memory leaks.
    ~Stack()
    {
        delete []num;
    }

    //returns the top element by reference.
    T &Top()
    {
        if(SIZE == 0)
            cout <<"Stack is empty !!"<<endl;
        else
            return num[SIZE];
    }

    //removes the top element.
    void Pop()
    {
        if(SIZE == 0)
            cout <<"Stack is empty!!"<<endl<<"there is no elements to delete!"<<endl;
        else
        {
            SIZE--;
        }
    }

    //adds an element to the top of the stack.
    void Push(T value)
    {
        num[++SIZE] = value;
    }
    //returns the number of elements in the stack.
    int Size()
    {
        return SIZE;
    }
    // check stack empty or not
    bool empty()
    {
        return SIZE==0;
    }
        
    
};


string simplify(string A)
{
    Stack<string> st; string dir, res; res.append("/");

    int len = A.length();
 
    for (int i = 0; i < len; i++) {

        dir.clear();
 
        while (A[i] == '/')
            i++;

        while (i < len && A[i] != '/') {
            dir.push_back(A[i]);
            i++;
        }

        if (dir.compare("..") == 0) {
            if (!st.empty())
                st.Pop();   
                
        }
 
        else if (dir.compare(".") == 0)
            continue;

        else if (dir.length() != 0)
            st.Push(dir); 
           
    }
 
    Stack<string> st1;
    while (!st.empty()) {
        st1.Push(st.Top());
        st.Pop();
    }

    while (!st1.empty()) {
        string temp = st1.Top();

        if (st1.Size() != 1)
            res.append(temp + "/");
        else
            res.append(temp);
 
        st1.Pop();
    } 
 
    return res;
}
 


int main()
{
    // absolute path which we have to simplify.
    string str1("/home/");
    cout <<simplify(str1)<<endl;
    cout<<"-----------------------------"<<endl;
    string str2("/../");
    cout <<simplify(str2)<<endl;
    cout<<"-----------------------------"<<endl;
    string str3("/home//foo/");
    cout <<simplify(str3)<<endl;
    cout<<"-----------------------------"<<endl;
    
    return 0;
}