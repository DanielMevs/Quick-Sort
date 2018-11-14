//In this file we will try to implement insertion sort
#define SIZE_MAX 50001
#define RAND_MAX 32568
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

//void swap(vector<int> &vect, int i, int j);
void quick_sort(vector<int> &vect, int left, int right);
//vector<int>* quick_sort(vector<int> &vect);
int partition(vector<int> &vect, int left, int right);
void swap(vector<int> &vect, int i, int j);

int partition(vector<int> &vect, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = vect[(left + right) / 2];
	while (i <= j) {
		while (vect[i] < pivot) {
			i++;
		}
		while (vect[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swap(vect, i, j);
			i++;
			j--;
		}
	};
	return i;
}
void swap(vector<int> &vect, int i, int j)
{
	int temp = vect[j];
	vect[j] = vect[i];
	vect[i] = temp;
}

void quick_sort(vector<int> &vect, int left, int right) {
	int index = partition(vect, left, right);
	if (left < index - 1) {
		quick_sort(vect, left, index - 1);
	}
	if (index < right) {
		quick_sort(vect, index, right);
	}
}
/*
vector<int>* quick_sort(vector<int> &vect)
{
	if (vect.size() <= 1) {
		return;
	}
	vector<int>left;
	vector<int>right;

	int pivot = vect.back();
	vect.pop_back();
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] < pivot) {
			left.push_back(vect[i]);
		}
		else if (vect[i] >= pivot) {
			right.push_back(vect[i]);
		}
	}
	return quick_sort(left.push_back(quick_sort(right.push_back(pivot))));
}*/



int main() {
	srand(time(NULL));
	vector<int> v = { 3,44,5,47,15,36,26,27,2,46 };
	quick_sort(v, 0, v.size() - 1);
	for (int i : v) {
		cout << i << ", " << endl;
	}
	/*for (int i : v) { //This print the entire contents of the vector
	cout << i << ', ';
	}*/
}

//cout << v.size() << endl;
//v.resize(9);
//cout << v.size() << endl;
/*for (int i : v) { //This print the entire contents of the vector
//cout << i << endl;
}*/

/*for (int i = 0; i<v.size(); i++) {
v[i] = rand() % RAND_MAX;
cout << v[i] << endl;
}*/

//alternate version
/*for (int i=0;i<v.size();i++){
cout << v[i]; << endl;
}*/
//insertion_sort(v);



/*bad_func(v);
for (int i : v) { //done to demonstrate that to change the value of the vector, you must pass by reference
cout << i << endl;

}
good_func(v);
for (int i : v) { //done to demonstrate that to change the value of the vector, you must pass by reference
cout << i << endl;

}*/
