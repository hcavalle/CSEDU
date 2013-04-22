
create table Movie(id int NOT NULL, title varchar(100) NOT NULL, year INT NOT NULL, rating VARCHAR(10) NOT NULL, company VARCHAR(50) NOT NULL);


create table Actor(
	id INT NOT NULL,
	last VARCHAR(20) NOT NULL,
	first VARCHAR(20) NOT NULL,
	sex VARCHAR(6) NOT NULL,
	dob date NOT NULL,
	dod date NOT NULL
);


create table Director(
	id INT NOT NULL,
	last VARCHAR(20) NOT NULL,
	first VARCHAR(20) NOT NULL,
	sex VARCHAR(6) NOT NULL,
	dob date NOT NULL,
	dod date NOT NULL
);


create table MovieGenre(
	mid INT NOT NULL,
	genre VARCHAR(20) NOT NULL
);


create table MovieDirector(
	mid INT NOT NULL,
	did int NOT NULL
);

create table MovieActor(
	mid INT NOT NULL,
	aid INT NOT NULL,
	role VARCHAR(50) NOT NULL
);

create table Review(
	name VARCHAR(20) NOT NULL,
	time TIMESTAMP NOT NULL,
	mid INT,
	rating INT,
	comment VARCHAR(500)
);

create table MaxPersonID(
	id INT NOT NULL
);

create table MaxMovieID(
	id INT NOT NULL
);



