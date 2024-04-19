#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIdx].y || (points[i].y == points[minIdx].y && points[i].x < points[minIdx].x)) {
            minIdx = i;
        }
    }

    swap(points[0], points[minIdx]);

    sort(points.begin() + 1, points.end(), [&](const Point& a, const Point& b) {
        double angle1 = atan2(a.y - points[0].y, a.x - points[0].x);
        double angle2 = atan2(b.y - points[0].y, b.x - points[0].x);
        return angle1 < angle2;
    });

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

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