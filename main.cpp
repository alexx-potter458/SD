#include <iostream>

using namespace std;

 class MultimeVector {
     public:
        int* multime;
        int lungime = 0;

        MultimeVector() {
           
            multime = new int[lungime];
        }

 };

//1. Inserare element x

void insereaza(MultimeVector &multimeaMea, int elemet) {
    int* temp;
    temp = new int[multimeaMea.lungime + 1];

    copy(multimeaMea.multime, multimeaMea.multime + multimeaMea.lungime, temp);
    delete [] multimeaMea.multime;
    multimeaMea.multime = temp;

    multimeaMea.multime[multimeaMea.lungime] = elemet;
    multimeaMea.lungime ++;
}


//2. Stergere elemet x

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


int main()
{
 
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