#define SIZE 100000

int a[SIZE];
int b[SIZE];
int c[SIZE];

void foo() {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			c[j] = a[j] + b[j];
		}
	}
	return;
}

int main() {
	int ret = 0;
	foo();
	return ret;
}
