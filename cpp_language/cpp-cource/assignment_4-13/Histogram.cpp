#include <iostream>

using namespace std;

class Histogram {
	string fullSentence = "";
	int length;
	int lengthOfAlpabet = 0;
	int* listOfAlpabet = new int[26]{0};
public:
	Histogram(string sentence) {
		cout << sentence;
		fullSentence += sentence;
		length += sentence.length();
	}
	void put(string sentence = "") {
		cout << sentence;
		fullSentence += sentence;
		length += sentence.length();
	};
	void putc(char word) {
		cout << word;
		fullSentence += word;
		length++;
	};
	void print() {
	//	cout << fullSentence;

		for (int i = 0; i < length; i++)
		{
			if (fullSentence[i] >= 65 && fullSentence[i] <= 90) {
				fullSentence[i] += 32;
				lengthOfAlpabet++;
			}
			else if (fullSentence[i] >= 97 && fullSentence[i] <= 122) {
				lengthOfAlpabet++;
			}
			else {
				continue;
			}
			listOfAlpabet[(int)(fullSentence[i] - 'a')]++;
		}
		
		cout << endl << "총 알파벳 수 " << lengthOfAlpabet << endl << endl;

		for (int i = 0; i < 26; i++)
		{
			cout << (char)(i + 97) << " (" << listOfAlpabet[i] << ")		: ";
			for (int j = 0; j < listOfAlpabet[i]; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	};
};

int main(void) {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis presley");
	elvisHisto.print();
}