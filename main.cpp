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
<<<<<<< HEAD
    Multime multime;
    multime.insereaza(2);
    multime.afiseaza();
    
=======
    cout << "esti prost";
    cout << "hai dreq azi";
    cout << "Gata ba, merge!";
    cout << "bine, duminica la 8 jum sa fii pe zona";
>>>>>>> 566e336c44957a8dabf217a649f7b768db602ed5
}