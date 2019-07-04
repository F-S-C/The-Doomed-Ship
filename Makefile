.PHONY: docs res

all: | project res


project:
	cmake --build .\cmake-build-debug --target all -- -j 4
docs:
	python "doxygen/m.css/doxygen/dox2html5.py" "src/Doxyfile-mcss"
pdf:
	cd ./docs/pdf && $(MAKE)
res:
	python encrypt_files.py res cmake-build-debug
preliminary:
	pip3 install jinja2 Pygments colorama