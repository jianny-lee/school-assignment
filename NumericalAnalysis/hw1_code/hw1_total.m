clear; clc; close all; %작업공간의 항목들 제거
load data_bisection.mat; %저장한 data_bisection.mat을 load
semilogy(etlist,'go-'); %load한 bisection의 semilogy 그리기

load data_false.mat; %저장한 data_false.mat을 load
hold on; %원래 그래프에 새로운 그래프를 그리고 겹치기 위해 저장
semilogy(etlist,'co-');%load한 false의 semilogy 그리기

load data_newton.mat;%저장한 data_newton.mat을 load
hold on;
semilogy(etlist,'ro-');%load한 newton의 semilogy 그리기

load data_secant.mat;%저장한 data_secant.mat을 load
hold on;
semilogy(etlist,'bo-');%load한 secant의 semilogy 그리기

grid on; %그래프에 눈금을 표시

% set(gcf)
set(gcf,'name','Total Graph'); %figure의 이름을 Total Graph로 지정

title("plot"); %그래프의 제목
xlabel("Iteration, x");%x축의 label 지정
ylabel("True percent relative error, y"); %y축의 label 지정
xlim([0 20]); ylim([10^(-6) 10^2]);

% legend
%현재 그래프의 각각의 label을 설정
lgd=legend("bisection","false position","newton","secant"); 
lgd.FontSize=15; %legend의 글씨크기 지정
