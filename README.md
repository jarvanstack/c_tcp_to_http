## C_TCP_TO_HTTP
a simple demo of implements http use tcp proto

**it will return `ok` if you run it correctly.**

### CLONE

run this command to clone this  repository.



```bash
git clone git@github.com:dengjiawen8955/c_tcp_to_http.git
```

### COMPILE

run this command to compile the program.

**NOTE: this c program just for linux.**

```shell
cd c_tcp_to_http
gcc -o main main.c 
```

### RUN

run this command to START your program.

**NOTE: program is run at 9000 port,you should make sure that port is not on used.**

```shell
./main
```

### CURL TEST

```shell
curl [ip]:9000/hello
```
if you run localhost and test also on localhost

```shell
curl localhost:9000/hello
```

### BROWSER TEST
if you have a browser on your COMPUTER 
```url
[ip]:9000/hello
```

if you run localhost and test also on localhost
```url
localhost:9000/hello
```