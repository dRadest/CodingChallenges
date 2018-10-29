#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

/* class D inherits from A, B and C
so we can call their implementation of func() */
class D: public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            // to keep track of how many times each implementation is called
             int a = 0; int b = 0; int c = 0;
             // copy new_val to x
             int x = new_val; 
             // calculate how many times each will be called
             while(x%5==0){
                 x=x/5;
                 c++;
             }
             while(x%3==0){
                 x=x/3;
                 b++;
             }
             while(x%2==0){
                 x=x/2;
                 a++;
             }
             // call each class' gunc() a, b and c-times
             while(a>0){
                 A::func(val);
                 a--;
             }
             while(b>0){
                 B::func(val);
                 b--;
             }
             while(c>0){
                 C::func(val);
                 c--;
             }
			
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}