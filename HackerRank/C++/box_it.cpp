#include<bits/stdc++.h>

using namespace std;

class Box{
    private:
    int l, b, h;
    public:
    // returns length
    int getLength(){
        return l;
    } 
    // returns breadth
    int getBreadth (){
        return b;
    } 
    // returns height
    int getHeight (){
        return h;
    }  
    // returns volume
    long long CalculateVolume(){
        return (long long) l*b*h;
    } 
    // overload <
    bool operator<(Box& box){
        if(l < box.getLength())
            return true;
        if(b < box.getBreadth() && l == box.getLength())
            return true;
        if(h < box.getHeight() && b == box.getBreadth() && l == box.getLength())
            return true;
        return false;
    }
    // empty constructor
    Box(){
        l=0, b=0, h=0;
    }
    // paramatirezed constructor
    Box(int x,int y,int z){
        l=x, b=y, h=z;
    }
    // copy constructor
    Box(Box &box){
        l=box.getLength(), b=box.getBreadth(), h=box.getHeight();
    }
    
};

// overload <<
ostream& operator<<(ostream& out, Box& B){
        out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
        return out;
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