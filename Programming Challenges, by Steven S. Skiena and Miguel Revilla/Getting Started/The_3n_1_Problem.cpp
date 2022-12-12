#include <iostream>

 
using namespace std ;

void The_3n_1_Problem(){
  int n;cout<<"Enter number of cases: ";
  cin>>n;
 
  while (n--)
  {
    // code her
     double max=0;
    int i,j;
    cin>>i>>j;
    for (int x=i; x <= j; x++)
    {
      int sum=1;
      int z=x;
      while (z>1)
      {
        if(z%2==0){z = z /2;}
        else if (z%2!=0){z = (z*3) +1;}
        sum++;
      }
      if (sum > max)
      {
       max = sum;
      }
      
    }
      cout<<i<<" "<<j<<" "<<max<<endl<<endl;
  }

  
}



int main()
{

    The_3n_1_Problem();
    
    return 0;
}
  
