#include "event.h"
#include <ctime>

int main(){
	list List;
	addressPeserta P = NULL;
	bool login = false;
	int selectMenu = 0;
	srand(time(0));

	createList(List);

	while (selectMenu != -1 && (P == NULL && !login)) {
		loginMenu(List, P, login);
			while (login == true) {
				cout << "\n1. Tambah Event" << endl;
				cout << "2. registasi event" << endl;
				cout << "3. hapus event" << endl;
				cout << "4. tampilkan event yang masih tersedia" << endl;
				cout << "5. Batalkan registrasi event" << endl;
				cout << "6. Check In Event" << endl;
				cout << "7. Tutup registasi event" << endl;
				cout << "8. Tampilkan tiket" << endl;
				cout << "9. tampilkan semua data event" << endl;
				cout << "10. menampilkan semua event dan jumlah peserta yang sudah checkin" << endl;
				cout << "11. cari peserta di event" << endl;
				cout << "0. logout" << endl;
				cout << "Input : "; selectMenu = menu(List, P);
				if (selectMenu == 0) {
					P = NULL;
					login = false;
					break;
				}
			}
	}
	return 0;
}