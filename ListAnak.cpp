#include "ListAnak.h"

add_Anak AlokasiAnak(string name, string gen, string tgl, string bln, string thn, string age){
    add_Anak P;
    P = new ElmAnak;
    info(P).nama = name;
    info(P).gender = gen;
    info(P).tanggal = tgl;
    info(P).bulan = bln;
    info(P).tahun = thn;
    info(P).umur = age;
    next(P) = NULL;
    return P;
}

void dealokasi(add_Anak &P){
    delete P;
}

void createListAnak(ListAnak &L){
    L.first = NULL;
}

add_Anak cariElmAnak(ListAnak L, string x){
    add_Anak P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && info(P).nama!= x){
            P = next(P);
        }
    }
    return P;
}

void ShowListAnak(ListAnak &L){
    if (L.first==NULL){
        cout<<"List Kosong...."<<endl;
    }else{
        int i = 1;
        add_Anak P = L.first;
        while (P!=NULL){
            cout<<"("<<i<<")"<<"NAMA: "<<info(P).nama<<endl;
            cout<<"  GENDER    || "<<info(P).gender   <<"||"<<endl;
            cout<<"  TANGGAL   || "<<info(P).tanggal <<" ||"<<endl;
            cout<<"  BULAN     || "<<info(P).bulan    <<"||"<<endl;
            cout<<"  TAHUN     || "<<info(P).tahun    <<"||"<<endl;
            cout<<"  UMUR      || "<<info(P).umur    <<" ||"<<endl;
            P = next(P);
            i++;
        }
    }
}


void insertLastAnak(ListAnak &L, add_Anak P){
    if (L.first==NULL){
        L.first = P;
    }else{
        add_Anak Q = L.first;
        while (next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;

    }
}


void deleteLastAnak(ListAnak &L, add_Anak &P){
    if (L.first==NULL){

    }else if(next(L.first)==NULL){
        P = L.first;
        L.first = NULL;
    }else{
        add_Anak Q;
        P = L.first;
        while (next(P)!=NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }
}


void deletePrecAnak(ListAnak &L,add_Anak &Prec){
    if (L.first==NULL){
      //  cout<<"List Kosong"<<endl;
    }else if (next(L.first)==NULL && Prec==NULL){
      //  cout<<"data tidak ditemukan"<<endl;
    }else if (next(Prec)==NULL){
        add_Anak P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = NULL;
    }else if (Prec==L.first){
        L.first = next(Prec);
        next(Prec) = NULL;
    }else if (Prec==L.first&&next(L.first)==NULL){
        L.first = NULL;
    }else{
        add_Anak P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = next(Prec);
        next(Prec) = NULL;
    }
}



bool cekAnak(ListAnak &L, string x){  //Return true jika tidak ada duplikat
    if (L.first==NULL){
        return true;
    }else{
        add_Anak P = L.first;
        while (P!=NULL && info(P).nama!=x){
            P = next(P);
        }
        if (P==NULL){
            return true;
        }else{
            return false;
        }
    }
}



bool isEmpty(ListAnak L){
    return (L.first==NULL);
}
