grammar SQL;

query : selectQuery | insertQuery | deleteQuery | updateQuery ;

selectQuery : 'SELECT' columns 'FROM' tableName (whereClause)? (orderByClause)? ';' ;

insertQuery : 'INSERT INTO' tableName 'VALUES' '(' values ')' ';' ;

deleteQuery : 'DELETE FROM' tableName (whereClause)? ';' ;

updateQuery : 'UPDATE' tableName 'SET' column '=' value (whereClause)? ';' ;

columns : '*' | column (',' column)* ;
column : ID ;
tableName : ID ;

whereClause : 'WHERE' condition ;
orderByClause : 'ORDER BY' column ( 'ASC' | 'DESC' )? ;
condition : column operator value ;
operator : '=' | '>' | '<' | '>=' | '<=' | '<>' ;
values : value (',' value)* ;
value : ID | STRING | NUMBER ;

ID : [a-zA-Z_][a-zA-Z0-9_]* ;
STRING : '"' .*? '"' ;
NUMBER : [0-9]+ ;
WS : [ \t\r\n]+ -> skip ;
