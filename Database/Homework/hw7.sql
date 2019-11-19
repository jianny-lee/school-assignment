SET SQL_SAFE_UPDATES =0;
SET foreign_key_checks = 0;

/*7.c Ships*/
delete from Ships
where name in (select ship
			   from Outcomes
               where result = 'sunk' and
					 battle = 'Surigao Strait');
select * from Ships;

/*7.c Outcomes*/
delete from Outcomes
where result = 'sunk' and
	  battle = 'Surigao Strait';

select * from Outcomes;

 /*7.d*/
select * from Classes;
update Classes
	set bore = bore*2.5;
update Classes
	set displacement = displacement/1.1;
select *from Classes;


/*7.f.delete Outcomes*/
delete from Outcomes
where ship in (select name
			   from Ships
               where class in (select class
							  from Ships
							  group by class
							  having count(class) < 3));
                              
select * from Outcomes;

/*7.f delete Ships*/
delete S
from Ships as S inner join (select class
				from Ships
				group by class
				having count(class) < 3) as T
on S.class=T.class;
select * from Ships;
                