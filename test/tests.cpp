// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "circle.h"
#include "tasks.h"


const double EPS = 1e-6;

//CIRCLE

TEST(CircleTest, ConstructorRadius) {
    Circle c(5);
    EXPECT_NEAR(c.getRadius(), 5, EPS);
}

TEST(CircleTest, ConstructorFerence) {
    Circle c(1);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI, EPS);
}

TEST(CircleTest, ConstructorArea) {
    Circle c(1);
    EXPECT_NEAR(c.getArea(), M_PI, EPS);
}

TEST(CircleTest, SetRadius) {
    Circle c(2);
    c.setRadius(10);
    EXPECT_NEAR(c.getRadius(), 10, EPS);
}

TEST(CircleTest, SetRadiusFerenceUpdate) {
    Circle c(2);
    c.setRadius(3);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 3, EPS);
}

TEST(CircleTest, SetRadiusAreaUpdate) {
    Circle c(2);
    c.setRadius(4);
    EXPECT_NEAR(c.getArea(), M_PI * 16, EPS);
}

TEST(CircleTest, SetFerenceRadiusUpdate) {
    Circle c(1);
    c.setFerence(2 * M_PI * 5);
    EXPECT_NEAR(c.getRadius(), 5, EPS);
}

TEST(CircleTest, SetFerenceAreaUpdate) {
    Circle c(1);
    c.setFerence(2 * M_PI * 3);
    EXPECT_NEAR(c.getArea(), M_PI * 9, EPS);
}

TEST(CircleTest, SetAreaRadiusUpdate) {
    Circle c(1);
    c.setArea(M_PI * 16);
    EXPECT_NEAR(c.getRadius(), 4, EPS);
}

TEST(CircleTest, SetAreaFerenceUpdate) {
    Circle c(1);
    c.setArea(M_PI * 25);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5, EPS);
}

TEST(CircleTest, RadiusGetter) {
    Circle c(7);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7);
}

TEST(CircleTest, FerenceGetter) {
    Circle c(3);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 3, EPS);
}

TEST(CircleTest, AreaGetter) {
    Circle c(3);
    EXPECT_NEAR(c.getArea(), M_PI * 9, EPS);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1000);
    EXPECT_NEAR(c.getArea(), M_PI * 1000000, EPS);
}

TEST(CircleTest, SmallRadius) {
    Circle c(0.1);
    EXPECT_NEAR(c.getArea(), M_PI * 0.01, EPS);
}

//ЗЕМЛЯ И ВЕРЁВКА

TEST(TaskTest, RopeGapPositive) {
    double gap = earthRopeGap();
    EXPECT_GT(gap, 0);
}

TEST(TaskTest, RopeGapValue) {
    double gap = earthRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.01);
}

//БАССЕЙН

TEST(TaskTest, PoolConcreteCostPositive) {
    double concrete, fence;
    poolTask(concrete, fence);
    EXPECT_GT(concrete, 0);
}

TEST(TaskTest, PoolFenceCostPositive) {
    double concrete, fence;
    poolTask(concrete, fence);
    EXPECT_GT(fence, 0);
}

TEST(TaskTest, PoolConcreteApprox) {
    double concrete, fence;
    poolTask(concrete, fence);
    EXPECT_NEAR(concrete, 21991.1, 100);
}

TEST(TaskTest, PoolFenceApprox) {
    double concrete, fence;
    poolTask(concrete, fence);
    EXPECT_NEAR(fence, 50265.4, 100);
}
