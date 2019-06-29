#include <iostream>
using namespace std;
int add(int a, int b);

main(void) {
	int a = 10, b = 20, c;

	c = add(a, b);
	cout << c;
	return 0;
}

int add(int a, int b) {
	int c = a + b;

	return c;
} 