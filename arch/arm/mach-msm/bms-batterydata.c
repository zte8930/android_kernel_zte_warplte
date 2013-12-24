/* Copyright (c) 2011-2012, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/mfd/pm8xxx/batterydata-lib.h>

//zte add
#include <asm/mach-types.h>
#include <linux/kernel.h>

static struct single_row_lut fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut pc_sf = {
	.rows		= 1,
	.cols		= 1,
	.row_entries={0},
	.percent	= {100},
	.sf			= {
				{100}
	}
};

//default
static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {2542, 2557, 2554, 2551, 2537},
	.cols	= 5
};

static struct sf_lut rbatt_sf = { 
        .rows           = 28, 
        .cols           = 5,
        /* row_entries are temperature */
        .row_entries            = {-20, 0, 25, 40, 60},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {
{1165,266,100,82,75},
{1128,277,105,85,76},
{1099,288,110,89,79},
{1102,295,116,92,81},
{1073,314,122,97,84},
{1100,290,128,100,86},
{1123,288,135,105,89},
{1142,295,135,112,93},
{1169,302,109,93,82},
{1209,315,108,86,78},
{1260,333,112,91,81},
{1323,360,118,95,84},
{1397,396,124,97,87},
{1480,439,133,99,86},
{1570,482,142,99,83},
{1681,518,144,99,82},
{1920,550,149,101,83},
{2413,642,162,106,86},
{1555,583,159,107,87},
{1584,610,166,110,88},
{1638,639,174,114,88},
{1770,671,183,116,88},
{1980,703,189,115,87},
{2273,734,192,117,89},
{2692,779,208,126,96},
{3308,843,234,143,106},
{4365,935,274,168,115},
{7165,2447,428,286,144},
       
	 }
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4340, 4337, 4332, 4328, 4320},
				{4251, 4261, 4263, 4261, 4256},
				{4181, 4200, 4204, 4203, 4199},
				{4116, 4143, 4148, 4147, 4143},
				{4061, 4090, 4095, 4093, 4090},
				{3987, 4037, 4046, 4045, 4040},
				{3937, 3968, 3994, 3995, 3994},
				{3895, 3922, 3953, 3955, 3952},
				{3855, 3885, 3909, 3913, 3912},
				{3822, 3851, 3859, 3863, 3862},
				{3795, 3822, 3830, 3830, 3830},
				{3773, 3800, 3807, 3808, 3808},
				{3754, 3785, 3789, 3790, 3789},
				{3736, 3775, 3776, 3774, 3773},
				{3720, 3765, 3767, 3761, 3754},
				{3704, 3750, 3755, 3746, 3732},
				{3684, 3725, 3729, 3721, 3707},
				{3655, 3695, 3696, 3689, 3675},
				{3618, 3675, 3676, 3671, 3660},
				{3608, 3670, 3674, 3668, 3657},
				{3595, 3663, 3669, 3664, 3653},
				{3578, 3650, 3661, 3655, 3640},
				{3555, 3626, 3640, 3631, 3613},
				{3523, 3587, 3600, 3589, 3571},
				{3481, 3531, 3547, 3536, 3519},
				{3423, 3458, 3481, 3471, 3455},
				{3343, 3361, 3394, 3388, 3370},
				{3217, 3229, 3270, 3263, 3241},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data palladium_data_default = {
	.fcc				= 2500,
	.fcc_temp_lut		= &fcc_temp,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
        .pc_sf_lut			= &pc_sf,
        .rbatt_sf_lut		=&rbatt_sf,
	.default_rbatt_mohm		=133,

};

//4350MV_2500MAH
static struct single_row_lut fcc_temp_4350MV_2500MAH = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {2542, 2557, 2554, 2551, 2537},
	.cols	= 5
};


static struct sf_lut rbatt_sf_4350MV_2500MAH = { 
        .rows           = 28, 
        .cols           = 5,
        /* row_entries are temperature */
        .row_entries            = {-20, 0, 25, 40, 60},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {
{1165,266,100,82,75},
{1128,277,105,85,76},
{1099,288,110,89,79},
{1102,295,116,92,81},
{1073,314,122,97,84},
{1100,290,128,100,86},
{1123,288,135,105,89},
{1142,295,135,112,93},
{1169,302,109,93,82},
{1209,315,108,86,78},
{1260,333,112,91,81},
{1323,360,118,95,84},
{1397,396,124,97,87},
{1480,439,133,99,86},
{1570,482,142,99,83},
{1681,518,144,99,82},
{1920,550,149,101,83},
{2413,642,162,106,86},
{1555,583,159,107,87},
{1584,610,166,110,88},
{1638,639,174,114,88},
{1770,671,183,116,88},
{1980,703,189,115,87},
{2273,734,192,117,89},
{2692,779,208,126,96},
{3308,843,234,143,106},
{4365,935,274,168,115},
{7165,2447,428,286,144},
       
	 }
};

static struct pc_temp_ocv_lut pc_temp_ocv_4350MV_2500MAH = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4340, 4337, 4332, 4328, 4320},
				{4251, 4261, 4263, 4261, 4256},
				{4181, 4200, 4204, 4203, 4199},
				{4116, 4143, 4148, 4147, 4143},
				{4061, 4090, 4095, 4093, 4090},
				{3987, 4037, 4046, 4045, 4040},
				{3937, 3968, 3994, 3995, 3994},
				{3895, 3922, 3953, 3955, 3952},
				{3855, 3885, 3909, 3913, 3912},
				{3822, 3851, 3859, 3863, 3862},
				{3795, 3822, 3830, 3830, 3830},
				{3773, 3800, 3807, 3808, 3808},
				{3754, 3785, 3789, 3790, 3789},
				{3736, 3775, 3776, 3774, 3773},
				{3720, 3765, 3767, 3761, 3754},
				{3704, 3750, 3755, 3746, 3732},
				{3684, 3725, 3729, 3721, 3707},
				{3655, 3695, 3696, 3689, 3675},
				{3618, 3675, 3676, 3671, 3660},
				{3608, 3670, 3674, 3668, 3657},
				{3595, 3663, 3669, 3664, 3653},
				{3578, 3650, 3661, 3655, 3640},
				{3555, 3626, 3640, 3631, 3613},
				{3523, 3587, 3600, 3589, 3571},
				{3481, 3531, 3547, 3536, 3519},
				{3423, 3458, 3481, 3471, 3455},
				{3343, 3361, 3394, 3388, 3370},
				{3217, 3229, 3270, 3263, 3241},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data palladium_data_4350MV_2500MAH = {
	.fcc				= 2500,
	.fcc_temp_lut		= &fcc_temp_4350MV_2500MAH,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut	= &pc_temp_ocv_4350MV_2500MAH,
        .pc_sf_lut			= &pc_sf,
        .rbatt_sf_lut		=&rbatt_sf_4350MV_2500MAH,
	.default_rbatt_mohm		=133,

};

//4350MV_1780MAH
static struct single_row_lut fcc_temp_4350MV_1780MAH = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {1796, 1794, 1807, 1805, 1798},
	.cols	= 5
};

static struct sf_lut rbatt_sf_4350MV_1780MAH = { 
        .rows           = 28, 
        .cols           = 5,
        /* row_entries are temperature */
        .row_entries            = {-20, 0, 25, 40, 60},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {

{723,371,100,77,68},
{720,359,103,80,70},
{714,350,106,82,72},
{725,346,109,83,74},
{757,348,112,85,75},
{793,349,114,87,77},
{839,353,116,88,79},
{900,356,116,89,80},
{975,360,108,85,78},
{1065,364,108,79,71},
{1169,369,111,81,72},
{1283,377,116,83,74},
{1431,386,121,85,77},
{1602,398,127,87,78},
{1819,414,134,90,75},
{2116,435,141,91,75},
{2547,464,144,92,76},
{3277,506,147,91,73},
{2762,477,145,90,73},
{3045,492,150,92,74},
{3364,507,155,94,76},
{3770,525,160,97,77},
{4254,556,168,99,79},
{4854,602,175,102,80},
{5677,661,180,104,78},
{6780,747,187,103,80},
{8382,882,208,109,84},
{11288,1120,241,120,88},

	 }
};

static struct pc_temp_ocv_lut pc_temp_ocv_4350MV_1780MAH = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4338, 4335, 4332, 4327, 4318},
				{4237, 4249, 4260, 4259, 4256},
				{4161, 4187, 4202, 4203, 4199},
				{4092, 4128, 4147, 4148, 4145},
				{4023, 4073, 4095, 4095, 4093},
				{3969, 4016, 4046, 4047, 4044},
				{3922, 3958, 3997, 3999, 3999},
				{3883, 3916, 3957, 3959, 3958},
				{3852, 3880, 3914, 3919, 3920},
				{3826, 3848, 3867, 3875, 3878},
				{3804, 3821, 3835, 3838, 3838},
				{3784, 3800, 3812, 3814, 3814},
				{3766, 3782, 3794, 3794, 3795},
				{3749, 3765, 3780, 3778, 3779},
				{3731, 3751, 3770, 3767, 3761},
				{3712, 3736, 3759, 3753, 3741},
				{3688, 3723, 3736, 3730, 3718},
				{3656, 3709, 3700, 3693, 3682},
				{3614, 3692, 3679, 3673, 3663},
				{3601, 3686, 3677, 3671, 3662},
				{3587, 3680, 3675, 3669, 3660},
				{3571, 3671, 3671, 3666, 3656},
				{3552, 3658, 3661, 3655, 3643},
				{3530, 3638, 3631, 3623, 3612},
				{3500, 3605, 3580, 3575, 3566},
				{3461, 3554, 3515, 3516, 3509},
				{3398, 3476, 3435, 3439, 3429},
				{3290, 3356, 3311, 3313, 3299},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data palladium_data_4350MV_1780MAH = {
	.fcc				= 1780,
	.fcc_temp_lut		= &fcc_temp_4350MV_1780MAH,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut	= &pc_temp_ocv_4350MV_1780MAH,
	.pc_sf_lut			= &pc_sf,	
         .rbatt_sf_lut		=&rbatt_sf_4350MV_1780MAH,
	.default_rbatt_mohm		=147,
};

//4200MV_1900MAH
static struct single_row_lut fcc_temp_4200MV_1900MAH = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {1898, 1902, 1902, 1900, 1893},
	.cols	= 5
};

static struct sf_lut rbatt_sf_4200MV_1900MAH = { 
        .rows           = 28, 
        .cols           = 5,
        /* row_entries are temperature */
        .row_entries            = {-20, 0, 25, 40, 60},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {
{721,274,100,79,71},
{776,279,104,82,73},
{804,280,108,85,75},
{819,281,110,86,77},
{841,283,113,87,78},
{867,286,114,88,79},
{901,288,115,88,79},
{941,292,111,87,78},
{993,297,111,82,73},
{1048,303,114,84,74},
{1126,312,119,86,76},
{1213,325,125,89,78},
{1321,345,132,92,79},
{1453,379,138,96,78},
{1628,421,143,98,78},
{1881,473,145,97,79},
{2274,528,147,94,76},
{3018,598,175,107,84},
{2566,387,146,98,80},
{2836,403,149,99,80},
{3187,428,153,99,79},
{3612,457,155,98,78},
{4160,497,158,98,78},
{4899,551,162,101,81},
{5904,626,172,106,83},
{7316,734,185,112,85},
{9426,903,201,116,88},
{13647,1342,230,128,117},

	}
};

static struct pc_temp_ocv_lut pc_temp_ocv_4200MV_1900MAH = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4189, 4188, 4185, 4182, 4177},
				{4116, 4125, 4128, 4127, 4124},
				{4049, 4077, 4081, 4081, 4078},
				{3998, 4027, 4038, 4038, 4036},
				{3956, 3978, 3997, 3998, 3997},
				{3922, 3941, 3963, 3963, 3961},
				{3893, 3907, 3931, 3931, 3929},
				{3867, 3877, 3902, 3902, 3900},
				{3844, 3850, 3859, 3870, 3869},
				{3823, 3826, 3830, 3831, 3831},
				{3804, 3806, 3808, 3809, 3809},
				{3786, 3790, 3792, 3791, 3792},
				{3770, 3775, 3780, 3778, 3778},
				{3754, 3762, 3772, 3768, 3767},
				{3739, 3749, 3764, 3761, 3751},
				{3723, 3736, 3752, 3746, 3733},
				{3703, 3722, 3727, 3721, 3708},
				{3677, 3705, 3690, 3682, 3671},
				{3634, 3682, 3676, 3669, 3659},
				{3626, 3677, 3673, 3667, 3657},
				{3613, 3669, 3668, 3664, 3654},
				{3596, 3657, 3659, 3654, 3642},
				{3574, 3635, 3636, 3626, 3614},
				{3546, 3602, 3595, 3585, 3575},
				{3508, 3557, 3541, 3535, 3529},
				{3457, 3494, 3478, 3479, 3473},
				{3389, 3404, 3404, 3403, 3393},
				{3277, 3274, 3281, 3279, 3270},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data palladium_data_4200MV_1900MAH = {
	.fcc				= 1900,
	.fcc_temp_lut		= &fcc_temp_4200MV_1900MAH,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut	= &pc_temp_ocv_4200MV_1900MAH,
	.pc_sf_lut			= &pc_sf,
	.rbatt_sf_lut		=&rbatt_sf_4200MV_1900MAH,
	.default_rbatt_mohm		=158,

};

//4350MV_1735MAH
static struct single_row_lut fcc_temp_4350MV_1735MAH = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {1796, 1794, 1807, 1805, 1798},
	.cols	= 5
};

static struct sf_lut rbatt_sf_4350MV_1735MAH = { 
        .rows           = 28, 
        .cols           = 5,
        /* row_entries are temperature */
        .row_entries            = {-20, 0, 25, 40, 60},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {

{723,371,100,77,68},
{720,359,103,80,70},
{714,350,106,82,72},
{725,346,109,83,74},
{757,348,112,85,75},
{793,349,114,87,77},
{839,353,116,88,79},
{900,356,116,89,80},
{975,360,108,85,78},
{1065,364,108,79,71},
{1169,369,111,81,72},
{1283,377,116,83,74},
{1431,386,121,85,77},
{1602,398,127,87,78},
{1819,414,134,90,75},
{2116,435,141,91,75},
{2547,464,144,92,76},
{3277,506,147,91,73},
{2762,477,145,90,73},
{3045,492,150,92,74},
{3364,507,155,94,76},
{3770,525,160,97,77},
{4254,556,168,99,79},
{4854,602,175,102,80},
{5677,661,180,104,78},
{6780,747,187,103,80},
{8382,882,208,109,84},
{11288,1120,241,120,88},

	 }
};

static struct pc_temp_ocv_lut pc_temp_ocv_4350MV_1735MAH = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4338, 4335, 4332, 4327, 4318},
				{4237, 4249, 4260, 4259, 4256},
				{4161, 4187, 4202, 4203, 4199},
				{4092, 4128, 4147, 4148, 4145},
				{4023, 4073, 4095, 4095, 4093},
				{3969, 4016, 4046, 4047, 4044},
				{3922, 3958, 3997, 3999, 3999},
				{3883, 3916, 3957, 3959, 3958},
				{3852, 3880, 3914, 3919, 3920},
				{3826, 3848, 3867, 3875, 3878},
				{3804, 3821, 3835, 3838, 3838},
				{3784, 3800, 3812, 3814, 3814},
				{3766, 3782, 3794, 3794, 3795},
				{3749, 3765, 3780, 3778, 3779},
				{3731, 3751, 3770, 3767, 3761},
				{3712, 3736, 3759, 3753, 3741},
				{3688, 3723, 3736, 3730, 3718},
				{3656, 3709, 3700, 3693, 3682},
				{3614, 3692, 3679, 3673, 3663},
				{3601, 3686, 3677, 3671, 3662},
				{3587, 3680, 3675, 3669, 3660},
				{3571, 3671, 3671, 3666, 3656},
				{3552, 3658, 3661, 3655, 3643},
				{3530, 3638, 3631, 3623, 3612},
				{3500, 3605, 3580, 3575, 3566},
				{3461, 3554, 3515, 3516, 3509},
				{3398, 3476, 3435, 3439, 3429},
				{3290, 3356, 3311, 3313, 3299},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data palladium_data_4350MV_1735MAH = {
	.fcc				= 1735,
	.fcc_temp_lut		= &fcc_temp_4350MV_1735MAH,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut	= &pc_temp_ocv_4350MV_1735MAH,
	.pc_sf_lut			= &pc_sf,	
         .rbatt_sf_lut		=&rbatt_sf_4350MV_1735MAH,
	.default_rbatt_mohm		=147,
};

static struct single_row_lut fcc_temp_4350MV_2070MAH = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {2053, 2083, 2070, 2053, 2026},
	.cols	= 5
};

static struct sf_lut rbatt_sf_4350MV_2070MAH = {
	.rows		= 29,
	.cols		= 5,
	.row_entries		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.sf		= {
				{1161, 254, 100, 84, 79},
				{1226, 254, 100, 86, 80},
				{1225, 261, 102, 86, 80},
				{1352, 273, 107, 88, 81},
				{1613, 285, 112, 92, 84},
				{1540, 307, 119, 95, 86},
				{1482, 297, 128, 100, 88},
				{1427, 266, 138, 109, 94},
				{1387, 262, 115, 98, 87},
				{1444, 259, 104, 89, 82},
				{1561, 263, 105, 90, 84},
				{1727, 267, 110, 93, 87},
				{1893, 270, 112, 98, 89},
				{2055, 268, 117, 92, 86},
				{2215, 280, 109, 90, 84},
				{2399, 296, 105, 88, 84},
				{2691, 347, 105, 88, 84},
				{3902, 473, 128, 98, 90},
				{8511, 589, 184, 132, 115},
				{8842, 564, 182, 138, 122},
				{8043, 600, 190, 143, 128},
				{9907, 648, 202, 151, 135},
				{12224, 710, 228, 165, 145},
				{15740, 804, 261, 184, 155},
				{21133, 930, 300, 207, 169},
				{29069, 1162, 340, 232, 191},
				{40083, 1522, 413, 285, 226},
				{53922, 2634, 632, 427, 350},
				{69724, 7252, 1385, 1374, 679}
	}
};

static struct pc_temp_ocv_lut pc_temp_ocv_4350MV_2070MAH = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4331, 4329, 4324, 4318, 4310},
				{4231, 4257, 4259, 4256, 4250},
				{4166, 4201, 4203, 4201, 4196},
				{4100, 4148, 4151, 4149, 4145},
				{4060, 4096, 4100, 4100, 4096},
				{3970, 4047, 4054, 4053, 4049},
				{3921, 3988, 4007, 4008, 4006},
				{3872, 3937, 3964, 3966, 3965},
				{3825, 3897, 3909, 3913, 3913},
				{3803, 3863, 3871, 3874, 3875},
				{3789, 3836, 3844, 3846, 3847},
				{3776, 3811, 3821, 3823, 3823},
				{3760, 3789, 3800, 3802, 3801},
				{3743, 3769, 3782, 3778, 3771},
				{3719, 3751, 3757, 3751, 3741},
				{3685, 3722, 3723, 3716, 3705},
				{3633, 3696, 3688, 3683, 3676},
				{3533, 3671, 3678, 3670, 3651},
				{3425, 3580, 3600, 3594, 3575},
				{3400, 3552, 3574, 3573, 3554},
				{3368, 3520, 3543, 3542, 3532},
				{3337, 3484, 3507, 3508, 3498},
				{3303, 3446, 3472, 3472, 3464},
				{3273, 3407, 3435, 3435, 3427},
				{3245, 3366, 3396, 3396, 3389},
				{3219, 3318, 3347, 3345, 3338},
				{3185, 3259, 3280, 3275, 3268},
				{3118, 3175, 3182, 3168, 3164},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data palladium_data_4350MV_2070MAH = {
	.fcc				= 2070,
	.fcc_temp_lut			= &fcc_temp_4350MV_2070MAH,
	.fcc_sf_lut				= &fcc_sf,
	.pc_temp_ocv_lut		= &pc_temp_ocv_4350MV_2070MAH,
	.pc_sf_lut			= &pc_sf,	
	.rbatt_sf_lut			= &rbatt_sf_4350MV_2070MAH,
	.default_rbatt_mohm	= 170
};

void* get_bms_battery_data(void)
{
	if(machine_is_apollo()	|| machine_is_demeter())	//P893U10,P893A30
	{
		printk("set bms battery data for 4350MV 2500MAH");
		return (void*)&palladium_data_4350MV_2500MAH;
	}
	else if(machine_is_becky()	|| machine_is_metis())		//P893A20
	{
		printk("set bms battery data for 4350MV 1735MAH");
		return (void*)&palladium_data_4350MV_1735MAH;
	}
	else if(machine_is_warplte()	|| machine_is_coeus()	|| machine_is_nestor()	|| machine_is_gaea()
		|| machine_is_hera())//warplte	//N9510,P893V10,P893A21,P893A22
	{
		printk("set bms battery data for 4350MV 2070MAH");
		return (void*)&palladium_data_4350MV_2070MAH;
	}
	else if(machine_is_nex())
	{
		printk("set bms battery data for 4200MV 1900MAH");
		return (void*)&palladium_data_4200MV_1900MAH;
	}
	else
	{
		printk("default bms battery data");
		return (void*)&palladium_data_default;
	}
}
//zte add,end

#if 0
static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 65},
	.y		= {1492, 1492, 1493, 1483, 1502},
	.cols	= 5
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.ocv		= {
				{4173, 4167, 4163, 4156, 4154},
				{4104, 4107, 4108, 4102, 4104},
				{4057, 4072, 4069, 4061, 4060},
				{3973, 4009, 4019, 4016, 4020},
				{3932, 3959, 3981, 3982, 3983},
				{3899, 3928, 3954, 3950, 3950},
				{3868, 3895, 3925, 3921, 3920},
				{3837, 3866, 3898, 3894, 3892},
				{3812, 3841, 3853, 3856, 3862},
				{3794, 3818, 3825, 3823, 3822},
				{3780, 3799, 3804, 3804, 3803},
				{3768, 3787, 3790, 3788, 3788},
				{3757, 3779, 3778, 3775, 3776},
				{3747, 3772, 3771, 3766, 3765},
				{3736, 3763, 3766, 3760, 3746},
				{3725, 3749, 3756, 3747, 3729},
				{3714, 3718, 3734, 3724, 3706},
				{3701, 3703, 3696, 3689, 3668},
				{3675, 3695, 3682, 3675, 3662},
				{3670, 3691, 3680, 3673, 3661},
				{3661, 3686, 3679, 3672, 3656},
				{3649, 3680, 3676, 3669, 3641},
				{3633, 3669, 3667, 3655, 3606},
				{3610, 3647, 3640, 3620, 3560},
				{3580, 3607, 3596, 3572, 3501},
				{3533, 3548, 3537, 3512, 3425},
				{3457, 3468, 3459, 3429, 3324},
				{3328, 3348, 3340, 3297, 3172},
				{3000, 3000, 3000, 3000, 3000}
	}
};

static struct sf_lut rbatt_sf = {
	.rows		= 29,
	.cols		= 5,
	/* row_entries are temperature */
	.row_entries	= {-20, 0, 20, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.sf		= {
				{357, 187, 100, 91, 91},
				{400, 208, 105, 94, 94},
				{390, 204, 106, 95, 96},
				{391, 201, 108, 98, 98},
				{391, 202, 110, 98, 100},
				{390, 200, 110, 99, 102},
				{389, 200, 110, 99, 102},
				{393, 202, 101, 93, 100},
				{407, 205, 99, 89, 94},
				{428, 208, 100, 91, 96},
				{455, 212, 102, 92, 98},
				{495, 220, 104, 93, 101},
				{561, 232, 107, 95, 102},
				{634, 245, 112, 98, 98},
				{714, 258, 114, 98, 98},
				{791, 266, 114, 97, 100},
				{871, 289, 108, 95, 97},
				{973, 340, 124, 108, 105},
				{489, 241, 109, 96, 99},
				{511, 246, 110, 96, 99},
				{534, 252, 111, 95, 98},
				{579, 263, 112, 96, 96},
				{636, 276, 111, 95, 97},
				{730, 294, 109, 96, 99},
				{868, 328, 112, 98, 104},
				{1089, 374, 119, 101, 115},
				{1559, 457, 128, 105, 213},
				{12886, 1026, 637, 422, 3269},
				{170899, 127211, 98968, 88907, 77102},
	}
};

struct bms_battery_data palladium_1500_data = {
	.fcc			= 1500,
	.fcc_temp_lut		= &fcc_temp,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
	.rbatt_sf_lut		= &rbatt_sf,
	.default_rbatt_mohm	= 236,
};
#endif
