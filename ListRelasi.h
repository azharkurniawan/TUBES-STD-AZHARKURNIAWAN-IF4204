#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED

#include <iostream>

using namespace std;

#include "ListPegawai.h"
#include "ListAnak.h"
#include "ListKeahlian.h"

#define next(P) P->next
#define Lpegawai(P) P->Lpegawai
#define Lanak(P) P->Lanak
#define Lkeahlian(P) P->Lkeahlian

typedef struct elmRelasi *add_relasi;

struct elmRelasi{
    add_pegawai Lpegawai;
    add_Anak Lanak;
    add_Keahlian Lkeahlian;
    add_relasi next;
};

struct ListRelasi{
    add_relasi first;
};

void createListRel(ListRelasi &L);
add_relasi alokasiRel(add_pegawai P, add_Anak Q, add_Keahlian R);
void insertFirstRel(ListRelasi &L, add_relasi P);
void showListRel(ListRelasi L);
add_relasi cariRelasiid(ListRelasi &L, string id);
void deletePrecRel(ListRelasi &L,add_relasi &Prec);
void deleteLastRel(ListRelasi &L, add_relasi &P);
bool cekRelasi(ListRelasi &L,string no );
bool isEmptyRel(ListRelasi LR);



#endif // LISTRELASI_H_INCLUDED
