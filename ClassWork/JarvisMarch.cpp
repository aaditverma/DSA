#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  
    return (val > 0) ? 1 : 2;  
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return points;

    vector<Point> hull;
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x || (points[i].x == points[leftmost].x && points[i].y < points[leftmost].y)) {
            leftmost = i;
        }
    }
    
    int p = leftmost, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != leftmost);

    return hull;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        char dummy;
        cin >> dummy;
        cin >> points[i].x;
        cin >> dummy;
        cin >> points[i].y;
        cin >> dummy;
    }

    vector<Point> convexPoints = convexHull(points);

    sort(convexPoints.begin(), convexPoints.end(), [](const Point& a, const Point& b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    for (const Point& point : convexPoints) {
        cout << "(" << point.x << "," << point.y << ")\n";
    }

    return 0;
}