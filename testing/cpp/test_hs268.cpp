/*
 *	This file is part of qpOASES.
 *
 *	qpOASES -- An Implementation of the Online Active Set Strategy.
 *	Copyright (C) 2007-2014 by Hans Joachim Ferreau, Andreas Potschka,
 *	Christian Kirches et al. All rights reserved.
 *
 *	qpOASES is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation; either
 *	version 2.1 of the License, or (at your option) any later version.
 *
 *	qpOASES is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *	See the GNU Lesser General Public License for more details.
 *
 *	You should have received a copy of the GNU Lesser General Public
 *	License along with qpOASES; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *	\file testing/cpp/test_bench.cpp
 *	\author Andreas Potschka, Christian Kirches, Hans Joachim Ferreau
 *	\version 3.0
 *	\date 2010-2014
 *
 *	Unit test running all benchmark examples stored in problems directory.
 */



#include <dirent.h>
#include <cstring>
#include <cstdlib>
#include <qpOASES.hpp>
#include <qpOASES/UnitTesting.hpp>


/** Run benchmark examples. */
int main( int argc, char *argv[] )
{
	USING_NAMESPACE_QPOASES

	/* 1) Define benchmark arguments. */
	BooleanType isSparse = BT_FALSE;
	//BooleanType isSparse = BT_TRUE;
	Options options;
 	options.setToDefault();
	//options.setToMPC();
	//options.setToReliable();
	//options.printLevel = PL_LOW;
	//options.printLevel = PL_MEDIUM;
	options.printLevel = PL_TABULAR;


	int nWSR;
	real_t maxCPUtime; /* seconds */
	real_t maxStationarity = 0.0, maxFeasibility = 0.0, maxComplementarity = 0.0;

	char OQPproblem[MAX_STRING_LENGTH];
	char problem[] = "HS268";
	returnValue returnvalue;

	
	/* 3) Run benchmark. */
	fprintf(stdFile, "%-10s ", problem);
	fflush(stdFile);

	snprintf(OQPproblem, MAX_STRING_LENGTH, "../testing/cpp/data/problems/%s/", problem);
	maxCPUtime = 100.0;
	nWSR = 100;

	returnvalue = runOQPbenchmark(	OQPproblem, isSparse, options,
									nWSR, maxCPUtime, maxStationarity, maxFeasibility, maxComplementarity 
									);

	printf( "\n" );
	printf( "stat:  %e\n", maxStationarity    );
	printf( "feas:  %e\n", maxFeasibility     );
	printf( "cmpl:  %e\n", maxComplementarity );

	QPOASES_TEST_FOR_TOL( maxStationarity,    1e-11 );
	QPOASES_TEST_FOR_TOL( maxFeasibility,     1e-14 );
	QPOASES_TEST_FOR_TOL( maxComplementarity, 1e-14 );


	return 0;
}


/*
 *	end of file
 */
