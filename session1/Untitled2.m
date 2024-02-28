wn=5;
num = [0, wn^2];
for E=0:.2:1;
den= [1,2*wn*E,wn^2];
[G,t]=tf(num, den);
i=step(G);
subplot(5,1,i)

end
