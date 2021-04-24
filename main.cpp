#include <iostream>
#include <fstream>

#include <chrono>

using namespace std;
using namespace std::chrono;


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
   
        return 1;
    }else {
        return 0;
    }
    
}


int main()
{


    
    int numar;
    ifstream f;
    ofstream g("test_out.txt");

    int option;


    cout << "1.Test 10 numere\n2.Test 100 numere\n3.Test 100 zerouri\n4.Test 500mii\n5.Test maxim";
    cout << "\nIntrodu numar: ";
    cin >> option;

    switch (option) {
        case 1:
            f.open("test1_in.txt");
            
            cout << "Testul " << option << " a fost ales\n";
            break;
        case 2:
            f.open("test2_in.txt");
            cout << "Testul " << option << " a fost ales\n";
            break;
        case 3:
            f.open("test3_in.txt");
            cout << "Testul " << option << " a fost ales\n";
            break;
        case 4:
            f.open("test4_in.txt");
            cout << "Testul " << option << " a fost ales\n";
            break;
        case 5:
            f.open("test5_in.txt");
            cout << "Testul " << option << " a fost ales\n";
            break;
        default:
         cout << "Nu ai ales corect\n";
         break;
    }

    if(option < 1 || option > 5)
        return 0;
    
    auto start = high_resolution_clock::now();

    MultimeVector v;
    while(f >> numar)
    {
        insereaza(v, numar);    // O(n)
    }

 


    g << "Minim: " << min(v) << "\nMaxim: " << max(v) << '\n';  // O(1)
    sterge(v, 10);  // O(n) in cel mai rau caz
    g << "Predecesor: " << predecesor(v, 600) << " " << '\n'; // O(n*logn)
    g << "K-element: " << k_element(v, 2931) << '\n';  // O(n*logn)
    g << "Cardinal: " << cardinal(v) << '\n';  // O(1)
    g << "Este-in: " << este_in(v, -1) << '\n'; // O(n) in cel mai rau caz
    f.close();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    g << "\nTimp executie: ";
    g << duration.count() << "ms\n";  
    g.close(); 

    return 0;

    ///////****** COMPLEXITATE FINALA O(n*logn)


    /*
    MOTIVATIE:
        Motivatia folosirii acestei structuri este reducerea timpului de executie prin memorarea in clasa a datelor necesare de tipul:  
        cadrinal multime, minim, maxim, astfel obtinand o complexitate O(1), evitand parcurgerile in plus ale multimii care ar duce la
        o complexitate de O(n); (+ clasele sunt misto)
        Avantajele structurii:
            este mai natural pentru gândirea noastră să modelăm un software folosind obiecte și clase. Ne gândim 
            deja în termeni de obiecte cu atribute si metode. Putem crea diferite module independente în cod destul de ușor ceea ce ajută la reutilizare.
        Dezavantajele structurii:
            schimbarea planului unor obiecte este dificilă. Dacă o multime este o multime, este greu să decizi la un moment dat că doresti să fie o mașină.
            În realitate, acest lucru se întâmplă mai rar, dar în software este mai frecvent decât s-ar aștepta.

    */
}