#include <iostream>
#include <windows.h>
#define SETCOLORFUN_H_INCLUDED
using namespace std;

class ColoredBox
{
private:
    int length;
    int width;
    int color;
    char Bchar;
    char **array;

public:
static double maxArea;
ColoredBox(const int len, const int wid):length(len), width(wid)
{
    char v='#';
    setChar(v);
    array = new char *[len];
    for (int i = 0; i < len; i++)
    {
        array[i] = new char[wid];
    }
     

    for(int x=0;x<len;x++)
    {
        for(int y=0;y<wid;y++)
        {
            array[x][y]=Bchar;
        }
    }
}

ColoredBox(int len, int wid,int col,char c):length(len), width(wid),color(col),Bchar(c)
{
    for(int x=0;x<len;x++)
    {
        for(int y=0;y<wid;y++)
        {
            array[x][y]=Bchar;
        }
    }
}
~ColoredBox()
{
    for(int i=0;i<length;i++)
    {
        delete []array[i];
    }
    delete []array;
}


void SetColor(int ForgC)
{
  	color = ForgC;
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
void setChar(char h)
{
	Bchar = h;
}


int getColor()const{return color;}
char getChar()const{return Bchar;}


void display()
{
  for(int i=0;i<length;i++)
	{
		for(int j=0;j<width;j++)
		{
			cout<<array[i][j];
		}
		cout<<endl;
	}
}


void displayTransposed()
{
    for(int i=0;i<width;i++)
	{
		for(int j=0;j<length;j++)
		{
			cout<<array[j][i];
		}
		cout<<endl;
	}
}

void displayWider()
{
   for(int i=0;i<length;i++)
	{
		for(int j=0;j<width;j++)
		{
			cout<<" "<<array[i][j];
		}
		cout<<endl;
	}
}

void displayChess(int c)
{
   int z=color;
	bool x=true;
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(x)
			{
				SetColor(z);
				cout<<array[i][j];
				x=false;
			}
			else
			{
				SetColor(c);
			    cout<<array[i][j];
				x=true;
			}

		}
		cout<<endl;
	}
}



double getArea()
{
    seetmaxArea();
    return length * width;
}
void seetmaxArea()
{
   if(length * width > maxArea)
    {
        maxArea = length * width;
    }
}
double getMaxArea()
{
    return maxArea;
}

};

double ColoredBox::maxArea=0;

int main()
{
int len,wid,col,col2;
char boxChar;
cout<<"Enter length and width of the box separated by a space: ";
cin>>len>>wid;
ColoredBox* cb1;
cb1 = new ColoredBox(len,wid);
cb1->display();
cb1->SetColor(15);
cout<<"Set the box to another color: ";
cin>>col;
cout<<"Displaying Transposed: "<<endl;
cb1->SetColor(col);
cb1->displayTransposed();
cb1->SetColor(15);
cout<<"Displaying Wider: "<<endl;
cb1->SetColor(col);
cb1->displayWider();
cb1->SetColor(15);
cout<<"Displaying Chess, enter the other color: "<<endl;
cin>>col2;
cb1->SetColor(col);
cb1->displayChess(col2);
cb1->SetColor(15);
cout<<endl<<"Area = "<<cb1->getArea();
cout<<endl<<"Max Area = "<<cb1->getMaxArea()<<endl;
delete cb1;

cout<<"Enter length,width,color,character of the box separated by spaces: ";
cin>>len>>wid>>col>>boxChar;
ColoredBox* cb2;
cb2 = new ColoredBox(len,wid,col,boxChar);
cb2->SetColor(col);
cb2->display();
cb2->SetColor(15);
cout<<"Displaying Transposed: "<<endl;
cb2->SetColor(col);
cb2->displayTransposed();
cb2->SetColor(15);
cout<<"Displaying Wider: "<<endl;
cb2->SetColor(col);
cb2->displayWider();
cb2->SetColor(15);
cout<<"Displaying Chess, enter the other color: "<<endl;
cin>>col2;
cb2->SetColor(col);
cb2->displayChess(col2);
cb2->SetColor(15);
cout<<"Displaying original again:"<<endl;
cb2->SetColor(col);
cb2->display();
cb2->SetColor(15);
cout<<endl<<"Area = "<<cb2->getArea();
cout<<endl<<"Max Area = "<<cb2->getMaxArea();
delete cb2;
return 0;
}