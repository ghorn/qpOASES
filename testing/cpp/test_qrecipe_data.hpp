/*
 *	This file is part of qpOASES.
 *
 *	qpOASES -- An Implementation of the Online Active Set Strategy.
 *	Copyright (C) 2007-2017 by Hans Joachim Ferreau, Andreas Potschka,
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
 *	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *USA
 *
 */

/**
 *	\file testing/cpp/test_qrecipe.cpp
 *	\author Andreas Potschka
 *	\version 3.2
 *	\date 2007-2017
 *
 *	QRECIPE example from the CUTEr test set with sparse matrices.
 */

USING_NAMESPACE_QPOASES

const real_t Inf = INFTY;

sparse_int_t H_jc[] = {
    0,  4,  8,  12, 16, 20, 20, 20, 20, 20, 20, 24, 28, 32, 36, 40, 40, 40, 40,
    40, 40, 44, 48, 52, 56, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 64, 68, 72,
    76, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80};

sparse_int_t H_ir[] = {
    0, 10, 20, 34, 1, 11, 21, 35, 2, 12, 22, 36, 3, 13, 23, 37, 4, 14, 24, 38,
    0, 10, 20, 34, 1, 11, 21, 35, 2, 12, 22, 36, 3, 13, 23, 37, 4, 14, 24, 38,
    0, 10, 20, 34, 1, 11, 21, 35, 2, 12, 22, 36, 3, 13, 23, 37, 4, 14, 24, 38,
    0, 10, 20, 34, 1, 11, 21, 35, 2, 12, 22, 36, 3, 13, 23, 37, 4, 14, 24, 38};

real_t H_val[] = {10, 1, 1, 1,  10, 1, 1, 1,  10, 1, 1, 1, 10, 1, 1, 1, 10,
                  1,  1, 1, 1,  10, 1, 1, 1,  10, 1, 1, 1, 10, 1, 1, 1, 10,
                  1,  1, 1, 10, 1,  1, 1, 1,  10, 1, 1, 1, 10, 1, 1, 1, 10,
                  1,  1, 1, 10, 1,  1, 1, 10, 1,  1, 1, 1, 10, 1, 1, 1, 10,
                  1,  1, 1, 10, 1,  1, 1, 10, 1,  1, 1, 10};

sparse_int_t A_jc[] = {
    0,   10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130,
    140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270,
    280, 290, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311,
    312, 313, 314, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328,
    329, 331, 333, 335, 337, 339, 341, 343, 345, 347, 349, 351, 353, 355,
    357, 359, 361, 363, 365, 367, 369, 371, 373, 383, 393, 403, 405, 408,
    410, 413, 415, 418, 420, 422, 424, 426, 428, 430, 432, 434, 436, 438,
    440, 442, 444, 446, 448, 450, 452, 454, 456, 458, 460, 462, 472, 482,
    492, 494, 497, 499, 502, 504, 507, 509, 511, 513, 515, 517, 519, 521,
    523, 525, 527, 529, 531, 533, 535, 537, 539, 541, 543, 545, 547, 549,
    551, 561, 571, 581, 583, 586, 588, 591, 593, 596, 597, 598, 599, 600,
    601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614,
    615, 616, 617, 618, 628, 638, 648, 650, 653, 655, 658, 660, 663};

sparse_int_t A_ir[] = {
    0,  14, 35, 36, 71, 72, 85, 86, 87, 88, 1,  14, 35, 36, 71, 72, 85, 86, 87,
    88, 2,  14, 35, 36, 71, 72, 85, 86, 87, 88, 3,  14, 35, 36, 71, 72, 85, 86,
    87, 88, 4,  14, 35, 36, 71, 72, 85, 86, 87, 88, 5,  14, 35, 36, 71, 72, 85,
    86, 87, 88, 6,  14, 35, 36, 71, 72, 85, 86, 87, 88, 7,  14, 35, 36, 71, 72,
    85, 86, 87, 88, 8,  14, 35, 36, 71, 72, 85, 86, 87, 88, 9,  14, 35, 36, 71,
    72, 85, 86, 87, 88, 0,  15, 37, 38, 69, 70, 79, 80, 81, 82, 1,  15, 37, 38,
    69, 70, 79, 80, 81, 82, 2,  15, 37, 38, 69, 70, 79, 80, 81, 82, 3,  15, 37,
    38, 69, 70, 79, 80, 81, 82, 4,  15, 37, 38, 69, 70, 79, 80, 81, 82, 5,  15,
    37, 38, 69, 70, 79, 80, 81, 82, 6,  15, 37, 38, 69, 70, 79, 80, 81, 82, 7,
    15, 37, 38, 69, 70, 79, 80, 81, 82, 8,  15, 37, 38, 69, 70, 79, 80, 81, 82,
    9,  15, 37, 38, 69, 70, 79, 80, 81, 82, 0,  16, 39, 40, 67, 68, 73, 74, 75,
    76, 1,  16, 39, 40, 67, 68, 73, 74, 75, 76, 2,  16, 39, 40, 67, 68, 73, 74,
    75, 76, 3,  16, 39, 40, 67, 68, 73, 74, 75, 76, 4,  16, 39, 40, 67, 68, 73,
    74, 75, 76, 5,  16, 39, 40, 67, 68, 73, 74, 75, 76, 6,  16, 39, 40, 67, 68,
    73, 74, 75, 76, 7,  16, 39, 40, 67, 68, 73, 74, 75, 76, 8,  16, 39, 40, 67,
    68, 73, 74, 75, 76, 9,  16, 39, 40, 67, 68, 73, 74, 75, 76, 10, 11, 12, 13,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 47, 58, 48, 59, 49, 60, 50, 61, 51, 62, 52, 63, 53,
    64, 54, 65, 55, 66, 46, 56, 45, 57, 47, 58, 48, 59, 49, 60, 50, 61, 51, 62,
    52, 63, 53, 64, 54, 65, 55, 66, 46, 56, 45, 57, 10, 14, 71, 72, 85, 86, 87,
    88, 89, 90, 11, 15, 69, 70, 79, 80, 81, 82, 83, 84, 12, 16, 67, 68, 73, 74,
    75, 76, 77, 78, 35, 90, 36, 89, 90, 37, 84, 38, 83, 84, 39, 78, 40, 77, 78,
    44, 58, 43, 59, 42, 60, 41, 61, 34, 62, 33, 63, 32, 64, 31, 65, 30, 66, 29,
    46, 28, 45, 44, 58, 43, 59, 42, 60, 41, 61, 34, 62, 33, 63, 32, 64, 31, 65,
    30, 66, 29, 46, 28, 45, 10, 14, 71, 72, 85, 86, 87, 88, 89, 90, 11, 15, 69,
    70, 79, 80, 81, 82, 83, 84, 12, 16, 67, 68, 73, 74, 75, 76, 77, 78, 35, 90,
    36, 89, 90, 37, 84, 38, 83, 84, 39, 78, 40, 77, 78, 27, 44, 26, 43, 25, 42,
    24, 41, 23, 34, 22, 33, 21, 32, 20, 31, 19, 30, 18, 29, 17, 28, 27, 44, 26,
    43, 25, 42, 24, 41, 23, 34, 22, 33, 21, 32, 20, 31, 19, 30, 18, 29, 17, 28,
    10, 14, 71, 72, 85, 86, 87, 88, 89, 90, 11, 15, 69, 70, 79, 80, 81, 82, 83,
    84, 12, 16, 67, 68, 73, 74, 75, 76, 77, 78, 35, 90, 36, 89, 90, 37, 84, 38,
    83, 84, 39, 78, 40, 77, 78, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 27,
    26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 10, 14, 71, 72, 85, 86, 87, 88, 89,
    90, 11, 15, 69, 70, 79, 80, 81, 82, 83, 84, 12, 16, 67, 68, 73, 74, 75, 76,
    77, 78, 35, 90, 36, 89, 90, 37, 84, 38, 83, 84, 39, 78, 40, 77, 78};

real_t A_val[] = {
    -1.0000000000000000e+00, 1.0000000000000000e+00,  8.8678200000000004e+01,
    9.3617050000000006e+01,  1.6000000000000000e+01,  8.1999999999999993e+00,
    9.9000000000000000e+01,  8.0000000000000000e+01,  1.2000000000000000e+01,
    9.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    8.0062830000000005e+01,  9.9224010000000007e+01,  1.0000000000000000e+02,
    2.1100000000000001e+01,  1.0000000000000000e+02,  1.0000000000000000e+02,
    1.1400000000000000e+02,  1.1680000000000000e+02,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  7.4697360000000003e+01,  8.3801220000000001e+01,
    -8.1999999999999993e+00, 2.0000000000000000e+00,  9.0000000000000000e+01,
    2.3999999999999999e+00,  -1.2000000000000000e+01, -1.4800000000000001e+01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  7.9194209999999998e+01,
    9.0175110000000004e+01,  4.3000000000000000e+01,  8.0000000000000000e+00,
    1.0000000000000000e+02,  9.5000000000000000e+01,  9.0000000000000000e+00,
    2.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    7.8568219999999997e+01,  8.5996200000000002e+01,  -1.2500000000000000e+01,
    1.0000000000000000e+00,  9.6500000000000000e+01,  4.0000000000000000e+00,
    -1.8000000000000000e+01, -2.1899999999999999e+01, -1.0000000000000000e+00,
    1.0000000000000000e+00,  8.2922240000000002e+01,  8.6963380000000001e+01,
    6.5000000000000000e+01,  1.2500000000000000e+01,  1.0000000000000000e+02,
    9.8000000000000000e+01,  4.9000000000000000e+01,  3.7000000000000000e+01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  8.2592740000000006e+01,
    9.3147599999999997e+01,  -1.2000000000000000e+01, 1.0000000000000000e+00,
    9.6500000000000000e+01,  4.0000000000000000e+00,  -1.8000000000000000e+01,
    -2.1899999999999999e+01, -1.0000000000000000e+00, 1.0000000000000000e+00,
    7.6506460000000004e+01,  7.8210250000000002e+01,  7.9000000000000000e+01,
    1.2000000000000000e+01,  1.0000000000000000e+02,  9.5000000000000000e+01,
    6.8000000000000000e+01,  6.1000000000000000e+01,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  8.8357460000000003e+01,  9.4257840000000002e+01,
    1.2500000000000000e+02,  6.1299999999999997e+01,  1.0000000000000000e+02,
    1.0000000000000000e+02,  1.4500000000000000e+02,  1.4500000000000000e+02,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  9.0590469999999996e+01,
    1.0582863000000000e+02,  6.2000000000000002e+00,  6.0000000000000000e+00,
    9.7000000000000000e+01,  2.8500000000000000e+01,  4.0000000000000000e+00,
    3.6000000000000001e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    8.8678200000000004e+01,  9.3617050000000006e+01,  1.6000000000000000e+01,
    8.1999999999999993e+00,  9.9000000000000000e+01,  8.0000000000000000e+01,
    1.2000000000000000e+01,  9.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  8.0062830000000005e+01,  9.9224010000000007e+01,
    1.0000000000000000e+02,  2.1100000000000001e+01,  1.0000000000000000e+02,
    1.0000000000000000e+02,  1.1400000000000000e+02,  1.1680000000000000e+02,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  7.4697360000000003e+01,
    8.3801220000000001e+01,  -8.1999999999999993e+00, 2.0000000000000000e+00,
    9.0000000000000000e+01,  2.3999999999999999e+00,  -1.2000000000000000e+01,
    -1.4800000000000001e+01, -1.0000000000000000e+00, 1.0000000000000000e+00,
    7.9194209999999998e+01,  9.0175110000000004e+01,  4.3000000000000000e+01,
    8.0000000000000000e+00,  1.0000000000000000e+02,  9.5000000000000000e+01,
    9.0000000000000000e+00,  2.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  7.8568219999999997e+01,  8.5996200000000002e+01,
    -1.2500000000000000e+01, 1.0000000000000000e+00,  9.6500000000000000e+01,
    4.0000000000000000e+00,  -1.8000000000000000e+01, -2.1899999999999999e+01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  8.2922240000000002e+01,
    8.6963380000000001e+01,  6.5000000000000000e+01,  1.2500000000000000e+01,
    1.0000000000000000e+02,  9.8000000000000000e+01,  4.9000000000000000e+01,
    3.7000000000000000e+01,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    8.2592740000000006e+01,  9.3147599999999997e+01,  -1.2000000000000000e+01,
    1.0000000000000000e+00,  9.6500000000000000e+01,  4.0000000000000000e+00,
    -1.8000000000000000e+01, -2.1899999999999999e+01, -1.0000000000000000e+00,
    1.0000000000000000e+00,  7.6506460000000004e+01,  7.8210250000000002e+01,
    7.9000000000000000e+01,  1.2000000000000000e+01,  1.0000000000000000e+02,
    9.5000000000000000e+01,  6.8000000000000000e+01,  6.1000000000000000e+01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  8.8357460000000003e+01,
    9.4257840000000002e+01,  1.2500000000000000e+02,  6.1299999999999997e+01,
    1.0000000000000000e+02,  1.0000000000000000e+02,  1.4500000000000000e+02,
    1.4500000000000000e+02,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    9.0590469999999996e+01,  1.0582863000000000e+02,  6.2000000000000002e+00,
    6.0000000000000000e+00,  9.7000000000000000e+01,  2.8500000000000000e+01,
    4.0000000000000000e+00,  3.6000000000000001e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  8.8678200000000004e+01,  9.3617050000000006e+01,
    1.6000000000000000e+01,  8.1999999999999993e+00,  9.9000000000000000e+01,
    8.0000000000000000e+01,  1.2000000000000000e+01,  9.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  8.0062830000000005e+01,
    9.9224010000000007e+01,  1.0000000000000000e+02,  2.1100000000000001e+01,
    1.0000000000000000e+02,  1.0000000000000000e+02,  1.1400000000000000e+02,
    1.1680000000000000e+02,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    7.4697360000000003e+01,  8.3801220000000001e+01,  -8.1999999999999993e+00,
    2.0000000000000000e+00,  9.0000000000000000e+01,  2.3999999999999999e+00,
    -1.2000000000000000e+01, -1.4800000000000001e+01, -1.0000000000000000e+00,
    1.0000000000000000e+00,  7.9194209999999998e+01,  9.0175110000000004e+01,
    4.3000000000000000e+01,  8.0000000000000000e+00,  1.0000000000000000e+02,
    9.5000000000000000e+01,  9.0000000000000000e+00,  2.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  7.8568219999999997e+01,
    8.5996200000000002e+01,  -1.2500000000000000e+01, 1.0000000000000000e+00,
    9.6500000000000000e+01,  4.0000000000000000e+00,  -1.8000000000000000e+01,
    -2.1899999999999999e+01, -1.0000000000000000e+00, 1.0000000000000000e+00,
    8.2922240000000002e+01,  8.6963380000000001e+01,  6.5000000000000000e+01,
    1.2500000000000000e+01,  1.0000000000000000e+02,  9.8000000000000000e+01,
    4.9000000000000000e+01,  3.7000000000000000e+01,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  8.2592740000000006e+01,  9.3147599999999997e+01,
    -1.2000000000000000e+01, 1.0000000000000000e+00,  9.6500000000000000e+01,
    4.0000000000000000e+00,  -1.8000000000000000e+01, -2.1899999999999999e+01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  7.6506460000000004e+01,
    7.8210250000000002e+01,  7.9000000000000000e+01,  1.2000000000000000e+01,
    1.0000000000000000e+02,  9.5000000000000000e+01,  6.8000000000000000e+01,
    6.1000000000000000e+01,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    8.8357460000000003e+01,  9.4257840000000002e+01,  1.2500000000000000e+02,
    6.1299999999999997e+01,  1.0000000000000000e+02,  1.0000000000000000e+02,
    1.4500000000000000e+02,  1.4500000000000000e+02,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  9.0590469999999996e+01,  1.0582863000000000e+02,
    6.2000000000000002e+00,  6.0000000000000000e+00,  9.7000000000000000e+01,
    2.8500000000000000e+01,  4.0000000000000000e+00,  3.6000000000000001e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  1.0000000000000000e+00,
    1.0000000000000000e+00,  1.0000000000000000e+00,  1.0000000000000000e+00,
    1.0000000000000000e+00,  1.0000000000000000e+00,  1.0000000000000000e+00,
    1.0000000000000000e+00,  1.0000000000000000e+00,  -1.2000000000000000e-01,
    -3.8000000000000000e-01, -5.0000000000000000e-01, 1.0000000000000000e+00,
    1.0000000000000000e+00,  1.0000000000000000e+00,  1.0000000000000000e+00,
    1.0000000000000000e+00,  1.0000000000000000e+00,  1.0000000000000000e+00,
    1.0000000000000000e+00,  1.0000000000000000e+00,  1.0000000000000000e+00,
    1.0000000000000000e+00,  1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    -4.7000000000000000e+01, -8.6999999999999993e+00, -9.0000000000000000e+01,
    -5.0000000000000000e+01, -1.0000000000000000e+01, -1.0000000000000000e+01,
    -9.3000000000000000e+01, -8.9000000000000000e+01, 1.0000000000000000e+00,
    -1.0000000000000000e+00, -4.7000000000000000e+01, -8.6999999999999993e+00,
    -9.0000000000000000e+01, -5.0000000000000000e+01, -1.0000000000000000e+01,
    -1.0000000000000000e+01, -8.9000000000000000e+01, -8.5000000000000000e+01,
    1.0000000000000000e+00,  -1.0000000000000000e+00, -4.7000000000000000e+01,
    -8.6999999999999993e+00, -9.0000000000000000e+01, -5.0000000000000000e+01,
    -1.0000000000000000e+01, -1.0000000000000000e+01, -9.1000000000000000e+01,
    -8.8000000000000000e+01, -1.0000000000000000e+00, 5.0000000000000000e-01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  5.0000000000000000e-01,
    -1.0000000000000000e+00, 5.0000000000000000e-01,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  5.0000000000000000e-01,  -1.0000000000000000e+00,
    5.0000000000000000e-01,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    5.0000000000000000e-01,  1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, -4.7000000000000000e+01,
    -8.6999999999999993e+00, -9.0000000000000000e+01, -5.0000000000000000e+01,
    -1.0000000000000000e+01, -1.0000000000000000e+01, -9.3000000000000000e+01,
    -8.9000000000000000e+01, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    -4.7000000000000000e+01, -8.6999999999999993e+00, -9.0000000000000000e+01,
    -5.0000000000000000e+01, -1.0000000000000000e+01, -1.0000000000000000e+01,
    -8.9000000000000000e+01, -8.5000000000000000e+01, 1.0000000000000000e+00,
    -1.0000000000000000e+00, -4.7000000000000000e+01, -8.6999999999999993e+00,
    -9.0000000000000000e+01, -5.0000000000000000e+01, -1.0000000000000000e+01,
    -1.0000000000000000e+01, -9.1000000000000000e+01, -8.8000000000000000e+01,
    -1.0000000000000000e+00, 5.0000000000000000e-01,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  5.0000000000000000e-01,  -1.0000000000000000e+00,
    5.0000000000000000e-01,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    5.0000000000000000e-01,  -1.0000000000000000e+00, 5.0000000000000000e-01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  5.0000000000000000e-01,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    -1.0000000000000000e+00, -4.7000000000000000e+01, -8.6999999999999993e+00,
    -9.0000000000000000e+01, -5.0000000000000000e+01, -1.0000000000000000e+01,
    -1.0000000000000000e+01, -9.3000000000000000e+01, -8.9000000000000000e+01,
    1.0000000000000000e+00,  -1.0000000000000000e+00, -4.7000000000000000e+01,
    -8.6999999999999993e+00, -9.0000000000000000e+01, -5.0000000000000000e+01,
    -1.0000000000000000e+01, -1.0000000000000000e+01, -8.9000000000000000e+01,
    -8.5000000000000000e+01, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    -4.7000000000000000e+01, -8.6999999999999993e+00, -9.0000000000000000e+01,
    -5.0000000000000000e+01, -1.0000000000000000e+01, -1.0000000000000000e+01,
    -9.1000000000000000e+01, -8.8000000000000000e+01, -1.0000000000000000e+00,
    5.0000000000000000e-01,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    5.0000000000000000e-01,  -1.0000000000000000e+00, 5.0000000000000000e-01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  5.0000000000000000e-01,
    -1.0000000000000000e+00, 5.0000000000000000e-01,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  5.0000000000000000e-01,  -1.0000000000000000e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    -1.0000000000000000e+00, -1.0000000000000000e+00, -1.0000000000000000e+00,
    1.0000000000000000e+00,  -1.0000000000000000e+00, -4.7000000000000000e+01,
    -8.6999999999999993e+00, -9.0000000000000000e+01, -5.0000000000000000e+01,
    -1.0000000000000000e+01, -1.0000000000000000e+01, -9.3000000000000000e+01,
    -8.9000000000000000e+01, 1.0000000000000000e+00,  -1.0000000000000000e+00,
    -4.7000000000000000e+01, -8.6999999999999993e+00, -9.0000000000000000e+01,
    -5.0000000000000000e+01, -1.0000000000000000e+01, -1.0000000000000000e+01,
    -8.9000000000000000e+01, -8.5000000000000000e+01, 1.0000000000000000e+00,
    -1.0000000000000000e+00, -4.7000000000000000e+01, -8.6999999999999993e+00,
    -9.0000000000000000e+01, -5.0000000000000000e+01, -1.0000000000000000e+01,
    -1.0000000000000000e+01, -9.1000000000000000e+01, -8.8000000000000000e+01,
    -1.0000000000000000e+00, 5.0000000000000000e-01,  -1.0000000000000000e+00,
    1.0000000000000000e+00,  5.0000000000000000e-01,  -1.0000000000000000e+00,
    5.0000000000000000e-01,  -1.0000000000000000e+00, 1.0000000000000000e+00,
    5.0000000000000000e-01,  -1.0000000000000000e+00, 5.0000000000000000e-01,
    -1.0000000000000000e+00, 1.0000000000000000e+00,  5.0000000000000000e-01};

real_t g[] = {
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00,
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00,
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00,
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00,
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00,
    +0e+00, -2e+00, -2e+00, -2e+00, -2e+00, -2e+00, -2e+00, -2e+00, -2e+00,
    +0e+00, -2e+00, +0e+00, +2e-03, +2e-03, +2e-03, +2e-03, +2e-03, +2e-03,
    +1e-03, +2e-03, +2e-03, +2e-03, +0e+00, -2e-03, -2e-03, -2e-03, -2e-03,
    -2e-03, -2e-03, -1e-03, -2e-03, -2e-03, -2e-03, +0e+00, +0e+00, +0e+00,
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +2e-03, +2e-03,
    +2e-03, +2e-03, +2e-03, +2e-03, +1e-03, +2e-03, +2e-03, +2e-03, +0e+00,
    -2e-03, -2e-03, -2e-03, -2e-03, -2e-03, -2e-03, -1e-03, -2e-03, -2e-03,
    -2e-03, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00,
    +0e+00, +0e+00, +2e-03, +2e-03, +2e-03, +2e-03, +2e-03, +2e-03, +1e-03,
    +2e-03, +2e-03, +2e-03, +0e+00, -2e-03, -2e-03, -2e-03, -2e-03, -2e-03,
    -2e-03, -1e-03, -2e-03, -2e-03, -2e-03, +0e+00, +0e+00, +0e+00, +0e+00,
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +1e-01, +1e-01, +1e-01,
    +1e-01, +1e-01, +1e-01, +1e-01, +1e-01, +1e-01, +1e-01, +0e+00, -1e-01,
    -1e-01, -1e-01, -1e-01, -1e-01, -1e-01, -1e-01, -1e-01, -1e-01, -1e-01,
    +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00, +0e+00};

real_t lb[] = {
    0, 0,  0, 0, 0,  0, 0, 0, 0,  0, 0,    0, 0,    0,  0, 0,  0, 0,  0, 0,
    0, 0,  0, 0, 0,  0, 0, 0, 0,  0, 0,    0, 0,    0,  0, 0,  0, 0,  0, 0,
    0, 0,  0, 0, 0,  0, 0, 0, 0,  0, -Inf, 0, -Inf, 0,  0, 0,  0, 0,  0, 0,
    0, 0,  0, 0, 0,  0, 0, 0, 10, 5, 10,   5, 0,    10, 0, 2,  0, 10, 0, 0,
    0, 0,  0, 0, 0,  0, 0, 0, 0,  0, 0,    0, 0,    0,  0, 0,  0, 0,  0, 10,
    5, 10, 5, 0, 10, 0, 5, 0, 10, 0, 0,    0, 0,    0,  0, 0,  0, 0,  0, 0,
    0, 0,  0, 0, 0,  0, 0, 0, 0,  0, 10,   5, 10,   5,  0, 10, 0, 5,  0, 10,
    0, 0,  0, 0, 0,  0, 0, 0, 0,  0, 0,    0, 0,    0,  0, 0,  0, 0,  0, 0,
    0, 0,  0, 0, 0,  0, 0, 0, 0,  0, 0,    0, 0,    0,  0, 0,  0, 0,  0, 0};

real_t ub[] = {
    Inf, Inf, Inf, Inf, Inf, Inf, Inf, Inf,  Inf, Inf, Inf, Inf, Inf, Inf, Inf,
    Inf, Inf, Inf, Inf, Inf, Inf, Inf, Inf,  Inf, Inf, Inf, Inf, Inf, Inf, Inf,
    Inf, Inf, Inf, Inf, Inf, Inf, Inf, Inf,  Inf, Inf, Inf, Inf, Inf, Inf, Inf,
    0,   92,  39,  87,  29,  0,   20,  0,    28,  20,  71,  Inf, 130, 45,  53,
    55,  75,  112, 0,   73,  480, 154, 121,  50,  30,  77,  20,  0,   18,  0,
    5,   20,  71,  Inf, Inf, Inf, Inf, Inf,  Inf, Inf, Inf, Inf, Inf, 130, 55,
    93,  60,  75,  115, 0,   67,  480, 154,  121, 50,  20,  37,  15,  0,   15,
    0,   8,   20,  71,  Inf, Inf, Inf, Inf,  Inf, Inf, Inf, Inf, Inf, Inf, 130,
    55,  93,  60,  75,  105, 0,   67,  4980, 154, 110, 50,  20,  37,  15,  0,
    25,  0,   8,   20,  71,  Inf, Inf, Inf,  Inf, Inf, Inf, Inf, Inf, Inf, Inf,
    20,  20,  20,  20,  0,   20,  0,   20,   0,   20,  0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   Inf, Inf,  Inf, Inf, Inf, Inf, Inf, Inf, Inf};

real_t lbA[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0,    0,    0,    0,    0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0,    0,    0,    0,    0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0,    0,    0,    0,    0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -Inf, -Inf, -Inf, -Inf, -Inf, -Inf, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0,    0,    0};

real_t ubA[] = {0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   Inf, Inf, Inf, Inf, Inf, Inf, Inf, Inf, Inf, Inf, Inf,
                Inf, Inf, Inf, Inf, Inf, Inf, Inf};

long H_nnz = sizeof(H_val) / sizeof(real_t);
long A_nnz = sizeof(A_val) / sizeof(real_t);
