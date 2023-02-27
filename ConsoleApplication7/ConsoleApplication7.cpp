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

