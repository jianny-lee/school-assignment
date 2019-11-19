/*1.a*/
create table Classes
(	class		varchar(15) ,
	type		varchar(2) ,
	country		varchar(15) ,
    numGuns		int ,
    bore		numeric(4,2) ,
    displacement	numeric(7,2),
    primary key (class));
 
 /*1.b*/
create table Ships
(	name		varchar(20),
	class		varchar(15),
    launched	int, 
    primary key (name),
    foreign key	(class) references Classes(class));
    
/*1.c*/
create table Battles
(	name		varchar(20),
	beginDate	date default '0000-00-00',
    endDate		date default '0000-00-00',
    primary key (name));

/*1.d*/
create table Outcomes
(	ship		varchar(20),
	battle		varchar(20),
    result		varchar(8),
    primary key (ship,battle),
    foreign key (ship) references Ships(name),
    foreign key (battle) references Battles(name));
   
describe Classes;
describe Ships;
describe Battles;
describe Outcomes;
