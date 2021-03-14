#include <iostream>
#include <set>

using namespace std;

class Multime {
    public:
        set<int> multime;
        set<int>::iterator it;
    Multime(){

    }

    void insereaza(int element){
        this->multime.insert(element);
    }

    void afiseaza(){
        for (this->it = this->multime.begin(); this->it != this->multime.end(); ++ this->it){
            cout << *this->it << " ";
        }
        cout << '\n';
    }
        
};


int main()
{
    Multime multime;
    multime.insereaza(2);
    multime.afiseaza();
    
}