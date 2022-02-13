download - A simple to use downloader application.
===

download is a simple project of mine that simply downloads a file from the internet.

# How to use

As download is a very simple app, it is extremely easy-to-use.

Example:

```bash
$ download https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Glenda_bunny_mascot_of_plan_9_from_bell_black.jpg/800px-Glenda_bunny_mascot_of_plan_9_from_bell_black.jpg p9.jpg
```

General Syntax:

```
$ download [site.com/file.file] [name.file]
```

Where the ``[site.com/file.file]`` should be replaced with the download link of the file, and the ``[name.file]`` should be replaced the name of the file.

# Building download

Install libcurl-openssl. This may be dependent upon your distribution's package manager.

Ubuntu 20.04 LTS:
```bash
$ sudo apt install libcurl-openssl-dev
```

Clone this git repository.

```
$ git clone https://github.com/wandererxp/download
$ cd download/
```

Compile it using `make`.

```
$ make build
$ gcc src/download.c -lcurl -o bin/download
$ install 
```