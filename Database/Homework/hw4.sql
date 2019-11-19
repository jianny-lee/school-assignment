/*4.a*/
select C.displacement as weight, S.name
from Classes as C, Ships as S
where S.class = C.class and C.displacement > 35000;

/*4.d*/
select distinct S.name
from Ships as S, Battles as B, Outcomes as O
where S.class = 'Renown' or 
	  (O.battle = 'North Atlantic' and S.name) or
      S.launched <1919;
     
/*4.g*/     
select T.ship
from Outcomes as T, Outcomes as S
where T.result = 'damaged' and
		(T.ship = S.ship and T.battle<>S.battle);
 
/*4.h*/ 
select O.ship, date_format(beginDate, '%m-%Y') as beginDate, date_format(endDate,'%m-%Y') as endDate
from Outcomes as O, Battles as B
where (beginDate between '1942-01-01' and '1943-12-31') and
	  (endDate between '1942-01-01' and '1943-12-31') and
      (O.battle = B.name);

      