#include <iostream>
#include <set>

using namespace std;

////////////////// incercare cu set

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
    }

////////////////////////// incercare cu vector

 class MultimeVector {
     public:
        int* multime;
        int lungime = 0;

        MultimeVector() {
           
            multime = new int[lungime];
        }

 };

void inserare2(MultimeVector &multimeaMea, int elemet) {
    int* temp;
    

    temp = new int[multimeaMea.lungime+ 1];

    copy(multimeaMea.multime, multimeaMea.multime + multimeaMea.lungime, temp); // Suggested by comments from Nick and Bojan
    delete [] multimeaMea.multime;
    multimeaMea.multime = temp;

    multimeaMea.multime[multimeaMea.lungime] = elemet;
    multimeaMea.lungime++;

}


/////////////////


int main()
{
    Multime multime;
    insereaza(multime, 2);
    cout<< "gata";
    //multime.afiseaza();

    cout << "\n\n-------------------------\n\n\n";

    MultimeVector v;
    inserare2(v,3);
    inserare2(v,55);

    for(int i=0; i< v.lungime; i++)
    cout << v.multime[i]<< " ";
    
}