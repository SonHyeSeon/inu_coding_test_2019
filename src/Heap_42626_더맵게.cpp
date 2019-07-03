// https://programmers.co.kr/learn/courses/30/lessons/42626
// 2019-07-02(ȭ)

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < scoville.size(); i++)
		q.emplace(scoville.at(i));

	int flag = 0;
	while (q.top() < K)
	{
		if (q.size() == 1 && q.top() < K) {
			flag = 1;
			break;
		}
		else {
			int first = q.top(); q.pop();
			int second = q.top(); q.pop();
			q.emplace(first + second * 2);
			answer++;
		}
	}
	if (flag == 1)
		answer = -1;
	return answer;
}

int main()
{
	//// testcase # 1 : -1
	//vector<int> input = { 1,1,1 };
	//int k = 10;

	//// testcase # 2 : -1
	//vector<int> input = { 0,0,1 };
	//int k = 1;

	//// testcase # 3 : 2
	//vector<int> input = { 1,2,3,9,10,12 };
	//int k = 7;

	// testcase # 4 : 2
	vector<int> input = {0,0,3};
	int k = 3;

	cout << solution(input, k) << endl;

	system("pause");
}