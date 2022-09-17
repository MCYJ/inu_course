#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	for (int i = 2; i <= 9; i += 2)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << 'X' << j << '=' << right << setw(2) << i * j;
			cout << "	";
			cout << i + 1 << 'X' << j << '=' << right << setw(2) << (i + 1) * j;
			cout << endl;
		}
		cout << "==============" << endl;
		if (i % 2 == 1) cout << endl;
	}
}