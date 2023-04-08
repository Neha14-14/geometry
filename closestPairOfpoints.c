// A divide and conquer program in C/C++ to find the smallest distance from a
// given set of points.

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// A structure to represent a Point in 2D plane
typedef struct Point
{
    int x, y;
    int ind;
}Point;

typedef struct {
  int a, b;
  float dis;
}ans;

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}


float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

ans bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    int a, b;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min){
                a = P[i].ind;
                b = P[j].ind;
                min = dist(P[i], P[j]);
            }
    ans aa;
    aa.a = a;
    aa.b = b;
    aa.dis = min;
    return aa;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}


ans stripClosest(Point strip[], int size, float d)
{
    float min = d;
    int a, b;
    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min){
                a = strip[i].ind;
                b = strip[j].ind;
                min = dist(strip[i], strip[j]);
            }
    ans aa;
    aa.a = a;
    aa.b = b;
    aa.dis = min;
    return aa;
}

ans closestUtil(Point P[], int n)
{

    if (n <= 3)
        return bruteForce(P, n);


    int mid = n/2;
    Point midPoint = P[mid];
    ans al = closestUtil(P, mid);
    ans ar = closestUtil(P + mid, n-mid);
    float dl = al.dis;
    float dr = ar.dis;

    int ind;
    float d;
    if (dl < dr) {
      d = dl;
      ind = 0;
    }else {
      d = dr;
      ind = 1;
    }

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
    ans aa = stripClosest(strip, j, d);

    if (aa.dis < d) {
      return aa;
    }else {
      if (ind){
        return ar;
      }else {
        return al;
      }
    }
}

ans closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

int main()
{
    int n;
    scanf ("%d", &n);
    Point P[n];
    int i;
    for (i = 0; i < n; i++) {
      scanf ("%d %d", &P[i].x, &P[i].y);
      P[i].ind = i;
    }
    ans aa =  closest(P, n);

    printf("%d %d %f\n", aa.a, aa.b, aa.dis);
    return 0;
}
