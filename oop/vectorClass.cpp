#include <iostream>
using namespace std;


template<typename T> 
class Vector
{
	int maxSize,currentSize;
	T *arr;


public:
	//contructor
	Vector(){
		cout << "a new vector is created" << endl;
		currentSize = 0, maxSize = 1;
		arr = new T[maxSize];
	}

	//copy constructor
	Vector(T &V){
		maxSize = V.maxSize;
		for (int i = 0; i < V.currentSize; i++){
			arr[currentSize] = V[i];
			currentSize++;
		}
	}

	void push_back(const T val){
		if (currentSize == maxSize){
			T *old = arr;
			// cout << old << endl;
			arr = new T[2 * maxSize];
			maxSize *= 2;
			for (int i = 0; i < currentSize; i++){
				arr[i] = old[i];
			}

			delete [] old;
		}
		arr[currentSize] = val;
		currentSize++;
	}

	void pop_back(){
		currentSize--;
	}

	void print() const{
		for (int i = 0; i < currentSize; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int size() const{
		return currentSize;
	}

	int capacity() const{
		return maxSize;
	}

	void reserve(int x) {
		maxSize = x;
	}
	
	T operator[](const int i){
		return arr[i];
	}

	void operator+(T &V){
		T *old = arr;
		arr = new T[2 * maxSize];
		maxSize *= 2;
		for (int i = 0; i < currentSize; i++){
			arr[i] = old[i];
			currentSize++;
		}
		delete [] old;

		for (int i = 0; i < V.currentSize; i++){
			arr[currentSize] = V[i];
			currentSize++;
		}
	}
};

int main(){	
	Vector<int> v1;
	v1.push_back(2);
	v1.push_back(8);
	v1.push_back(10);
	v1.push_back(91);
	v1.push_back(32);
	v1.pop_back();

	Vector<int> v2(v1);

	cout << v1.size() << endl;
	v1.print();
	v2.print();



	v1.reserve(100);
	cout << v1.capacity() << endl;

	// v1 + v2;
	cout << v1[3] << endl;
	v1.print();

}