%false-position method
ff=@(x) x-cos(x); %주어진 함수를 선언
iter=0;
xl=0; xu=1; %xl과 xu의 값을 임의 지정
ea=100;  maxit=100; es=5e-19;
tzero=0.73908513321516064166;%주어진 함수의 true value 선언
etlist=zeros(1,maxit); %1부터 maxit까지 모두 0으로 구성된 배열을 생성


while 1
    iter=iter+1; %iter의 값을 1씩 더한다
    %false position method의 핵심적인 식
    xr=xu-ff(xu)*(xl-xu)/(ff(xl)-ff(xu));
    if iter==1 %만약 iter이 1이면
        ea=nan; %ea는 수가 아님
    else
        %새로운 xr에서 바로 직전의 xr값을 뺀 값을 xr로 나눈 값을 100을 곱해 ea에 대입
        ea=abs((xr-xrold)/xr)*100;
    end
    
    %true value에 중간값을 빼서 true value로 나눈 값에 100 곱한다
    et=abs((tzero-xr)/tzero)*100;
    %iter이 속한 배열에 et의 값을 대입
    etlist(iter)=et;
    
    %각 iteration의 xr,ea,et 출력
    fprintf('%d %.20f %.20f, %.20f\n',iter,xr,ea,et);
    
    %함수의 xl값과 xr의 값을 곱하여 어느쪽을 새로운 xr로 바꿀지 test
    test=ff(xl)*ff(xr);
    
    if test<0 %만약 test<0이면
        xu=xr; %xu를 xr로 교환
    elseif test>0 %만약 test>0이면
        xl=xr; %xl를 xr로 교환
    else %만약 test=0이면
        ea=0;
    end
    
    xrold=xr; %원래의 xr을 xrold에 대입
    
    if ea<es||iter>=maxit  %ea가 es보다 작거나 iter이 maxit보다 크거나 같으면
        break %종료
    end
end

semilogy(etlist); grid on; %배열 etlist의 그래프 그리기
hold on;

save data_false.mat; %결과값을 data_false.mat에 저장

