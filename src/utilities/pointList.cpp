#include <pointList.h>

bool PointList::empty() const {
    return size == 0;
}

int PointList::getSize() const {
    return size;
}

int PointNode::next() const {
    return nextIndex;
}

int PointNode::prev() const {
    return prevIndex;
}

void PointList::remove(int i) {
    if (size == 1) {
        size--;
        return;
    }
    const PointNode &p = points[i];
    points[p.prev()].nextIndex = p.next();
    points[p.next()].prevIndex = p.prev();
    size--;
}

PointList::PointList(const std::vector<Point> &points) : size {points.size()} {
    for (int i = 0; i < points.size(); i++) {
        this->points[i] = PointNode{i - 1, i + 1, points[i]};
    }
    this->points[0].prevIndex = size - 1;
    this->points[size - 1].nextIndex = 0; 
}