L=1;
g=9.81;

ode=@(t,theta) [theta(2); -(1/L)*(g*sin(theta(1)))];
tspan = [0,10];
theta0 =[1;1];
[t,theta]=ode45(ode,tspan,theta0);
position = theta(:, 1);
velocity = theta(:, 2);
plot(t,position);

hold on 
plot(t,velocity);
legend(' angular displacement',' angular velocity');
xlabel('time');
ylabel('amplitude');