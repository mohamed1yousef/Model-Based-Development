R=4000;
C=.2e-6;
RC=R*C;
zeta=1.2;
wn=1/RC;
num=wn^2;
den=[1 2*zeta*wn wn^2];
G=tf(num, den)
sys_close=feedback(G,1);
step(sys_close)%over damped
hold on
zeta=1;
den=[1 2*zeta*wn wn^2];
G=tf(num, den)
sys_close=feedback(G,1);
step(sys_close)%critcal
legend('over damped','critcal')