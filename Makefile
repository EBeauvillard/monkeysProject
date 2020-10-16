CFLAGS=-Wall  -Wextra -Werror -std=c99 -g3
CURRENT_DIR=achievement0

all : project display_project

clean :
	rm *.o | rm *~ | rm *#* | rm project | rm a.out

project :
	make -C ${CURRENT_DIR} project
	cp ${CURRENT_DIR}/project project

display_project :
	make -C ${CURRENT_DIR} display_project

bin_test :
	make -C ${CURRENT_DIR} bin_test
	cp ${CURRENT_DIR}/bin_test bin_test

test : bin_test
	make -C ${CURRENT_DIR} test

compil_report : compil_report
	make -C report compil_report

report :
	make -C report report
