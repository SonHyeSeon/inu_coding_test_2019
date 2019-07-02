#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string arrangement) {
	int answer = 0;

	int left = 0;
	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(')
			left++;
		else {
			left--;
			if (arrangement[i - 1] == '(')
				answer += left;
			else
				answer += 1;
		}
	}

	return answer;
}

int main()
{
	// testcase #1 : 17
	string input = "()(((()())(())()))(())";
	cout << solution(input) << endl;

	system("pause");
}