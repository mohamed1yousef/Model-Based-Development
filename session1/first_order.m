clear
clc

k=1;
R = 1000;
C = 1e-6;
t =R*C;
num=[1,k];
don=[t,1]
u=tf(num,don)

