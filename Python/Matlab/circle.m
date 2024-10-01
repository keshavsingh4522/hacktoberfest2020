%Initializing
x1 = 0;
y1 = 0;
x2 = -20;
y2 = 0;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'b*');

hold on;

x1 = x2;
y1 = y2;
x2 = x1;
y2 = 30;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1-15;
y2 = y1;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1;
y2 = y1+50;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1+50;
y2 = y1;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1;
y2 = y1-30;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1+20;
y2 = y1;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1;
y2 = y1+30;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1+60;
y2 = y1;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1;
y2 = y1-40;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1-20;
y2 = y1;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1;
y2 = y1-40;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1-30;
y2 = y1;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1;
y2 = y1+40;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1-45;
y2 = y1;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');

x1 = x2;
y1 = y2;
x2 = x1;
y2 = y1-40;
gap = max(abs(x2-x1),abs(y2-y1));
m = (y2-y1)/(x2-x1);
xinc = (x2-x1)/gap;
yinc = (y2-y1)/gap;

E = []; F = [];

for i = 1:gap+1
    E(i) = x1;
    F(i) = y1;
    x1 = x1 + xinc;
    y1 = y1 + yinc;
end

E = round(E);
F = round(F);

plot(E,F, 'g*');



hold off;
