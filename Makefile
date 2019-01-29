.PHONY: docs res

all: | project compile res


project: 
	cd bin && cmake .. -G "MinGW Makefiles"
compile: 
	$(MAKE) -C ./bin
docs: 
	python "doxygen/m.css/doxygen/dox2html5.py" "src/Doxyfile-mcss"
pdf: 
	cd ./docs/pdf && $(MAKE)
res:
	python encrypt_files.py res bin
preliminary:
	pip3 install jinja2 Pygments colorama