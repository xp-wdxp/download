PREFIX  ?= /usr

all:
        mkdir bin/
        gcc src/download.c -lcurl -o bin/download
        @echo "Compilation successfully completed."
        mkdir -p $(PREFIX)/bin
        install -m 0755 bin/download $(PREFIX)/bin/download
        @echo "download has been successfully installed."
build:
        mkdir bin/
        gcc src/download.c -lcurl -o bin/download

install:
        mkdir -p $(PREFIX)/bin
        install -m 0755 bin/download $(PREFIX)/bin/download
        @echo "download has been successfully installed."

uninstall:
        rm -f $(PREFIX)/bin/download
        @echo "download has been uninstalled."
