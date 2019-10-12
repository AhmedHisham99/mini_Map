#include "pch.h"
#include "Graph.h"
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
Graph::Graph()
{
	num_of_towns = 0;
}
void Graph::AddTown(string s)
{
	if (town[s] != 0)cout << "invalid Town !" << endl;
	else {
		num_of_towns++;
		town[s] = num_of_towns;
		temp[num_of_towns] = s;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::AddWay(string s, string t, int x)
{
	if (town[s] == 0 || town[t] == 0)
		cout << "invalid City" << endl;
	else
	{
		v[town[s]].push_back({ town[t],x });
		v[town[t]].push_back({ town[s],x });

	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void Graph::display()
{

	if (num_of_towns == 0)cout << "There is No Data" << endl;
	else {
		for (int i = 1; i <= num_of_towns; i++)
		{
			if (!v[i].empty())
				for (auto it : v[i])
				{
					cout << "The Distance From " << temp[i] << " to " << temp[it.first] << " is: " << it.second << endl;

				}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void Graph::update(string s, string t, int x)
{
	if (town[s] == 0 || town[t] == 0)		cout << "invalid City" << endl;
	else
	{
		int cnt1 = 0, cnt2 = 0;
		for (auto it : v[town[s]])
		{
			if (temp[it.first] == t)
			{
				v[town[s]].erase(v[town[s]].begin() + cnt1);
				v[town[s]].push_back({ it.first,x });
				break;
			}
			cnt1++;
		}

		for (auto it : v[town[t]])
		{
			if (temp[it.first] == s)
			{
				v[town[t]].erase(v[town[t]].begin() + cnt2);
				v[town[t]].push_back({ it.first,x });
				break;
			}
			cnt2++;
		}
		cout << "Updated Successfully..." << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void Graph::Delete(string s)
{
	v[town[s]].clear();
	if (num_of_towns == 0)cout << "There is No Data" << endl;
	else {
		for (int i = 1; i <= num_of_towns; i++)
		{
			int cnt = 0;
			if (!v[i].empty())
				for (auto it : v[i])
				{
					if (temp[it.first] == s)
					{
						v[i].erase(v[i].begin() + cnt);
						break;
					}
					cnt++;
				}
		}
		int x = town[s];
		town.erase(s); temp.erase(x);

	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void Graph::generate_dis()
{
	for (int i = 1; i <= num_of_towns; i++)
	{
		if (!v[i].empty())
			for (auto it : v[i])
			{
				distance[i][it.first] = it.second;
				distance[it.first][i] = it.second;
				if (i == it.first)
				{
					distance[i][it.first] = 0;
					distance[it.first][i] = 0;
				}
			}
	}
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////// 
void Graph::Path(int i, int j)
{
	if (i != j)
	{
		Path(i, prev[i][j]);
	}
	cout << temp[j]<<" " ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void Graph::Shortest_Path(string s, string t)
{
	memset(distance, OO, sizeof distance);
	memset(prev, -1, sizeof prev);
	memset(mn1, OO, sizeof mn1);
	
	//memset(mn2, OO, sizeof mn2);
	 if (town[s] == 0 || town[t] == 0)cout << "invalid City " << endl;
	 else
	 {
		 generate_dis();
		 for (int i = 1; i <= num_of_towns; i++)for (int j = 1; j <= num_of_towns; j++)if (i == j)distance[i][j] = 0;
		 
		 for (int k = 1; k <= num_of_towns; ++k)
			 for (int i = 1; i <= num_of_towns; ++i)
				 for (int j = 1; j <= num_of_towns; ++j)
				 {
					 int x = distance[i][j];
					 distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
					 if (x == distance[i][j] &&i!=j&&distance[i][j]<OO&&distance[i][j]<mn1[i][j])     prev[i][j] = i, prev[j][i] = j,mn1[i][j]=distance[i][j];
					 else if (i != j && distance[i][j] < OO&&distance[i][j] < mn1[i][j])           prev[i][j] = k, prev[k][j] = k , mn1[i][j] = distance[i][j];
				 }
	
		 		
	 }

		 if (distance[town[s]][town[t]] >= OO)cout << "There is No Way between them...!" << endl;
		 else if (distance[town[s]][town[t]]==0)cout << "You already there..." << endl;
		 else
		 {
			 cout << "Shortsest Path between " << s << " & " << t << " is : " << distance[town[s]][town[t]] << endl;
			 cout << "The Path is :";
			 Path(town[s],town[t]);
			 cout << endl;
		 }
 }

//////////////////////////////////////////////////////////////////////////////////////////////////
Graph::~Graph()
{
}
