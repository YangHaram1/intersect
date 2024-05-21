#include<vector>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Point {
public:
	string L;
	double x1;
	double y1;
	double x2;
	double y2;
	double A;//Ax+By+C=0
	double B;
	double C;
public:
	Point(){
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
		A = 0;
		B = 0;
		C = 0;
	}
	Point(string l,double X1, double Y1, double X2, double Y2) {
		L = l;
		x1 = X1;
		x2 = X2;
		y1 = Y1;
		y2 = Y2;
	}
};
class dot {
public:
	double x;
	double y;
	dot() {
		x = 0;
		y = 0;
	};
};
bool check(Point p1, Point p2);
double solve(Point p[], int n);
void ABC(Point &p);
void result_dot(dot &k, Point p1, Point p2);
bool check_dot(dot D[],int d);

dot D[50];
int main(int argc, char* argv[]) {
	int n = 0;//n条直线
	Point p[100];
	
	char symbol[1000] = { 0 };
	char* token = NULL;
	char* next_token = NULL;
	double number[4] = { 0 ,0,0,0 };
	char space[] = " ";

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int j = 0;

		cin.getline(symbol, 100);
		token = strtok_s(symbol, space, &next_token);
		p[i].L = token;
		while (token != NULL)
		{
			token = strtok_s(NULL, space, &next_token);
			//printf("%s\n", token);
			if (token != NULL)number[j++] = atoi(token);
		}
		p[i].x1 = number[0];
		p[i].y1 = number[1];
		p[i].x2 = number[2];
		p[i].y2 = number[3];
		j = 0;
		next_token = NULL;
		

	}
	//cout << p[0].y2<<endl;
	//cout << p[1].y2;

	
	printf("%d\n", (int)solve(p, n));
	return 0;
}
bool check(Point p1, Point p2) {
	double a1;
	double a2;
	a1 = (p1.y1 - p1.y2) / (p1.x1 - p1.x2);
	a2 = (p2.y1 - p2.y2 )/ (p2.x1 - p2.x2);
	if (a1 == a2)return false;
	else return true;
}
bool check_dot(dot D[],int d) {
	if (d == 1)return true;
	for (int i = 0; i < d-1; i++) {
		for (int j = 1 + i; j < d; j++) {
			if ((D[i].x == D[j].x) && (D[i].y == D[j].y))
				return false;
			else
				return true;

		}
	}

}
void result_dot(dot &k,Point p1, Point p2) {
	double a = (p1.A * p2.B) - (p1.B * p2.A);
	//cout << (p1.A * p2.B) << endl;
	//cout << (p1.B * p2.A) << endl;
	if (((p1.B * p2.C) - (p1.C * p2.B)) == 0.0) {
		k.x = ((p1.B * p2.C) - (p1.C * p2.B));
	}
	else
	k.x = ((p1.B * p2.C) - (p1.C * p2.B)) / a;

	if (((p1.C * p2.A) - (p1.A * p2.C)) == 0.0) {

		k.y = ((p1.C * p2.A) - (p1.A * p2.C));
	}
	else
	k.y = ((p1.C * p2.A) - (p1.A * p2.C)) / a;

	//cout << k[d].x << k[d].y << endl;
}
void ABC(Point &p) {
	p.A = p.y2 - p.y1;
	p.B = p.x1 - p.x2;
	p.C = (p.x2 * p.y1) - (p.x1 * p.y2);
	//cout << p.A << endl<< p.B <<endl<< p.C << endl;
}
double solve(Point p[],int n) {
	for (int i = 0; i < n; i++)
	{
		ABC(p[i]);
	}
	double result = 0;
	int d = 0;
	if (n == 1)return 0.0;
	for (int i = 0; i < n - 1; i++)
	{
		// 1 2 3 4 5
		for (int j = 1 + i; j < n; j++) {
			if (check(p[i], p[j]) && (p[i].L == "L") && (p[j].L == "L")) {
				result_dot(D[d++], p[i], p[j]);
				if(check_dot(D,d))
					result++;
			}

		}
	}
	return result;
}