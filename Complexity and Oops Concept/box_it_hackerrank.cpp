//Box It 
//HackerRank question on classes
#include<iostream>
using namespace std;
class Box{
    int length;
    int breadth;
    int height;
public:
    //Default Ctor
    Box()
    {
        length=breadth=height=0;
    }

    //Parameterized Ctor
    Box(int l,int b,int h)
    {
        length=l;
        breadth =b;
        height=h;
    }
    //Methods of Class

    int getLength()
    {
        return length;
    }
    int getBreadth() 
    {
        return breadth;
    }
    int getHeight()
    {
        return height;
    }
    long long CalculateVolume()
    {
        return length*breadth*height;
    }

//Overloading operator

    bool operator<(Box& b)
    {
        if(length<b.length)
        {
            return true;
        }
        else if(length ==b.length && breadth<b.breadth)
        {
            return true;
        }
        else if(length ==b.length && breadth==b.breadth && height<b.height)
        {
            return true;
        }
        else {
            return false;
        }
    }

    

    //Copy cTor
    Box(Box &B)
    {   length= B.length;
        breadth = B.breadth;
        height = B.height;
    }

    //Destructor
    ~Box()
    {}
};
//Cout operation
    ostream& operator<<(ostream &ob,Box &b)
    {
        ob<<b.getLength()<<" "<<b.getBreadth()<<" "<<b.getHeight();
        return ob;
    }

void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}