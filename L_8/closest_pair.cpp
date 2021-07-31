#include "closest_pair.h"

#include <stdexcept>
#include "point.h"
#include <vector>
#include <map>
#include <iostream>


using namespace std;


void sortVectorByX(vector<Point>& massOfPoints) {
	for (int startIndex = 0; startIndex < massOfPoints.size() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < massOfPoints.size(); ++currentIndex)
		{
			if (massOfPoints[currentIndex].x < massOfPoints[smallestIndex].x)
				smallestIndex = currentIndex;
		}
		std::swap(massOfPoints[startIndex], massOfPoints[smallestIndex]);
	}

	for (int i = 0; i < massOfPoints.size(); i++) {
		cout << massOfPoints[i] << "\n";
	}
}

std::pair<Point, Point> nearestPoints(std::vector<Point> points) {
	Point nearPoint1;
	Point nearPoint2;
	float distanceFromPoint = FLT_MAX;
	float actualDIstance;

	for (int i = 0; i < points.size() - 1; i++) {
		for (int j = i + 1; j < points.size(); j++) {
			actualDIstance = sqrt(pow((points[j].x - points[i].x), 2) + pow(points[j].y - points[i].y, 2));
			if (actualDIstance < distanceFromPoint) {
				nearPoint1 = points[i];
				nearPoint2 = points[j];
				distanceFromPoint = actualDIstance;
			}
		}
	}

	auto result = std::make_pair(nearPoint1, nearPoint2);
	return result;
}

std::pair<Point, Point> closest_pair(const std::vector<Point>& points) {
	if (points.size() < 2) {
		throw invalid_argument("Not enough points");
	}

	vector<Point> massOfPoints = points;
	sortVectorByX(massOfPoints);

	if (massOfPoints.size() % 2 != 0) {

	}

	auto result = make_pair(Point(), Point());
	return result;
}

std::pair<Point, Point> bruteforce(const std::vector<Point>& points) {
	if (points.size() < 2) {
		throw invalid_argument("Not enough points");
	}

	Point nearPoint1;
	Point nearPoint2;
	float distanceFromPoint = FLT_MAX;
	float actualDIstance;

	for (int i = 0; i < points.size() - 1; i++) {
		for (int j = i + 1; j < points.size(); j++) {
			actualDIstance = sqrt(pow((points[j].x - points[i].x), 2) + pow(points[j].y - points[i].y, 2));
			if (actualDIstance < distanceFromPoint) {
				nearPoint1 = points[i];
				nearPoint2 = points[j];
				distanceFromPoint = actualDIstance;
			}
		}
	}

	auto result = std::make_pair(nearPoint1, nearPoint2);
	return result;
}