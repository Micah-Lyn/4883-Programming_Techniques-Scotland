#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

struct Point {
   int a;
   int b; 

   };


double distance(Point a1, Point b1)
{
    return sqrt((double)(a1.a - b1.a) * (a1.a - b1.a)
                      + (a1.b - b1.b) * (a1.b - b1.b));
}

bool compareVal(const Point &a1, const Point &b1)
{
    return b1.a < a1.a;
}

int main()
{    
    int testCases;

    cin >> testCases;
    while ( testCases-- )
    {
        int cPairs;

        cin >> cPairs;

        vector<Point> points;

        for (int i = 1; i <= cPairs; i++)
        {
            Point point;
            cin >> point.a >> point.b;
            points.push_back(point);
        }

        
        sort(points.begin(), points.end(), compareVal);

        double len = 0;

        int currY = 0;
        
        for (int j = 1; j < points.size(); j++)
        {
            if (points[j].b > currY)
            {
                len += distance(points[j], points[j - 1])* (points[j].b - currY) / (points[j].b - points[j - 1].b); 
                currY = points[j].b;
            }
        }

       
        cout << setprecision(2) << setiosflags(ios::fixed) << len << '\n';
    }

    return 0;
}