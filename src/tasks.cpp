// Copyright 2025 UNN-CS Team
#include "tasks.h"
#include "circle.h"
#include <cmath>

double earthRopeGap() {
    const double earthRadius = 6378.1 * 1000;

    Circle earth(earthRadius);

    double oldFerence = earth.getFerence();
    double newFerence = oldFerence + 1.0;

    Circle newCircle(earthRadius);
    newCircle.setFerence(newFerence);

    double gap = newCircle.getRadius() - earthRadius;

    return gap;
}

void poolTask(double& concreteCost, double& fenceCost) {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;

    const double concretePrice = 1000.0;
    const double fencePrice = 2000.0;

    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double pathArea = outer.getArea() - pool.getArea();

    concreteCost = pathArea * concretePrice;
    fenceCost = outer.getFerence() * fencePrice;
}
