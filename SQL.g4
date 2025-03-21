grammar SQL;

query : createQuery | selectQuery | insertQuery | deleteQuery | updateQuery | createIndex ;

createQuery: 'CREATE TABLE' tableName '(' tableValues ')' ';' ;

selectQuery : 'SELECT' columns 'FROM' tableName (whereClause)? (orderByClause)? ';' ;

insertQuery : 'INSERT INTO' tableName ( '(' insertColumns ')' )? 'VALUES' '(' values ')' ';' ;

deleteQuery : 'DELETE FROM' tableName (whereClause)? ';' ;

updateQuery : 'UPDATE' tableName 'SET' column '=' value (whereClause)? ';' ;

createIndex : 'CREATE INDEX' indexName 'ON' tableName '(' column ')' ';' ;

insertColumns: column (',' column)* ;

columns : '*' | column (',' column)* ;
column : ID ;
tableName : ID ;
indexName: ID ;

whereClause : 'WHERE' condition ;
orderByClause : 'ORDER BY' column ( 'ASC' | 'DESC' )? ;
condition : orCondition ;
orCondition : andCondition (OR andCondition)* ;
andCondition : baseCondition (AND baseCondition)* ;
baseCondition : '(' condition ')' | columnValueCondition ;
columnValueCondition : column operator value ;
operator : '=' | '>' | '<' | '>=' | '<=' | '<>' ;
AND : 'AND' ;
OR : 'OR' ;
tableValues : tableValue (',' tableValue)* ;
tableValue : value TYPE ;
values : value (',' value)* ;
value : ID ;

TYPE : 'INT' | 'TEXT' | VARCHAR ;
VARCHAR : 'VARCHAR' '(' NUMBER ')' ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;
STRING : '"' .*? '"' ;
NUMBER : [0-9]+ ;
WS : [ \t\r\n]+ -> skip ;
