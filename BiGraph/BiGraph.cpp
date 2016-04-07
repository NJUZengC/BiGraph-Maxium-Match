#include<string.h>
#include"BiGraph.h"

#include<iostream>
#include<Windows.h>




 
int BiGraph::isMatch(vector<Match> match, Point p)
{
		for (unsigned int i = 0; i < match.size(); i++)
			if (match.at(i).end.id == p.id)
				return i;
		return -1;
};


int BiGraph::findEdgeIndex(Edge e)
{
		for (unsigned int i = 0; i < edge.size(); i++)
		{
			if ((edge.at(i).start.id == e.start.id) && (edge.at(i).end.id == e.end.id))
				return i;
		}
		return -1;
};


int BiGraph::findPointIndex(Point e)
{
		for (unsigned int i = 0; i < point.size(); i++)
		{
			if ((point.at(i).id == e.id))
				return i;
		}
		return -1;
};


vector<Match>  BiGraph::findMaxMatch(int index, vector<Match> nowMatch, vector<Match> match, vector<bool> visit)
	
{
		
		
		bool fullvisit = true;
		for (unsigned int i = 0; i < edge.size(); i++)
			if (visit.at(i) == false)
				fullvisit = false;

		if (fullvisit)
			return nowMatch;
		
		bool flag = false;
		for (unsigned int i = 0; i < edge.size(); i++)
		{
			if ((edge.at(i).start.id == point.at(index).id) && (visit.at(i) ==false))
			{
				flag = true;
				int matchIndex = isMatch(match, edge.at(i).end);
				if (matchIndex ==-1)
				{
					Match m;
					m.start = point.at(index);
					m.end = edge.at(i).end;
					nowMatch.push_back(m);
					return nowMatch;
				}
				else{
					visit.at(i) = true;
					Edge e= match.at(matchIndex);	
					int edgeIndex = findEdgeIndex(e);
					visit.at(edgeIndex) = true;
					nowMatch.push_back(edge.at(i));
					return findMaxMatch(findPointIndex(match.at(matchIndex).start), nowMatch,match, visit);
					
				}
			}
		}
		if (flag == false)
		{
			int backIndex=-1;
			for (unsigned int j = 0; j < match.size();j++)
				if (match.at(j).start.id == point.at(index).id)
				{
					backIndex = match.at(j).end.id;
				}
			if (backIndex == -1)
				return nowMatch;
			for (unsigned int m = 0; m < nowMatch.size();m++)
				if (nowMatch.at(m).end.id == backIndex)
				{
					int leftbackIndex = findPointIndex(nowMatch.at(m).start);
					nowMatch.erase(nowMatch.begin() + m);
					return findMaxMatch(leftbackIndex, nowMatch, match, visit);

				}
		}
		return nowMatch;
};


BiGraph::BiGraph(){};

BiGraph::~BiGraph(){};

	
void BiGraph::addEdge(Edge e){
		for (unsigned int i = 0; i < edge.size(); i++)
		{
			if ((edge.at(i).start.id == e.start.id) && (edge.at(i).end.id == e.end.id))
			{
				cout << "存在重复边，自动忽略该重复边\n";
				return ;
			}
		}
		edge.push_back(e); 
};

	
void BiGraph::addPoint(Point v){
		for (unsigned int i = 0; i < point.size(); i++)
		{
			if ((point.at(i).id == v.id))
			{
				if (point.at(i).leftpos != v.leftpos)
				{
					cout << "输入图不是二部图！程序退出！\n";
					Sleep(500);
					exit(-1);
				}
				return;
			}
		}
		
		point.push_back(v); 
};


int BiGraph::getEdgeSize(){ return edge.size(); };
	

Edge *BiGraph::getEdge(unsigned int i)
{  
		if (i >= edge.size()||i<0||getEdgeSize()==0) 
	     return NULL; 
		return &edge.at(i);
	
};

	
int BiGraph::getPointSize()
{ 
	return point.size(); 
};


	
Point *BiGraph::getPoint(unsigned int i)
{
		if (i >= point.size() || i<0 || getPointSize() == 0)
			return NULL;
		return &point.at(i);
	
};

	
vector<Match> BiGraph::getMaxMatch()
{
		vector<Match> maxMatch;
		vector<bool>visit;
	
		for (unsigned int i = 0; i < edge.size(); i++)
			visit.push_back(false);
		for (unsigned int i = 0; i < point.size(); i++)
		{
			vector<Match> tempMatch;
			vector<Match> initMatch;
			if (point.at(i).leftpos == true)
			{
				tempMatch = findMaxMatch(i, initMatch,maxMatch, visit);
				for (unsigned int j = 0; j < tempMatch.size(); j++)
				{
					int index = isMatch(maxMatch, tempMatch.at(j).end);
					if (index != -1)
						maxMatch.erase(maxMatch.begin() +index);
					maxMatch.push_back(tempMatch.at(j));
				}
			}
			
		}

		return maxMatch;
};

	
void BiGraph::printPoint()
{
		cout << "\n--------------V---------------\n";
		for (unsigned int i = 0; i < point.size(); i++)
		{
			if ((point.at(i).leftpos == true))
				cout << point.at(i).id << "      " << "LEFT\n";
			else
				cout << point.at(i).id << "      " << "RIGHT\n";
		}
		cout << "\n--------------V---------------\n";
};

	
void BiGraph::printEdge()
{
		cout << "\n--------------E---------------\n";
		for (unsigned int j = 0; j < edge.size(); j++)
			cout << edge.at(j).start.id << " -----  " << edge.at(j).end.id << endl;
		cout << "\n--------------E---------------\n";
};

	
void BiGraph::print()
{
		printPoint();
		printEdge();
};




