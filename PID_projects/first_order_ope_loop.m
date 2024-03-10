R=1000;
C=1e-6;
RC=R*C;
num=1;
den=[RC 1];
G=tf(num, den)
step(G)