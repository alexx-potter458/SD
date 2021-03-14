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

//2. Stergere element x

void sterge(MultimeVector &multimeaMea, int element){
    bool amGasitElement = false;
    size_t i = 0;

    for (i; i < multimeaMea.lungime; i ++) {
        
        if(multimeaMea.multime[i] == element) {
           amGasitElement = true; 
        }

        if( amGasitElement == true) {
            multimeaMea.multime[i] = multimeaMea.multime[i+1];
        }

    }
    
    if(amGasitElement) {
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

//6. Predecesorul elementului x

int predecesor(MultimeVector &multimeaMea, int x){
    QuickSort(multimeaMea.multime, 0, multimeaMea.lungime);
    int pozitie = CautareBinara(multimeaMea.multime, 0, multimeaMea.lungime, x);
    if(pozitie == 0){
        return -1;
    }else {
        return multimeaMea.multime[pozitie - 1];
    }
}

//7. Al k-lea element

int k_element(MultimeVector &multimeaMea, int k){
    QuickSort(multimeaMea.multime, 0, multimeaMea.lungime);
    if(k > 0 && k <= multimeaMea.lungime){
        return multimeaMea.multime[k - 1];
    }else {
        return -1;
    }
}

//8. Cardinalul multimii

int cardinal(MultimeVector &multimeaMea){
    return multimeaMea.lungime;
}

//9. Este in multime?


int este_in(MultimeVector &multimeaMea, int x){
    bool amGasitElement = false;
    for (size_t i = 0; i < multimeaMea.lungime; i ++){
        if(x == multimeaMea.multime[i]){
            amGasitElement = true;
            break;
        }
    }
    if(amGasitElement){
        return 69;
    }else {
        return 0;
    }
    
}


int main()
{
    cout << "\n\n-------------------------\n\n\n";

    MultimeVector v;
    for (int i = 0; i < 10; i ++)
    {
        insereaza(v, i % 10);
    }

    for(int i=0; i< v.lungime; i++)
        cout << v.multime[i]<< " ";
    cout << '\n';
    // cout << "\n\n\n" << min(v) << " " << max(v);
    // cout << succesor(v, 24);
    // cout << predecesor(v, 0) << " ";
    // cout << k_element(v, 2);
    // cout << cardinal(v);
    // cout << este_in(v, -1);
}