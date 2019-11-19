/*3.a*/
select class, country
from classes
where numGuns < 10;

/*3.c*/
select country
from Classes
where type = 'bc';

/*3.d*/
select name as newship
from Ships
where launched >1918;

/*3.g*/
select name
from Ships
where name like 'R%';
