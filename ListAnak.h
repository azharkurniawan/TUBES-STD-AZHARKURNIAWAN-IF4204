#ifndef LISTANAK_H_INCLUDED
#define LISTANAK_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) P->info
#define next(P) P->next

struct anak{
    string nama;
    string gender;
    string tanggal;
    string bulan;
    string tahun;
    string umur;
};

typedef struct ElmAnak *add_Anak;

struct ElmAnak{
    anak info;
    add_Anak next;
};

struct ListAnak{
    add_Anak first;
};

add_Anak AlokasiAnak(string name, string gen, string tgl, string bln, string thn, string age);
void dealokasi(add_Anak &P);
void createListAnak(ListAnak &L);
add_Anak cariElmAnak(ListAnak L, string x);
void ShowListAnak(ListAnak &L);
void insertLastAnak(ListAnak &L, add_Anak P);
void deleteLastAnak(ListAnak &L, add_Anak &P);
void deletePrecAnak(ListAnak &L, add_Anak &Prec);
bool cekAnak(ListAnak &L, string x);
bool isEmpty(ListAnak L);


#endif // LISTANAK_H_INCLUDED
