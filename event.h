#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;

typedef struct elementEvent *addressEvent;
typedef struct elementPeserta *addressPeserta;

struct tanggal {
    int tgl, tahun, bulan;
};
struct event {
    string namaEvent, jenisEvent, tempatEvent;
    tanggal tanggalEvent;
    int quota, nPeserta;
};
struct peserta {
    string namaPeserta, emailPeserta, jenisTiket;
    int noPeserta, noTelepon, noTempatDuduk;
    bool checkIn;
};
struct elementEvent {
    event info;
    addressEvent next, prev;
    addressPeserta nextPeserta;
};
struct elementPeserta {
    peserta info;
    addressPeserta next, prev;
};


struct list {
    addressEvent first;
    addressPeserta firstPeserta;
};


void createList(list &List);
void showDataEventAll(list List);
void registrasiPeserta(list &List, addressPeserta &P);
addressPeserta newElementPeserta(peserta info);
void insertLastPeserta(list &List, addressPeserta P);
void tambahEvent(list &List);
addressEvent newElementEvent(event info);
void insertLastEvent(list &List, addressEvent E);
void findPeserta(list List, string nama, addressPeserta &P);
void registrasiEvent(list &List, addressEvent &E, addressPeserta &P);
addressEvent findEvent(list &List, string namaEvent);
void insertLastPesertaEvent(addressEvent &E, addressPeserta &P);
void hapusEvent(list &List, string namaEvent);
void deleteFirstEvent(list &List);
void deleteLastEvent(list &List);
void deleteAfterEvent(addressEvent &prec, addressEvent &E);
int jumlahPeserta(addressEvent E);
void showEventTersedia(list List);
void cancelRegistrasiEvent(list &List, addressPeserta P);
void deleteFirstPeserta(addressEvent &E);
void deleteLastPeserta(addressEvent &E);
void deleteAfterPeserta(addressPeserta &prec, addressPeserta &P);
void deletePeserta(addressEvent &E, addressPeserta &P);
bool cekKursi(addressEvent E, int i);
int menu(list &List, addressPeserta P);
void loginMenu(list &List, addressPeserta &P, bool &loggedIn);

#endif /* EVENT_H */

/**
    *TODO: hapus registrasi
    *TODO: Masuk Event (checkIn)
    *TODO: Mencari peserta di sebuah event
    *TODO: akhiri event
    *TODO: Batalkan registrasi event
 **/