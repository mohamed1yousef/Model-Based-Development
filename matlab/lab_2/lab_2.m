clear 
clc
%Task 1: While Loop
n=20;
count=1;
for count =1:n
    if rem(count,2)==0
        fprintf('%d is enven\n',count)
    else
        fprintf('%d is odd\n',count)
    end
end
num2getfact=input('enter num: ');
prod = 1;
while num2getfact>=1
    prod = prod * num2getfact;
    num2getfact = num2getfact -1;
end
fprintf('fact is =%d\n',prod)

%Task 2: Switch Statement

prompt='enter the optian would u like to have: ';
trip_trans=input(prompt,'s');
km_1=input('enter no of mils for calc the cost:');
switch trip_trans
    case 'car'
        disp('fees is 3 cent/km for car option\n')
        total_cost=3*km_1;
        fprintf('total cost is %d for your trip\n',total_cost)
    case 'bus'
        disp('fees is 5 cent/km for bus option')
        total_cost=5*km_1;
        fprintf('total cost is %d for your trip\n',total_cost)
    case 'airplane'
        disp('fees is 15 cent/km for airplane option')
        total_cost=15*km_1;
        fprintf('total cost is %d for your trip\n',total_cost)
        otherwise
        disp('fees is 15 cent/km \n')
        total_cost=15*km_1;
        fprintf('total cost is %d for your trip\n',total_cost)
end
color=input('enter the color: ','s');
switch color
    case 'red'
        disp('color code is 123456')
    case 'blue'
        disp('color code is 55345')
    case 'black'
        disp('color code is 00000000')
        otherwise
        disp('color code is 6666666')
end