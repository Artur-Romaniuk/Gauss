all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	@echo "# Te testy powinny zakonczyc sie bez bledu:"
	bin/gauss dane/test1/A dane/test1/b 1>/dev/null
	@echo "# Te testy powinny zakonczyc sie bledem osobliwosci macierzy:"
	bin/gauss dane/test2/A dane/test2/b 1>/dev/null
