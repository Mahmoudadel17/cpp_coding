#include <iostream>

 
using namespace std ;



void The_Trip(){

  int n;cin>>n;
  float *arr = new float[n];
  float sum=0;
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }

  float ave = sum/(float)n,result=0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i]>ave)
    {
      result += arr[i] - ave;
    }
   
  }
  
  
  cout<<result;


}


int main()
{

    The_Trip();
    
    return 0;
}
  
