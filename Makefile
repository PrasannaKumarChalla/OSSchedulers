.PHONY: clean

driver: cpu_sched.c  main.c  proc.c  schedulers.c
	gcc -Wall -g $? -o $@

clean:
	rm -rf driver
