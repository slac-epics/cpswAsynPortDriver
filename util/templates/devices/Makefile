PY_FILES := $(wildcard *.py)
PY_FILES := $(filter-out deviceGeneration.py, $(PY_FILES))

all: $(PY_FILES)
	for i in $^ ; do \
		python deviceGeneration.py -d $$i ; \
	done  ; \

clean: $(PY_FILES:%.py=%)
	rm -f *.pyc
	for i in $^ ; do \
		rm -rf $$i ; \
	done  ; \
