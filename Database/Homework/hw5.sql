/*5.a*/
select country
from Classes
where numGuns in (select max(numGuns)
				  from Classes);

/*5.b*/
select class
from Ships
where name = some (select ship
				  from Outcomes
                  where result = 'damaged');
