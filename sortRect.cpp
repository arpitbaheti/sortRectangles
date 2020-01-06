#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} rect;

typedef struct _float6 {
    float x; float y; float z; float w; float v; float u;
} float6;

template <typename T>
void printRect(vector<T> rects)
{
    for (uint32_t i = 0U; i < rects.size(); i++) {
        cout << rects[i].x1  << " " <<
                rects[i].y1 << " " <<
                rects[i].x2 << " " <<
                rects[i].y2 << endl;
    }
}

void printRects(float6 r[], uint32_t numBoxes) {

    for (uint32_t i = 0U; i < numBoxes; i++) {
        cout << r[i].x << " " <<
                r[i].y << " " <<
                r[i].z << " " <<
                r[i].w << " " <<
                r[i].v << " " <<
                r[i].u << endl;
    }
}

bool compareInterval(rect first, rect second)
{
    return ((first.y1 - second.y1) != 0) ? (first.y1 - second.y1) < 0 :
           ((first.x1 - second.x1) != 0) ? (first.x1 - second.x1) < 0 :
           ((first.y2 - second.y2) != 0) ? (first.y2 - second.y2) < 0 :
           ((first.x2 - second.x2) != 0) ? (first.x2 - second.x2) < 0 :
           false;
}

static bool compareRect(float6 A, float6 B)
{
    return ((A.y - B.y) != 0) ? (A.y - B.y) < 0 :
           ((A.x - B.x) != 0) ? (A.x - B.x) < 0 :
           ((A.w - B.w) != 0) ? (A.w - B.w) < 0 :
           ((A.z - B.z) != 0) ? (A.z - B.z) < 0 :
           false;
}

int main()
{
    uint32_t numBoxes;
    float6 rects[7];

    numBoxes = 0;
    rects[numBoxes].x = 1, rects[numBoxes].y = 4,rects[numBoxes].z = 3,rects[numBoxes].w = 6,rects[numBoxes].v = 98.0,rects[numBoxes].u = 0;
    numBoxes = 1;
    rects[numBoxes].x = 3, rects[numBoxes].y = 1,rects[numBoxes].z = 5,rects[numBoxes].w = 3,rects[numBoxes].v = 99.0,rects[numBoxes].u = 0;
    numBoxes = 2;
    rects[numBoxes].x = 4, rects[numBoxes].y = 3,rects[numBoxes].z = 5,rects[numBoxes].w = 5,rects[numBoxes].v = 91.0,rects[numBoxes].u = 0;
    numBoxes = 3;
    rects[numBoxes].x = 1, rects[numBoxes].y = 1,rects[numBoxes].z = 2,rects[numBoxes].w = 3,rects[numBoxes].v = 96.0,rects[numBoxes].u = 0;
    numBoxes = 4;
    rects[numBoxes].x = 6, rects[numBoxes].y = 5,rects[numBoxes].z = 7,rects[numBoxes].w = 6,rects[numBoxes].v = 68.0,rects[numBoxes].u = 0;
    numBoxes = 5;
    rects[numBoxes].x = 1, rects[numBoxes].y = 1,rects[numBoxes].z = 3,rects[numBoxes].w = 3,rects[numBoxes].v = 67.5,rects[numBoxes].u = 1;
    numBoxes = 6;
    rects[numBoxes].x = 1, rects[numBoxes].y = 1,rects[numBoxes].z = 3,rects[numBoxes].w = 4,rects[numBoxes].v = 78.3,rects[numBoxes].u = 3;
    numBoxes = 7;

    cout << "Before sort:" << endl;
    printRects(rects, numBoxes);

    sort(rects, rects + numBoxes, compareRect);

    cout << "After sort:" << endl;
    printRects(rects, numBoxes);


    vector<rect> vrects;
    rect r;
    r.x1 = 1, r.y1 = 4, r.x2 = 3, r.y2 = 6;
    vrects.push_back(r);
    r.x1 = 3, r.y1 = 1, r.x2 = 5, r.y2 = 3;
    vrects.push_back(r);
    r.x1 = 4, r.y1 = 3, r.x2 = 5, r.y2 = 5;
    vrects.push_back(r);
    r.x1 = 1, r.y1 = 1, r.x2 = 2, r.y2 = 3;
    vrects.push_back(r);
    r.x1 = 6, r.y1 = 5, r.x2 = 7, r.y2 = 6;
    vrects.push_back(r);
    r.x1 = 1, r.y1 = 1, r.x2 = 3, r.y2 = 3;
    vrects.push_back(r);
    r.x1 = 1, r.y1 = 1, r.x2 = 3, r.y2 = 4;
    vrects.push_back(r);

    cout << "Before sort:" << endl;
    printRect(vrects);

    sort(vrects.begin(), vrects.end(), compareInterval);

    cout << "After sort:" << endl;
    printRect(vrects);

    return 0;
}

