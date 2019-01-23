.PHONY: docs res

all: | project compile res docs


project: 
	cd bin && cmake .. -G "MinGW Makefiles"
compile: 
	$(MAKE) -C ./bin
docs: 
	python "doxygen/m.css/doxygen/dox2html5.py" "src/Doxyfile-mcss"
pdf: 
	cd ./docs/pdf && $(MAKE)
res:
	xcopy res bin\\res /E /I /Y