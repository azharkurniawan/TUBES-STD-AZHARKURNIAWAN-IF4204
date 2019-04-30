#include "ListKeahlian.h"

add_Keahlian AlokasiKeahlian(string name, string peng){
    add_Keahlian P;
    P = new ElmKeahlian;
    info(P).nama_keahlian = name;
    info(P).lamapeng = peng;
    next(P) = NULL;
    return P;
}

void dealokasi(add_Keahlian &P){
    delete P;
}

void createListKeahlian(ListKeahlian &L){
    L.first = NULL;
}

add_Keahlian cariElmKeahlian(ListKeahlian L, string x){
    add_Keahlian P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && info(P).nama_keahlian!= x){
            P = next(P);
        }
    }
    return P;
}

void ShowListKeahlian(ListKeahlian &L){
    if (L.first==NULL){
        cout<<"List Kosong...."<<endl;
    }else{
        int i = 1;
        add_Keahlian P = L.first;
        while (P!=NULL){
            cout<<"("<<i<<")"<<"KEAHLIAN: "<<info(P).nama_keahlian<<endl;
            cout<<"  PENGALAMAN    || "<<info(P).lamapeng   <<"||"<<endl;
            P = next(P);
            i++;
        }
    }
}


void insertLastKeahlian(ListKeahlian &L, add_Keahlian P){
    if (L.first==NULL){
        L.first = P;
    }else{
        add_Keahlian Q = L.first;
        while (next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;

    }
}


void deleteLastKeahlian(ListKeahlian &L, add_Keahlian &P){
    if (L.first==NULL){

    }else if(next(L.first)==NULL){
        P = L.first;
        L.first = NULL;
    }else{
        add_Keahlian Q;
        P = L.first;
        while (next(P)!=NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }
}


void deletePrecKeahlian(ListKeahlian &L,add_Keahlian &Prec){
    if (L.first==NULL){
      //  cout<<"List Kosong"<<endl;
    }else if (next(L.first)==NULL && Prec==NULL){
      //  cout<<"data tidak ditemukan"<<endl;
    }else if (next(Prec)==NULL){
        add_Keahlian P = L.first;
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
        add_Keahlian P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = next(Prec);
        next(Prec) = NULL;
    }
}



bool cekKeahlian(ListKeahlian &L, string x){  //Return true jika tidak ada duplikat
    if (L.first==NULL){
        return true;
    }else{
        add_Keahlian P = L.first;
        while (P!=NULL && info(P).nama_keahlian!=x){
            P = next(P);
        }
        if (P==NULL){
            return true;
        }else{
            return false;
        }
    }
}



bool isEmpty(ListKeahlian L){
    return (L.first==NULL);
}
