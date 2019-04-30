#ifndef LISTPEGAWAI_H_INCLUDED
#define LISTPEGAWAI_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) P->info
#define next(P) P->next

struct pegawai{
    string no_pegawai;
    string nama;
    string jabatan;
    string umur;
    string gaji;
};

typedef struct ElmPegawai *add_pegawai;

struct ElmPegawai{
    pegawai info;
    add_pegawai next;
};

struct ListPegawai{
    add_pegawai first;
};

add_pegawai AlokasiPegawai(string id, string name, string jab, string age, string sal);
void dealokasi(add_pegawai &P);
void createListPegawai(ListPegawai &L);
add_pegawai cariElmPegawai(ListPegawai L, string x);
void ShowListPegawai(ListPegawai &L);
void insertLastPegawai(ListPegawai &L, add_pegawai P);
void deleteLastPegawai(ListPegawai &L, add_pegawai &P);
void deletePrecPegawai(ListPegawai &L,add_pegawai &Prec);
bool cekPegawai(ListPegawai &L, string x);
bool isEmpty(ListPegawai L);


#endif // LISTPEGAWAI_H_INCLUDED
