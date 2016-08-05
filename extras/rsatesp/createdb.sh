#/bin/sh


sqlite3 auth.db "create table users (id INTEGER PRIMARY KEY, user TEXT, pin TEXT);"
sqlite3 auth.db "insert into users (user,pin) values ('bill','2345');"
