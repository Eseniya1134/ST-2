// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double r) {
    radius = r;
    calculateFromRadius();
}

void Circle::calculateFromRadius() {
    ference = 2 * PI * radius;
    area = PI * radius * radius;
}

void Circle::calculateFromFerence() {
    radius = ference / (2 * PI);
    area = PI * radius * radius;
}

void Circle::calculateFromArea() {
    radius = std::sqrt(area / PI);
    ference = 2 * PI * radius;
}

void Circle::setRadius(double r) {
    radius = r;
    calculateFromRadius();
}

void Circle::setFerence(double f) {
    ference = f;
    calculateFromFerence();
}

void Circle::setArea(double a) {
    area = a;
    calculateFromArea();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
