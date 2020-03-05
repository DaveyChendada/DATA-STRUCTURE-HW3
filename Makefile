CC = g++
COPTFLAGS = -O3 -g

insert_test: insert_test.o HashTable.o
	$(CC) $(COPTFLAGS) -o $@ $^
search_test:

edit_distance:
