R1 = 10e6; 
R2 = 10e6; 
C1 = 22e-9; 
C2 = 22e-9;
num = 1/(R1*R2*C1*C2);
den = [1 (R1*C1+R2*C2+R1*C2)/(R1*R2*C1*C2) 1/(R1*R2*C1*C2)]; 
kp=6.6002;
ki=4.54;
con_num=[kp ki];
con_den=[1 0];

G = tf(num,den)
G_contoller = tf(con_num,con_den)
G_system=series(G, G_contoller)
System_total = feedback(G_system,1); 
step(System_total);