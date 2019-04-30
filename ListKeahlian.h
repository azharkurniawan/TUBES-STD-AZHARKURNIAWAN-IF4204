#ifndef LISTKEAHLIAN_H_INCLUDED
#define LISTKEAHLIAN_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) P->info
#define next(P) P->next

struct keahlian{
    string nama_keahlian;
    string lamapeng;
};

typedef struct ElmKeahlian *add_Keahlian;

struct ElmKeahlian{
    keahlian info;
    add_Keahlian next;
};

struct ListKeahlian{
    add_Keahlian first;
};

add_Keahlian AlokasiKeahlian(string name, string peng);
void dealokasi(add_Keahlian &P);
void createListKeahlian(ListKeahlian &L);
add_Keahlian cariElmKeahlian(ListKeahlian L, string x);
void ShowListKeahlian(ListKeahlian &L);
void insertLastKeahlian(ListKeahlian &L, add_Keahlian P);
void deleteLastKeahlian(ListKeahlian &L, add_Keahlian &P);
void deletePrecKeahlian(ListKeahlian &L,add_Keahlian &Prec);
bool cekKeahlian(ListKeahlian &L, string x);
bool isEmpty(ListKeahlian L);


#endif // LISTKEAHLIAN_H_INCLUDED
