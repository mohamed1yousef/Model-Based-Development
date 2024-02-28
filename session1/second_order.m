wn=[4,1,2];
zeta=[.1,.5,.9];
t_step=0:.01:10;
t1=ones(size(t_step));
for i=1:3
    if i==1 
      x=0; 
  elseif i==2
      x=3; 
  else
      x=6;
  end
    for j=1:3
      num = [0, wn(i)^2];
      den= [1,2*wn(i)*zeta(j),wn(i)^2];
      G=tf(num, den);
      [out,tout]=step(G,t_step);
      subplot(3,3,j+x);
      plot(tout,out,'r')
      hold on
      ylim([0,2])
      plot(t_step,t1,'b');
      xlabel('time');
      ylabel('out');
      legend('response','step')
      title(['under damped system due to ','(\omega_n)=',num2str(wn(i)),' and zeta=',num2str(zeta(j))]);
      
    end
end
