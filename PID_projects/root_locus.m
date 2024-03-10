den=[0 1];
num=conv([1 1],[1 5]);
kp=20.8;
G=tf(den, num);
%rlocus(G)
close_loop_sys=feedback(kp*G,1)
step(close_loop_sys)
xlim([0,10])