#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#ifndef N
	#define N 30
#endif

#define BOX 50000

struct point {
	int x;
	int y;

	inline point operator-(const point p1) {
		return {x - p1.x, y - p1.y};
	}
};

bool pointsIsEqual(const point p1, const point p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

int zCrossProduct(const point p1, const point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}


void computeConvexHull(std::vector<point> &hull, point *dataset) {
	std::sort(dataset, dataset+N, [](const point p1, const point p2) { return p1.x < p2.x; });

	int i = 2;

	point leftMost, currentVertex, nextVertex, checking;
   	leftMost = dataset[0];
	currentVertex = leftMost;
	hull.push_back(currentVertex);
	nextVertex = dataset[1];
	
	do {
		for (; i<N; i++) {
			checking = dataset[i];
			point a = nextVertex - currentVertex;
			point b = checking - currentVertex;
			int cp = zCrossProduct(a, b);
			if (cp < 0)
				nextVertex = checking;
		}
		if (pointsIsEqual(nextVertex, leftMost))
			break;
		hull.push_back(nextVertex);
		currentVertex = nextVertex;
		nextVertex = leftMost;
		i = 0;
	} while(true);
}

int main() {
	srand(time(nullptr));

	std::vector<point> hull;

	FILE *in = fopen("dataset.txt", "w");
	point *dataset = new point[N];
	for (int i=0; i<N; i++) {
		dataset[i].x = rand() % BOX;
		dataset[i].y = rand() % BOX;

		fprintf(in, "%d %d\n", dataset[i].x, dataset[i].y);
	}
	fclose(in);
	
	//do the algorithm
	computeConvexHull(hull, dataset);
	
	in = fopen("hull.txt", "w");
	for (auto p : hull)
		fprintf(in , "%d %d\n", p.x, p.y);
	fclose(in);

	delete[] dataset;
	return 0;
}
