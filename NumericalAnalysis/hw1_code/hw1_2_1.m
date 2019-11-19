%Newton-Raphson method
ff=@(x) 1/(x-1); %주어진 함수를 선언
fp=@(x) -1/(x-1).^2; %주어진 함수를 x에 대해 미분한 함수

maxit=100; oldx=0; 
ea=100; es=5e-4; iter=0;

ealist=zeros(1,maxit); %1부터 maxit까지 모두 0으로 구성된 배열을 생성


while 1
    iter=iter+1;  %iter의 값을 1씩 더한다
    %newton method의 핵심적인 식
    newx=oldx-ff(oldx)/fp(oldx); %우리의 해에 빠르게 도달 가능한 식
    
    %true relative error을 구한다
    %true value에 중간값을 빼서 true value로 나눈 값에 100 곱한다
    ea=abs((newx-oldx)/newx)*100;
    
    %iter이 속한 배열에 et의 값을 대입
    ealist(iter)=ea;
    
    %newx로 선언한 변수의 값을 oldx에 대입
    oldx=newx;
    
    %iteration에 대한 oldx, newx, et 출력
    fprintf('iter:%d, x=%.5f ea=%.5f\n',iter,newx,ea);
    
    %ea가 es보다 작거나 iter이 maxit보다 크거나 같으면
    if ea<es||iter>=maxit
        break; %종료
    end
end

%배열 etlist의 그래프 그리기
semilogy(ealist,"bo-"); hold on; grid on;
xlabel("Iteration");