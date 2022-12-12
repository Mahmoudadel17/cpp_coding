// Online Shopping System:

#include <iostream>
#include <string>
#include <vector>
using namespace std;



// This Class have details about each item:
class Item
{
private:

    string Name;   // Name of item
    static int ID; // static variable start from 1 and increment
    int id;        // spical id for each item
    int quantity;  // Quantity of item
    float price;   // price of item

public:

    Item(){}  // Default constructor

    Item(string name, long long quantity, double price)   // Parameterize constructor
    {
        Name = name;
        quantity = quantity;
        price = price;
    }

    Item(Item &obj)  // copy constructor
    {
        Name = obj.Name;
        price = obj.price;
        quantity = obj.quantity;
        id = obj.id;
    }

    // setters

    void setName(string s)
    {
        Name = s;
    }
    void setQuantity(int n)
    {
        quantity = n;
    }
    void setPrice(float p)
    {
        price = p;
    }
     void setId()
    {
        id = ID;
        ID++;
    }

    // getters

  string getName() const {return Name;}
  int getid() const {return id;}
  int getQuantity() const {return quantity;}
  float getPrice() const {return price;}

  // operator overloading

 void operator+=(const Item &ob1)
{
    quantity = quantity + ob1.quantity;

}
void operator-=(int num)
{

    quantity = quantity - num;

}

friend bool operator== (Item &i1, Item &i2);
friend ostream & operator << (ostream &out, const Item &c);
friend istream & operator >> (istream &in,  Item  &c);


};

bool operator== (Item &i1,Item &i2)
{
    return (i1.Name == i2.Name);
}

ostream & operator << (ostream &out, const Item &c)
{
    // cout the object from Item class

    out<<"------------------------------"<<endl;
    out<<"ID of item is "<<c.getid()<<endl;
    out<<"name of item is "<<c.getName()<<endl;
    out<<"quantity of item is "<<c.getQuantity()<<endl;
    out<<"price of item is "<<c.getPrice()<<endl;
    out<<"------------------------------"<<endl;
    return out;
}
istream & operator >> (istream &in,  Item &c)
{
    // cin the object from Item class

    cout<<"Enter name of item: ";
    //in>>c.Name;
    in.ignore();
    getline(in,c.Name);
    cout<<"Enter Quantity: ";
    in>>c.quantity;
    cout<<"Enter price of item: ";
    in>>c.price;
    return in;
}

int Item::ID=1; // initialize static ID from one


// This Class have details about Seller:

class Saller
{
private:
    string name;   // Name seller
    string email;  // Email for seller
    Item *items;   // Array from Item class
    int maxItem;   // max number for items in array
public:
static int x; // static variable to used in for loob

Saller() // Default constructor
{
    name = " ";
    email = " ";
    maxItem = 0;

}

// Setter

void setName(string s)
    {
        name = s;
    }
void setEmail(string e)
    {
        email = e; 
    }
void setMaxItem(int m)
{
    maxItem = m;
    items = new Item[maxItem];
}

// geterr
int getMaxItem() const {return maxItem;}
string getEmail()const {return email;}
string getName() const {return name;}

bool Add_An_Item(Item obj) //
{

    for (int i = 0; i < x; i++)
    {
        if (items[i]==obj)
        {
            items[i]+=obj;
            cout<<" << successful addition of item >>"<<endl;
            cout<<endl;
            return true;
        }

    }
    if (x<maxItem)
    {
        items[x]=obj;
        items[x].setId();
        x++;
        cout<<" << successful addition of item >>"<<endl;
        cout<<endl;
        return true;
    }
    else
    {
        cout<<" << fail addition of item ,store capacity full>>"<<endl;
        cout<<endl;
        return false;
    }


}
bool Sell_An_Item(string n,int q)
{
   for (int i = 0; i < x; i++)
    {

        string check = items[i].getName();
        if (check == n)
        {
            long long qCheck = items[i].getQuantity();
            if (!(q <= qCheck))
            {
                cout << "There is only { " << qCheck << " } left for this item"<<endl;
                cout<<endl;
                return false;
            }
            else
            {
                items[i] -= q;
                cout << endl<<"Sell succeeded"<<endl;
                cout<<endl;
                return true;
            }
        }
    }
    cout << "no item called " << n << endl;
    return false;
}

void Print_Items()  // funtion for print details array of items
{
    for (int i = 0; i < x; i++)
    {
        cout<<items[i];
    }

}

Item Find_An_Item_By_ID(int id)  // fontion to find an item by his id
{
    for (int i = 0; i < x; i++)
    {
        int check = items[i].getid();
        if (check == id)
        {
            return items[i];
        }
    }
    cout << "No item with this ID\n";
}

// operator overloading
friend ostream & operator << (ostream &out, const Saller &c);
friend istream & operator >> (istream &in,  Saller &c);

~Saller() // destructor for delete dainamyc array
{
    delete []items;
}
};

ostream & operator << (ostream &out, const Saller &c)
{
    // cout the object from seller class
    out<<"------------------------------"<<endl;
    out<<"name is "<<c.name<<endl;
    out<<"email is "<<c.email<<endl;
    out<<"------------------------------"<<endl;
    return out;
}
istream & operator >> (istream &in,  Saller &c)
{
    // cin the object from seller class
    cout<<"Enter name of seller: ";
    getline(in,c.name);
    cout<<"Enter email of seller: ";
    in>>c.email;
    return in;
}


int Saller::x=0; // initialize static variable from zero (first index in array)


int main()
{
    Saller s1; // object from seller class
    cin>>s1;   // cin object
    cout<<"Enter your max number of items: "; // ask user for his store capacity
    int x;
    cin>>x;
    s1.setMaxItem(x); // store capacity

    bool c=true;  // bool variable to check user need to continues
    while (c)
    {
        // print menu for user

       cout<<"choose your option from menu"<<endl;
       cout<<"--------------------------------"<<endl;
       cout<<"(1). Print My Info."<<endl;
       cout<<"(2). Add An Item."<<endl;
       cout<<"(3). Sell An Item."<<endl;
       cout<<"(4). Print Items."<<endl;
       cout<<"(5). Find an Item by ID."<<endl;
       cout<<"(6). Exit."<<endl;
       cout<<"--------------------------------"<<endl;
       cout<<">>> ";
       cin>>x;

       // check choose
       if(x==1)
       {
           //  user choose (1). Print My Info.
           cout<<s1;
        }
       else if(x==2)
       {
           //  user choose (2). Add An Item.
            Item i;
            cin>>i;
            s1.Add_An_Item(i);
       }
       else if(x==3)
       {
           //  user choose (3). Sell An Item.
           cout<<"Enter name of item: ";
           string s;
           cin.ignore();
           getline(cin,s);
           cout<<"Enter quantity of item: ";
           int Q;
           cin>>Q;
           s1.Sell_An_Item(s,Q);
       }
       else if(x==4)
       {
            //  user choose (4). Print Items.
           s1.Print_Items();
       }
       else if(x==5)
       {
           //  user choose (5). Find an Item by ID.
           cout<<"Enter your id: ";
           int id;
           cin>>id;
           cout<<s1.Find_An_Item_By_ID(id);
       }
       else if(x==6)
       {
           //  user choose (6). Exit.
           c = false;
           cout<<"Good By^_^"<<endl;
        }

    }



    return 0;
}
