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

/*void insereaza(Multime &mySet, int element){
        mySet.multime.insert(element);
    }
*/
////////////////////////// incercare cu vector

 class MultimeVector {
     public:
        int* multime;
        int lungime = 0;

        MultimeVector() {
           
            multime = new int[lungime];
        }

 };

void insereaza(MultimeVector &multimeaMea, int elemet) {
    int* temp;
    temp = new int[multimeaMea.lungime + 1];

    copy(multimeaMea.multime, multimeaMea.multime + multimeaMea.lungime, temp); // Suggested by comments from Nick and Bojan
    delete [] multimeaMea.multime;
    multimeaMea.multime = temp;

    multimeaMea.multime[multimeaMea.lungime] = elemet;
    multimeaMea.lungime ++;
}



void sterge(MultimeVector &multimeaMea, int element){
    bool amGasitElemem = false;
    size_t i = 0;

    for (i; i < multimeaMea.lungime; i ++) {
        
        if(multimeaMea.multime[i] == element) {
           amGasitElemem = true; 
        }

        if( amGasitElemem == true) {
            multimeaMea.multime[i] = multimeaMea.multime[i+1];
        }

    }
    
    if(amGasitElemem) {
        int* temp;
        multimeaMea.lungime--;

        temp = new int[multimeaMea.lungime];
        copy(multimeaMea.multime, multimeaMea.multime + multimeaMea.lungime,temp);
        delete [] multimeaMea.multime;
        multimeaMea.multime = temp;
    }
}



/////////////////


int main()
{
    //Multime multime;
   // insereaza(multime, 2);
    cout<< "gata";
    //multime.afiseaza();

    cout << "\n\n-------------------------\n\n\n";

    MultimeVector v;
    for (size_t i = 0; i < 55; i ++)
    {
        insereaza(v, i);
    }
    
    sterge(v, 56);
    for(int i=0; i< v.lungime; i++)
    cout << v.multime[i]<< " ";

    
}