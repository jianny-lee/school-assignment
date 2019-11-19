%secant method
ff=@(x) x-cos(x); %주어진 함수를 선언

tzero=0.73908513321516064166;%주어진 함수의 true value 선언

maxit=30;
iter=0;
ooldx=0; oldx=10; es=5e-19;

etlist=zeros(1,maxit); %1부터 maxit까지 모두 0으로 구성된 배열을 생성

while 1
    iter=iter+1; %iter의 값을 1씩 더한다
    %secant method의 핵심적인 식, false position의 식과 동일
    newx=oldx-(ff(oldx)*(ooldx-oldx)/(ff(ooldx)-ff(oldx)));
    
    %true relative error을 구한다
    %true value에 중간값을 빼서 true value로 나눈 값에 100 곱한다
    et=abs((tzero-newx)/tzero)*100;
    
    %iteration에 대한 newx, ea, et의 값을 구한다
    fprintf("%d, %.20f %.20f %.20f \n",iter,newx,ea,et);
    etlist(iter)=et;%iter이 속한 배열에 et의 값을 대입
    ooldx=oldx;%oldx의 값을 ooldx에 대입
    oldx=newx;%newx의 값을 oldx에 대
    %ea가 es보다 작거나 iter이 maxit보다 크거나 같으면
    if ea<es||iter>=maxit
        break; %종료
    end
    
    %newx가 0보다 작거나 같으면
    if newx<=0
        break; %종료
    end
end

%배열 etlist의 그래프 그리기
semilogy(etlist); hold on; grid on;

save data_secant.mat; %결과값을 data_bisection.mat에 저장