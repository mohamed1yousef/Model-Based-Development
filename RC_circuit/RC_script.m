clear
clc

s= tf('s');
R = 1000;
C = 1e-6;
RC_INV = 1/(R*C);
func = (RC_INV/(s+RC_INV));
step(func)
