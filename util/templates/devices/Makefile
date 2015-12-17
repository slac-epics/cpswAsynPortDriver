PY_FILES := $(wildcard *.py)

%: %.py
	python $@ $<

all: $(PY_FILES)
	for i in $^ ; do \
		python $$i ; \
	done  ; \

