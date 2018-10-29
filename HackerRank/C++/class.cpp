#include <iostream>
#include <sstream>
using namespace std;

class Student{
  private:
    int age;
    string first_name;
    string last_name;
    int standard;
  public:
    int get_age(){
        return age;
    }
    string get_first_name(){
        return first_name;
    }
    string get_last_name() {
        return last_name;
    }
    int get_standard() {
        return standard;
    }
    void set_age(int x){
        age = x;
    }
    void set_first_name(string s){
        first_name = s;
    }
    void set_last_name(string s) {
        last_name = s;
    }
    void set_standard(int x) {
        standard = x;
    }
    string to_string(){
        stringstream s;
        s<<age<<","<<first_name<<","<<last_name<<","<<standard;
        return s.str();
    }
    
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}