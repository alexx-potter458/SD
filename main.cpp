#include <iostream>
#include <set>

using namespace std;

class Multime {
    public:
        set<int> multime;
        set<int>::iterator it;
    Multime(){

    }

    void afiseaza(){
        for (this->it = this->multime.begin(); this->it != this->multime.end(); ++ this->it){
            cout << *this->it << " ";
        }
        cout << '\n';
    }
        
};

void insereaza(Multime &mySet, int element){
        mySet.multime.insert(element);
        for(int i=0; i<1000333323; i++)
        mySet.multime.insert(i+323);
    }

int main()
{
    Multime multime;
    insereaza(multime, 2);
    cout<< "gata";
    //multime.afiseaza();
    
}