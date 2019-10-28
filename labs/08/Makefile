proc:
	gcc process.c -o nonOpt
	objdump -d ./nonOpt > noOptimizations.log
	gcc -O3 process.c -o opt3
	objdump -d ./opt3 > optimizations3.log
	time ./nonOpt
	time ./opt3