/*2.a*/
insert into Classes (class,type,country,numGuns,bore,displacement) values
					('Bismarck','bb','Germany',8,15,42000),
					('Iowa','bb','USA',9,16,46000),
					('Kongo','bc','Japan',8,14,32000),
					('North Carolina','bb','USA',9,16,37000),
					('Renown','bc','Gt. Britain',6,15,32000),
					('Revenge','bb','Gt. Britain',8,15,29000),
					('Tennessee','bb','USA',12,14,32000),
					('Yamato','bb','Japan',9,18,65000);

/*2.b*/
insert into Battles (name,beginDate,endDate) values
					('North Atlantic','1941-05-24','1941-05-27'),
                    ('Guadalcanal','1942-11-15','1942-11-15'),
                    ('North Cape','1943-12-26','1943-12-26'),
                    ('Surigao Strait','1944-10-25','1944-10-25');

/*2.c*/
insert into Ships (name,class,launched) values
					('Prince of Wales','Tennessee',1921),
					('Bismarck','Bismarck',1915),
					('Duke of York','Kongo',1914),
					('Iowa','Iowa',1943),
					('Kirishima','Kongo',1915),
					('Kongo','Kongo',1913),
					('Fuso','Iowa',1943),
					('Yamashiro','Yamato',1942),
					('California','Iowa',1943),
					('North Carolina','North Carolina',1941),
					('Renown','Renown',1916),
					('Hood','Renown',1916),
					('Scharnhorst','Revenge',1916),
					('Revenge','Revenge',1916),
					('King George V','Revenge',1916),
					('South Dakota','Revenge',1916),
					('Tennessee','Tennessee',1920),
					('Washington','North Carolina',1941),
					('West Virginia','Iowa',1943),
					('Yamato','Yamato',1941);

/*2.d*/
insert into Outcomes (ship,battle,result) values
					('Bismarck','North Atlantic','sunk'),
                    ('California','Surigao Strait','ok'),
                    ('Duke of York','North Cape','ok'),
                    ('Duke of York','Surigao Strait','ok'),
                    ('Fuso','Surigao Strait','sunk'),
                    ('Hood','North Atlantic','sunk'),
                    ('King George V','North Atlantic','ok'),
                    ('Kirishima','Guadalcanal','sunk'),
                    ('Prince of Wales','North Atlantic','damaged'),
                    ('Prince of Wales','North Cape','ok'),
                    ('Scharnhorst','North Cape','sunk'),
                    ('South Dakota','Guadalcanal','damaged'),
                    ('Tennessee','Surigao Strait','sunk'),
                    ('Washington','Guadalcanal','ok'),
                    ('West Virginia','Surigao Strait','ok'),
                    ('Yamashiro','Surigao Strait','ok');
       
select *
from Classes;

select *
from Battles;

select *
from Ships;

select *
from Outcomes;