#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FloatArray // for Array
{
protected:
    float *array; // array 
    int size; // size of array
    int i = 0; // index will be increase use to insert array
    int counter=0; // counter for cout array in file

public:

    FloatArray(int s) //parameterized constructor that takes the array size
    {
        size = s; // set size
        array = new float[size];// declare dynamic array
    }
    virtual int Add(float a)// overriding add method 
    {
        array[i] = a;
        i++;// increase index
        counter++;// increase counter 
        return 0;
    }
    // operator overloading
    friend ofstream &operator<<(ofstream &out, FloatArray &obj);
    friend ifstream &operator>>(ifstream &in, FloatArray &obj);
    
    ~FloatArray()//destructor to deallocate the array
    {
        delete[] array;
    }
}; 
ofstream &operator<<(ofstream &out, FloatArray &obj)
{
    out << obj.counter << "|\t";// print size in file
    for (int i = 0; i < obj.counter; i++)
    {
        out << obj.array[i] << "\t"; // print array in file
    }
    out << endl;// new line for another object
    return out;
}

ifstream &operator>>(ifstream &in, FloatArray &obj)
{
    float a;
    for (int i = 0; i < obj.size; i++)
    {
        in >> a;// read float number
        obj.Add(a); // call add method from object
    }
    return in;
}

class SortedArray : public FloatArray // for Sorted
{
    int x = 0; // index array will be increase use to insert array
public:
    SortedArray(int s) : FloatArray(s){}
    int Add(float a) 
    {
        counter++; // increase counter 

        // adds a float at the right place in the array
        for (int i = 0; i < x; i++)
        {
            if (array[i] > a)
            {
                x++;
                for (int j = x; j > i; j--)
                {
                    array[j] = array[j - 1];
                }
                array[i] = a;
                return 0;
            }
        }
        array[x] = a;
        x++;

       return 0;
    }
};
class FrontArray : public FloatArray
{
    int i = size - 1;// index array will be decrease use to insert array
public:
    FrontArray(int s) : FloatArray(s){}
    int Add(float a)
    {
        counter++;// increase counter 
        array[i] = a;
        i--;
        return 0;
    }
};
class PositiveArray : public SortedArray
{

public:
    PositiveArray(int s) : SortedArray(s){}
    int Add(float a)
    {
         // check a float greater than zero
        if (a > 0)
        {
            SortedArray::Add(a);// call SortedArray add method
        }

        return 0;
    }
};
class NegativeArray : public SortedArray
{
public:
    NegativeArray(int s) : SortedArray(s){}
    int Add(float a)
    {
        // check a float less than zero
        if (a < 0)
        {
            SortedArray::Add(a);// call SortedArray add method
        }

        return 0;
    }
};

int main()
{

    FloatArray *array[10];//array of FloatArray*
    string type;
    string name_file_in, name_file_out;
    int size;// size array read from file
    
    // user Enter name input and output file
    cout<<"Enter the name of the input file: "<<endl;
    cin>>name_file_in;
    cout<<"Enter the name of the output file: "<<endl;
    cin>>name_file_out;
    //open input and output file
    ifstream infile(name_file_in);
    ofstream outfile(name_file_out);
    // if the input file opened successfully, continue.
    if (infile)
    {

    for (int i = 0; i < 10; i++)
    {
        infile >> type;// read type of object

        // check what type of object is?
        if (type == "Array")
        {
            infile >> size;//read size of array
            array[i] = new FloatArray(size);// create object
            infile >> *array[i];// read object from file (extraction operator)
            outfile << *array[i];// print object in file (insertion operator)
        }
        else if (type == "Front")  // same the last in all (else if)
        {
            infile >> size;
            array[i] = new FrontArray(size);
            infile >> *array[i];
            outfile << *array[i];
        }
        else if (type == "Sorted")
        {
            infile >> size;
            array[i] = new SortedArray(size);
            infile >> *array[i];
            outfile << *array[i];
        }
        else if (type == "Positive")
        {
            infile >> size;
            array[i] = new PositiveArray(size);
            infile >> *array[i];
            outfile << *array[i];
        }
        else if (type == "Negative")
        {
            infile >> size;
            array[i] = new NegativeArray(size);
            infile >> *array[i];
            outfile << *array[i];
        }
    }

    }
    else
    {
        cout<<"Error can not found "<<name_file_in<<" file:)";
    }
    
    for (int i = 0; i < 10; i++)
    {
        delete []array[i];// deallocate (deleting array of objects)
    }

    return 0;
}
