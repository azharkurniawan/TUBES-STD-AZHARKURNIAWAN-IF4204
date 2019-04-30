#include "ListPegawai.h"

add_pegawai AlokasiPegawai(string id, string name, string jab, string age, string sal){
    add_pegawai P;
    P = new ElmPegawai;
    info(P).no_pegawai = id;
    info(P).nama = name;
    info(P).jabatan = jab;
    info(P).umur = age;
    info(P).gaji = sal;
    next(P) = NULL;
    return P;
}

void dealokasi(add_pegawai &P){
    delete P;
}

void createListPegawai(ListPegawai &L){
    L.first = NULL;
}

add_pegawai cariElmPegawai(ListPegawai L, string x){
    add_pegawai P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && info(P).no_pegawai!= x){
            P = next(P);
        }
    }
    return P;
}

void ShowListPegawai(ListPegawai &L){
    if (L.first==NULL){
        cout<<"List Kosong, tidak ada pegawai"<<endl;
    }else{
        int i = 1;
        add_pegawai P = L.first;
        while (P!=NULL){
            cout<<"("<<i<<")"<<"NO_PEGAWAI: "<<info(P).no_pegawai<<endl;
            cout<<"  NAMA      || "<<info(P).nama    <<" ||"<<endl;
            cout<<"  JABATAN   || "<<info(P).jabatan <<" ||"<<endl;
            cout<<"  UMUR      || "<<info(P).umur    <<" ||"<<endl;
            cout<<"  GAJI      || "<<info(P).gaji    <<" ||"<<endl;
            P = next(P);
            i++;
        }
    }
}


void insertLastPegawai(ListPegawai &L, add_pegawai P){
    if (L.first==NULL){
        L.first = P;
    }else{
        add_pegawai Q = L.first;
        while (next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;

    }
}


void deleteLastPegawai(ListPegawai &L, add_pegawai &P){
    if (L.first==NULL){

    }else if(next(L.first)==NULL){
        P = L.first;
        L.first = NULL;
    }else{
        add_pegawai Q;
        P = L.first;
        while (next(P)!=NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }
}


void deletePrecPegawai(ListPegawai &L,add_pegawai &Prec){
    if (L.first==NULL){
      //  cout<<"List Kosong"<<endl;
    }else if (next(L.first)==NULL && Prec==NULL){
      //  cout<<"data tidak ditemukan"<<endl;
    }else if (next(Prec)==NULL){
        add_pegawai P = L.first;
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
        add_pegawai P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = next(Prec);
        next(Prec) = NULL;
    }
}



bool cekPegawai(ListPegawai &L, string x){  //Return true jika tidak ada duplikat
    if (L.first==NULL){
        return true;
    }else{
        add_pegawai P = L.first;
        while (P!=NULL && info(P).no_pegawai!=x){
            P = next(P);
        }
        if (P==NULL){
            return true;
        }else{
            return false;
        }
    }
}



bool isEmpty(ListPegawai L){
    return (L.first==NULL);
}
