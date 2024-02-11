%fixed origin points
x_orgin=0;
y_orgin=0;

% the legths of the arms
length_first_arm=10;
length_2th_arm=9;

% the range of the angles of arms
angle_first_arm=linspace(0,180,500);
angle_2th_arm=linspace(0,360,500);

% the equations of the system
y1=length_first_arm*sind(angle_first_arm);
x1=length_first_arm*cosd(angle_first_arm);
y2=length_2th_arm*sind(angle_2th_arm+angle_first_arm)+y1;
x2=length_2th_arm*cosd(angle_2th_arm+angle_first_arm)+x1;

% plots to be deleted in the loop to delete the old plot and dram the new
first_plot = plot([x_orgin,x1(1)],[y_orgin,y1(1)],'LineWidth',7,'Color','r');
secend_plot = plot([x1,x2(1)],[y1,y2(1)],'LineWidth',8,'Color','b');

% the ranges of x,y axis
xlim([-length_first_arm*2,length_first_arm*2])
ylim([-length_2th_arm*2,length_2th_arm*2])

% to draw every plot in the loop in the same figure
hold on
grid on

%to get the shape of the 2th arm moves
plot(x2, y2);

% the loop to display the motion graphic of the arms
for i=1:length(angle_first_arm)
  % delete the old graph   
  delete(first_plot);
  delete(secend_plot);
  
  %plot the new graph
  first_plot=plot([x_orgin,x1(i)],[y_orgin,y1(i)],'LineWidth',7,'Color','r');
  secend_plot=plot([x1(i),x2(i)],[y1(i),y2(i)],'LineWidth',5,'Color','b');
  
  % to show the new graph not only the last one
  drawnow
 
  % pause function to control the time of every graph
  %pause(.05);
  
end
