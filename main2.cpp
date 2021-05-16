#include <iostream>
#include <fstream>

using namespace std;
ofstream g;

class structura
{
public:
    int lungime = 0;
    int *v = new int[lungime];
    int* temp;
};

void afisare(structura s)
{
    g<<"Structura este: ";
    for(int i=0; i<=s.lungime-1; i++)
        g<<s.v[i]<<" ";
}

void insereaza(structura &s, int x)
{
    if(s.lungime==0)
    {

        s.temp = new int[s.lungime+1];
        s.lungime++;
        s.temp[0] = x;
        delete[] s.v;
        s.v = s.temp;
    }
    else
        if(s.lungime >= 1)
            if(s.v[0]>x)
            {
                s.temp = new int[s.lungime+1];
                s.lungime++;
                for(int i=1; i<=s.lungime; i++)
                {
                    s.temp[i] = s.v[i-1];
                }
                s.temp[0] = x;
                delete[] s.v;
                s.v = s.temp;

            }
        else if(s.v[s.lungime-1] < x)
        {
            s.temp = new int[s.lungime+1];
            s.lungime++;
            for(int i=0; i<s.lungime-1; i++)
                s.temp[i] = s.v[i];
            s.temp[s.lungime-1] = x;
            delete[] s.v;
            s.v = s.temp;

        }
        else if(s.v[s.lungime-1] > x and s.v[0]<x)
        {
            int p,u,m;
            p = 0;
            u = s.lungime-1;
            while(p<u and p>=0 and p<=s.lungime-1 and u>=0 and u<=s.lungime-1)
            {
                m = (p+u)/2;
                if(s.v[m] == x)
                    {
                        g<<"Elementul "<<x<<" exista deja in structura.";
                        return;
                    }
                else
                    if(s.v[m] > x)
                    {
                        u= m-1;
                    }
                else
                    if(s.v[m] < x)
                        {
                            p = m +1;
                        }
            }
            s.temp = new int[s.lungime+1];
            s.lungime++;
            if(s.v[p] > x)
            {
                for(int i = 0; i<p; i++)
                    s.temp[i] = s.v[i];
                s.temp[p] = x;
                for(int i = p+1; i<= s.lungime-1; i++)
                    s.temp[i] = s.v[i-1];
                delete[] s.v;
            }
            else
            {
                for(int i = 0; i<=p; i++)
                    s.temp[i] = s.v[i];
                s.temp[p+1] = x;
                for(int i = p+2; i<= s.lungime-1; i++)
                    s.temp[i] = s.v[i-1];
                delete[] s.v;

            }
            s.v = s.temp;
        }

        g<<"Elementul "<<x<<" a fost introdus."<<endl;
        //afisare(s);
}

int cautare(structura s,int x)
{
    int m,u,p;
    p = 0;
    u = s.lungime-1;
    while(p<=u)
    {
        m=(p+u)/2;
        if(x == s.v[m])
            return m;
        else
            if(x > s.v[m])
                p = m+1;
            else
                u = m-1;
    }
    return -1;
}

void stergere(structura &s,int x)
{
    if(s.lungime == 0)
        g<<"Structura nu contine niciun element.";
    else
    {
        int pozitie = cautare(s,x);
        if(pozitie != -1)
        {


            s.temp = new int[s.lungime+1];

            for(int i = 0; i< pozitie; i++)
            {
                s.temp[i] = s.v[i];
            }

            for(int i = pozitie; i< s.lungime; i++)
            {
                s.temp[i] = s.v[i+1];
            }
            s.lungime--;
            delete[] s.v;
            s.v = s.temp;
            g <<"Elementul "<< x <<" a fost sters."<< endl;
            //afisare(s);
        }
        else
            g <<"Elementul nu exista in structura.";
    }
}

void predecesor(structura s,int x)
{
    g<<"Elementul "<< x;
    int pozitie = cautare(s,x);
    if(pozitie == 0)
    {
        g<<" este pe prima pozitie si nu are predecesor.";
    }
    else if(pozitie == -1)
        {
        g<<" nu exista in structura.";
    }
    else
    {
        g<<" il are ca predecesor pe "<<s.v[pozitie-1];
    }
}

void succesor(structura s,int x)
{
    g<<"Elementul "<< x;
    int pozitie = cautare(s,x);
    if(pozitie == s.lungime-1)
    {
        g<<" este pe ultima pozitie si nu are succesor.";
    }
    else if(pozitie == -1)
        {
        g<<" nu exista in structura.";
    }
    else
    {
        g<<" il are ca succesor pe "<<s.v[pozitie+1];
    }
}

void kelem(structura s,int k)
{
    if(k>s.lungime-1)
    {
        g<<"Structura nu este ocupata pana la pozitia "<<k;
    }
    else
    {
        g<<"Elementul de pe pozitia " << k <<" este: "<<s.v[k];
    }
}

void minim(structura s)
{
    if(s.lungime)
    {
        g<<"Valoarea minima din structura este: "<<s.v[0];
    }
    else
        g<<"Structura este goala.";
}

void maxim(structura s)
{
    if(s.lungime)
    {
        g<<"Valoarea maxima din structura este: "<<s.v[s.lungime-1];
    }
    else
        g<<"Structura este goala.";
}

int get_lungime(structura s)
{
    g<<"Cardinalul este: ";
    return s.lungime;
}

const char* exista(structura s,int x)
{
    
    if(s.lungime)
    {
        g<<"Elementul "<<x<<" exista: ";
        int pozitie = cautare(s,x);
        if(pozitie == -1)
            return "Nu";
        return "Da";
    }
    else
        return "Structura este goala.";
}

int main()
{
    ifstream f;
    int op, elem, option = 0;
    structura v;
    cout<<"\t\tComenzi posibile"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"1 pentru citirea a 10 valori din fisier"<<endl;
    cout<<"2 pentru citirea a 100 de valori din fisier"<<endl;
    cout<<"3 pentru citirea a 10000 de valori din fisier"<<endl;
    cout<<"4 pentru citirea a 100000 de valori din fisier"<<endl;
    cout<<"5 pentru citirea a 500000 de valori din fisier"<<endl<<endl;
    do
    {
        cout<<"Citeste optiunea ";
        cin>>option;

        if(option == 1)
        {
            f.open("test_10.txt");
            g.open("text_10_output.txt");
            cout << "Testul " << option << " a fost ales"<<endl;
            break;
        }
        else if(option == 2)
        {
           f.open("test_100.txt");
           g.open("text_100_output.txt");
           cout << "Testul " << option << " a fost ales"<<endl;
           break;
        }
        else if(option == 3)
        {
            f.open("test_10000.txt");
            g.open("text_10000_output.txt");
            cout << "Testul " << option << " a fost ales"<<endl;
            break;
        }
        else if(option == 4)
        {
            f.open("test_100000.txt");
            g.open("text_100000_output.txt");
            cout << "Testul " << option << " a fost ales"<<endl;
            break;
        }
        else if(option == 5)
        {
            f.open("test_500000.txt");
            g.open("text_500000_output.txt");
            cout << "Testul " << option << " a fost ales"<<endl;
            break;
        }
        else cout << "Nu ai ales corect, mai citeste o data"<<endl;
    }
    while(option>5 || option<=0);

    while(f>>op)
    {
        f>>elem;
        if(op == 1)
        {
            insereaza(v,elem);
            g<<endl<<endl;
        }
        else if(op == 2)
        {
            stergere(v,elem);
            g<<endl<<endl;
        }
        else if(op == 3)
        {
            minim(v);
            g<<endl<<endl;
        }
        else if(op == 4)
        {
            maxim(v);
            g<<endl<<endl;
        }
        else if(op == 6)
        {
            succesor(v,elem);
            g<<endl<<endl;
        }
        else if(op == 5)
        {
            predecesor(v,elem);
            g<<endl<<endl;
        }
        else if(op == 9)
        {
            g<<get_lungime(v);
            g<<endl<<endl;
        }
        else if(op == 8)
        {
            g<<exista(v,elem);
            g<<endl<<endl;
        }
        else if(op == 7)
        {
            kelem(v,elem);
            g<<endl<<endl;
        }
    }
    f.close();
    g.close();
    delete[] v.v;
    delete[] v.temp;
    return 0;
}
