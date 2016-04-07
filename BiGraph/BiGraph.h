#ifndef __BIGRAPH_H_
#define __BIGRAPH_H_


#include<vector>
using namespace std;

#define Match Edge

struct Point{
	int id;
	bool leftpos;
};


struct Edge{
	Point start;
	Point end;
};

class BiGraph{

private:
	vector<Point> BiGraph::point;
	vector<Edge> BiGraph::edge;


	int BiGraph::isMatch(vector<Match> match, Point p);//�ж϶���ͼ�ҽڵ�p�Ƿ�match�����ҵ��򷵻�ƥ�����ƥ�����±꣬���򷵻�-1��

	int BiGraph::findEdgeIndex(Edge e);//�ҵ����±꣬δ�ҵ��򷵻�-1

	int BiGraph::findPointIndex(Point e);//�ҵ������±꣬δ�ҵ��򷵻�-1

	vector<Match>  BiGraph::findMaxMatch(int index, vector<Match> nowMatch, vector<Match> match, vector<bool> visit);//������ǰ����·ƥ��nowMatch�͵�ǰ����ͼ�ҵ������ƥ��match���������бߵķ��ʼ�¼visit���󶥵��±�Ϊindex����һ������·
	

public:
	BiGraph::BiGraph();
	BiGraph::~BiGraph();

	void BiGraph::addEdge(Edge e);//����ͼ��ӱߣ������ظ�����������

	void BiGraph::addPoint(Point v);//��Ӷ��㣬�ظ�����id����ͬһ���㵫������ұ�ǲ�ͬ�򷵻ش���

	int BiGraph::getEdgeSize();//���ر���
	Edge *BiGraph::getEdge(unsigned int i);//���ظ����±�ıߣ����Ϲ淶�򷵻�NULL
	
	int BiGraph::getPointSize();//���ض�������
	Point *BiGraph::getPoint(unsigned int i);////���ظ����±�Ķ��㣬���Ϲ淶�򷵻�NULL

	vector<Match> BiGraph::getMaxMatch();//�������ƥ��δ����
	

	void BiGraph::printPoint();//��ӡ������Ϣ

	void BiGraph::printEdge();//��ӡ����Ϣ

	void BiGraph::print();//��ӡͼ���ݰ�������Ϣ�Ͷ�����Ϣ

};


#endif