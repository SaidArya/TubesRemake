#include "event.h"
#include "conio.h"

void createList(list &List) {
    List.first = NULL;
    List.firstPeserta = NULL;
}

void showDataEventAll(list List) {
    char select;
    cout << "Data event" << endl;
    if (List.first == NULL) {
        cout << "Kosong" << endl;
    } else {
        cout << "Tampilkan peserta ? (Y/N) : "; select = getche();
        addressEvent E = List.first;
        while (E != NULL) {
            cout << endl;
            cout << "Nama event  : " << E->info.namaEvent << endl;
            cout << "Jenis event : " << E->info.jenisEvent << endl;
            cout << "Tempat event: " << E->info.tempatEvent << endl;
            cout << "tanggalEvent: " << E->info.tanggalEvent.tgl << " " << E->info.tanggalEvent.bulan << " " << E->info.tanggalEvent.tahun << endl;
            if (tolower(select) == 'y'){
                cout << "Peserta Event" << endl << endl;
                addressPeserta P = E->nextPeserta;
                if (P == NULL) {
                    cout << "Kosong" << endl;
                } else {
                    while (P != NULL) {
                    cout << "Nama peserta : " << P->info.namaPeserta << endl;
                    cout << "Email peserta: " << P->info.emailPeserta << endl;
                    cout << "Jenis peserta: " << P->info.jenisTiket << endl;
                    cout << "No. Telepon  : " << P->info.noTelepon << endl;
                    cout << "No. peserta  : " << P->info.noPeserta << endl;
                    cout << "No. Duduk    : " << P->info.noTempatDuduk << endl;
                    cout << "Checkin      : ";
                    if (P->info.checkIn == true) {
                        cout << "Sudah check in" << endl << endl;
                    } else {
                        cout << "Belum check in" << endl << endl;
                    }
                    P = P->next;
                    }
                }
            }
            E = E->next;
        }
    }
    cout << "Data peserta" << endl;
    if (List.firstPeserta == NULL) {
        cout << "Kosong" << endl;
    } else {
        addressPeserta P = List.firstPeserta;
        while (P != NULL) {
            cout << P->info.namaPeserta << endl;
            P = P->next;
        }
    }
}

addressPeserta newElementPeserta(peserta info) {
    addressPeserta P = new elementPeserta;
    P->info = info;
    P->next = NULL;
    return P;
}

void insertLastPeserta(list &List, addressPeserta P) {
    addressPeserta Q = List.firstPeserta;
    if (List.firstPeserta == NULL) {
        List.firstPeserta = P;
    } else {
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void registrasiPeserta(list &List, addressPeserta &P) {
    peserta Peserta;
    char ulang = 'n';
    while (tolower(ulang) != 'y') {
        cin.ignore(1000, '\n');
        cout << "\nNama  : "; getline(cin, Peserta.namaPeserta);
        cout << "Email : "; cin >> Peserta.emailPeserta;
        cout << "No. HP: "; cin >> Peserta.noTelepon;
        cout << "\n Data sudah benar (Y/N) : "; ulang = getche();
        if (tolower(ulang) == 'y') {
            P = newElementPeserta(Peserta);
            insertLastPeserta(List, P);
        }
    }
}

addressEvent newElementEvent(event info) {
    addressEvent E = new elementEvent;
    E->info = info;
    E->next = NULL;
    E->nextPeserta = NULL;
    return E;
}

void insertLastEvent(list &List, addressEvent E) {
    if (List.first == NULL) {
        List.first = E;
    } else {
        addressEvent P = List.first;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = E;
        E->prev = P;
    }
}

void tambahEvent(list &List) {
    event Event;
    addressEvent E;
    int maxTgl = 0;
    char ulang = 'n';
    while (tolower(ulang) != 'y') {
        cin.ignore(1000, '\n');
        cout << "\nNama Event    : "; getline(cin, Event.namaEvent);
        cout << "Jenis Event   : "; getline(cin, Event.jenisEvent);
        cout << "Tempat Event  : "; getline(cin, Event.tempatEvent);
        cout << "Tahun Event   : "; cin >> Event.tanggalEvent.tahun;
        cout << "Bulan Event   : "; cin >> Event.tanggalEvent.bulan;

        while (Event.tanggalEvent.bulan < 1 || Event.tanggalEvent.bulan > 12) {
            cout << "Input tidak valid" << endl;
            cout << "Bulan Event   : "; cin >> Event.tanggalEvent.bulan;
        }

        if (Event.tanggalEvent.bulan == 1 || Event.tanggalEvent.bulan == 3 || Event.tanggalEvent.bulan == 5|| Event.tanggalEvent.bulan == 7
        || Event.tanggalEvent.bulan == 8 || Event.tanggalEvent.bulan == 10 || Event.tanggalEvent.bulan == 12) {
            maxTgl = 31;
        } else if (Event.tanggalEvent.bulan == 4 || Event.tanggalEvent.bulan == 6 || Event.tanggalEvent.bulan == 9 || Event.tanggalEvent.bulan == 11) {
            maxTgl = 30;
        } else {
            if ((Event.tanggalEvent.tahun % 4) == 0) {
                maxTgl = 29;
            } else {
                maxTgl = 28;
            }
        }

        cout << "Tanggal Event : "; cin >> Event.tanggalEvent.tgl;

        while (Event.tanggalEvent.tgl < 1 ||Event.tanggalEvent.tgl > maxTgl) {
            cout << "Input tidak valid" << endl;
            cout << "Tanggal Event : "; cin >> Event.tanggalEvent.tgl;
        }
        
        cout << "Quota Event   : "; cin >> Event.quota;
        
        cout << "\n Data sudah benar (Y/N) : "; ulang = getche();
        if (ulang == 'y') {
            E = newElementEvent(Event);
            insertLastEvent(List, E);
        }
        
    }
    cout << endl;
}

int menu(list &List, addressPeserta P) {
    int iMenu = 0;
    string namaEvent;
    addressEvent E;
    cin >> iMenu;
    switch (iMenu) {
        case 1:
            tambahEvent(List);
            break;
        case 2:
            showEventTersedia(List);
            cin.ignore(1000, '\n');
            cout << "\nNama event : "; getline(cin, namaEvent);
            E = findEvent(List, namaEvent);
            if (E != NULL) {
                registrasiEvent(List, E, P);
            } else {
                cout << "Event tidak ditemukan" << endl;
            }
            break;
        case 3: 
            cin.ignore(1000, '\n');
            cout << "Nama event : "; getline(cin, namaEvent);
            E = findEvent(List, namaEvent);
            if (E != NULL) {
                hapusEvent(List, namaEvent);
            } else {
                cout << "Event tidak ditemukan" << endl;
            }
            break;
        case 4: 
            showEventTersedia(List);
            break;
        case 5: 
            cancelRegistrasiEvent(List, P);
            break;
        case 6: 
            E = List.first;
            while (E != NULL) {
                addressPeserta Q = E->nextPeserta;
                while (Q != NULL) {
                    if (Q->info.namaPeserta == P->info.namaPeserta) {
                        cout << "Nama Event     : " << E->info.namaEvent << endl;
                        cout << "Tanggal Event  : " << E->info.tanggalEvent.tgl << " " << E->info.tanggalEvent.bulan << " " << E->info.tanggalEvent.tahun << endl << endl;
                        cout << "Status check in: ";
                        if (Q->info.checkIn == true) {
                            cout << "Sudah check in" << endl << endl;
                        } else {
                            cout << "Belum check in" << endl << endl;
                        }
                        break;
                        }
                    Q = Q->next;
                }
                E = E->next;
            }
            cin.ignore(1000, '\n');
            cout << "Nama event : "; getline(cin, namaEvent);
            checkInStatus(List, P, namaEvent);
            break;
        case 9:
            showDataEventAll(List);
            break;
    }
    return iMenu;
}

addressEvent findEvent(list &List, string namaEvent) {
    addressEvent E = List.first;
    while (E != NULL) {
        if (E->info.namaEvent == namaEvent) {
            break;
        }
        E = E->next;
    }
    return E;
}

void loginMenu(list &List, addressPeserta &P, bool &loggedIn) {
    int iMenu = 0;
    loggedIn = false;
    string nama;
    cout << "1. Login" << endl;
    cout << "2. Registrasi" << endl;
    cout << "Input : "; cin >> iMenu;
    if (iMenu == 1) {
        cin.ignore(1000, '\n');
        cout << "Nama : "; getline(cin, nama);
        findPeserta(List, nama, P);
        if (P != NULL) {
            loggedIn = true;
        }
    } else if (iMenu == 2) {
            registrasiPeserta(List, P);
            loggedIn = true;
    } else if (iMenu == 0) {
        P = NULL;
    }
}

void findPeserta(list List, string nama, addressPeserta &P) {
    P = List.firstPeserta;
    while (P != NULL) {
        if (P->info.namaPeserta == nama) {
            break;
        }
        P = P->next;
    }
}

void registrasiEvent(list &List, addressEvent &E, addressPeserta &P) {
    addressPeserta Q = newElementPeserta(P->info);
    int i = 0;
    cout << "Jenis peserta (reguler/VIP) : "; cin >>Q->info.jenisTiket;
    Q->info.checkIn = false;
    Q->info.noPeserta = (rand() % 1000000) + 1;
    i = (rand() % E->info.quota) + 1;
    if (cekKursi(E, i)) {
        i = (rand() % E->info.quota) + 1;
    }
    Q->info.noTempatDuduk = i;
    Q->info.checkIn = false;
    insertLastPesertaEvent(E, Q);
}
void insertLastPesertaEvent(addressEvent &E, addressPeserta &P) {
    addressPeserta Q = E->nextPeserta;
    if (E->nextPeserta == NULL) {
        E->nextPeserta = P;
    } else {
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void hapusEvent(list &List, string namaEvent) {
    addressEvent E = findEvent(List, namaEvent);
    if (E == List.first) {
        deleteFirstEvent(List);
    } else if (E->next == NULL) {
        deleteLastEvent(List);
    } else {
        addressEvent prec = E->prev;
        deleteAfterEvent(prec, E);
    }
}

void deleteFirstEvent(list &List) {
    if (List.first->next == NULL) {
        List.first = NULL;
    } else {
        List.first = List.first->next;
        List.first->prev = NULL;
    }
}

void deleteLastEvent(list &List) {
    addressEvent E = List.first;
    while (E->next != NULL) {
        E = E->next;
    }
    if (E->next == NULL) {
        E = E->prev;
        E->next = NULL;
    } else {
        List.first = NULL;
    }
}

void deleteAfterEvent(addressEvent &prec, addressEvent &E) {
    prec->next = E->next;
    E->next->prev = prec;
    E->next = NULL;
    E->prev = NULL;
}

int jumlahPeserta(addressEvent E) {
    int nPeserta = 0;
    addressPeserta P = E->nextPeserta;
    while (P != NULL) {
        nPeserta++;
        P = P->next;
    }
    return nPeserta;
}

void showEventTersedia(list List) {
    int i = 0;
    addressEvent E = List.first;
    while (E != NULL) {
        if (jumlahPeserta(E) < E->info.quota) {
            cout << endl;
            cout << "Nama event  : " << E->info.namaEvent << endl;
            cout << "Jenis event : " << E->info.jenisEvent << endl;
            cout << "Tempat event: " << E->info.tempatEvent << endl;
            cout << "tanggalEvent: " << E->info.tanggalEvent.tgl << " " << E->info.tanggalEvent.bulan << " " << E->info.tanggalEvent.tahun << endl;
            cout << "Kuota Maks  : " << E->info.quota << endl;
            cout << "Sisa kursi  : " << (E->info.quota - jumlahPeserta(E)) << endl;
            i++;
        }
        E = E->next;
    }
    if (i == 0) {
        cout << "Kosong" << endl;
    }
}

void cancelRegistrasiEvent(list &List, addressPeserta P) {
    string namaEvent;
    addressEvent E = List.first;
    while (E != NULL) {
        addressPeserta Q = E->nextPeserta;
        while (Q != NULL) {
            if (Q->info.namaPeserta == P->info.namaPeserta) {
                cout << "Nama Event    : " << E->info.namaEvent << endl;
                cout << "Tanggal Event : " << E->info.tanggalEvent.tgl << " " << E->info.tanggalEvent.bulan << " " << E->info.tanggalEvent.tahun << endl << endl;
                break;
            }
            Q = Q->next;
        }
        E = E->next;
    }
    cin.ignore(1000, '\n');
    cout << "\n Masukkan nama event yang ingin dibatalkan : "; getline(cin, namaEvent);
    E = findEvent(List, namaEvent);
            if (E != NULL) {
                deletePeserta(E, P);
            } else {
                cout << "Event tidak ditemukan" << endl;
            }
}

void deletePeserta(addressEvent &E, addressPeserta &P) {
    addressPeserta Q = E->nextPeserta;
    while (Q != NULL) {
        if (Q->info.namaPeserta == P->info.namaPeserta) {
            break;
        }
        Q = Q->next;
    }

    if (Q == E->nextPeserta) {
        deleteFirstPeserta(E);
    } else if (Q->next == NULL) {
        deleteLastPeserta(E);
    } else {
        addressPeserta prec = Q->prev;
        deleteAfterPeserta(prec, P);
    }
}

void deleteFirstPeserta(addressEvent &E) {
    if (E->nextPeserta->next == NULL) {
        E->nextPeserta = NULL;
    } else {
        E->nextPeserta = E->nextPeserta->next;
        E->nextPeserta->prev = NULL;
    }
}

void deleteLastPeserta(addressEvent &E) {
    addressPeserta P = E->nextPeserta;
    while (P->next != NULL) {
        P = P->next;
    }
    if (P->next == NULL) {
        P = P->prev;
        P->next = NULL;
    } else {
        E->nextPeserta = NULL;
    }
}

void deleteAfterPeserta(addressPeserta &prec, addressPeserta &P) {
    prec->next = P->next;
    P->next->prev = prec;
    P->next = NULL;
    P->prev = NULL;
}

bool cekKursi(addressEvent E, int i) {
    bool duplicate = false;
    addressPeserta P = E->nextPeserta;
    while (P != NULL) {
        if (i == P->info.noTempatDuduk) {
            duplicate = true;
        }
        P = P->next;
    }
    return duplicate;
}

void checkInStatus(list &List, addressPeserta P, string namaEvent) {
    addressEvent E = findEvent(List, namaEvent);
    if (E != NULL) {
        addressPeserta Q = E->nextPeserta;
        while (Q != NULL) {
            if (Q->info.namaPeserta == P->info.namaPeserta) {
                Q->info.checkIn = true;
                break;
            }
            Q = Q->next;
        }
    } else {
        cout << "Event tidak ditemukan" << endl;
    }
}