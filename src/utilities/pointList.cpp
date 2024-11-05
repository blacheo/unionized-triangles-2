#include <pointList.h>

bool PointList::empty() const {
    return size == 0;
}

int PointList::getSize() const {
    return size;
}
int PointList::prev(const PointNode &p) const {
    const int index = (p.prevIndex + size) % size;
    return index;
}

int PointList::next(const PointNode &p) const {
    const int index = p.nextIndex % size;
    return index;
}


void PointList::remove(int i) {
    if (size == 1) {
        size--;
        return;
    }
    const PointNode &p = points[i];
    int prevInd = prev(p);
    int nextInd = next(p);
    points[prevInd].nextIndex = nextInd;
    points[nextInd].prevIndex = prevInd;
    size--;
}

PointList::PointList(const std::vector<Point> &points) : size {points.size()} {
    for (int i = 0; i < points.size(); i++) {
        this->points[i] = PointNode{i - 1, i + 1, points[i]};
    }
}