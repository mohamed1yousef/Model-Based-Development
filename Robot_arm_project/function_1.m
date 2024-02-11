x0=0;
y0=0;

length_first_arm=input('enter L1: ');
length_2th_arm=input('enter L2: ');

angle_first_arm=input('enter the angle of first arm in degree: ');
angle_2th_arm=input('enter the angle of 2th arm in degree: ');

len_theta_1=linspace(0,angle_first_arm,200);
len_theta_2=linspace(0,angle_2th_arm,200);

y1 = times(length_first_arm,sind(len_theta_1));
x1 = times(length_first_arm,cosd(len_theta_1));
y2 = times(length_2th_arm,sind(len_theta_2)+y1);
x2 = times(length_2th_arm,cosd(len_theta_2)+x1);

first = plot([x0,0],[y0,0],'LineWidth',5,'Color','r');
secend = plot([0,0],[0,0],'LineWidth',5,'Color','b');
hold on
grid on
xlim([-length_first_arm*2,length_first_arm*2])
ylim([-length_2th_arm*2,length_2th_arm*2])
plot(x2, y2);
for i=1:1:length(len_theta_1)
    

  delete(first);
  delete(secend);
  first = plot([x0,x1(i)],[y0,y1(i)],'LineWidth',4,'Color','r');
  secend = plot([x1(i),x2(i)],[y1(i),y2(i)],'LineWidth',5,'Color','b');
  drawnow
    
end
