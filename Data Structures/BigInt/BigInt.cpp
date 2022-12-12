#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <fstream>
#include<sstream>
#include <cmath>

using namespace std;

class BigInt 
{
private:
    string num;
public:
    BigInt (string n); 
    BigInt (int n); 
    BigInt ();
    BigInt operator+ (const BigInt &a);
    BigInt operator- (const BigInt &a);
    BigInt &operator=(const BigInt &);
    int size(const BigInt & a);
    friend ostream& operator<<(ostream& out, const BigInt& obj);
    friend istream& operator>>(istream& out, BigInt& obj);

};

string sum(string s1,string s2)
{
    string s3="";
    if (s1.length() > s2.length())
    {
        swap(s1,s2);
    }
    int n1 = s1.length() , n2 = s2.length();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((s1[i]-'0') + (s2[i]-'0')+carry);
        s3.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i = n1; i <n2; i++)
    {
        int sum = ((s2[i]-'0') + carry);
        s3.push_back(sum%10 + '0');
        carry = sum/10;

    }
    
    if (carry)
    {
        s3.push_back(carry + '0');
    }
    reverse(s3.begin(),s3.end());
    return s3;
}

bool small(string s1 , string s2)
{
   
    
    int n1 = s1.length() , n2 = s2.length();

    if (n1 < n2){return true;}
    else if(n2 < n1){return false;}

    for (int i = 0; i < n1; i++)
    {
        if (s1[i] < s2[i]){return true;}
        else if (s1[i] > s2[i]){return false;}
    }
        
    return false; 
}

string substracc(string s1,string s2)
{
    if (small(s1,s2)){swap(s1,s2);}

    string s3 = "";
    
    int n1 = s1.length() , n2 = s2.length();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    int carry = 0;
    for (int i = 0; i < n2; i++)
    {
        int sub = ((s1[i]-'0') - (s2[i]-'0') - carry);
        if (sub < 0)
        {
            sub+=10;
            carry=1;
        }
        else{carry = 0;}
        s3.push_back(sub + '0');
        
    }
    for (int i = n2; i < n1; i++)
    {
        int sub = ((s1[i]-'0') - carry);
        if (sub < 0)
        {
            sub+=10;
            carry=1;
        }
        else{carry = 0;}
        s3.push_back(sub + '0');
    }
    reverse(s3.begin(),s3.end());
    return s3;
    
}

int BigInt::size(const BigInt & a)
{
    if (a.num[0]!='-'){return a.num.size();}
    return a.num.size()-1;
} 

BigInt BigInt:: operator+(const BigInt &a)//
{
    BigInt temp;
    string s1 = num, s2 = a.num;
    
    if (s1[0] != '-' && s2[0] != '-')//
    {
       temp.num = sum(s1,s2);
    }
    else if (s1[0] == '-' && s2[0] != '-')//
    {
        s1 = s1.substr(1);
        if (small(s1,s2))
        {
            temp.num = substracc(s2,s1);
            if (temp.num[0]=='0')
            {
                temp.num = temp.num.substr(1);
            }
            
        }
        else
        {
            temp.num = '-';
            string s3 = substracc(s2,s1);
            int x = s3.size();
            if (s3[0]=='0')
            {
                s3 = s3.substr(1);
            }
            
            for (int i = 0; i < x; i++) 
            {
                temp.num.push_back(s3[i]);
            }
            
            
        }

    }
    else if (s1[0] != '-' && s2[0] == '-')
    {
        s2 = s2.substr(1);
        if (small(s2,s1))
        {
            temp.num = substracc(s2,s1);
            if (temp.num[0]=='0')
            {
                temp.num = temp.num.substr(1);
            }
        }
        else
        {
            temp.num = '-';
            string s3 = substracc(s2,s1);
            int x = s3.size();
            if (s3[0]=='0')
            {
                s3 = s3.substr(1);
            }
            for (int i = 0; i < x; i++) 
            {
                temp.num.push_back(s3[i]);
            }

        }
    }
    else if (s1[0] == '-' && s2[0] == '-')
    {   
        s1[0]='0';s2[0]='0';
        temp.num="-";
        string s3 = sum(s1,s2);
        int x = s3.size();
        for (int i = 1; i < x; i++) 
        {
            temp.num.push_back(s3[i]);
        }
        

    }
    
    return temp;
    
}

BigInt BigInt:: operator-(const BigInt &a)
{
    BigInt temp;
    string s1 = num, s2 = a.num;

    if (s1[0] != '-' && s2[0] != '-')//
    {
        if (s1 == s2)
        {
            temp.num = "0";
            return temp;
        }
        
        if (small(s1,s2))
        {
            temp.num = '-';
            string s3 = substracc(s1,s2);
            int x = s3.size();
            for (int i = 0; i < x; i++) 
            {
                temp.num.push_back(s3[i]);
            }
            if (temp.num[1] == '0')
            {
                string s4 = temp.num.substr(2);
                temp.num = '-';
                int x = s4.size();
                for (int i = 0; i < x; i++) 
                {
                temp.num.push_back(s4[i]);
                }
            }
            
        }
        else
        {
            temp.num = substracc(s1,s2);
            if (temp.num[0]=='0')
            {
                temp.num = temp.num.substr(1);
            }            

        }
        
    }
    else if (s1[0] == '-' && s2[0] != '-')//
    {
        s1 = s1.substr(1);
        string s3 = sum(s1 , s2);
        temp.num = '-';
        int x = s3.size();
        for (int i = 0; i < x; i++) 
        {
            temp.num.push_back(s3[i]);
        }

    }
    else if (s1[0] != '-' && s2[0] == '-')//
    {
        s2 = s2.substr(1);
        temp.num = sum(s1 , s2);
    }
    else if (s1[0] == '-' && s2[0] == '-')//
    {
       s2 = s2.substr(1);
       s1 = s1.substr(1);
       if (small(s1,s2))
       {
           temp.num = substracc(s1,s2);
       }
       else{
           temp.num = "-";
           string s3 = substracc(s1,s2);
           int x = s3.size();
           if (s3[0]=='0')
           {
               s3 = s3.substr(1);
           }
           
           for (int i = 0; i < x; i++) 
            {
                temp.num.push_back(s3[i]);
            }
            
            
       }
       

    }
    return temp;
}

bool cheeckValid(string n)
{
    int x = n.size();
    int i=0;
    if (n[0] == '-' )
    {
        i++;
    }
    for (; i < x; i++)
    {
        if (!isdigit(n[i]))
        {
            return false;
        }
            
    }
    
    return true;
}

BigInt::BigInt(string n)
{
    if (cheeckValid(n))
    {
        num = n;
    }
    
}

BigInt::BigInt(int n)
{
  
  stringstream ss;  
  ss<<n;  
  string s;  
  ss>>s;
  if (cheeckValid(s))
  {
    num = s;
  }
  
        
}

BigInt::BigInt()
{
    num = "";
}

BigInt &BigInt::operator=(const BigInt &a){
	num= a.num;
	return *this;
}

istream &operator>>(istream &in,BigInt&a){
	string s;
	in >> s;
	int n = s.size();
	for (int i = n - 1; i >= 0;i--){
		if(!isdigit(s[i]))
        {
            throw("ERROR");
        }
	}
    a.num = s;
	return in;
}

ostream &operator<<(ostream &out,const BigInt &a){
	for (int i = 0 ; i < a.num.size()  ; i++)
    {
        out <<a.num[i];
    }
		
	return out;
}



int main()
{
BigInt num1("123456789012345678901234567890");
BigInt num2("113456789011345678901134567890");
BigInt num3 = num2 + num1;
BigInt num4 = num2 - num1;
cout << "num1 = " << num1 << endl;
cout << "num2 = " << num2 << endl;
//236913578023691357802369135780
cout << "num2 + num1 = " << num3 << endl;
//-10000000001000000000100000000
cout << "num2 - num1 = " << num4 << endl;
cout<<"-----------------------------------"<<endl;
BigInt num5("-123456789012345678901234567890");
BigInt num6("-113456789011345678901134567890");
BigInt num7 = num6 + num5;
BigInt num8 = num6 - num5;
cout << "num5 = " << num5 << endl;
cout << "num6 = " << num6 << endl;
//-236913578023691357802369135780
cout << "num6 + num5 = " << num7 << endl;
//10000000001000000000100000000
cout << "num6 - num5 = " << num8 << endl;
cout<<"-----------------------------------"<<endl;
BigInt num9("-123456789012345678901234567890");
BigInt num10("113456789011345678901134567890");
BigInt num11 = num10 + num9;
BigInt num12 = num10 - num9;
cout << "num9 = " << num9 << endl;
cout << "num10 = " << num10 << endl;
//-10000000001000000000100000000
cout << "num10 + num9 = " << num11 << endl;
//236913578023691357802369135780
cout << "num10 - num9 = " << num12 << endl;

}
