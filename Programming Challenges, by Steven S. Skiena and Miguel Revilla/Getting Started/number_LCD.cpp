#include <iostream>

 
using namespace std ;




void number_LCD(){
          //    0        1         2       3      4        
string a[5] = {"   " , " - "  , "  |" , "|  " , "| |"};



string dig[10][5] {
{a[1],a[4],a[0],a[4],a[1]}, // for 0
{a[0],a[2],a[0],a[2],a[0]}, // for 1
{a[1],a[2],a[1],a[3],a[1]}, // for 2
{a[1],a[2],a[1],a[2],a[1]}, // for 3
{a[0],a[4],a[1],a[2],a[0]}, // for 4
{a[1],a[3],a[1],a[2],a[1]}, // for 5
{a[1],a[3],a[1],a[4],a[1]}, // for 6
{a[1],a[2],a[0],a[2],a[0]}, // for 7
{a[1],a[4],a[1],a[4],a[1]}, // for 8
{a[1],a[4],a[1],a[2],a[1]} //  for 9
};

 string exp;cin>>exp;
  int x = 0;
  int z=1;
  for (int i = 0; i < 5; i++)
  {
    // cout<<exp.length()<<endl;
    for (int j = 0; j < exp.length(); j++)
    {
      x = (int)exp[j] - int('0');
      cout<<dig[x][i]<<"  ";
    }

    
    cout<<endl;
  }
  
  
}


int main()
{

    number_LCD();
    
    return 0;
}
  

