#include <chrono>
#include<iostream>
#include <unistd.h>
#include<numeric>
#include<vector>
#include<algorithm>
#include"SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;
int main()
{
    unsigned int n = 10;//questo è il numero di volte che testo il sorting sul vettore per fare la media
    size_t dimv = 200;
    vector<int> v1(dimv);
    //iota(v1.begin(),v1.end(),1); //vettore ordinato in ordine crescente
    //generate(v1.begin(),v1.end(), [&dimv] () {return --dimv;}); //vettore ordinato in ordine decrescente
       for(unsigned int i =0; i<dimv; i++)
    v1[i] = rand() % 1000; //vettore di numeri interi casuali minori di 1000
    //for (int i = 0; i < dimv / 2; ++i) { //vettore di valore prima crescenti e poi decrescenti
        //v1[i] = i + 1;
    //}


    //for (int i = dimv / 2, j = dimv; i < dimv; ++i, --j) {
       // v1[i] = j;
    //}
    vector<int> v2 = v1;
    double S1 = 0;
    double S2 = 0;

    for(unsigned int i = 0; i < n; i++)
    {
        vector<int> v = v1; //in questo modo ogni volta riprende il vettore che ho definito fuori dal ciclo, non quello ordinato ottenuto alla fine del primo ciclo
        //for(unsigned int i =0; i<3; i++)
            //v1[i] = rand() % 100 perturbo i primi dati 3  per vedere quanto questo influenza i tempi

    chrono::steady_clock::time_point t_begin1
        = chrono::steady_clock::now();

    BubbleSort(v);

    chrono::steady_clock::time_point t_end1
        = chrono::steady_clock::now();

    double timeElapsed1 = chrono::duration_cast<chrono::microseconds>(t_end1-t_begin1).count();
    S1 += timeElapsed1;

    }
    double mediaBubble = S1/n;
    cout<< "BubbleSort ha impiegato mediamente: " << mediaBubble << " ms" << endl;
    for(unsigned int i = 0; i < n; i++)
    {
        vector<int> v = v2;



    chrono::steady_clock::time_point t_begin2
        = chrono::steady_clock::now();

    MergeSort(v);

    chrono::steady_clock::time_point t_end2
        = chrono::steady_clock::now();

    double timeElapsed2 = chrono::duration_cast<chrono::microseconds>(t_end2-t_begin2).count();
    S2 +=timeElapsed2;

    }
    double mediaMerge = S2/n;
    cout<< "MergeSort ha impiegato mediamente : " << mediaMerge << " ms" << endl;





    return 0;
}

