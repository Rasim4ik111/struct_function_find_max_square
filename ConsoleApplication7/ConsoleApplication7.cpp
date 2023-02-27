#include <iostream>
using namespace std;
struct duzb {
	int en;
	int uz;
};
int sahe(duzb a) {
	return a.en * a.uz;
}
void daxil_et(duzb& a) {
	cout << "Duzbucaqlinin en ve uzunlugunu daxil edin: ";
	cin >> a.en >> a.uz;
}
void cap_et(duzb a) {
	cout << "en = " << a.en << "  " << "uz = " << a.uz << "\t"
		<< "sahe = " << sahe(a) << "\n";
}
void daxil_et_mas(duzb d[], int& cnt) {
	cout << "Obyektlerin sayini daxil et: ";
	cin >> cnt;
	int i;
	for (i = 0; i < cnt; i++) {
		daxil_et(d[i]);
	}
	cout << endl;
}
void cap_et_mas(duzb d[], int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		cout << i << ") ";
		cap_et(d[i]);
	}
	cout << endl;
}
void el_sil_indeks(duzb a[], int& cnt, int sil) {
	int i, k;
	if (sil < cnt) {
		for (i = sil; i < cnt; i++) {
			a[i] = a[i + 1];
		}
		cnt--;
	}
}
int get_indeks(duzb a[], int cnt, duzb b) {
	int i, k;
	k = 0;
	for (i = 0; i < cnt; i++) {
		if (a[i].en == b.en && a[i].uz == b.uz) {
			k = i;
			return k;
		}
	}
	return -1;
}

void el_sil(duzb a[], int& say, duzb b) {
	int ind;
	while (1) {
		ind = get_indeks(a, say, b);
		if (ind == -1) {
			break;
		}
		el_sil_indeks(a, say, ind);
	}
}

int get_max_ind(duzb a[], int& say) {
	int i, q, max_ind = 0;

	q = sahe(a[0]);
	for (i = 0; i < say; i++) {
		if (sahe(a[i]) > q) {
			q = sahe(a[i]);
			max_ind = i;
		}
	}
	return max_ind;
}

void del_max(duzb a[], int& say) {
	int i, q;
	q = get_max_ind(a, say);
	el_sil_indeks(a, say, q);
}

int main() {
	duzb a[100], q, b;
	int i, say;
	daxil_et_mas(a, say);
	cap_et_mas(a, say);
	
	cout << "Sahesi en boyuk olnanin ideksi: " << get_max_ind(a, say);
	del_max(a, say);
	

	cout << "\n\n";
	cap_et_mas(a, say);
}





//#include <iostream>
//#include <cmath>
//using namespace std;
//
//struct time {
//	int saat, deq, san;
//};
//
//void daxil_et(time &q) {
//
//	cout << "Vaxti daxil edin(saat, deqiqe, saniye): ";
//	cin >> q.saat >> q.deq >> q.san;
//}
//
//
//void cap_et(zaman q) {
//	cout << endl;
//	cout << q.saat << ":" << q.deqiqe << ":" << q.saniye;
//}
//
//
//int main() {
//	time t1, t2;
//
//	daxil_et(t1);
//	daxil_et(t2);	
//
//}
//int cemi_saniye(zaman q) {
//
	//q.cem = q.saniye + (q.deqiqe * 60) + (q.saat * pow(60, 2));
	//return q.cem;
//
//};
//void cap_et(zaman q) {
//
//	if (q.saat < 10) {
//		cout << endl;
//		cout << 0 << q.saat << ":" << q.deqiqe << ":" << q.saniye;
//	}
//	else if (q.deqiqe < 10) {
//		cout << endl;
//		cout << q.saat << ":" << 0 << q.deqiqe << ":" << q.saniye;
//	}
//	else if (q.saniye < 10) {
//		cout << endl;
//		cout << q.saat << ":" << q.deqiqe << ":" << 0 << q.saniye;
//	}
//	else {
//		cout << endl;
//		cout << q.saat << ":" << q.deqiqe << ":" << q.saniye;
//	}
//}
//void cap_et(int arr[], int say) {
//	int i;
//	cout << "Yeni massivin elementleri: ";
//	for (i = 0; i < say; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//void el_sil_qiymet(int arr[], int& say, int del_el) {
//	int i, sil_el_ind;
//
//	for (i = 0; i < say; i++) {
//		if (arr[i] == del_el) {
//			sil_el_ind = i;
//		}
//	}
//
//	for (i = sil_el_ind; i < say; i++) {
//		arr[i] = arr[i + 1];
//	}
//	say--;
//}
//int get_max_pos(int arr[], int say) {
//	int i, max_ind;
//
//	max_ind = arr[0];
//	for (i = 0; i < say; i++) {
//		if (arr[i] < max_ind) {
//			max_ind = i;
//		}
//	}
//	return max_ind;
//}
//void sil_max_el(int arr[], int& say, int max_ind) {
//	int i;
//
//	for (i = max_ind; i < say; i++) {
//		arr[i] = arr[i + 1];
//	}
//	say--;
//}
//void del_el_index(int arr[], int &say, int del_el) {
//	int i;
//	for (i = del_el; i < say; i++) {
//		arr[i] = arr[i + 1];
//	}
//	say--;
//}
//void el_dys(int arr[], int say) {
//	int i, a, b;
//
//	for (i = 0; i < say; i++) {
//		a = arr[i] / 10;
//		b = arr[i] % 10;
//		cout << b << a << " ";
//	}
//}
//int arr_min(int arr[],int say) {
//
//	int i, min = arr[0];
//	for (i = 0; i < say; i++) {
//		if (min > arr[i]) {
//			min = arr[i];
//		}
//	}
//	return min;
//}
//int arr_min_pos(int arr[],int say) {
//	int i, min = arr[0], min_ind;
//	for (i = 0; i < say; i++) {
//		if (min > arr[i]) {
//			min = arr[i];
//			min_ind = i;
//		}
//	}
//	return min_ind;
//}
//int arr_max(int arr[], int say) {
//	int i, max = arr[0];
//	for (i = 0; i < say; i++) {
//		if (max < arr[i]) {
//			max = arr[i];
//		}
//	}
//	return max;
//}
//int arr_max_pos(int arr[],int say) {
//	int i, max = arr[0], max_ind;
//	for (i = 0; i < say; i++) {
//		if (max < arr[i]) {
//			max = arr[i];
//			max_ind = i;
//		}
//	}
//	return max_ind;
//}
//double average(int arr[], int say) {
//	int i;
//	double arr_avrg = 0;
//	for (i = 0; i < say; i++){
//		arr_avrg += arr[i];
//	}
//
//	return arr_avrg/say;
//}
//int find(int arr[], int say, int find_el) {
//	int i, el = 0;
//	for (i = 0; i < say; i++) {
//		if (arr[i] == find_el) {
//			el = i;
//		}
//	}
//	return el;
//}
//int el_say(int arr[], int say, int el) {
//	int i, k;
//
//	k = 0;
//	for (i = 0; i < say; i++) {
//		if (arr[i] == el) {
//			k++;
//		}
//	}
//	return k;
//}
//void el_sil(int arr[], int say, int del_el) {
//	int i;
//
//	for (i = del_el - 1; i < say; i++) {
//		arr[i] = arr[i + 1];
//	}
//	say--;
//
//	cout << "Yeni massiv: ";
//	for (i = 0; i < say; i++) {
//		cout << arr[i] << " ";
//	}
//
//}

