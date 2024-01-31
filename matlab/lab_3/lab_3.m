%Cell Arrays:
cell_array = {100,'hellow', rand(2)}

%Structures:
person.name='ali';
person.age=22;
person.city='alex';

fprintf('person name: %s\n',person.name)
fprintf('person city: %s\n',person.city)
fprintf('person age: %d\n\n',person.age)

%Character Data:
my_name='mohamed';
my_2th=strcat(my_name, 'yousef');
fprintf('my name is : %s\n\n',my_2th)

%Conditional Statements (If)
num=input('enter number for check even or odd:\n');
if rem(num,0)==1
    disp('even numer\n')
else
     disp('odd numer\n')
end

%For Loops:
n=10;

for i=1:n
   squre = i^2;
   fprintf('squre of %d is: [%d]\n',i,squre)
end

%Basic Plotting:
x= linspace(0,2*pi,50);
y=sin(x);
plot(x,y,'-','color','r','marker','o','MarkerSize',3,'LineWidth',3)
xlabel('x_axis')
ylabel('y_axis')
title('sine of points')
grid on


