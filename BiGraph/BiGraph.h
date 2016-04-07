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


	int BiGraph::isMatch(vector<Match> match, Point p);//判断二部图右节点p是否被match饱和找到则返回匹配边在匹配中下标，否则返回-1；

	int BiGraph::findEdgeIndex(Edge e);//找到边下标，未找到则返回-1

	int BiGraph::findPointIndex(Point e);//找到顶点下标，未找到则返回-1

	vector<Match>  BiGraph::findMaxMatch(int index, vector<Match> nowMatch, vector<Match> match, vector<bool> visit);//给定当前增广路匹配nowMatch和当前二部图找到的最大匹配match，对于所有边的访问记录visit，求顶点下标为index的下一步增广路
	

public:
	BiGraph::BiGraph();
	BiGraph::~BiGraph();

	void BiGraph::addEdge(Edge e);//二部图添加边，出现重复边则不做处理

	void BiGraph::addPoint(Point v);//添加顶点，重复顶点id当作同一个点但如果左右标记不同则返回错误

	int BiGraph::getEdgeSize();//返回边数
	Edge *BiGraph::getEdge(unsigned int i);//返回给定下标的边，不合规范则返回NULL
	
	int BiGraph::getPointSize();//返回顶点总数
	Point *BiGraph::getPoint(unsigned int i);////返回给定下标的顶点，不合规范则返回NULL

	vector<Match> BiGraph::getMaxMatch();//返回最大匹配未排序
	

	void BiGraph::printPoint();//打印顶点信息

	void BiGraph::printEdge();//打印边信息

	void BiGraph::print();//打印图内容包含边信息和顶点信息

};


#endif