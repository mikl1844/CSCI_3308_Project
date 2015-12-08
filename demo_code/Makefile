TARGET = smart_home_demo
CC = g++
CPPFILE = smart_home_demo.cpp smart_home_sql.cpp
CFLAGS = -I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DNDEBUG -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl

$(TARGET): 
	$(CC) $(CPPFILE) -o $(TARGET) $(CFLAGS)

.PHONY: clean

clean:
	rm $(TARGET)
