# OOP_Library
## Thành viên
Lê Đăng Tấn - 11236199


- [[History of db]]
- Defi: a db is a form of electronic storage in which data is organized systematically
- Entity: a table in db
- Object oriented databased - OOD: data stored in the form of objects
- Graph databases: data stored in the form of nodes
- Document db (MongoDB fr): stored as JSON objs
- [[Relation forms]]
- [[Table databases]]
- [[DB structures]]
- Keys in DB:
	- Key attribute: used to uniquely identify an individual record of data
	- Candidate key: each rows in a column is unique
	- Composite key: ensure that each rows of 2 or more columns is unique
	- Primary key: a selected candidate key
	- Alternate key: the second primary key 
	- Foreign key: references a unique key in another table
	- A [[schema]] is a plan or blueprint that defines how data is organized in a database.
		- Logical DB Schema: components within a schema, show the linking between tables to form a Entity relationship modeling (ER) - illustrating relationships between entity types (a tables-map show first row of each table - the tags row) (draft, plan of ER)![[Pasted image 20240903150142.png]]
		- Physical schema: how the physical structure of a DB is stored on a disk (hard codes)
- [[Relational model]]:
	- One to one
	- One to many
	- Many to Many
- Entity: an object with related attributes (could be anythings - tables, rows, records, columns, ...)
- Attribute types:
	- Simple: cannot be classified further (grades, types, ...)
	- Composite: could be classified further (names to first name and last name, ...)
	- Single valued: can only store 1 value (date, ids, ...)
	- Multi-valued: can store more than 1 value (emails, addresses, ...)
	- Derived: inherits/depends/mades on other attributes 
	- Key: holds unique value
- [[DB normalization]]: process for structuring tables that minimizes challenges facing db systems (acidentally detele, update shit, ...), fix this by follow 3 normal form
	- First normal form 1NF: enforces [[QUOPID#Data atomicity|data atomicity]] and eleminates unnecessary repeating groups of data 
	- Second normal form 2NF: break table to ensure that each table should be a key - nonkey combination (with [[QUOPID#Partial dependency|partial dependency]], a composite key can form 2 column and 1 column for value)
	- Third normal form 3NF: to avoid [[QUOPID#Transitive dependency|transitive dependency]] seem to like a dictionary, 1 for defi and 1 for word ... 
	- More details: [Database Design – 2nd Edition](https://opentextbc.ca/dbdesign01/chapter/chapter-12-normalization/) [Database Normalization](https://www.databasestar.com/database-normalization/) [Anomalies](https://www.bbc.co.uk/bitesize/guides/zc93tv4/revision/2)
