#include <iostream>
using namespace std;
struct squares {
	int width;
	int height;
};
int square(squares a) {
	return a.width * a.height;
}
void input_w_h(squares& a) {
	cout << "Input width and height of square: ";
	cin >> a.width >> a.height;
}
void print_w_h(squares a) {
	cout << "Width = " << a.width << "  " << "Height = " << a.height << "\t"
		<< "Square = " << square(a) << "\n";
}
void input_arr(squares d[], int& cnt) {
	cout << "Inpunt count of squares: ";
	cin >> cnt;
	int i;
	for (i = 0; i < cnt; i++) {
		input_w_h(d[i]);
	}
	cout << endl;
}
void print_arr(squares d[], int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		cout << i << ") ";
		print_w_h(d[i]);
	}
	cout << endl;
}
void rmv_el_index(squares a[], int& cnt, int rmv) {
	int i, k;
	if (rmv < cnt) {
		for (i = rmv; i < cnt; i++) {
			a[i] = a[i + 1];
		}
		cnt--;
	}
}
int get_indeks(squares a[], int cnt, squares b) {
	int i, k;
	k = 0;
	for (i = 0; i < cnt; i++) {
		if (a[i].width == b.width && a[i].height == b.height) {
			k = i;
			return k;
		}
	}
	return -1;
}

void rmv_el(squares a[], int& cnt, squares b) {
	int ind;
	while (1) {
		ind = get_indeks(a, cnt, b);
		if (ind == -1) {
			break;
		}
		rmv_el_index(a, cnt, ind);
	}
}

int get_max_ind(squares a[], int& cnt) {
	int i, q, max_ind = 0;

	q = square(a[0]);
	for (i = 0; i < cnt; i++) {
		if (square(a[i]) > q) {
			q = square(a[i]);
			max_ind = i;
		}
	}
	return max_ind;
}

void rmv_max(squares a[], int& cnt) {
	int i, q;
	q = get_max_ind(a, cnt);
	rmv_el_index(a, cnt, q);
}

int main() {
	squares a[100], q, b;
	int i, say;
	input_arr(a, say);
	print_arr(a, say);
	
	cout << "Index of the largest area: " << get_max_ind(a, say);
	rmv_max(a, say);
	

	cout << "\n\n";
	print_arr(a, say);
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

