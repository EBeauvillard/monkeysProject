all: rapport

clean :
	rm *~ | rm *#* | rm *.aux | rm *.aux | rm *.pdf | rm *.log

compil_report : report.tex
	pdflatex report.tex

report : compil_report
	evince report.tex
