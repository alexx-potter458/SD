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

// QUICKSORT

void QuickSort(int* vector, int st, int dr){
	if(st < dr)
	{   //pivotul este inițial v[st]
		int m = (st + dr) / 2;
		int aux = vector[st];
		vector[st] = vector[m];
		vector[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j)
		{
			if(vector[i] > vector[j])
			{
				aux = vector[i]; 
				vector[i] = vector[j];
				vector[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(vector, st , i - 1);
		QuickSort(vector, i + 1 , dr);
	}
}

//CAUTARE BINARA

int CautareBinara(int* vector, int st, int dr, int elementDeCautat)
{
    if(st > dr)
        return -1;
    else
    {
        int mijloc =(st+dr)/2;
        if(elementDeCautat == vector[mijloc])
            return mijloc;
        if(elementDeCautat < vector[mijloc])
            return CautareBinara(vector , st, mijloc-1, elementDeCautat);
        else
            return CautareBinara(vector , mijloc+1, dr, elementDeCautat);
    }
}


//2. Stergere element x

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

//3. Elementul Minim

int min(MultimeVector &multimeaMea)
{
    return multimeaMea.minim;
}

//4. Elementul Maxim

int max(MultimeVector &multimeaMea)
{
    return multimeaMea.maxim;
}

//5. Succesorul elementului x

int succesor(MultimeVector &multimeaMea, int x){
    QuickSort(multimeaMea.multime, 0, multimeaMea.lungime);
    int pozitie = CautareBinara(multimeaMea.multime, 0, multimeaMea.lungime, x);
    return multimeaMea.multime[pozitie + 1];
}


int main()
{
 
    cout << "\n\n-------------------------\n\n\n";

    MultimeVector v;
    for (int i = 0; i < 10; i ++)
    {
        insereaza(v, rand() % 100);
    }

    for(int i=0; i< v.lungime; i++)
    cout << v.multime[i]<< " ";
    cout << '\n';
    //cout << "\n\n\n" << min(v) << " " << max(v);
    cout << succesor(v, 24);
    
}