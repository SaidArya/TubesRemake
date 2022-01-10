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
				cout << "1. Tambah Event" << endl;
				cout << "2. registasi event" << endl;
				cout << "3. hapus event" << endl;
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