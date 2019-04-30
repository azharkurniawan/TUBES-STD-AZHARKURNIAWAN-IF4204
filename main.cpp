#include "ListPegawai.h"
#include "ListAnak.h"
#include "ListKeahlian.h"
#include "ListRelasi.h"

#include <stdlib.h>
#include <stdio.h>

void mainmenu();

ListPegawai LP;
add_pegawai Dp;
pegawai peg;
bool unavailable;
string id,nam,jab,um,gaj,idd;
int menu;
char out,pilih;
//////////////////////////////////////
ListAnak LA;
add_Anak Da;
bool unavailable2;
string namaa,gend,tang,bul,tah,umurr;
/////////////////////////////////////
ListKeahlian LK;
add_Keahlian Dk;
bool unavailable3;
string namke,lamp;
////////////////////////////////////
string nope,namaan,namkee;
bool unavailable4;
///////////////////////////////////
ListRelasi LR;



void menuPegawai(){
        cout<<endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[            MENU PEGAWAI            ]]" << endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[ 1. Tambah Data Pegawai             ]]" <<endl;
        cout <<"[[ 2. Hapus Data Pegawai              ]]" <<endl;
        cout <<"[[ 3. Cari Data Pegawai               ]]" <<endl;
        cout <<"[[ 4. View Data Pegawai               ]]" <<endl;
        cout <<"[[ 5. Update ID Pegawai               ]]" <<endl;
        cout <<"[[ 0. Keluar                          ]]" <<endl;
        cout <<"[[====================================]]" <<endl;
        cout<<"  Pilih Menu: ";
        cin>>menu;
        if (menu==1){
            system("cls");
            cout<<"=================="<<endl;
            cout<<"Input Data Pegawai "<<endl;
            cout<<"=================="<<endl;
            cout<<"Input '.' Pada No_pegawai jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"No Pegawai: ";
            cin>>id;
            while (id!="."){
            unavailable = cekPegawai(LP,id);
            if (unavailable){
                cout<<"Nama: ";
                cin>>nam;
                cout<<"Jabatan: ";
                cin>>jab;
                cout<<"Umur: ";
                cin>>um;
                cout<<"Gaji: ";
                cin>>gaj;
                insertLastPegawai(LP,AlokasiPegawai(id,nam,jab,um,gaj));
            }else{
                cout<<"Data sudah ada, input kembali"<<endl;
                system("PAUSE");
                cout<<endl;
            }
            cout<<endl;
            cout<<"Input '.' Pada No Pegawai jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"No Pegawai: ";
            cin>>id;
            }
            system("cls");
            menuPegawai();
       }else if (menu==2){
            string id;
            cout<<"    Delete Pegawai   "<<endl;
            cout<<endl;
            cout<<"Masukkan no pegawai: ";
            cin>>id;
            add_pegawai cari = cariElmPegawai(LP,id);
            if (isEmpty(LP)&&cari==NULL){
                cout<<"List Kosong"<<endl;
                system("pause");
            }else{
                if (cari==NULL){
                    cout<<"Nomor Pegawai Tidak Ditemukan"<<endl;
                    system("PAUSE");
                    cout<<endl;
                }else if (next(cari)==NULL){
                    deleteLastPegawai( LP,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }else{
                    deletePrecPegawai(LP,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }
            }
            system("cls");
            menuPegawai();
        }else if (menu==3){
            cout<<"    Cari Pegawai   "<<endl;
            cout<<endl;
            cout<<"Masukkan No pegawai: ";
            cin>>id;
            add_pegawai cari = cariElmPegawai(LP,id);
            if (cari==NULL){
                cout<<"Nomor tidak ditemukan"<<endl;
                system("PAUSE");
                system("cls");
                menuPegawai();
            }else{
                cout<<endl;
                cout<<"Data ditemukan"<<endl;
                cout<<endl;
                cout<<"No Pegawai: "<<info(cari).no_pegawai<<endl;
                cout<<"  NAMA     || "<<info(cari).nama <<" ||"<<endl;
                cout<<"  JABATAN  || "<<info(cari).jabatan <<" ||"<<endl;
                cout<<"  UMUR     || "<<info(cari).umur <<" ||"<<endl;
                cout<<"  GAJI     || "<<info(cari).gaji <<" ||"<<endl;
                system("PAUSE");
                system("cls");
                menuPegawai();
            }
            system("cls");
        }else if (menu==4){
            system("CLS");
            ShowListPegawai(LP);
            system("PAUSE");
            system("cls");
            menuPegawai();
        }else if (menu==5){
            system("cls");
            cout<<"UPDATE DATA "<<endl;
            cout<<endl;
            cout<<"Masukkan No Pegawai:";
            cin>>idd;
            add_pegawai P = cariElmPegawai(LP,idd);
            if (isEmpty(LP)&&P==NULL){
                cout<<"DATA MASIH KOSONG"<<endl;
                system("pause");
                system("cls");
                menuPegawai();
            }else{
                if (P==NULL){
                    cout<<"Nomor Tidak Ditemukan"<<endl;
                    system("pause");
                    system("cls");
                    menuPegawai();
                }else{
                    cout<<endl;
                    cout<<"------------------"<<endl;
                    cout<<"Input Data Baru"<<endl;
                    cout<<endl;
                    cout<<"Nama: ";
                    cin>>nam;
                    cout<<"Jabatan: ";
                    cin>>jab;
                    cout<<"Umur: ";
                    cin>>um;
                    cout<<"Gaji: ";
                    cin>>gaj;
                    info(P).nama = nam;
                    info(P).jabatan = jab;
                    info(P).umur = um;
                    info(P).gaji = gaj;
                    cout<<endl;
                    cout<<"Data Terupdate"<<endl;
                    system("pause");
                    system("cls");
                    menuPegawai();
                }
            }



        }else if (menu==0){
             cout<<"yakin ingin keluar?(y/n): ";
            cin>>out;
            if (out=='y'){
                system("cls");
                mainmenu();
            }else{
                system("cls");
                menuPegawai();
            }
        }


}

void menuAnak(){
        cout<<endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[            MENU Anak               ]]" << endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[ 1. Tambah Data Anak                ]]" <<endl;
        cout <<"[[ 2. Hapus Data Anak                 ]]" <<endl;
        cout <<"[[ 3. Cari Data Anak                  ]]" <<endl;
        cout <<"[[ 4. View Data Anak                  ]]" <<endl;
        cout <<"[[ 5. Update ID Anak                  ]]" <<endl;
        cout <<"[[ 0. Keluar                          ]]" <<endl;
        cout <<"[[====================================]]" <<endl;
        cout<<"  Pilih Menu: ";
        cin>>menu;
        if (menu==1){
            system("cls");
            cout<<"=================="<<endl;
            cout<<"Input Data Anak "<<endl;
            cout<<"=================="<<endl;
            cout<<"Input '.' Pada nama jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"Nama Anak: ";
            cin>>namaa;
            while (namaa!="."){
            unavailable2 = cekAnak(LA,namaa);
            if (unavailable2){
                cout<<"Gender: ";
                cin>>gend;
                cout<<"Tanggal: ";
                cin>>tang;
                cout<<"Bulan: ";
                cin>>bul;
                cout<<"Tahun: ";
                cin>>tah;
                cout<<"umur: ";
                cin>>umurr;
                insertLastAnak(LA,AlokasiAnak(namaa,gend,tang,bul,tah,umurr));
            }else{
                cout<<"Data sudah ada, input kembali"<<endl;
                system("PAUSE");
                cout<<endl;
            }
            cout<<endl;
            cout<<"Input '.' Pada nama jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"Nama Anak: ";
            cin>>namaa;
            }
            system("cls");
            menuAnak();
       }else if (menu==2){
            string id;
            cout<<"    Delete Anak   "<<endl;
            cout<<endl;
            cout<<"Masukkan Nama Anak: ";
            cin>>id;
            add_Anak cari = cariElmAnak(LA,id);
            if (isEmpty(LA)&&cari==NULL){
                cout<<"List Kosong"<<endl;
                system("pause");
            }else{
                if (cari==NULL){
                    cout<<"Anak Tidak Ditemukan"<<endl;
                    system("PAUSE");
                    cout<<endl;
                }else if (next(cari)==NULL){
                    deleteLastAnak( LA,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }else{
                    deletePrecAnak(LA,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }
            }
            system("cls");
            menuAnak();
        }else if (menu==3){
            cout<<"    Cari Anak   "<<endl;
            cout<<endl;
            cout<<"Masukkan Nama Anak: ";
            cin>>id;
            add_Anak cari = cariElmAnak(LA,id);
            if (cari==NULL){
                cout<<"Anak tidak ditemukan"<<endl;
                system("PAUSE");
                system("cls");
                menuAnak();
            }else{
                cout<<endl;
                cout<<"Data ditemukan"<<endl;
                cout<<endl;
                cout<<"Nama Anak: "<<info(cari).nama<<endl;
                cout<<"  GENDER    || "<<info(cari).gender <<" ||"<<endl;
                cout<<"  TANGGAL   || "<<info(cari).tanggal <<" ||"<<endl;
                cout<<"  BULAN     || "<<info(cari).bulan <<" ||"<<endl;
                cout<<"  TAHUN     || "<<info(cari).tahun <<" ||"<<endl;
                cout<<"  UMUR      || "<<info(cari).umur<<" ||"<<endl;
                system("PAUSE");
                system("cls");
                menuAnak();
            }
            system("cls");
        }else if (menu==4){
            system("CLS");
            ShowListAnak(LA);
            system("PAUSE");
            system("cls");
            menuAnak();
        }else if (menu==5){
            system("cls");
            cout<<"UPDATE DATA "<<endl;
            cout<<endl;
            cout<<"Masukkan Nama Anak:";
            cin>>namaa;
            add_Anak P = cariElmAnak(LA,namaa);
            if (isEmpty(LA)&&P==NULL){
                cout<<"DATA MASIH KOSONG"<<endl;
                system("pause");
                system("cls");
                menuAnak();
            }else{
                if (P==NULL){
                    cout<<"Anak Tidak Ditemukan"<<endl;
                    system("pause");
                    system("cls");
                    menuAnak();
                }else{
                    cout<<endl;
                    cout<<"------------------"<<endl;
                    cout<<"Input Data Baru"<<endl;
                    cout<<endl;
                    cout<<"Tanggal: ";
                    cin>>tang;
                    cout<<"Bulan: ";
                    cin>>bul;
                    cout<<"Tahun: ";
                    cin>>tah;
                    cout<<"Umur: ";
                    cin>>um;
                    info(P).tanggal = tang;
                    info(P).bulan = bul;
                    info(P).tahun = tah;
                    info(P).umur = um;
                    cout<<endl;
                    cout<<"Data Terupdate"<<endl;
                    system("pause");
                    system("cls");
                    menuAnak();
                }
            }



        }else if (menu==0){
             cout<<"yakin ingin keluar?(y/n): ";
            cin>>out;
            if (out=='y'){
                system("cls");
                mainmenu();
            }else{
                system("cls");
                menuAnak();
            }
        }


}

void menuKeahlian(){
        cout<<endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[            MENU KEAHLIAN           ]]" << endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[ 1. Tambah Data Keahlian            ]]" <<endl;
        cout <<"[[ 2. Hapus Data Keahlian             ]]" <<endl;
        cout <<"[[ 3. Cari Data Keahlian              ]]" <<endl;
        cout <<"[[ 4. View Data Keahlian              ]]" <<endl;
        cout <<"[[ 5. Update ID Keahlian              ]]" <<endl;
        cout <<"[[ 0. Keluar                          ]]" <<endl;
        cout <<"[[====================================]]" <<endl;
        cout<<"  Pilih Menu: ";
        cin>>menu;
        if (menu==1){
            system("cls");
            cout<<"=================="<<endl;
            cout<<"Input Data Keahlian "<<endl;
            cout<<"=================="<<endl;
            cout<<"Input '.' Pada nama jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"Nama Keahlian: ";
            cin>>namke;
            while (namke!="."){
            unavailable3 = cekKeahlian(LK,namke);
            if (unavailable3){
                cout<<"Lama Pengalaman: ";
                cin>>lamp;
                insertLastKeahlian(LK,AlokasiKeahlian(namke,lamp));
            }else{
                cout<<"Data sudah ada, input kembali"<<endl;
                system("PAUSE");
                cout<<endl;
            }
            cout<<endl;
            cout<<"Input '.' Pada Keahlian jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"Nama Keahlian: ";
            cin>>namke;
            }
            system("cls");
            menuKeahlian();
       }else if (menu==2){
            string id;
            cout<<"    Delete Keahlian   "<<endl;
            cout<<endl;
            cout<<"Masukkan Keahlian: ";
            cin>>id;
            add_Keahlian cari = cariElmKeahlian(LK,id);
            if (isEmpty(LK)&&cari==NULL){
                cout<<"List Kosong"<<endl;
                system("pause");
            }else{
                if (cari==NULL){
                    cout<<"Keahlian Tidak Ditemukan"<<endl;
                    system("PAUSE");
                    cout<<endl;
                }else if (next(cari)==NULL){
                    deleteLastKeahlian(LK,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }else{
                    deletePrecKeahlian(LK,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }
            }
            system("cls");
            menuKeahlian();
        }else if (menu==3){
            cout<<"    Cari Keahlian   "<<endl;
            cout<<endl;
            cout<<"Masukkan Nama Keahlian: ";
            cin>>id;
            add_Keahlian cari = cariElmKeahlian(LK,id);
            if (cari==NULL){
                cout<<"Keahlian tidak ditemukan"<<endl;
                system("PAUSE");
                system("cls");
                menuKeahlian();
            }else{
                cout<<endl;
                cout<<"Data ditemukan"<<endl;
                cout<<endl;
                cout<<"Nama Keahlian: "<<info(cari).nama_keahlian<<endl;
                cout<<"  LAMA PENGALAMAN  || "<<info(cari).lamapeng <<" ||"<<endl;
                system("PAUSE");
                system("cls");
                menuKeahlian();
            }
            system("cls");
        }else if (menu==4){
            system("CLS");
            ShowListKeahlian(LK);
            system("PAUSE");
            system("cls");
            menuKeahlian();
        }else if (menu==5){
            system("cls");
            cout<<"UPDATE DATA "<<endl;
            cout<<endl;
            cout<<"Masukkan Nama Keahlian:";
            cin>>namke;
            add_Keahlian P = cariElmKeahlian(LK,namke);
            if (isEmpty(LK)&&P==NULL){
                cout<<"DATA MASIH KOSONG"<<endl;
                system("pause");
                system("cls");
                menuKeahlian();
            }else{
                if (P==NULL){
                    cout<<"Keahlian Tidak Ditemukan"<<endl;
                    system("pause");
                    system("cls");
                    menuKeahlian();
                }else{
                    cout<<endl;
                    cout<<"------------------"<<endl;
                    cout<<"Input Data Baru"<<endl;
                    cout<<endl;
                    cout<<"Lama Pengalaman: ";
                    cin>>lamp;
                    info(P).lamapeng = lamp;
                    cout<<endl;
                    cout<<"Data Terupdate"<<endl;
                    system("pause");
                    system("cls");
                    menuKeahlian();
                }
            }



        }else if (menu==0){
             cout<<"yakin ingin keluar?(y/n): ";
            cin>>out;
            if (out=='y'){
                system("cls");
                mainmenu();
            }else{
                system("cls");
                menuKeahlian();
            }
        }


}

void menurelasi(){
        cout<<endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[            MENU RELASI             ]]" << endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[ 1. Tambah Relasi                   ]]" <<endl;
        cout <<"[[ 2. Hapus Relasi                    ]]" <<endl;
        cout <<"[[ 3. View All Relasi                 ]]" <<endl;
        cout <<"[[ 4. View Data Pegawai dan Anak      ]]" <<endl;
        cout <<"[[ 0. Keluar                          ]]" <<endl;
        cout <<"[[====================================]]" <<endl;
        cout<<"  Pilih Menu: ";
        cin>>menu;
        if (menu==1){
            system("cls");
            cout<<"===================="<<endl;
            cout<<"   SAMBUNG RELASI   "<<endl;
            cout<<"===================="<<endl;
            cout<<endl;
            cout<<"Masukkan No Pegawai: ";
            cin>>nope;
            cout<<"Masukkan Nama Anak: ";
            cin>>namaan;
            cout<<"Masukkan Keahlian: ";
            cin>>namkee;
            add_pegawai pegg = cariElmPegawai(LP,nope);
            add_Anak anakk = cariElmAnak(LA,namaan);
            add_Keahlian ahli = cariElmKeahlian(LK,namkee);
            unavailable4 = cekRelasi(LR,nope);
            if (unavailable4 && pegg!=NULL && anakk!=NULL && ahli!=NULL){
                insertFirstRel(LR,alokasiRel(pegg,anakk,ahli));
                cout<<"Data Terelasi"<<endl;
                system("PAUSE");
            }else{
                cout<<"GAGAL"<<endl;
                system("PAUSE");
            }
            system("cls");
            menurelasi();
        }else if(menu==2){
            cout<<"Hapus Relasi"<<endl;
            cout<<endl;
            cout<<"Masukkan No Pegawai: ";
            cin>>idd;
            add_relasi P = cariRelasiid(LR,idd);
            if (P==NULL){
                cout<<"Tidak ada relasi"<<endl;
                system("PAUSE");
            }else if (next(P)==NULL){
                deleteLastRel(LR,P);
                cout<<"Relasi terhapus"<<endl;
                system("PAUSE");
            }else{
                deletePrecRel(LR,P);
                cout<<"Relasi terhapus"<<endl;
                system("PAUSE");
            }
            system("cls");
            menurelasi();
        }else if (menu==3){
            system("CLS");
            showListRel(LR);
            system("PAUSE");
            system("cls");
            menurelasi();
        }else if (menu==4){
            system("cls");
            cout<<"DATA PEGAWAI"<<endl;
            ShowListPegawai(LP);
            cout<<"============================"<<endl;
            cout<<endl;
            cout<<"DATA ANAK"<<endl;
            ShowListAnak(LA);
            cout<<endl;
            cout<<"============================"<<endl;
            cout<<"DATA KEAHLIAN"<<endl;
            cout<<endl;
            ShowListKeahlian(LK);
            cout<<endl;
            system("pause");
            system("cls");
            menurelasi();
        }else if (menu==0){
            cout<<"yakin ingin keluar?(y/n): ";
            cin>>out;
            if (out=='y'){
                system("cls");
                mainmenu();
            }else{
                system("cls");
                menurelasi();
            }
        }
}



void mainmenu(){
    while (out!='0'){
        cout<<"----------"<<endl;
        cout<<"PILIH MENU"<<endl;
        cout<<"----------"<<endl;
        cout<<"1. Menu Pegawai"<<endl;
        cout<<"2. Menu Anak"<<endl;
        cout<<"3. Menu Keahlian"<<endl;
        cout<<"4. Relasi"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Pilih Menu: ";
        cin>>pilih;
        if (pilih=='1'){
            system("cls");
            menuPegawai();
        }else if (pilih=='2'){
            system("cls");
            menuAnak();
        }else if (pilih=='3'){
            system("cls");
            menuKeahlian();
        }else if (pilih=='4'){
            system("cls");
            menurelasi();
        }else if (pilih=='5'){
            cout<<"exiting program... click 0"<<endl;
            cin>>out;
        }
    }
}


int main()
{
    createListPegawai(LP);
    createListAnak(LA);
    createListKeahlian(LK);
    mainmenu();

}
