#include <iostream>

 
using namespace std ;



void Minesweeper(){
    int n,m;cin>>n>>m;

  char** arr = new char*[n];
  for (int x = 0; x < m; x++)
  {
    arr[x] = new char[m];
  }
  


  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin>>arr[i][j];
    }
    
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] == '*')
      {


        if (i-1 >= 0 )
        {
          // ----------------------
          if (arr[i-1][j] == '.')
          {
            arr[i-1][j] = '1';
          }
          else if (arr[i-1][j] != '.' && arr[i-1][j] != '*')
          {
            arr[i-1][j]++;
          } 
          // -----------------------

        }

         if (i+1 < n )
        {
          // ----------------------
          if (arr[i+1][j] == '.')
          {
            arr[i+1][j] = '1';
          }
          else if (arr[i+1][j] != '.' && arr[i+1][j] != '*')
          {
            arr[i+1][j]++;
          } 
          // -----------------------
        }

        if (j-1 >= 0)
        {
           // ----------------------
          if (arr[i][j - 1] == '.')
          {
            arr[i][j - 1] = '1';
          }
          else if (arr[i][j - 1] != '.'  && arr[i][j - 1] != '*')
          {
            arr[i][j - 1]++;
          } 
          // -----------------------
        }    

        if (j + 1 < m)
        {
          // -----------------------
          if (arr[i][j + 1] == '.')
          {
            arr[i][j + 1] = '1';
          }
          else if (arr[i][j + 1] != '.'  && arr[i][j + 1] != '*')
          {
            arr[i][j + 1]++;
          } 
          // -----------------------
        }
        
        if (i -1 >=0 && j - 1 >=0)
        {
          // ----------------------
          if (arr[i-1][j - 1] == '.')
          {
            arr[i-1][j - 1] = '1';
          }
          else if (arr[i-1][j - 1] != '.'  && arr[i-1][j-1] != '*')
          {
            arr[i-1][j - 1]++;
          } 
          // -----------------------
        }
        
          if (i -1 >= 0 && j + 1 < m)
        {
          // ----------------------
          if (arr[i-1][j + 1] == '.')
          {
            arr[i-1][j + 1] = '1';
          }
          else if (arr[i-1][j + 1] != '.'  && arr[i-1][j+1] != '*')
          {
            arr[i-1][j + 1]++;
          } 
          // -----------------------
        }

          if (i+1 < n && j - 1 >=0)
        {
          // ----------------------
          if (arr[i+1][j - 1] == '.')
          {
            arr[i+1][j - 1] = '1';
          }
          else if (arr[i+1][j - 1] != '.'  && arr[i+1][j-1] != '*')
          {
            arr[i+1][j - 1]++;
          } 
          // -----------------------
        }
        
         if (i+1 < n && j + 1 < m)
        {
          // ----------------------
          if (arr[i+1][j + 1] == '.')
          {
            arr[i+1][j + 1] = '1';
          }
          else if (arr[i+1][j + 1] != '.'  && arr[i+1][j+1] != '*')
          {
            arr[i+1][j + 1]++;
          } 
          // -----------------------
        }
        
        

        
      }
      
    }
    
  }
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j]=='.')
      {
        arr[i][j] = '0';
      }
      
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  


}


int main()
{
    Minesweeper();
    
    
    return 0;
}
  
