#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8151132212255276688);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8615557392453245857);
void pose_H_mod_fun(double *state, double *out_5897624149051276938);
void pose_f_fun(double *state, double dt, double *out_1487863932007426038);
void pose_F_fun(double *state, double dt, double *out_1174346146939149897);
void pose_h_4(double *state, double *unused, double *out_3883517451541200036);
void pose_H_4(double *state, double *unused, double *out_7717322874957573799);
void pose_h_10(double *state, double *unused, double *out_4242053638467512277);
void pose_H_10(double *state, double *unused, double *out_4011677399619585283);
void pose_h_13(double *state, double *unused, double *out_6794008573600612330);
void pose_H_13(double *state, double *unused, double *out_4505049049625240998);
void pose_h_14(double *state, double *unused, double *out_7417388947128580419);
void pose_H_14(double *state, double *unused, double *out_3754082018618089270);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}