CC=gcc
CFLAGS=

ls:
	$(CC) $(CFLAGS) run_ls.c -o run_ls

lsC:
	$(CC) $(CFLAGS) run_ls_child.c -o run_ls_child

ls_args:
	$(CC) $(CFLAGS) run_ls_args.c -o run_ls_args

args:
	$(CC) $(CFLAGS) args.c -o args
	
clean:
	rm run_ls_args
