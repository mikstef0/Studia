clc
close all
clear
out=sim('zaddom.slx');

t=out.t
h=out.h
h0=str2num(get_param('zaddom/Subsystem','h0'));
v0=str2num(get_param('zaddom/Subsystem','v0'));
g=str2num(get_param('zaddom/Subsystem','g'));


figure
for i=1:length(t)
    %hold on
    plot(1,h(i),'b.', 'MarkerSize',25)
    title(['t=', num2str(t(i)), ' h=', num2str(h(i))])
    %hold off
    axis([0, 2, 0,max(h)])
    pause(0.015) 
end
