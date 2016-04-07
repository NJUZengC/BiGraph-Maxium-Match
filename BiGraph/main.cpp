#include"BiGraph.h"
#include<string.h>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

void extract(char *p, int *left, int *right)
{
	int index = 0;
	*left = *right = 0;
	int flag = 1;
	if (p[index] == '-')
	{
		flag = -1;
		index++;
	}
	for (unsigned int i = index; i < strlen(p) && p[i] != ','; i++)
	{
		*left = (*left) * 10 + p[i] - '0';
		index = i + 1;
	}
	*left = flag*(*left);
	flag = 1;
	if (p[index + 1] == '-')
	{
		flag = -1;
		index++;
	}
	for (unsigned int i = index + 1; i < strlen(p); i++)
		(*right) = (*right) * 10 + p[i] - '0';
	*right = flag * (*right);
};


bool SortByStart(const Match &v1, const Match &v2)
{
	return v1.start.id < v2.start.id;//升序排列  
};

int main()
{

	int pointnum;
	cin >> pointnum;
	BiGraph biGraph;
	int left = 0, right = 0;

	char *input = new char[100];
	gets(input);
	gets(input);
	extract(input, &left, &right);
	while (left != -1 && right != -1)
	{
		if (left < 0 || left >= pointnum || right<0 || right>=pointnum)
		{
			cout << "输入下标不规范！程序退出！\n";
			return 0;
		}
		Point Left;
		Left.id = left;
		Left.leftpos = true;

		Point Right;
		Right.id = right;
		Right.leftpos = false;


		biGraph.addPoint(Left);
		biGraph.addPoint(Right);

		Edge e;
		e.start = Left;
		e.end = Right;
		biGraph.addEdge(e);

		gets(input);
		extract(input, &left, &right);
	}

	//biGraph.print();

	vector<Match> maxMatch = biGraph.getMaxMatch();
	for (unsigned int i = 0; i < maxMatch.size(); i++)
	{
		Point start(maxMatch.at(i).start);
		Point end(maxMatch.at(i).end);

		if (start.id>end.id)
		{
			maxMatch[i].start = end;
			maxMatch[i].end = start;
		}
	}

	std::sort(maxMatch.begin(), maxMatch.end(), SortByStart);

	cout << maxMatch.size() << endl;
	for (unsigned int i = 0; i < maxMatch.size(); i++)
	{
		cout << maxMatch.at(i).start.id << "," << maxMatch.at(i).end.id << endl;
	}

	return 0;

}