#include <iostream>
#include <fstream>
#include <string.h>

using namespace std ;

void print(char** a,int n,int m){
 // fstream outfile("out.txt");

   ofstream fou("output.bmp", ios::binary);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    { 
    //  outfile<<a[i][j]<<" ";
      fou<<a[i][j]<<" ";
      cout<<a[i][j]<<" ";
    }cout<<endl;
   // outfile<<endl;
   fou<<endl;
    
  }
  
}
//  I  ,  C  ,  L  ,  V  ,  H  ,  K  ,  F  ,  S Name ,  X
void Graphical_Editor(){

    bool a=true;
  while (a)
  {
    string s;cin>>s;
    int m,n;char** matr;
    if (s[0]=='I')
    {
      if (s.length()!=3)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }
      
      m=s[1] - '0';n=s[2] - '0';
      matr = new char*[n];
      for (int i = 0; i < n; i++)
      {
        matr[i] = new char[m];
      }

       for (int i = 0; i < n; i++)
        {
         for (int j = 0; j < m; j++)
          {
              matr[i][j] = 'O';
          }
        }
      
    }
    else if (s[0]=='C')
    { if (s.length()!=1)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }
        for (int i = 0; i < n; i++)
        {
         for (int j = 0; j < m; j++)
          {
              matr[i][j] = 'O';
          }
        }
    }
    else if (s[0]=='L')
    {
       if (s.length()!=4)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }
      int i=s[1] - '0';
      int j=s[2] - '0';
      matr[i-1][j-1] = s[3];
    }
    else if (s[0]=='V')
    {
       if (s.length()!=5)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }
      int i=s[1] - '0';
      int j=s[2] - '0';
      int J=s[3] - '0';
      j--;
      for (; j < J; j++)
      {
        matr[j][i-1] = s[4];
      }
      
    }
    else if (s[0]=='H')
    {
       if (s.length()!=5)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }
      int i=s[1] - '0';
      int j=s[2] - '0';
      i--;
      int J=s[3] - '0';
      for (; i < j; i++)
      {
        matr[J-1][i] = s[4];
      }
    }
    else if (s[0]=='K')
    {
       if (s.length()!=6)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }

      int x1,x2,y1,y2;
      x1=s[1]-'0';
      x2=s[3]-'0';
      y1=s[2]-'0';
      y2=s[4]-'0';
      x1--;y1--;

      for (int i = x1; i < x2; i++)
      {
        matr[y1][i] = s[5];
        matr[y2-1][i] = s[5];
      }
      
      for (int j = y1; j < y2; j++)
      {
        matr[j][x1] = s[5];
        matr[j][x2-1] = s[5];
      }
      
      
    }
    else if (s[0]=='F')
    {
       if (s.length()!=4)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }
      int i=s[1] - '0';
      int j=s[2] - '0';
      i--;j--;
      const char f = matr[i][j];

      for (int q = 0; q < n; q++)
      {
        for (int p = 0; p < m; p++)
        {
          if (matr[q][p]==f)
            {
              matr[q][p] = s[3];
            }
      
        }
    
      }

    }
    else if (s[0]=='S')
    {
      //  if (s.length()!=3)
      // {
      //   cout<<"Error commend!!"<<endl;
      //   continue;
      // }
      print(matr,n,m);
    }
    else if (s[0]=='X')
    {
       if (s.length()!=1)
      {
        cout<<"Error commend!!"<<endl;
        continue;
      }
      a=false;
    }
    else{
      continue;
    }
    
  }
}




int main()
{
    Graphical_Editor();
    
    
    return 0;
}
  
