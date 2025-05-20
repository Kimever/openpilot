#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8151132212255276688) {
   out_8151132212255276688[0] = delta_x[0] + nom_x[0];
   out_8151132212255276688[1] = delta_x[1] + nom_x[1];
   out_8151132212255276688[2] = delta_x[2] + nom_x[2];
   out_8151132212255276688[3] = delta_x[3] + nom_x[3];
   out_8151132212255276688[4] = delta_x[4] + nom_x[4];
   out_8151132212255276688[5] = delta_x[5] + nom_x[5];
   out_8151132212255276688[6] = delta_x[6] + nom_x[6];
   out_8151132212255276688[7] = delta_x[7] + nom_x[7];
   out_8151132212255276688[8] = delta_x[8] + nom_x[8];
   out_8151132212255276688[9] = delta_x[9] + nom_x[9];
   out_8151132212255276688[10] = delta_x[10] + nom_x[10];
   out_8151132212255276688[11] = delta_x[11] + nom_x[11];
   out_8151132212255276688[12] = delta_x[12] + nom_x[12];
   out_8151132212255276688[13] = delta_x[13] + nom_x[13];
   out_8151132212255276688[14] = delta_x[14] + nom_x[14];
   out_8151132212255276688[15] = delta_x[15] + nom_x[15];
   out_8151132212255276688[16] = delta_x[16] + nom_x[16];
   out_8151132212255276688[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8615557392453245857) {
   out_8615557392453245857[0] = -nom_x[0] + true_x[0];
   out_8615557392453245857[1] = -nom_x[1] + true_x[1];
   out_8615557392453245857[2] = -nom_x[2] + true_x[2];
   out_8615557392453245857[3] = -nom_x[3] + true_x[3];
   out_8615557392453245857[4] = -nom_x[4] + true_x[4];
   out_8615557392453245857[5] = -nom_x[5] + true_x[5];
   out_8615557392453245857[6] = -nom_x[6] + true_x[6];
   out_8615557392453245857[7] = -nom_x[7] + true_x[7];
   out_8615557392453245857[8] = -nom_x[8] + true_x[8];
   out_8615557392453245857[9] = -nom_x[9] + true_x[9];
   out_8615557392453245857[10] = -nom_x[10] + true_x[10];
   out_8615557392453245857[11] = -nom_x[11] + true_x[11];
   out_8615557392453245857[12] = -nom_x[12] + true_x[12];
   out_8615557392453245857[13] = -nom_x[13] + true_x[13];
   out_8615557392453245857[14] = -nom_x[14] + true_x[14];
   out_8615557392453245857[15] = -nom_x[15] + true_x[15];
   out_8615557392453245857[16] = -nom_x[16] + true_x[16];
   out_8615557392453245857[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5897624149051276938) {
   out_5897624149051276938[0] = 1.0;
   out_5897624149051276938[1] = 0.0;
   out_5897624149051276938[2] = 0.0;
   out_5897624149051276938[3] = 0.0;
   out_5897624149051276938[4] = 0.0;
   out_5897624149051276938[5] = 0.0;
   out_5897624149051276938[6] = 0.0;
   out_5897624149051276938[7] = 0.0;
   out_5897624149051276938[8] = 0.0;
   out_5897624149051276938[9] = 0.0;
   out_5897624149051276938[10] = 0.0;
   out_5897624149051276938[11] = 0.0;
   out_5897624149051276938[12] = 0.0;
   out_5897624149051276938[13] = 0.0;
   out_5897624149051276938[14] = 0.0;
   out_5897624149051276938[15] = 0.0;
   out_5897624149051276938[16] = 0.0;
   out_5897624149051276938[17] = 0.0;
   out_5897624149051276938[18] = 0.0;
   out_5897624149051276938[19] = 1.0;
   out_5897624149051276938[20] = 0.0;
   out_5897624149051276938[21] = 0.0;
   out_5897624149051276938[22] = 0.0;
   out_5897624149051276938[23] = 0.0;
   out_5897624149051276938[24] = 0.0;
   out_5897624149051276938[25] = 0.0;
   out_5897624149051276938[26] = 0.0;
   out_5897624149051276938[27] = 0.0;
   out_5897624149051276938[28] = 0.0;
   out_5897624149051276938[29] = 0.0;
   out_5897624149051276938[30] = 0.0;
   out_5897624149051276938[31] = 0.0;
   out_5897624149051276938[32] = 0.0;
   out_5897624149051276938[33] = 0.0;
   out_5897624149051276938[34] = 0.0;
   out_5897624149051276938[35] = 0.0;
   out_5897624149051276938[36] = 0.0;
   out_5897624149051276938[37] = 0.0;
   out_5897624149051276938[38] = 1.0;
   out_5897624149051276938[39] = 0.0;
   out_5897624149051276938[40] = 0.0;
   out_5897624149051276938[41] = 0.0;
   out_5897624149051276938[42] = 0.0;
   out_5897624149051276938[43] = 0.0;
   out_5897624149051276938[44] = 0.0;
   out_5897624149051276938[45] = 0.0;
   out_5897624149051276938[46] = 0.0;
   out_5897624149051276938[47] = 0.0;
   out_5897624149051276938[48] = 0.0;
   out_5897624149051276938[49] = 0.0;
   out_5897624149051276938[50] = 0.0;
   out_5897624149051276938[51] = 0.0;
   out_5897624149051276938[52] = 0.0;
   out_5897624149051276938[53] = 0.0;
   out_5897624149051276938[54] = 0.0;
   out_5897624149051276938[55] = 0.0;
   out_5897624149051276938[56] = 0.0;
   out_5897624149051276938[57] = 1.0;
   out_5897624149051276938[58] = 0.0;
   out_5897624149051276938[59] = 0.0;
   out_5897624149051276938[60] = 0.0;
   out_5897624149051276938[61] = 0.0;
   out_5897624149051276938[62] = 0.0;
   out_5897624149051276938[63] = 0.0;
   out_5897624149051276938[64] = 0.0;
   out_5897624149051276938[65] = 0.0;
   out_5897624149051276938[66] = 0.0;
   out_5897624149051276938[67] = 0.0;
   out_5897624149051276938[68] = 0.0;
   out_5897624149051276938[69] = 0.0;
   out_5897624149051276938[70] = 0.0;
   out_5897624149051276938[71] = 0.0;
   out_5897624149051276938[72] = 0.0;
   out_5897624149051276938[73] = 0.0;
   out_5897624149051276938[74] = 0.0;
   out_5897624149051276938[75] = 0.0;
   out_5897624149051276938[76] = 1.0;
   out_5897624149051276938[77] = 0.0;
   out_5897624149051276938[78] = 0.0;
   out_5897624149051276938[79] = 0.0;
   out_5897624149051276938[80] = 0.0;
   out_5897624149051276938[81] = 0.0;
   out_5897624149051276938[82] = 0.0;
   out_5897624149051276938[83] = 0.0;
   out_5897624149051276938[84] = 0.0;
   out_5897624149051276938[85] = 0.0;
   out_5897624149051276938[86] = 0.0;
   out_5897624149051276938[87] = 0.0;
   out_5897624149051276938[88] = 0.0;
   out_5897624149051276938[89] = 0.0;
   out_5897624149051276938[90] = 0.0;
   out_5897624149051276938[91] = 0.0;
   out_5897624149051276938[92] = 0.0;
   out_5897624149051276938[93] = 0.0;
   out_5897624149051276938[94] = 0.0;
   out_5897624149051276938[95] = 1.0;
   out_5897624149051276938[96] = 0.0;
   out_5897624149051276938[97] = 0.0;
   out_5897624149051276938[98] = 0.0;
   out_5897624149051276938[99] = 0.0;
   out_5897624149051276938[100] = 0.0;
   out_5897624149051276938[101] = 0.0;
   out_5897624149051276938[102] = 0.0;
   out_5897624149051276938[103] = 0.0;
   out_5897624149051276938[104] = 0.0;
   out_5897624149051276938[105] = 0.0;
   out_5897624149051276938[106] = 0.0;
   out_5897624149051276938[107] = 0.0;
   out_5897624149051276938[108] = 0.0;
   out_5897624149051276938[109] = 0.0;
   out_5897624149051276938[110] = 0.0;
   out_5897624149051276938[111] = 0.0;
   out_5897624149051276938[112] = 0.0;
   out_5897624149051276938[113] = 0.0;
   out_5897624149051276938[114] = 1.0;
   out_5897624149051276938[115] = 0.0;
   out_5897624149051276938[116] = 0.0;
   out_5897624149051276938[117] = 0.0;
   out_5897624149051276938[118] = 0.0;
   out_5897624149051276938[119] = 0.0;
   out_5897624149051276938[120] = 0.0;
   out_5897624149051276938[121] = 0.0;
   out_5897624149051276938[122] = 0.0;
   out_5897624149051276938[123] = 0.0;
   out_5897624149051276938[124] = 0.0;
   out_5897624149051276938[125] = 0.0;
   out_5897624149051276938[126] = 0.0;
   out_5897624149051276938[127] = 0.0;
   out_5897624149051276938[128] = 0.0;
   out_5897624149051276938[129] = 0.0;
   out_5897624149051276938[130] = 0.0;
   out_5897624149051276938[131] = 0.0;
   out_5897624149051276938[132] = 0.0;
   out_5897624149051276938[133] = 1.0;
   out_5897624149051276938[134] = 0.0;
   out_5897624149051276938[135] = 0.0;
   out_5897624149051276938[136] = 0.0;
   out_5897624149051276938[137] = 0.0;
   out_5897624149051276938[138] = 0.0;
   out_5897624149051276938[139] = 0.0;
   out_5897624149051276938[140] = 0.0;
   out_5897624149051276938[141] = 0.0;
   out_5897624149051276938[142] = 0.0;
   out_5897624149051276938[143] = 0.0;
   out_5897624149051276938[144] = 0.0;
   out_5897624149051276938[145] = 0.0;
   out_5897624149051276938[146] = 0.0;
   out_5897624149051276938[147] = 0.0;
   out_5897624149051276938[148] = 0.0;
   out_5897624149051276938[149] = 0.0;
   out_5897624149051276938[150] = 0.0;
   out_5897624149051276938[151] = 0.0;
   out_5897624149051276938[152] = 1.0;
   out_5897624149051276938[153] = 0.0;
   out_5897624149051276938[154] = 0.0;
   out_5897624149051276938[155] = 0.0;
   out_5897624149051276938[156] = 0.0;
   out_5897624149051276938[157] = 0.0;
   out_5897624149051276938[158] = 0.0;
   out_5897624149051276938[159] = 0.0;
   out_5897624149051276938[160] = 0.0;
   out_5897624149051276938[161] = 0.0;
   out_5897624149051276938[162] = 0.0;
   out_5897624149051276938[163] = 0.0;
   out_5897624149051276938[164] = 0.0;
   out_5897624149051276938[165] = 0.0;
   out_5897624149051276938[166] = 0.0;
   out_5897624149051276938[167] = 0.0;
   out_5897624149051276938[168] = 0.0;
   out_5897624149051276938[169] = 0.0;
   out_5897624149051276938[170] = 0.0;
   out_5897624149051276938[171] = 1.0;
   out_5897624149051276938[172] = 0.0;
   out_5897624149051276938[173] = 0.0;
   out_5897624149051276938[174] = 0.0;
   out_5897624149051276938[175] = 0.0;
   out_5897624149051276938[176] = 0.0;
   out_5897624149051276938[177] = 0.0;
   out_5897624149051276938[178] = 0.0;
   out_5897624149051276938[179] = 0.0;
   out_5897624149051276938[180] = 0.0;
   out_5897624149051276938[181] = 0.0;
   out_5897624149051276938[182] = 0.0;
   out_5897624149051276938[183] = 0.0;
   out_5897624149051276938[184] = 0.0;
   out_5897624149051276938[185] = 0.0;
   out_5897624149051276938[186] = 0.0;
   out_5897624149051276938[187] = 0.0;
   out_5897624149051276938[188] = 0.0;
   out_5897624149051276938[189] = 0.0;
   out_5897624149051276938[190] = 1.0;
   out_5897624149051276938[191] = 0.0;
   out_5897624149051276938[192] = 0.0;
   out_5897624149051276938[193] = 0.0;
   out_5897624149051276938[194] = 0.0;
   out_5897624149051276938[195] = 0.0;
   out_5897624149051276938[196] = 0.0;
   out_5897624149051276938[197] = 0.0;
   out_5897624149051276938[198] = 0.0;
   out_5897624149051276938[199] = 0.0;
   out_5897624149051276938[200] = 0.0;
   out_5897624149051276938[201] = 0.0;
   out_5897624149051276938[202] = 0.0;
   out_5897624149051276938[203] = 0.0;
   out_5897624149051276938[204] = 0.0;
   out_5897624149051276938[205] = 0.0;
   out_5897624149051276938[206] = 0.0;
   out_5897624149051276938[207] = 0.0;
   out_5897624149051276938[208] = 0.0;
   out_5897624149051276938[209] = 1.0;
   out_5897624149051276938[210] = 0.0;
   out_5897624149051276938[211] = 0.0;
   out_5897624149051276938[212] = 0.0;
   out_5897624149051276938[213] = 0.0;
   out_5897624149051276938[214] = 0.0;
   out_5897624149051276938[215] = 0.0;
   out_5897624149051276938[216] = 0.0;
   out_5897624149051276938[217] = 0.0;
   out_5897624149051276938[218] = 0.0;
   out_5897624149051276938[219] = 0.0;
   out_5897624149051276938[220] = 0.0;
   out_5897624149051276938[221] = 0.0;
   out_5897624149051276938[222] = 0.0;
   out_5897624149051276938[223] = 0.0;
   out_5897624149051276938[224] = 0.0;
   out_5897624149051276938[225] = 0.0;
   out_5897624149051276938[226] = 0.0;
   out_5897624149051276938[227] = 0.0;
   out_5897624149051276938[228] = 1.0;
   out_5897624149051276938[229] = 0.0;
   out_5897624149051276938[230] = 0.0;
   out_5897624149051276938[231] = 0.0;
   out_5897624149051276938[232] = 0.0;
   out_5897624149051276938[233] = 0.0;
   out_5897624149051276938[234] = 0.0;
   out_5897624149051276938[235] = 0.0;
   out_5897624149051276938[236] = 0.0;
   out_5897624149051276938[237] = 0.0;
   out_5897624149051276938[238] = 0.0;
   out_5897624149051276938[239] = 0.0;
   out_5897624149051276938[240] = 0.0;
   out_5897624149051276938[241] = 0.0;
   out_5897624149051276938[242] = 0.0;
   out_5897624149051276938[243] = 0.0;
   out_5897624149051276938[244] = 0.0;
   out_5897624149051276938[245] = 0.0;
   out_5897624149051276938[246] = 0.0;
   out_5897624149051276938[247] = 1.0;
   out_5897624149051276938[248] = 0.0;
   out_5897624149051276938[249] = 0.0;
   out_5897624149051276938[250] = 0.0;
   out_5897624149051276938[251] = 0.0;
   out_5897624149051276938[252] = 0.0;
   out_5897624149051276938[253] = 0.0;
   out_5897624149051276938[254] = 0.0;
   out_5897624149051276938[255] = 0.0;
   out_5897624149051276938[256] = 0.0;
   out_5897624149051276938[257] = 0.0;
   out_5897624149051276938[258] = 0.0;
   out_5897624149051276938[259] = 0.0;
   out_5897624149051276938[260] = 0.0;
   out_5897624149051276938[261] = 0.0;
   out_5897624149051276938[262] = 0.0;
   out_5897624149051276938[263] = 0.0;
   out_5897624149051276938[264] = 0.0;
   out_5897624149051276938[265] = 0.0;
   out_5897624149051276938[266] = 1.0;
   out_5897624149051276938[267] = 0.0;
   out_5897624149051276938[268] = 0.0;
   out_5897624149051276938[269] = 0.0;
   out_5897624149051276938[270] = 0.0;
   out_5897624149051276938[271] = 0.0;
   out_5897624149051276938[272] = 0.0;
   out_5897624149051276938[273] = 0.0;
   out_5897624149051276938[274] = 0.0;
   out_5897624149051276938[275] = 0.0;
   out_5897624149051276938[276] = 0.0;
   out_5897624149051276938[277] = 0.0;
   out_5897624149051276938[278] = 0.0;
   out_5897624149051276938[279] = 0.0;
   out_5897624149051276938[280] = 0.0;
   out_5897624149051276938[281] = 0.0;
   out_5897624149051276938[282] = 0.0;
   out_5897624149051276938[283] = 0.0;
   out_5897624149051276938[284] = 0.0;
   out_5897624149051276938[285] = 1.0;
   out_5897624149051276938[286] = 0.0;
   out_5897624149051276938[287] = 0.0;
   out_5897624149051276938[288] = 0.0;
   out_5897624149051276938[289] = 0.0;
   out_5897624149051276938[290] = 0.0;
   out_5897624149051276938[291] = 0.0;
   out_5897624149051276938[292] = 0.0;
   out_5897624149051276938[293] = 0.0;
   out_5897624149051276938[294] = 0.0;
   out_5897624149051276938[295] = 0.0;
   out_5897624149051276938[296] = 0.0;
   out_5897624149051276938[297] = 0.0;
   out_5897624149051276938[298] = 0.0;
   out_5897624149051276938[299] = 0.0;
   out_5897624149051276938[300] = 0.0;
   out_5897624149051276938[301] = 0.0;
   out_5897624149051276938[302] = 0.0;
   out_5897624149051276938[303] = 0.0;
   out_5897624149051276938[304] = 1.0;
   out_5897624149051276938[305] = 0.0;
   out_5897624149051276938[306] = 0.0;
   out_5897624149051276938[307] = 0.0;
   out_5897624149051276938[308] = 0.0;
   out_5897624149051276938[309] = 0.0;
   out_5897624149051276938[310] = 0.0;
   out_5897624149051276938[311] = 0.0;
   out_5897624149051276938[312] = 0.0;
   out_5897624149051276938[313] = 0.0;
   out_5897624149051276938[314] = 0.0;
   out_5897624149051276938[315] = 0.0;
   out_5897624149051276938[316] = 0.0;
   out_5897624149051276938[317] = 0.0;
   out_5897624149051276938[318] = 0.0;
   out_5897624149051276938[319] = 0.0;
   out_5897624149051276938[320] = 0.0;
   out_5897624149051276938[321] = 0.0;
   out_5897624149051276938[322] = 0.0;
   out_5897624149051276938[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1487863932007426038) {
   out_1487863932007426038[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1487863932007426038[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1487863932007426038[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1487863932007426038[3] = dt*state[12] + state[3];
   out_1487863932007426038[4] = dt*state[13] + state[4];
   out_1487863932007426038[5] = dt*state[14] + state[5];
   out_1487863932007426038[6] = state[6];
   out_1487863932007426038[7] = state[7];
   out_1487863932007426038[8] = state[8];
   out_1487863932007426038[9] = state[9];
   out_1487863932007426038[10] = state[10];
   out_1487863932007426038[11] = state[11];
   out_1487863932007426038[12] = state[12];
   out_1487863932007426038[13] = state[13];
   out_1487863932007426038[14] = state[14];
   out_1487863932007426038[15] = state[15];
   out_1487863932007426038[16] = state[16];
   out_1487863932007426038[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1174346146939149897) {
   out_1174346146939149897[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1174346146939149897[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1174346146939149897[2] = 0;
   out_1174346146939149897[3] = 0;
   out_1174346146939149897[4] = 0;
   out_1174346146939149897[5] = 0;
   out_1174346146939149897[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1174346146939149897[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1174346146939149897[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1174346146939149897[9] = 0;
   out_1174346146939149897[10] = 0;
   out_1174346146939149897[11] = 0;
   out_1174346146939149897[12] = 0;
   out_1174346146939149897[13] = 0;
   out_1174346146939149897[14] = 0;
   out_1174346146939149897[15] = 0;
   out_1174346146939149897[16] = 0;
   out_1174346146939149897[17] = 0;
   out_1174346146939149897[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1174346146939149897[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1174346146939149897[20] = 0;
   out_1174346146939149897[21] = 0;
   out_1174346146939149897[22] = 0;
   out_1174346146939149897[23] = 0;
   out_1174346146939149897[24] = 0;
   out_1174346146939149897[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1174346146939149897[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1174346146939149897[27] = 0;
   out_1174346146939149897[28] = 0;
   out_1174346146939149897[29] = 0;
   out_1174346146939149897[30] = 0;
   out_1174346146939149897[31] = 0;
   out_1174346146939149897[32] = 0;
   out_1174346146939149897[33] = 0;
   out_1174346146939149897[34] = 0;
   out_1174346146939149897[35] = 0;
   out_1174346146939149897[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1174346146939149897[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1174346146939149897[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1174346146939149897[39] = 0;
   out_1174346146939149897[40] = 0;
   out_1174346146939149897[41] = 0;
   out_1174346146939149897[42] = 0;
   out_1174346146939149897[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1174346146939149897[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1174346146939149897[45] = 0;
   out_1174346146939149897[46] = 0;
   out_1174346146939149897[47] = 0;
   out_1174346146939149897[48] = 0;
   out_1174346146939149897[49] = 0;
   out_1174346146939149897[50] = 0;
   out_1174346146939149897[51] = 0;
   out_1174346146939149897[52] = 0;
   out_1174346146939149897[53] = 0;
   out_1174346146939149897[54] = 0;
   out_1174346146939149897[55] = 0;
   out_1174346146939149897[56] = 0;
   out_1174346146939149897[57] = 1;
   out_1174346146939149897[58] = 0;
   out_1174346146939149897[59] = 0;
   out_1174346146939149897[60] = 0;
   out_1174346146939149897[61] = 0;
   out_1174346146939149897[62] = 0;
   out_1174346146939149897[63] = 0;
   out_1174346146939149897[64] = 0;
   out_1174346146939149897[65] = 0;
   out_1174346146939149897[66] = dt;
   out_1174346146939149897[67] = 0;
   out_1174346146939149897[68] = 0;
   out_1174346146939149897[69] = 0;
   out_1174346146939149897[70] = 0;
   out_1174346146939149897[71] = 0;
   out_1174346146939149897[72] = 0;
   out_1174346146939149897[73] = 0;
   out_1174346146939149897[74] = 0;
   out_1174346146939149897[75] = 0;
   out_1174346146939149897[76] = 1;
   out_1174346146939149897[77] = 0;
   out_1174346146939149897[78] = 0;
   out_1174346146939149897[79] = 0;
   out_1174346146939149897[80] = 0;
   out_1174346146939149897[81] = 0;
   out_1174346146939149897[82] = 0;
   out_1174346146939149897[83] = 0;
   out_1174346146939149897[84] = 0;
   out_1174346146939149897[85] = dt;
   out_1174346146939149897[86] = 0;
   out_1174346146939149897[87] = 0;
   out_1174346146939149897[88] = 0;
   out_1174346146939149897[89] = 0;
   out_1174346146939149897[90] = 0;
   out_1174346146939149897[91] = 0;
   out_1174346146939149897[92] = 0;
   out_1174346146939149897[93] = 0;
   out_1174346146939149897[94] = 0;
   out_1174346146939149897[95] = 1;
   out_1174346146939149897[96] = 0;
   out_1174346146939149897[97] = 0;
   out_1174346146939149897[98] = 0;
   out_1174346146939149897[99] = 0;
   out_1174346146939149897[100] = 0;
   out_1174346146939149897[101] = 0;
   out_1174346146939149897[102] = 0;
   out_1174346146939149897[103] = 0;
   out_1174346146939149897[104] = dt;
   out_1174346146939149897[105] = 0;
   out_1174346146939149897[106] = 0;
   out_1174346146939149897[107] = 0;
   out_1174346146939149897[108] = 0;
   out_1174346146939149897[109] = 0;
   out_1174346146939149897[110] = 0;
   out_1174346146939149897[111] = 0;
   out_1174346146939149897[112] = 0;
   out_1174346146939149897[113] = 0;
   out_1174346146939149897[114] = 1;
   out_1174346146939149897[115] = 0;
   out_1174346146939149897[116] = 0;
   out_1174346146939149897[117] = 0;
   out_1174346146939149897[118] = 0;
   out_1174346146939149897[119] = 0;
   out_1174346146939149897[120] = 0;
   out_1174346146939149897[121] = 0;
   out_1174346146939149897[122] = 0;
   out_1174346146939149897[123] = 0;
   out_1174346146939149897[124] = 0;
   out_1174346146939149897[125] = 0;
   out_1174346146939149897[126] = 0;
   out_1174346146939149897[127] = 0;
   out_1174346146939149897[128] = 0;
   out_1174346146939149897[129] = 0;
   out_1174346146939149897[130] = 0;
   out_1174346146939149897[131] = 0;
   out_1174346146939149897[132] = 0;
   out_1174346146939149897[133] = 1;
   out_1174346146939149897[134] = 0;
   out_1174346146939149897[135] = 0;
   out_1174346146939149897[136] = 0;
   out_1174346146939149897[137] = 0;
   out_1174346146939149897[138] = 0;
   out_1174346146939149897[139] = 0;
   out_1174346146939149897[140] = 0;
   out_1174346146939149897[141] = 0;
   out_1174346146939149897[142] = 0;
   out_1174346146939149897[143] = 0;
   out_1174346146939149897[144] = 0;
   out_1174346146939149897[145] = 0;
   out_1174346146939149897[146] = 0;
   out_1174346146939149897[147] = 0;
   out_1174346146939149897[148] = 0;
   out_1174346146939149897[149] = 0;
   out_1174346146939149897[150] = 0;
   out_1174346146939149897[151] = 0;
   out_1174346146939149897[152] = 1;
   out_1174346146939149897[153] = 0;
   out_1174346146939149897[154] = 0;
   out_1174346146939149897[155] = 0;
   out_1174346146939149897[156] = 0;
   out_1174346146939149897[157] = 0;
   out_1174346146939149897[158] = 0;
   out_1174346146939149897[159] = 0;
   out_1174346146939149897[160] = 0;
   out_1174346146939149897[161] = 0;
   out_1174346146939149897[162] = 0;
   out_1174346146939149897[163] = 0;
   out_1174346146939149897[164] = 0;
   out_1174346146939149897[165] = 0;
   out_1174346146939149897[166] = 0;
   out_1174346146939149897[167] = 0;
   out_1174346146939149897[168] = 0;
   out_1174346146939149897[169] = 0;
   out_1174346146939149897[170] = 0;
   out_1174346146939149897[171] = 1;
   out_1174346146939149897[172] = 0;
   out_1174346146939149897[173] = 0;
   out_1174346146939149897[174] = 0;
   out_1174346146939149897[175] = 0;
   out_1174346146939149897[176] = 0;
   out_1174346146939149897[177] = 0;
   out_1174346146939149897[178] = 0;
   out_1174346146939149897[179] = 0;
   out_1174346146939149897[180] = 0;
   out_1174346146939149897[181] = 0;
   out_1174346146939149897[182] = 0;
   out_1174346146939149897[183] = 0;
   out_1174346146939149897[184] = 0;
   out_1174346146939149897[185] = 0;
   out_1174346146939149897[186] = 0;
   out_1174346146939149897[187] = 0;
   out_1174346146939149897[188] = 0;
   out_1174346146939149897[189] = 0;
   out_1174346146939149897[190] = 1;
   out_1174346146939149897[191] = 0;
   out_1174346146939149897[192] = 0;
   out_1174346146939149897[193] = 0;
   out_1174346146939149897[194] = 0;
   out_1174346146939149897[195] = 0;
   out_1174346146939149897[196] = 0;
   out_1174346146939149897[197] = 0;
   out_1174346146939149897[198] = 0;
   out_1174346146939149897[199] = 0;
   out_1174346146939149897[200] = 0;
   out_1174346146939149897[201] = 0;
   out_1174346146939149897[202] = 0;
   out_1174346146939149897[203] = 0;
   out_1174346146939149897[204] = 0;
   out_1174346146939149897[205] = 0;
   out_1174346146939149897[206] = 0;
   out_1174346146939149897[207] = 0;
   out_1174346146939149897[208] = 0;
   out_1174346146939149897[209] = 1;
   out_1174346146939149897[210] = 0;
   out_1174346146939149897[211] = 0;
   out_1174346146939149897[212] = 0;
   out_1174346146939149897[213] = 0;
   out_1174346146939149897[214] = 0;
   out_1174346146939149897[215] = 0;
   out_1174346146939149897[216] = 0;
   out_1174346146939149897[217] = 0;
   out_1174346146939149897[218] = 0;
   out_1174346146939149897[219] = 0;
   out_1174346146939149897[220] = 0;
   out_1174346146939149897[221] = 0;
   out_1174346146939149897[222] = 0;
   out_1174346146939149897[223] = 0;
   out_1174346146939149897[224] = 0;
   out_1174346146939149897[225] = 0;
   out_1174346146939149897[226] = 0;
   out_1174346146939149897[227] = 0;
   out_1174346146939149897[228] = 1;
   out_1174346146939149897[229] = 0;
   out_1174346146939149897[230] = 0;
   out_1174346146939149897[231] = 0;
   out_1174346146939149897[232] = 0;
   out_1174346146939149897[233] = 0;
   out_1174346146939149897[234] = 0;
   out_1174346146939149897[235] = 0;
   out_1174346146939149897[236] = 0;
   out_1174346146939149897[237] = 0;
   out_1174346146939149897[238] = 0;
   out_1174346146939149897[239] = 0;
   out_1174346146939149897[240] = 0;
   out_1174346146939149897[241] = 0;
   out_1174346146939149897[242] = 0;
   out_1174346146939149897[243] = 0;
   out_1174346146939149897[244] = 0;
   out_1174346146939149897[245] = 0;
   out_1174346146939149897[246] = 0;
   out_1174346146939149897[247] = 1;
   out_1174346146939149897[248] = 0;
   out_1174346146939149897[249] = 0;
   out_1174346146939149897[250] = 0;
   out_1174346146939149897[251] = 0;
   out_1174346146939149897[252] = 0;
   out_1174346146939149897[253] = 0;
   out_1174346146939149897[254] = 0;
   out_1174346146939149897[255] = 0;
   out_1174346146939149897[256] = 0;
   out_1174346146939149897[257] = 0;
   out_1174346146939149897[258] = 0;
   out_1174346146939149897[259] = 0;
   out_1174346146939149897[260] = 0;
   out_1174346146939149897[261] = 0;
   out_1174346146939149897[262] = 0;
   out_1174346146939149897[263] = 0;
   out_1174346146939149897[264] = 0;
   out_1174346146939149897[265] = 0;
   out_1174346146939149897[266] = 1;
   out_1174346146939149897[267] = 0;
   out_1174346146939149897[268] = 0;
   out_1174346146939149897[269] = 0;
   out_1174346146939149897[270] = 0;
   out_1174346146939149897[271] = 0;
   out_1174346146939149897[272] = 0;
   out_1174346146939149897[273] = 0;
   out_1174346146939149897[274] = 0;
   out_1174346146939149897[275] = 0;
   out_1174346146939149897[276] = 0;
   out_1174346146939149897[277] = 0;
   out_1174346146939149897[278] = 0;
   out_1174346146939149897[279] = 0;
   out_1174346146939149897[280] = 0;
   out_1174346146939149897[281] = 0;
   out_1174346146939149897[282] = 0;
   out_1174346146939149897[283] = 0;
   out_1174346146939149897[284] = 0;
   out_1174346146939149897[285] = 1;
   out_1174346146939149897[286] = 0;
   out_1174346146939149897[287] = 0;
   out_1174346146939149897[288] = 0;
   out_1174346146939149897[289] = 0;
   out_1174346146939149897[290] = 0;
   out_1174346146939149897[291] = 0;
   out_1174346146939149897[292] = 0;
   out_1174346146939149897[293] = 0;
   out_1174346146939149897[294] = 0;
   out_1174346146939149897[295] = 0;
   out_1174346146939149897[296] = 0;
   out_1174346146939149897[297] = 0;
   out_1174346146939149897[298] = 0;
   out_1174346146939149897[299] = 0;
   out_1174346146939149897[300] = 0;
   out_1174346146939149897[301] = 0;
   out_1174346146939149897[302] = 0;
   out_1174346146939149897[303] = 0;
   out_1174346146939149897[304] = 1;
   out_1174346146939149897[305] = 0;
   out_1174346146939149897[306] = 0;
   out_1174346146939149897[307] = 0;
   out_1174346146939149897[308] = 0;
   out_1174346146939149897[309] = 0;
   out_1174346146939149897[310] = 0;
   out_1174346146939149897[311] = 0;
   out_1174346146939149897[312] = 0;
   out_1174346146939149897[313] = 0;
   out_1174346146939149897[314] = 0;
   out_1174346146939149897[315] = 0;
   out_1174346146939149897[316] = 0;
   out_1174346146939149897[317] = 0;
   out_1174346146939149897[318] = 0;
   out_1174346146939149897[319] = 0;
   out_1174346146939149897[320] = 0;
   out_1174346146939149897[321] = 0;
   out_1174346146939149897[322] = 0;
   out_1174346146939149897[323] = 1;
}
void h_4(double *state, double *unused, double *out_3883517451541200036) {
   out_3883517451541200036[0] = state[6] + state[9];
   out_3883517451541200036[1] = state[7] + state[10];
   out_3883517451541200036[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7717322874957573799) {
   out_7717322874957573799[0] = 0;
   out_7717322874957573799[1] = 0;
   out_7717322874957573799[2] = 0;
   out_7717322874957573799[3] = 0;
   out_7717322874957573799[4] = 0;
   out_7717322874957573799[5] = 0;
   out_7717322874957573799[6] = 1;
   out_7717322874957573799[7] = 0;
   out_7717322874957573799[8] = 0;
   out_7717322874957573799[9] = 1;
   out_7717322874957573799[10] = 0;
   out_7717322874957573799[11] = 0;
   out_7717322874957573799[12] = 0;
   out_7717322874957573799[13] = 0;
   out_7717322874957573799[14] = 0;
   out_7717322874957573799[15] = 0;
   out_7717322874957573799[16] = 0;
   out_7717322874957573799[17] = 0;
   out_7717322874957573799[18] = 0;
   out_7717322874957573799[19] = 0;
   out_7717322874957573799[20] = 0;
   out_7717322874957573799[21] = 0;
   out_7717322874957573799[22] = 0;
   out_7717322874957573799[23] = 0;
   out_7717322874957573799[24] = 0;
   out_7717322874957573799[25] = 1;
   out_7717322874957573799[26] = 0;
   out_7717322874957573799[27] = 0;
   out_7717322874957573799[28] = 1;
   out_7717322874957573799[29] = 0;
   out_7717322874957573799[30] = 0;
   out_7717322874957573799[31] = 0;
   out_7717322874957573799[32] = 0;
   out_7717322874957573799[33] = 0;
   out_7717322874957573799[34] = 0;
   out_7717322874957573799[35] = 0;
   out_7717322874957573799[36] = 0;
   out_7717322874957573799[37] = 0;
   out_7717322874957573799[38] = 0;
   out_7717322874957573799[39] = 0;
   out_7717322874957573799[40] = 0;
   out_7717322874957573799[41] = 0;
   out_7717322874957573799[42] = 0;
   out_7717322874957573799[43] = 0;
   out_7717322874957573799[44] = 1;
   out_7717322874957573799[45] = 0;
   out_7717322874957573799[46] = 0;
   out_7717322874957573799[47] = 1;
   out_7717322874957573799[48] = 0;
   out_7717322874957573799[49] = 0;
   out_7717322874957573799[50] = 0;
   out_7717322874957573799[51] = 0;
   out_7717322874957573799[52] = 0;
   out_7717322874957573799[53] = 0;
}
void h_10(double *state, double *unused, double *out_4242053638467512277) {
   out_4242053638467512277[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4242053638467512277[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4242053638467512277[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4011677399619585283) {
   out_4011677399619585283[0] = 0;
   out_4011677399619585283[1] = 9.8100000000000005*cos(state[1]);
   out_4011677399619585283[2] = 0;
   out_4011677399619585283[3] = 0;
   out_4011677399619585283[4] = -state[8];
   out_4011677399619585283[5] = state[7];
   out_4011677399619585283[6] = 0;
   out_4011677399619585283[7] = state[5];
   out_4011677399619585283[8] = -state[4];
   out_4011677399619585283[9] = 0;
   out_4011677399619585283[10] = 0;
   out_4011677399619585283[11] = 0;
   out_4011677399619585283[12] = 1;
   out_4011677399619585283[13] = 0;
   out_4011677399619585283[14] = 0;
   out_4011677399619585283[15] = 1;
   out_4011677399619585283[16] = 0;
   out_4011677399619585283[17] = 0;
   out_4011677399619585283[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4011677399619585283[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4011677399619585283[20] = 0;
   out_4011677399619585283[21] = state[8];
   out_4011677399619585283[22] = 0;
   out_4011677399619585283[23] = -state[6];
   out_4011677399619585283[24] = -state[5];
   out_4011677399619585283[25] = 0;
   out_4011677399619585283[26] = state[3];
   out_4011677399619585283[27] = 0;
   out_4011677399619585283[28] = 0;
   out_4011677399619585283[29] = 0;
   out_4011677399619585283[30] = 0;
   out_4011677399619585283[31] = 1;
   out_4011677399619585283[32] = 0;
   out_4011677399619585283[33] = 0;
   out_4011677399619585283[34] = 1;
   out_4011677399619585283[35] = 0;
   out_4011677399619585283[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4011677399619585283[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4011677399619585283[38] = 0;
   out_4011677399619585283[39] = -state[7];
   out_4011677399619585283[40] = state[6];
   out_4011677399619585283[41] = 0;
   out_4011677399619585283[42] = state[4];
   out_4011677399619585283[43] = -state[3];
   out_4011677399619585283[44] = 0;
   out_4011677399619585283[45] = 0;
   out_4011677399619585283[46] = 0;
   out_4011677399619585283[47] = 0;
   out_4011677399619585283[48] = 0;
   out_4011677399619585283[49] = 0;
   out_4011677399619585283[50] = 1;
   out_4011677399619585283[51] = 0;
   out_4011677399619585283[52] = 0;
   out_4011677399619585283[53] = 1;
}
void h_13(double *state, double *unused, double *out_6794008573600612330) {
   out_6794008573600612330[0] = state[3];
   out_6794008573600612330[1] = state[4];
   out_6794008573600612330[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4505049049625240998) {
   out_4505049049625240998[0] = 0;
   out_4505049049625240998[1] = 0;
   out_4505049049625240998[2] = 0;
   out_4505049049625240998[3] = 1;
   out_4505049049625240998[4] = 0;
   out_4505049049625240998[5] = 0;
   out_4505049049625240998[6] = 0;
   out_4505049049625240998[7] = 0;
   out_4505049049625240998[8] = 0;
   out_4505049049625240998[9] = 0;
   out_4505049049625240998[10] = 0;
   out_4505049049625240998[11] = 0;
   out_4505049049625240998[12] = 0;
   out_4505049049625240998[13] = 0;
   out_4505049049625240998[14] = 0;
   out_4505049049625240998[15] = 0;
   out_4505049049625240998[16] = 0;
   out_4505049049625240998[17] = 0;
   out_4505049049625240998[18] = 0;
   out_4505049049625240998[19] = 0;
   out_4505049049625240998[20] = 0;
   out_4505049049625240998[21] = 0;
   out_4505049049625240998[22] = 1;
   out_4505049049625240998[23] = 0;
   out_4505049049625240998[24] = 0;
   out_4505049049625240998[25] = 0;
   out_4505049049625240998[26] = 0;
   out_4505049049625240998[27] = 0;
   out_4505049049625240998[28] = 0;
   out_4505049049625240998[29] = 0;
   out_4505049049625240998[30] = 0;
   out_4505049049625240998[31] = 0;
   out_4505049049625240998[32] = 0;
   out_4505049049625240998[33] = 0;
   out_4505049049625240998[34] = 0;
   out_4505049049625240998[35] = 0;
   out_4505049049625240998[36] = 0;
   out_4505049049625240998[37] = 0;
   out_4505049049625240998[38] = 0;
   out_4505049049625240998[39] = 0;
   out_4505049049625240998[40] = 0;
   out_4505049049625240998[41] = 1;
   out_4505049049625240998[42] = 0;
   out_4505049049625240998[43] = 0;
   out_4505049049625240998[44] = 0;
   out_4505049049625240998[45] = 0;
   out_4505049049625240998[46] = 0;
   out_4505049049625240998[47] = 0;
   out_4505049049625240998[48] = 0;
   out_4505049049625240998[49] = 0;
   out_4505049049625240998[50] = 0;
   out_4505049049625240998[51] = 0;
   out_4505049049625240998[52] = 0;
   out_4505049049625240998[53] = 0;
}
void h_14(double *state, double *unused, double *out_7417388947128580419) {
   out_7417388947128580419[0] = state[6];
   out_7417388947128580419[1] = state[7];
   out_7417388947128580419[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3754082018618089270) {
   out_3754082018618089270[0] = 0;
   out_3754082018618089270[1] = 0;
   out_3754082018618089270[2] = 0;
   out_3754082018618089270[3] = 0;
   out_3754082018618089270[4] = 0;
   out_3754082018618089270[5] = 0;
   out_3754082018618089270[6] = 1;
   out_3754082018618089270[7] = 0;
   out_3754082018618089270[8] = 0;
   out_3754082018618089270[9] = 0;
   out_3754082018618089270[10] = 0;
   out_3754082018618089270[11] = 0;
   out_3754082018618089270[12] = 0;
   out_3754082018618089270[13] = 0;
   out_3754082018618089270[14] = 0;
   out_3754082018618089270[15] = 0;
   out_3754082018618089270[16] = 0;
   out_3754082018618089270[17] = 0;
   out_3754082018618089270[18] = 0;
   out_3754082018618089270[19] = 0;
   out_3754082018618089270[20] = 0;
   out_3754082018618089270[21] = 0;
   out_3754082018618089270[22] = 0;
   out_3754082018618089270[23] = 0;
   out_3754082018618089270[24] = 0;
   out_3754082018618089270[25] = 1;
   out_3754082018618089270[26] = 0;
   out_3754082018618089270[27] = 0;
   out_3754082018618089270[28] = 0;
   out_3754082018618089270[29] = 0;
   out_3754082018618089270[30] = 0;
   out_3754082018618089270[31] = 0;
   out_3754082018618089270[32] = 0;
   out_3754082018618089270[33] = 0;
   out_3754082018618089270[34] = 0;
   out_3754082018618089270[35] = 0;
   out_3754082018618089270[36] = 0;
   out_3754082018618089270[37] = 0;
   out_3754082018618089270[38] = 0;
   out_3754082018618089270[39] = 0;
   out_3754082018618089270[40] = 0;
   out_3754082018618089270[41] = 0;
   out_3754082018618089270[42] = 0;
   out_3754082018618089270[43] = 0;
   out_3754082018618089270[44] = 1;
   out_3754082018618089270[45] = 0;
   out_3754082018618089270[46] = 0;
   out_3754082018618089270[47] = 0;
   out_3754082018618089270[48] = 0;
   out_3754082018618089270[49] = 0;
   out_3754082018618089270[50] = 0;
   out_3754082018618089270[51] = 0;
   out_3754082018618089270[52] = 0;
   out_3754082018618089270[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_8151132212255276688) {
  err_fun(nom_x, delta_x, out_8151132212255276688);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8615557392453245857) {
  inv_err_fun(nom_x, true_x, out_8615557392453245857);
}
void pose_H_mod_fun(double *state, double *out_5897624149051276938) {
  H_mod_fun(state, out_5897624149051276938);
}
void pose_f_fun(double *state, double dt, double *out_1487863932007426038) {
  f_fun(state,  dt, out_1487863932007426038);
}
void pose_F_fun(double *state, double dt, double *out_1174346146939149897) {
  F_fun(state,  dt, out_1174346146939149897);
}
void pose_h_4(double *state, double *unused, double *out_3883517451541200036) {
  h_4(state, unused, out_3883517451541200036);
}
void pose_H_4(double *state, double *unused, double *out_7717322874957573799) {
  H_4(state, unused, out_7717322874957573799);
}
void pose_h_10(double *state, double *unused, double *out_4242053638467512277) {
  h_10(state, unused, out_4242053638467512277);
}
void pose_H_10(double *state, double *unused, double *out_4011677399619585283) {
  H_10(state, unused, out_4011677399619585283);
}
void pose_h_13(double *state, double *unused, double *out_6794008573600612330) {
  h_13(state, unused, out_6794008573600612330);
}
void pose_H_13(double *state, double *unused, double *out_4505049049625240998) {
  H_13(state, unused, out_4505049049625240998);
}
void pose_h_14(double *state, double *unused, double *out_7417388947128580419) {
  h_14(state, unused, out_7417388947128580419);
}
void pose_H_14(double *state, double *unused, double *out_3754082018618089270) {
  H_14(state, unused, out_3754082018618089270);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
