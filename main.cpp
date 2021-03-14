#include <iostream>

using namespace std;

 class MultimeVector {
     public:
        int* multime;
        int lungime = 0;
        int maxim = INT_MIN;
        int minim = INT_MAX;

        MultimeVector() {
           
            multime = new int[lungime];
        }

 };

//1. Inserare element x

void insereaza(MultimeVector &multimeaMea, int element) {
    int* temp;
    temp = new int[multimeaMea.lungime + 1];

    copy(multimeaMea.multime, multimeaMea.multime + multimeaMea.lungime, temp);
    delete [] multimeaMea.multime;
    multimeaMea.multime = temp;

    multimeaMea.multime[multimeaMea.lungime] = element;
    multimeaMea.lungime ++;

    if(element > multimeaMea.maxim)
        multimeaMea.maxim = element;

    if(element < multimeaMea.minim)
        multimeaMea.minim = element;
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

int min(MultimeVector &multimeaMea)
{
    return multimeaMea.minim;
}

int max(MultimeVector &multimeaMea)
{
    return multimeaMea.maxim;
}


int main()
{
 
    cout << "\n\n-------------------------\n\n\n";

    MultimeVector v;
    for (int i = 0; i < 100; i ++)
    {
        insereaza(v, rand()%1000);
    }
    

    for(int i=0; i< v.lungime; i++)
    cout << v.multime[i]<< " ";

    cout << "\n\n\n" << min(v) << " " << max(v);
    
}