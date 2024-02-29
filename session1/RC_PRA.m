r=1000;
c=1e-6;
t_const=r*c;
k=2;
num = [k];
den = [t_const 1];
g=tf(num, den);
t_ramp=0:.1:10;
t_par=.5*t_ramp.^2;
[res,t]=lsim(g, t_par, t_ramp);
plot(t,res)
hold on

stepinfo(g)