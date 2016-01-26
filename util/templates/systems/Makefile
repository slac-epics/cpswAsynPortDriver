PY_FILES := $(wildcard *.py)
PY_FILES := $(filter-out systemGeneration.py, $(PY_FILES))
DIRS := $(patsubst %.py, %, $(PY_FILES))

all: $(PY_FILES)
	for i in $^ ; do \
		python systemGeneration.py -d $$i ; \
	done  ; \

% : %.py
	python deviceGeneration.py -d $^

clean:
	rm -f *.pyc
	for i in $(DIRS) ; do \
		if [  -d $$i  ]; then \
			rm -rf $$i ; \
		fi ; \
	done  ; \
