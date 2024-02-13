% inital values for pramters 
xo=1;
k=400;
b=10;
m=6;

diff_val_mass=1:2:10;
model_name = gcs;

for i = 1:length(diff_val_mass);
   m= diff_val_mass(i); 
   res = sim(model_name)
   plot(res.logsout.get('x').Values)
   hold on
name_of_legend(i)= "m = " + num2str(m);
   
end
legend(name_of_legend)