make all:
	rm -r dist
	mkdir dist
	cd dist

	g++ Queue/queue.cpp -o dist/queue.o -c 
	g++ PublicQueue/publicqueue.cpp -o dist/publicqueue.o -c
	g++ ProtectedQueue/protectedqueue.cpp -o dist/protectedqueue.o -c
	g++ PrivateQueue/privatequeue.cpp -o dist/privatequeue.o -c
	g++ main.cpp -o dist/main.o -c
	
	g++ -o dist/target dist/main.o dist/publicqueue.o dist/protectedqueue.o dist/privatequeue.o dist/queue.o
