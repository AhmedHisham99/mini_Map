#include"pch.h"
#include "pch.h"
#include "Graph.h"
#include <iostream>
#include<string>
using namespace std;
int main()
{
	
	
	Graph G;
	while (true)
	{
		cout << "Press \n'1' to Add Town. \n'2' to Add new Route. \n'3' to Update specific Route. \n'4' to delete specific Town. \n'5' to display all Data. \n'6' to Get Shortest Path Between any Two Towns. \n else To Close Program .\n";
		int ch; cin >> ch;
		switch (ch)
		{
		case 1:
		{
			int q; 
			cout << "How many Towns you will insert ? ";
			cin >> q; while (q--) {
				string x;
				cout << "Enter The Name of Town" << endl;
				cin >> x;
				G.AddTown(x);
			}
			break;
		}
		case 2:
		{ int q;
		cout << "How many ways you will Add ? " ;
		cin >> q;
		while (q--) {
			int x; string s, t;
			cout << "Enter Name of First Town & Name of Second Name & Distance" << endl;
			cin >> s >> t >> x;
			G.AddWay(s, t, x);
		}
			break;
		}
		case 3:
		{
			int x; string s, t;
			cout << "Enter Name of First Town & Name of Second Name & Distance" << endl;
			cin >> s >> t >> x;
			G.update(s, t, x);
			break;
		}
		case 4:
		{ 
			cout << "Enter The Name of Town" << endl;
			string s;
			cin >> s;
			G.Delete(s);
			break;
		}
		case 5:
		{
			G.display();
			break;
		}
		case 6:
		{
			string s, t;
			cout << "Enter the Name of First Town &  second Town " << endl;
			cin >> s >> t;
			G.Shortest_Path(s, t);
			break;
		}
		
		default:
			return 0;
		}
	}
	
	
}
