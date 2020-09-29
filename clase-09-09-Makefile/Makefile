all: fig.pdf # se ejecuta el target “all” que depende de “fig.pdf”

%.out: %.cpp # crea “sumas.out” con "sumas.cpp"
	g++ $< -o $@

%.txt: %.out # crea “sumas.txt” con "sumas.out"
	./$< > $@

fig.pdf: plotsumas.py sumas.txt # depende de “plot.py” y “sumas.txt”
	python3 $<

clean: # no tiene dependencias, corre de inmediado en la consola haciendo “make clean”
	rm -f a.out *.x sumas.txt
