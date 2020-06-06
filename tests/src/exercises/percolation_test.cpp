//
// Created by Ivan Yarkov on 06/06/2020.
//

#include <exercises/percolation_test.h>
#include <exercises/percolation.h>
#include <cassert>
#include <cmath>

static double PERCOLATION_THRESHOLD = 0.592746;
static double DELTA = 0.01;
static int GRID_SIDE_SIZE = 1000;

void tests::runAllPercolationTests() {
	double percoltaionExperimentThreshold = exercises::findPercolationNumber(GRID_SIDE_SIZE);
	assert(abs(PERCOLATION_THRESHOLD - percoltaionExperimentThreshold) < DELTA);
}

