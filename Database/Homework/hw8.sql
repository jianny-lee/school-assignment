/*8_b*/
select * from Ships;
alter table Ships add company varchar(20);
update Ships
	set company = 'ShipCompany'
    where company is null;

select * from Ships;


