values = 1e-6:1e-6:10e-6;
name_of_model = gcs;

for i=1:length(values)
    CAP = values(i);
    res = sim(name_of_model);
   plot(res.logsout{1}.Values)
   hold on
name_of_legend(i)= "CAP VALUE = " + num2str(CAP)+"F";
end
legend(name_of_legend);
ylabel('voltage');
title('At AC Voltage =100');