OBJS = data_impl.o tfunc_impl.o job_impl.o main.o
prog:$(OBJS)
	gcc -o $@ $^
main.o:main.c pthreaddef.h tfunc.h job.h
	gcc -c $<
data_impl.o:data_impl.c pthreaddef.h
	gcc -c $<
tfunc_impl.o:tfunc_impl.c pthreaddef.h tfunc.h
	gcc -c $<
job_impl.o:job_impl.c pthreaddef.h tfunc.h job.h
	gcc -c $<
clean:
	rm *.o *.exe






OBJS=apipe_impl.o npipe_impl.o parray_impl.o pipeex_impl.o pshell_impl.o main.o
Prog:$(OBJS)
   gcc ¨Co $@ $^
main.o:main.c
