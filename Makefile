all:
	mkdir bin/
	gcc download.c -lcurl -o bin/download
	@echo "Compilation successfully completed."
build:
	mkdir bin/
	gcc download.c -lcurl -o bin/download
