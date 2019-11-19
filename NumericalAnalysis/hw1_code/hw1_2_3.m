%secant method
ff=@(x) tan(x.^2); %주어진 함수를 선언

maxit=20;
iter=0; ea=100;
ooldx=2; oldx=3; es=5e-19;

ealist=zeros(1,maxit);
while 1
    iter=iter+1; %iter의 값을 1씩 더한다
    %secant method의 핵심적인 식, false position의 식과 동일
    newx=oldx-(ff(oldx)*(ooldx-oldx)/(ff(ooldx)-ff(oldx)));
    
    %approximate error를 구한다
    ea=abs((newx-oldx)/newx)*100;
    
    %iteration에 대한 newx, ea의 값을 구한다
    fprintf("iter:%d newx=%.20f ea=%.20f \n",iter,newx,ea);
    ealist(iter)=ea;
    
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

%배열 etlist와 ealist의 그래프 그리기
semilogy(ealist,'ro-'); hold on; grid on;
title('tan(x) secant');
legend("approximate error");