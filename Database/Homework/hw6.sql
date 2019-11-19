/*6.a*/
select count(class)
from Classes
where type = 'bb';

/*6.b*/
select avg(numGuns)
from Classes
where type = 'bb';

/*6.e*/
select class, count(class)
from Outcomes as O, Ships as S
where O.ship=S.name and O.result = 'sunk'
group by class;

/*6.h*/
select battle, sum(numGuns)
from Outcomes as O, Battles as B, Classes as C, Ships as S
where (B.name = O.battle) and (O.ship = S.name) and (S.class = C.class)
group by battle;
