#include "ListRelasi.h"

void createListRel(ListRelasi &L){
    L.first = NULL;
}

add_relasi alokasiRel(add_pegawai P, add_Anak Q, add_Keahlian R){
    add_relasi E = new elmRelasi;
    Lpegawai(E) = P;
    Lanak(E) = Q;
    Lkeahlian(E) = R;
    next(E) = NULL;
    return E;

}

void insertFirstRel(ListRelasi &L, add_relasi P){
    next(P) = L.first;
    L.first = P;

}

void showListRel(ListRelasi L){
    if (L.first != NULL) {
        int i = 1;
        add_relasi P = L.first;
        while(P != NULL) {
            cout<<endl;
            cout<<"    INFO RELASI   "<<endl;
            cout<<"("<<i<<")"<<"NO_PEGAWAI: "<<info(Lpegawai(P)).no_pegawai<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"  NAMA         : "<<info(Lpegawai(P)).nama <<" ||"<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"  KEAHLIAN     : "<<info(Lkeahlian(P)).nama_keahlian<<endl;
            cout<<"  PENGALAMAN   : "<<info(Lkeahlian(P)).lamapeng <<" <<"<<endl;
            cout<<"  NAMA         : "<<info(Lanak(P)).nama <<" <<"<<endl;
            cout<<"  GENDER       : "<<info(Lanak(P)).gender <<" <<"<<endl;
            cout<<"  UMUR         : "<<info(Lanak(P)).umur <<" <<"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            P = next(P);
            i++;
        }
    }else{
        cout<<"DATA KOSONG"<<endl;
    }
}

add_relasi cariRelasiid(ListRelasi &L, string id){ //mencari relasi melalui id daerah
    add_relasi P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && id!=info(Lpegawai(P)).no_pegawai){
            P = next(P);
        }
    }
    return P;

}


void deletePrecRel(ListRelasi &L,add_relasi &Prec){
    if (L.first==NULL){
      //  cout<<"List Kosong"<<endl;
    }else if (next(L.first)==NULL && Prec==NULL){
      //  cout<<"data tidak ditemukan"<<endl;
    }else if (next(Prec)==NULL){
        add_relasi P = L.first;
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
        add_relasi P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = next(Prec);
        next(Prec) = NULL;
    }

}

void deleteLastRel(ListRelasi &L, add_relasi &P){
    if (L.first==NULL){

    }else if(next(L.first)==NULL){
        P = L.first;
        L.first = NULL;
    }else{
        add_relasi Q;
        P = L.first;
        while (next(P)!=NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }

}

bool cekRelasi(ListRelasi &L,string no ){
    if (L.first==NULL){
        return true;
    }else{
        add_relasi P = L.first;
        while (P!=NULL &&info(Lpegawai(P)).no_pegawai!=no){
            P = next(P);
        }
        if (P==NULL){
            return true;
        }else{
            return false;
        }
    }
}


bool isEmptyRel(ListRelasi LR){
    return (LR.first==NULL);
}
